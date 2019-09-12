#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
typedef pair < int , int > ii;
const int inf = 1e9;
const LL INF = 1e18;
const int N = 1e5 + 5;
const int mod = 1000000007;
const double eps = 1e-8;
const double pi = acos( -1.0 );

char s[10];
int n , q , parent[ N ][ 30 ];
LL val[ N ] , sub[ N ] , depth[ N ];
vector <int> graph[ N ];

void dfs( int s , int p ) {
        depth[s] = depth[p] + 1;
        sub[s] = val[s];
        for( auto x : graph[s] ) {
                if( x != p ) dfs( x , s ) , sub[s] += sub[x];
        }
}
int LCA( int u , int v ) {
        if( depth[u] < depth[v] ) swap( u , v );
        int diff = depth[u] - depth[v];
        for( int i = 25; i >= 0; i-- ) {
                if( ( 1 << i )&diff ) u = parent[u][i];
        }
        if( u == v ) return u;
        for( int i = 25; i >= 0; i-- ) {
                if( parent[u][i] != 0 && parent[u][i] != parent[v][i] ) {
                        u = parent[u][i];
                        v = parent[v][i];
                }
        }
        return parent[u][0];
}
void calc( ) {
        for( int i = 1; ( 1 << i ) <= n; i++ ) {
                for( int j = 1; j <= n; j++ ) {
                        if( parent[j][i-1] )
                        parent[j][i] = parent[ parent[j][i-1] ][i-1];
                }
        }
}
int main( int argc , char const *argv[] ) {
        scanf("%d",&n);
        for( int i = 1; i <= n; i++ ) scanf("%d",&val[i]);
        for( int i = 2; i <= n; i++ ) {
                scanf("%d",&parent[i][0]);
                graph[ parent[i][0] ].push_back( i);
                graph[ i ].push_back( parent[i][0] );
        }
        dfs( 1 , 0 );
        calc( );
        scanf("%d",&q);
        int root = 1;
        while( q-- ) {
                int k;
                scanf("%s %d",s,&k);
                if( s[0] == 'R' ) {
                        root = k;
                }
                else {
                       if( root == k ) {
                            printf("%lld\n",sub[1]);
                            continue;
                       }
                       int lca = LCA( root , k );
                       if( lca == k ) {
                            int diff = depth[root] - depth[k]-1;
                            k = root;
                            for( int i = 25; i >= 0; i-- ) {
                                    if( ( 1 << i )&diff ) k = parent[k][i];
                            }
                            printf("%lld\n",sub[1]-sub[k]);
                       }
                       else printf("%lld\n",sub[k]);
                }
        }
        return 0;
}






