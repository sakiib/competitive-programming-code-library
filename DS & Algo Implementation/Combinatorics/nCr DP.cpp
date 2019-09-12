#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;
long long dp[ 1005 ][ 1005 ];

long long nCr( int n , int r ) {
        if( r == 1 ) return dp[n][r] = n;
        if( r == 0 ) return dp[n][r] = 1;
        if( n == r ) return dp[n][r] = 1;
        if( dp[n][r] != -1 ) return dp[n][r];
        return dp[n][r] = nCr( n-1 , r ) + nCr( n-1 , r-1 );
}
int main( int argc , char const *argv[] ) {
        int n , r;
        memset( dp , -1 , sizeof(dp) );
        while( cin >> n >> r ) {
                cout << nCr( n , r ) << endl;
        }
        return 0;
}
