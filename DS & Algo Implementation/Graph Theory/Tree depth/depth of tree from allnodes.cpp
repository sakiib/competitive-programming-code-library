#include <bits/stdc++.h>
using namespace std;

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
int dp[ N ];

void dfs( int s, int p ) {
        dp[s] = 1;
        for( auto x : graph[s] ) {
                if( x != p ) {
                        dfs( x , s );
                        dp[s] = max( dp[s] , 1 + dp[x] );
                }
        }
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( NULL );
        cin >> n;
        for( int i = 1; i <= n - 1; i++ ) {
                int u , v;
                cin >> u >> v;
                graph[u].push_back( v );
                graph[v].push_back( u );
        }
        dfs( 1 , 0 );
        for( int i = 1; i <= n; i++ ) cout << i << " depth : " << dp[i] << endl;
        return 0;
}

/**
7
1 2
1 3
2 6
3 4
3 5
5 7
*/











