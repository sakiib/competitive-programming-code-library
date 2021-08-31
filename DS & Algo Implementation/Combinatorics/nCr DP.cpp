

long long dp[ 1005 ][ 1005 ];

long long nCr( int n , int r ) {
        if( r == 1 ) return dp[n][r] = n;
        if( r == 0 ) return dp[n][r] = 1;
        if( n == r ) return dp[n][r] = 1;
        if( dp[n][r] != -1 ) return dp[n][r];
        return dp[n][r] = nCr( n-1 , r ) + nCr( n-1 , r-1 );
}

