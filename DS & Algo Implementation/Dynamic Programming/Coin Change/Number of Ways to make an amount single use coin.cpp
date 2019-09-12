#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
const int N = 1e5 + 5;
const int mod = 1000000007;

int n , m , k , w;
int a[ 151 ] , b[ 151 ];
LL dp1[ 15005 ] , dp2[ 15005 ];

/**
 1 coin can be used single time.
 number of ways to make an amount.
 */

void calc1( ) {
        dp1[0] = 1LL;
        for( int i = 1; i <= n; i++ ) {
                for( int j = w; j-a[i] >= 0; j-- ) {
                        dp1[j] = ( dp1[j]%mod + dp1[ j-a[i] ]%mod )%mod;
                }
        }
}
void calc2( ) {
        dp2[0] = 1LL;
        for( int i = 1; i <= m; i++ ) {
                for( int j = w; j-b[i] >= 0; j-- ) {
                        dp2[j] = ( dp2[j]%mod + dp2[ j-b[i] ]%mod )%mod;
                }
        }
}
int main( int argc , char const *argv[] ) {
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
                scanf("%d %d %d %d",&n,&m,&k,&w);
                for( int i = 1; i <= n; i++ ) scanf("%d",&a[i]);
                for( int i = 1; i <= m; i++ ) scanf("%d",&b[i]);

                memset( dp1 , 0 , sizeof(dp1) );
                memset( dp2 , 0 , sizeof(dp2) );

                calc1( );
                calc2( );

                LL ans = 0;
                for( int i = 0; i <= w; i++ ) {
                        int j = w - i;
                        if( abs(i-j) <= k ) {
                                ans = ( ans%mod + dp1[i]%mod * dp2[j]%mod )%mod;
                        }
                }
                printf("%lld\n",ans);
        }
        return 0;
}







