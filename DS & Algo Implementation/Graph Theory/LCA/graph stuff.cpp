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

const int k = 25;
int n , q;
vector < pair<int,int> > graph[ N ];
int parent[ N ][ k+5 ] , MX[ N ][ k+5 ];
int depth[ N ];

void dfs( int s , int p ) {
        parent[s][0] = p;
        depth[s] = depth[p] + 1;
        for( auto x : graph[s] ) {
                if( x.first != p ) {
                        MX[x.first][0] = x.second;
                        dfs( x.first , s );
                }
        }
}
void calc( ) {
        for( int i = 1; i <= k; i++ ) {
                for( int j = 1; j <= n; j++ ) {
                        parent[j][i] = parent[parent[j][i-1]][i-1];
                        MX[j][i] = max( MX[j][i-1] , MX[parent[j][i-1]][i-1] );
                }
        }
}
int LCA( int u , int v ) {
        if( depth[u] < depth[v] ) swap( u , v );
        int mx = 0;
        int diff = depth[u] - depth[v];
        for( int i = k; i >= 0; i-- ) {
                if( ( diff >> i )&1 ) {
                        mx = max( mx , MX[u][i] );
                        u = parent[u][i];
                }
        }
        if( u == v ) return mx;
        for( int i = k; i >= 0; i-- ) {
                if( parent[u][i] != 0 && parent[u][i] != parent[v][i] ) {
                        mx = max( mx , MX[u][i] );
                        mx = max( mx , MX[v][i] );
                        u = parent[u][i];
                        v = parent[v][i];
                }
        }
        mx = max( mx , max( MX[u][0] , MX[v][0] ) );
        return mx;
}
int main( int argc , char const *argv[] ) {
        scanf("%d %d",&n,&q);
        for( int i = 1; i <= n-1; i++ ) {
                int u , v , w;
                scanf("%d %d %d",&u,&v,&w);
                graph[u].push_back( {v,w} );
                graph[v].push_back( {u,w} );
        }
        dfs( 1 , 0 );
        calc( );
        while( q-- ) {
                int u , v;
                scanf("%d %d",&u,&v);
                printf("%d\n",LCA(u,v));
        }
        return 0;
}






