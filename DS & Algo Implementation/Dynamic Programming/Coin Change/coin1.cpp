#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
const int MOD = 100000007;

int n , tot;
int coin[ 55 ] , cnt[ 55 ];
int dp[ 55 ][ 1005 ];

/**
# of ways to make tot
each coin[i] can be use in cnt[i] times
*/
void add( int &a , int b ) {
        a += b;
        if( a > MOD ) a -= MOD;
}
void sub( int &a , int b ) {
        a -= b;
        if( a < MOD ) a += MOD;
}
int main( int argc , char const *argv[] ) {
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
                scanf("%d %d",&n,&tot);
                for( int i = 1; i <= n; i++ ) scanf("%d",&coin[i]);
                for( int i = 1; i <= n; i++ ) scanf("%d",&cnt[i]);
                memset( dp , 0 , sizeof( dp ) );
                for( int i = 0; i <= n; i++ ) dp[i][0] = 1;
                for( int i = 1; i <= tot; i++ ) {
                        for( int j = 1; j <= n; j++ ) {
                                for( int k = 0; k <= cnt[j]; k++ ) {
                                        if( coin[j]*k <= i ) {
                                                add( dp[j][i] , dp[j-1][ i - coin[j]*k ] );
                                        }
                                        else {
                                                add( dp[j][i] , dp[j-1][i] );
                                        }
                                }
                        }
                }
                printf("Case %d: %d\n",tc,dp[n][tot]);
        }
        return 0;
}













