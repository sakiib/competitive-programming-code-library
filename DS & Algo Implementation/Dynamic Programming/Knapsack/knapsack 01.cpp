#include <bits/stdc++.h>
using namespace std;

int n , cap;
int w[ 2005 ] , val[ 2005 ];
int dp[ 2005 ][ 2005 ];

int solve( int idx , int rem ) {
        if( idx > n ) return 0;
        if( rem == 0 ) return 0;
        if( dp[idx][rem] != -1 ) return dp[idx][rem];
        int ret = 0;
        ret = solve( idx + 1 , rem );
        if( w[idx] <= rem ) ret = max( ret , solve( idx + 1 , rem - w[idx] ) + val[idx] );
        return dp[idx][rem] = ret;
}
void Print( int idx , int remCap ) {
        if( idx > n ) return;
        if( remCap <= 0 ) return;
        int op1 = 0 , op2 = 0;
        if( w[idx] <= remCap ) {
                op1 = solve( idx + 1 , remCap - w[idx] ) + val[idx];
        }
        op2 = solve( idx + 1 , remCap );
        if( op1 <= op2 ) {
                Print( idx + 1 , remCap );
        }
        else {
                cout << idx << " ";
                Print( idx + 1 , remCap - w[idx] );
        }
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( NULL );
        int t;
        cin >> t;
        while( t-- ) {
                cin >> cap >> n;
                for( int i = 1; i <= n; i++ ) cin >> w[i] >> val[i];
                memset( dp , -1 , sizeof( dp ) );
                cout << solve( 1 , cap ) << endl;
        }
        return 0;
}










