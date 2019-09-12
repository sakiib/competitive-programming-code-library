#include <bits/stdc++.h>
using namespace std;

int n , cap;
int w[ 2005 ] , val[ 2005 ];
int dp[ 2005 ][ 2005 ];
int dp[ 2005 ];


int solve( ) {
        for( int i = 1; i <= n; i++ ) {
                for( int j = 1; j <= 2000; j++ ) {
                        if( w[i] <= j ) {
                                dp[i][j] = max( dp[i-1][j] , dp[i-1][ j - w[i] ] + val[i] );
                        }
                        else {
                                dp[i][j] = dp[i-1][j];
                        }
                }
        }
        return dp[n][cap];
}


int solve( ) {
        /// here a item can be taken atmost once , for multiple rum j loop small to large
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










