#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
const int N = 1e5 + 5;
const int mod = 1000000007;

int n , m , k , w;
int a[ 151 ] , b[ 151 ];
LL dp1[ 151 ][ 15001 ] , dp2[ 151 ][ 15001 ];
LL w1[ 15001 ] , w2[ 15001 ];

/**
 1 coin can be used only once.
 Total number of ways to make an amount
 */

LL go1( int id , int am ) {
        if( am < 0 ) return 0LL;
        if( am == 0 ) return 1LL;
        if( id > n ) return ( am == 0 ? 1LL : 0LL );
        if( dp1[id][am] != -1 ) return dp1[id][am];
        LL x = 0 , y = 0;
        x += go1( id+1 , am-a[id] ) , y += go1( id+1 , am );
        return dp1[id][am] = (x+y)%mod;
}
LL go2( int id , int am ) {
        if( am < 0 ) return 0;
        if( am == 0 ) return 1;
        if( id > m ) return ( am == 0 ? 1LL : 0LL );
        if( dp2[id][am] != -1 ) return dp2[id][am];
        LL x = 0 , y = 0;
        x += go2( id+1 , am-b[id] ) , y += go2( id+1 , am );
        return dp2[id][am] = (x+y)%mod;
}
int main( int argc , char const *argv[] ) {
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
                scanf("%d %d %d %d",&n,&m,&k,&w);
                for( int i = 1; i <= n; i++ ) scanf("%d",&a[i]);
                for( int i = 1; i <= m; i++ ) scanf("%d",&b[i]);

                memset( dp1 , -1 , sizeof(dp1) );
                memset( dp2 , -1 , sizeof(dp2) );

                for( int i = w; i >= 0; i-- ) w1[i] = go1( 1 , i );
                for( int i = w; i >= 0; i-- ) w2[i] = go2( 1 , i );
                LL ans = 0;

                for( int i = 0; i <= w; i++ ) {
                        int j = w - i;
                        if( abs(i-j) <= k ) {
                                ans = ( ans%mod + w1[i]%mod * w2[j]%mod )%mod;
                        }
                }
                printf("%lld\n",ans);
        }
        return 0;
}






