#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector <int> graph[ N ];
int val[ N ];
int dp[ N ];
/**
 geeksforgeeks & rachit jain treeDP - 1
 Max sum of nodes value from root to a child.
 Both works
 dfs2() is just like calculating tree depth
 */


void dfs1( int s , int p ) {
        int mx = 0;
        dp[s] = val[s];
        for( auto x : graph[s] ) {
                if( x != p ) {
                        dfs1( x , s );
                        mx = max( mx , dp[x] );
                }
        }
        dp[s] += mx;
}
void dfs2( int s , int p ) {
        dp[s] = val[s];
        for( auto x : graph[s] ) {
                if( x != p ) {
                        dfs2( x , s );
                        dp[s] = max( dp[s] , val[s] + dp[x] );
                }
        }
}
int main( int argc , char const *argv[] ) {
        int n;
        cin >> n;
        for( int i = 1; i <= n-1; i++ ) {
                int u , v;
                cin >> u >> v;
                graph[u].push_back( v );
                graph[v].push_back( u );
        }
        for( int i = 1; i <= n; i++ ) cin >> val[i];
        dfs1( 1 , 0 );
        cout << "ans : " << dp[1] << endl;
        return 0;
}
/**
14
1 2
1 3
1 4
2 5
2 6
3 7
4 8
4 9
4 10
5 11
5 12
7 13
7 14
3 2 1 10 1 3 9 1 5 3 4 5 9 8

out : 22
*/





