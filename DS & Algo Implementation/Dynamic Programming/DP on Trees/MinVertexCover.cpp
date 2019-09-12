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

int n;
vector <int> graph[ N ];
int dp[ N ][ 2 ];

int dfs( int s , int p , int taken ) {
        int ret = 0;
        if( dp[s][taken] != -1 ) return dp[s][taken];
        for( auto x : graph[s] ) {
                if( x != p ) {
                        if( taken ) {
                                ret += min( 1 + dfs( x , s , 1 ) , dfs( x , s , 0 ) );
                        }
                        else {
                                ret += 1 + dfs( x , s , 1 );
                        }
                }
        }
        return dp[s][taken] = ret;
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( nullptr );
        cin >> n;
        for( int i = 1; i <= n - 1; i++ ) {
                int u , v;
                cin >> u >> v;
                graph[u].push_back( v );
                graph[v].push_back( u );
        }
        memset( dp , -1 , sizeof( dp ) );
        cout << min( 1 + dfs( 1 , 0 , 1 ) , dfs( 1 , 0 , 0 ) ) << endl;
        return 0;
}











