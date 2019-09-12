#include <bits/stdc++.h>
using namespace std;
/**
Tarjan criterion:

Some spanning tree is minimal if and only if the weight of
any other edge (x,y) (not from spanning tree) is not less
than the weight of the heaviest edge on the path from x to y in spanning tree.
*/

typedef long long LL;
const int LOG = 25;
const int N = 2e5 + 5;

int n , m;

struct Edge {
        int u , v , w;
        Edge(){}
        Edge( int u , int v , int w ):u(u),v(v),w(w){}
        bool operator <( const Edge &q ) const {
                return w < q.w;
        }
};

vector <Edge> V;
vector < pair<int,int> > graph[ N ];
int orderu[ N ] , orderv[ N ] , orderw[ N ];
int par[ N ] , p[ N ][ LOG ] , mx[ N ][ LOG ] , level[ N ];

void Makeset( ) {
        for( int i = 1; i <= n; i++ ) par[i] = i;
}
int Find( int x ) {
        return par[x] == x ? x : par[x] = Find( par[x] );
}
void Union( int x , int y ) {
        int u = Find( x ) , v = Find( y );
        if( u != v ) par[u] = v;
}
LL Kruskal( ) {
        Makeset( );
        sort( V.begin() , V.end() );
        LL cost = 0;
        for( auto x : V ) {
                int u = x.u , v = x.v , w = x.w;
                if( Find( u ) != Find( v ) ) {
                        cost += w , Union( u , v );
                        graph[u].push_back( {v,w} );
                        graph[v].push_back( {u,w} );
                }
        }
        return cost;
}
void DFS( int s , int f , int lvl ) {
        p[s][0] = f;
        level[s] = lvl;
        for( auto x : graph[s] ) {
                if( x.first != f ) {
                        mx[x.first][0] = x.second;
                        DFS( x.first , s , lvl+1 );
                }
        }
}
void LCA_init( ) {
        for( int i = 1; i <= LOG-1; i++ ) {
                for( int j = 1; j <= n; j++ ) {
                        p[j][i] = p[ p[j][i-1] ][i-1];
                        mx[j][i] = max( mx[j][i-1] , mx[ p[j][i-1] ][i-1] );
                }
        }
}
int LCA( int u , int v ) {
        if( level[u] < level[v] ) swap( u , v );
        int diff = level[u] - level[v];
        int mx_edge = 0;
        for( int i = LOG-1; i >= 0; i-- ) {
                if( ( 1 << i)&diff ) {
                        mx_edge = max( mx_edge , mx[u][i] );
                        u = p[u][i];
                }
        }
        if( u == v ) return mx_edge;
        for( int i = LOG-1; i >= 0; i-- ) {
                if( p[u][i] != 0 && p[u][i] != p[v][i] ) {
                        mx_edge = max( mx_edge , mx[u][i] );
                        mx_edge = max( mx_edge , mx[v][i] );
                        u = p[u][i];
                        v = p[v][i];
                }
        }
        mx_edge = max( mx_edge , mx[u][0] );
        mx_edge = max( mx_edge , mx[v][0] );
        return mx_edge;
}
int main( int argc , char const *argv[] ) {
        scanf("%d%d",&n,&m);
        for( int i = 1; i <= m; i++ ) {
                int u , v , w;
                scanf("%d %d %d",&u,&v,&w);
                V.push_back( Edge( u , v , w ) );
                orderu[i] = u , orderv[i] = v , orderw[i] = w;
        }
        LL mst_cost = Kruskal();
        DFS(1 , 0 , 1 );
        LCA_init( );
        for( int i = 1; i <= m; i++ ) {
                int u = orderu[i] , v = orderv[i] , w = orderw[i];
                int rem = LCA( u , v );
                LL ans = mst_cost - rem + w;
                printf("%lld\n",ans);
        }
        return 0;
}






