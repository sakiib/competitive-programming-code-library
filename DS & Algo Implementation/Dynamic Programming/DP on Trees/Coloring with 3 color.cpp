#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
typedef unsigned long long uLL;
typedef long long int LL;
typedef pair <int,int> pii;
typedef pair <int,pii> piii;
typedef pair <long long,long long> pll;
typedef pair <long long,pll> plll;
const int N = 1e5 + 5;
const int inf = 1e9;
const long long INF = 1e18;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int MOD = 1000000007;
/**
Farmer John has a large farm with N barns (1<=N<=105), some of which are already painted
 and some not yet painted. Farmer John wants to paint these remaining barns so
  that all the barns are painted, but he only has three paint colors available.
   Moreover, his prize cow Bessie becomes confused if two barns that are directly
    reachable from one another are the same color, so he wants to make sure this situation
    does not happen.
*/
int n , k;
vector <int> graph[ N ];
int color[ N ];
bool vis[ N ][ 5 ];
LL dp[ N ][ 5 ];

void dfs( int s , int p , int c ) {
        if( vis[s][c] ) return;
        vis[s][c] = 1;
        if( color[s] != 0 && color[s] != c ) {
                dp[s][c] = 0;
                return;
        }
        dp[s][c] = 1;
        for( auto x : graph[s] ) {
                if( x != p ) {
                        for( int i = 1; i <= 3; i++ ) if( i != c ) dfs( x , s , i );
                        LL sum = 0;
                        for( int i = 1; i <= 3; i++ ) if( i != c ) sum += dp[x][i];
                        dp[s][c] *= sum;
                        dp[s][c] %= MOD;
                }
        }
}
///or this...
/**
LL dfs( int s , int p , int c ) {
        if( color[s] != 0 && color[s] != c ) return dp[s][c] = 0; /// color kora node e onno color
                                                                  /// onno color diye disi
        if( dp[s][c] != -1 ) return dp[s][c];
        LL ret = 1;
        for( auto x : graph[s] ) {
                if( x != p ) {
                        LL sum = 0;
                        for( int i = 1; i <= 3; i++ ) if( i != c ) sum += dfs( x , s , i );
                        ret *= sum;
                        ret %= MOD;
                }
        }
        return dp[s][c] = ret;
}
*/
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( nullptr );
        //freopen( "barnpainting.in" , "r" , stdin );
        //freopen( "barnpainting.out" , "w" , stdout );
        cin >> n >> k;
        for( int i = 1; i <= n - 1; i++ ) {
                int u , v;
                cin >> u >> v;
                graph[u].push_back( v );
                graph[v].push_back( u );
        }
        for(int i = 1; i <= k; i++ ) {
                int node , c;
                cin >> node >> c;
                color[node] = c;
        }
        for( int i = 1; i <= 3; i++ ) dfs( 1 , 0 , i );
        cout << ( dp[1][1]%MOD + dp[1][2]%MOD + dp[1][3]%MOD )%MOD << endl;
        return 0;
}










