#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
const int N = 1e5 + 5;
const LL INF = 1e18;

int n , q;

struct data {
        int u , v;
        LL w;
        data(){}
        data( int u , int v , LL w ) : u(u) , v(v) , w(w){}
        bool operator <( const data &q ) const {
                return w < q.w;
        }
};

const int LOG = 25;

vector <data> Edge;
int parent[ N ];
vector < pair <int,int> > graph[ N ];
vector <data> badEdge;

int par[ N ][ LOG+5 ];
LL dist[ N ];
int level[ N ];

int Find( int u ) {
        return ( parent[u] == u ? u : parent[u] = Find( parent[u] ) );
}
void Union( int x , int y ) {
        int u = Find( x ) , v = Find( y );
        if( u != v ) parent[u] = v;
}
void addEdge( int u , int v , int w ) {
        graph[u].push_back( make_pair( v , w ) );
        graph[v].push_back( make_pair( u , w ) );
}
void Make_Tree( ) {
        sort( Edge.begin() , Edge.end() );
        for( int i = 0; i < Edge.size(); i++ ) {
                int u = Edge[i].u , v = Edge[i].v , w = Edge[i].w;
                if( Find( u ) != Find( v ) ) {
                        addEdge( u , v , w );
                        Union( u , v );
                }
                else badEdge.push_back( data( u , v , w ) );
        }
}
void Reset( ) {
        for( int i = 1; i < N; i++ ) parent[i] = i;
        Edge.clear();
        badEdge.clear();
        for( int i = 1; i < N; i++ ) graph[i].clear();
        memset( dist , 0 , sizeof(dist) );
}
void see( ) {
        cout << "badEdges : " << endl;
        for( auto x : badEdge ) cout << x.u << " " << x.v << " " << x.w << endl;
}
void dfs( int s , int p , int lvl ) {
        par[s][0] = p;
        level[s] = lvl;
        for( auto x : graph[s] ) {
                if( x.first != p ) {
                        dist[x.first] = dist[s] + x.second;
                        dfs( x.first , s , lvl + 1 );
                }
        }
}
void precalc_LCA( ) {
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
int main( int argc , char const *argv[] ) {
        int t;
        scanf("%d",&t);
        while( t-- ) {
                Reset();
                scanf("%d %d",&n,&q);
                for( int i = 1; i <= n; i++ ) {
                        int u , v , w;
                        scanf("%d %d %d",&u,&v,&w);
                        Edge.push_back( data( u , v , w ) );
                }
                Make_Tree( );
                dfs( 1 , 0 , 0 );
                precalc_LCA( );
                int U = badEdge[0].u , V = badEdge[0].v , W = badEdge[0].w;
                while( q-- ) {
                        int u , v;
                        scanf("%d %d",&u,&v);
                        LL a = treeDist( u , v );
                        LL b = treeDist( u , U ) + treeDist( V , v ) + W;
                        LL c = treeDist( u , V ) + treeDist( v , U ) + W;
                        LL ans = min( a , min( b , c ) );
                        printf("%lld\n",ans);
                }
        }
        return 0;
}







