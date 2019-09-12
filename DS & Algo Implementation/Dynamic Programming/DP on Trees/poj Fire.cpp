#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair <int,int> ii;
const int inf = 1e9;
const LL INF = 1e18;
const int N = 1e3 + 5;

int n;
int W[ N ] , D[ N ] , dist[ N ][ N ] , All[ N ] , dp[ N ][ N ];
vector < pair <int,int> > graph[ N ];

void reset( ) {
        for( int i = 1; i < N; i++ ) graph[i].clear();
        memset( dp , 0x3f3f3f3f , sizeof(dp) );
        memset( All , 0x3f3f3f3f , sizeof(All) );
}
void dfs( int s , int p , int ss , int d ) {
        dist[ss][s] = d;
        for( int i = 0; i < graph[s].size(); i++ ) {
                pair <int,int> P = graph[s][i];
                if( P.first != p ) {
                        dfs( P.first , s , ss , d + P.second );
                }
        }
}
void dfsDP( int s , int p ) {
        for( int i = 1; i <= n; i++ ) {
                if( dist[s][i] <= D[s] ) dp[s][i] = W[i];
        }
        for( int i = 0; i < graph[s].size(); i++ ) {
                pair <int,int> P = graph[s][i];
                if( P.first == p ) continue;
                dfsDP( P.first , s );
                for( int j = 1; j <= n; j++ ) {
                        dp[s][j] += min( dp[P.first][j] - W[j] , All[P.first] );
                }
        }
        for( int i = 1; i <= n; i++ ) All[s] = min( All[s] , dp[s][i] );
}
int main( int argc , char const *argv[] ) {
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
                reset();
                scanf("%d",&n);
                for( int i = 1; i <= n; i++ ) scanf("%d",&W[i]);
                for( int i = 1; i <= n; i++ ) scanf("%d",&D[i]);
                for( int i = 1; i <= n-1; i++ ) {
                        int u , v , w;
                        scanf("%d %d %d",&u,&v,&w);
                        graph[u].push_back( make_pair(v,w) );
                        graph[v].push_back( make_pair(u,w) );
                }
                for( int i = 1; i <= n; i++ ) dfs( i , 0 , i , 0 );
                dfsDP( 1 , 0 );
                printf("%d\n",All[1]);
        }
        return 0;
}






