#include <bits/stdc++.h>
using namespace std;

int n;
int a[ 2005 ];
int dp[ 2005 ];
int lim;

/**
in a circular array , maximum sum we can make without taking two neighbouring elements
*/

int solve( int idx ) {
        if( idx > lim ) return 0;
        if( dp[idx] != -1 ) return dp[idx];
        int ret = 0;
        ret = solve( idx + 1 );
        ret = max( ret , solve( idx + 2 ) + a[idx] );
        return dp[idx] = ret;
}
int main( int argc , char const *argv[] ) {
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
               scanf("%d",&n);
               for( int i = 1; i <= n; i++ ) scanf("%d",&a[i]);
               for( int i = n + 1; i <= 2*n;i++ ) a[i] = a[i-n];
               int ans = 0;
               memset( dp , -1 , sizeof( dp ) );
               for( int i = 1; i <= n; i++ ) {
                        lim = i + ( n - 2 );
                        ans = max( ans , solve( i ) );
               }
               printf("Case %d: %d\n",tc,ans);
        }
        return 0;
}










