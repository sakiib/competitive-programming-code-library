#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

char a[35] , b[35];
int dp[ 35 ][ 35 ];
LL DP[ 35 ][ 35 ][ 35 ];
int la , lb;
int len , lcs;

/**
1. The length of the shortest string that contains the names as subsequence.

2. Total number of unique shortest strings which contain the names as subsequence
*/

int LCS( int i ,int j ) {
        if( i >= la || j >= lb ) return 0;
        if( dp[i][j] != -1 ) return dp[i][j];
        if( a[i] == b[j] ) return 1 + LCS( i + 1 , j + 1 );
        return dp[i][j] = max( LCS( i + 1 , j ) , LCS( i , j + 1 ) );
}
LL solve( int i , int j , int l ) {
        if( i >= la || j >= lb ) return l == lcs;
        if( DP[i][j][l] != -1 ) return DP[i][j][l];
        if( a[i] == b[j] ) return solve( i + 1 , j + 1 , l + 1 );
        return DP[i][j][l] = solve( i + 1 , j , l ) + solve( i , j + 1 , l );
}
int main( int argc , char const *argv[] ) {
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
                scanf("%s %s",a,b);
                la = strlen( a );
                lb = strlen( b );
                memset( dp , -1 , sizeof( dp ) );
                lcs = LCS( 0 , 0 );
                len = la + lb - lcs;
                memset( DP , -1 , sizeof( DP ) );
                LL ans = solve( 0 , 0 , 0 );
                printf("Case %d: %d %lld\n",tc,len,ans);
        }
        return 0;
}










