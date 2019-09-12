#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;

const int N = 1e5 + 5;
const LL INF = 1e18;
const int LOG = 25;

struct data {
        int u , v;
        LL w;
        data(){}
        data( int u , int v , LL w ) : u(u) , v(v) , w(w) {}
        bool operator <( const data &q ) const {
                return w < q.w;
        }
};

int n , e , q;
vector <data> V;
vector < pair <int,LL> > graph[ N ] , tree[ N ];
vector <data> badEdge;
int parent[ N ];
set <int> Node;
map <int,int> ID;
int level[ N ];
int par[ N ][ LOG+5 ];
LL dist[ N ];
LL djDist[ N ][ 55 ];

int Find( int u ) {
        return parent[u] == u ? u : parent[u] = Find( parent[u] );
}
void Union( int x , int y ) {
        int u = Find( x );
        int v = Find( y );
        if( u != v ) parent[u] = v;
}
void addEdge( int u , int v , LL w ) {
        graph[u].push_back( make_pair( v , w ) );
        graph[v].push_back( make_pair( u , w ) );
}
void makeTree( ) {
        sort( V.begin() , V.end() );
        for( int i = 0; i < V.size(); i++ ) {
                int u = V[i].u , v = V[i].v; LL w = V[i].w;
                if( Find( u ) != Find( v ) ) {
                        tree[u].push_back( make_pair( v , w ) );
                        tree[v].push_back( make_pair( u , w ) );
                        Union( u , v );
                }
                else {
                        badEdge.push_back( data( u , v , w ) );
                        Node.insert( u );
                        Node.insert( v );
                }
        }
}
void makeSet( ) {
        for( int i = 1; i < N; i++ ) parent[i] = i;
}
void dfs( int s , int p , int lvl ) {
        par[s][0] = p;
        level[s] = lvl;
        for( auto x : tree[s] ) {
                if( x.first != p ) {
                        dist[x.first] = dist[s] + x.second;
                        dfs( x.first , s , lvl + 1 );
                }
        }
}
void precalcLCA( ) {
        for( int i = 1; i <= LOG; i++ ) {
                for( int j = 1; j <= n; j++ ) {
                        par[j][i] = par[ par[j][i-1] ][i-1];
                }
        }
}
int LCA( int u , int v ) {
        if( level[ v ] < level[ u ] ) swap( u , v );
        int dif = level[ v ] - level[ u ];
        for( int i = 0; i <= LOG; i++ ) {
                if( ( dif >> i )&1 ) v = par[ v ][ i ];
        }
        if( u == v ) return u;
        for( int i = LOG; i >= 0; i-- ) {
                if( par[ u ][ i ] != par[ v ][ i ] && par[u][i] != 0 ) {
                        u = par[ u ][ i ];
                        v = par[ v ][ i ];
                }
        }
        return par[ u ][ 0 ];
}
LL treeDist( int u , int v ) {
        LL Dist = dist[ u ] + dist[ v ] - 2 * dist[ LCA( u , v ) ];
        return Dist;
}
void Dijkstra( int s , int id ) {
        priority_queue < pair<LL,LL> , vector <pair<LL,LL>> , greater <pair<LL,LL>> > Q;
        djDist[s][id] = 0;
        Q.push( make_pair( djDist[s][id] , s ) );
        while( !Q.empty() ) {
                pair <LL,LL> t = Q.top(); Q.pop();
                LL ps = t.second , pc = t.first;
                for( auto x : graph[ps] ) {
                        if( djDist[x.first][id] == INF || djDist[x.first][id] > djDist[ps][id] + x.second ) {
                                djDist[x.first][id] = djDist[ps][id] + x.second;
                                Q.push( make_pair( djDist[x.first][id] , x.first ) );
                        }
                }
        }
}
void goDijkstra( ) {
        int id = 0;
        for( int i = 1; i <= 50; i++ ) {
                for( int j = 1; j < N; j++ ) {
                        djDist[j][i] = INF;
                }
        }
        for( auto x : Node ) ID[x] = ++id , Dijkstra( x , ID[x] );
}
LL solveQuery( int u , int v ) {
        LL ret = treeDist( u , v );
        for( auto x : badEdge ) {
                int idu = ID[x.u] , idv = ID[x.v];
                ret = min( ret , djDist[u][idu] + djDist[v][idv] + x.w );
                ret = min( ret , djDist[v][idu] + djDist[u][idv] + x.w );
        }
        return ret;
}
void see( ) {
        cout << "Nodes : "<< endl;
        for( auto x : Node ) cout << x << " "; cout << endl;
        cout << "badEdges : " << endl;
        for( auto x : badEdge ) cout << x.u << " "<< x.v << " " << x.w << endl;
}
int main( int argc , char const *argv[] ) {
        scanf("%d %d",&n,&e);
        for( int i = 1; i <= e; i++ ) {
                int u , v , w;
                scanf("%d %d %d",&u,&v,&w);
                V.push_back( data( u , v , w ) );
                addEdge( u , v , w );
        }
        makeSet( );
        makeTree( );
        dfs( 1 , 0 , 0 );
        precalcLCA( );
        goDijkstra( );
        scanf("%d",&q);
        while( q-- ) {
                int u , v;
                scanf("%d %d",&u,&v);
                LL ans = solveQuery( u , v );
                printf("%lld\n",ans);
        }
        return 0;
}
