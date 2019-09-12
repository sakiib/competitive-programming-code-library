#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
typedef unsigned long long uLL;
typedef long long int LL;
typedef pair <int,int> pii;
typedef pair <int,pii> piii;
typedef pair <long long,long long> pll;
typedef pair <long long,pll> plll;
const int N = 2005;
const int inf = 1e9;
const long long INF = 1e18;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int MOD = 998244353;

LL dp[ N ][ N ];

int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( nullptr );
        int n , m , k;
        cin >> n >> m >> k;
        dp[1][0] = m;
        for( int i = 2; i <= n; i++ ) {
                for( int j = 0; j <= k; j++ ) {
                        if( j == 0 ) {
                                dp[i][j] += dp[i-1][j] , dp[i][j] %= MOD;
                        }
                        else {
                                dp[i][j] += dp[i-1][j] , dp[i][j] %= MOD;
                                dp[i][j] += ( dp[i-1][j-1] * ( m - 1 ) ) , dp[i][j] %= MOD;
                        }
                }
        }
        cout << dp[n][k] <<endl;
        return 0;
}











