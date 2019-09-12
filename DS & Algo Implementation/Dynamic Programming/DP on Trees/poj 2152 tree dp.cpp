#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <cstring>
#include <set>
#include <queue>
#include <algorithm>
#include <vector>
#include <map>
#include <cctype>
#include <cmath>
#include <stack>
#include <sstream>
#include <list>
#include <assert.h>
#include <bitset>
using namespace std;

const int N = 1e3 + 5;
const int inf = 0x3f3f3f3f; /// 1061109567

int n;
int cost[ N ] , limit[ N ];
vector < pair <int,int> > graph[ N ];
int dist[ N ][ N ];
int ans[ N ] , dp[ N ][ N ];

void calc_dist( int s , int p , int root ) {
        for( int i = 0; i < graph[s].size(); i++ ) {
                int v = graph[s][i].first , w = graph[s][i].second;
                if( v == p ) continue;
                dist[root][v] = dist[v][root] = dist[root][s] + w;
                calc_dist( v , s , root );
        }
}
void dfs( int s , int p ) {
        for( int i = 0; i < graph[s].size(); i++ ) {
                int v = graph[s][i].first , w = graph[s][i].second;
                if( v == p ) continue;
                dfs( v , s );
        }
        for( int j = 1; j <= n; j++ ) {
                if( dist[s][j] > limit[s] ) continue;
                dp[s][j] = cost[j];
                for( int i = 0; i < graph[s].size(); i++ ) {
                        int v = graph[s][i].first;
                        if( v == p ) continue;
                        dp[s][j] += min( ans[v] , dp[v][j] - cost[j] );
                }
                ans[s] = min( ans[s] , dp[s][j] );
        }
}
int main( ) {
        //FIO;
        #ifdef OFFLINE
            freopen( "input.txt" , "r" , stdin );
        #endif // OFFLINE
        int t;
        scanf("%d",&t);
        while( t-- ) {
                for( int i = 1; i < N; i++ ) graph[i].clear();
                memset( dist , 0 , sizeof( dist ) );
                scanf("%d",&n);
                for( int i = 1; i <= n; i++ ) scanf("%d",&cost[i]);
                for( int i = 1; i <= n; i++ ) scanf("%d",&limit[i]);
                for( int i = 1; i <= n - 1; i++ ) {
                        int u , v , w;
                        scanf("%d %d %d",&u,&v,&w);
                        graph[u].push_back( make_pair( v , w ) );
                        graph[v].push_back( make_pair( u , w ) );
                }
                /// calculates all pair distance by rooting the tree at node i
                for( int i = 1; i <= n; i++ ) calc_dist( i , 0 , i );
                memset( ans , inf , sizeof( ans ) );
                memset( dp , inf , sizeof( dp ) );
                dfs( 1 , 0 );
                printf("------------------->%d\n",ans[1]);
        }
        return 0;
}






