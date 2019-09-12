#include <bits/stdc++.h>
using namespace std;

int n , cap;
int w[ 2005 ] , val[ 2005 ];
int dp[ 2005 ];

int solve( ) {
        for( int i = 1; i <= n; i++ ) {
                for( int j = 2000; j - w[i] >= 0; j-- ) {
                        dp[j] = max( dp[j] , val[i] + dp[ j - w[i] ] );
                }
        }
        return dp[cap];
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( NULL );
        int t;
        cin >> t;
        while( t-- ) {
                cin >> cap >> n;
                for( int i = 1; i <= n; i++ ) cin >> w[i] >> val[i];
                cout << solve( ) << endl;
        }
        return 0;
}











