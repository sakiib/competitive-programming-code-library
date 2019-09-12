#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
typedef long long int LL;
const int N = 205;
const int inf = 1e9;

int n , k;
LL a[ N ];
LL dp[ N ][ N ];

int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( nullptr );
        cin >> n >> k;
        for( int i = 1; i <= n; i++ ) cin >> a[i];
        for( int i = 1; i <= n; i++ ) for( int j = 1; j <= k; j++ ) dp[i][j] = -inf;
        dp[0][0] = 0;
        for( int i = 1; i <= n; i++ ) {
                for( int j = 1; j <= i; j++ ) {
                        dp[i][j] = max( dp[i-1][j] , dp[i-1][j-1] + a[i] );
                        //cout << i << " " << j << " " << dp[i][j] <<endl;
                }
        }
        cout << "y : " << dp[n][k] << endl;
        return 0;
}












