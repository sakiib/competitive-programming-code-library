#include <bits/stdc++.h>
using namespace std;

const int N = 701;

int n;
int a[ N ];
int dp[ 701*701 + 1 ];

int main( int argc , char const *argv[] ) {
        cin >> n;
        int tot = 0;
        for( int i = 1; i <= n; i++ ) cin >> a[i] , tot += a[i];
        dp[0] = 1;
        for( int i = 1; i <= n; i++ ) {
                for( int j = tot; j - a[i] >= 0; j-- ) {
                        dp[j] |= dp[ j - a[i] ];
                }
        }
        //for( int i = 1; i <= tot; i++ ) cout << dp[i] << " ";
        int ans = 100000000;
        for( int i = 0; i <= tot; i++ ) {
                if( dp[i] == 1 && dp[ tot - i ] == 1 ) {
                        ans = min( ans , abs( tot - i - i ) );
                }
        }
        cout << ans << endl;
        return 0;
}











