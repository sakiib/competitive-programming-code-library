#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

/**
 gfg treeDP type -> 2
 in[s] = height of Node s

 Height of Tree if rooted Dynamically.
 */

int n , in[ N ] , out[ N ];
vector <int> graph[ N ];

void dfs1( int s , int p ) {
        in[s] = 0;
        for( auto x : graph[s] ) {
                if( x != p ) {
                        dfs1( x , s );
                        in[s] = max( in[s] , 1 + in[x] );
                }
        }
}
void dfs2( int s , int p ) {
        int mx1 = -1 , mx2 = -1;
        for( auto x : graph[s] ) {
                if( x == p ) continue;
                if( in[x] >= mx1 ) mx2 = mx1 , mx1 = in[x];
                else if( in[x] > mx2 ) mx2 = in[x];
        }
        for( auto x : graph[s] ) {
                if( x == p ) continue;
                int longest = mx1;
                if( mx1 == in[x] ) longest = mx2;
                out[x] = 1 + max( out[s] , 1 + longest );
                dfs2( x , s );
        }
}
int main( int argc , char const *argv[] ) {
        cin >> n;
        for( int i = 1; i <= n-1; i++ ) {
                int u , v;
                cin >> u >> v;
                graph[u].push_back( v );
                graph[v].push_back( u );
        }
        dfs1( 1 , 0 );
        /// Height of tree if rooted at 1.
        for( int i = 1; i <= n; i++ ) cout << i << " " << in[i] << endl;
        dfs2( 1 , 0 );
        /// Height of tree if rooted at i :
        for( int i = 1; i <= n; i++ ) cout << i << " " << max( in[i] , out[i] ) << endl;
        return 0;
}

/**
11
1 2
1 3
1 4
2 5
2 6
3 7
7 10
7 11
4 8
4 9
*/




