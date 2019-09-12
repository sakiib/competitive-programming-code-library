#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
typedef pair < int , int > ii;
const int inf = 1e9;
const LL INF = 1e18;
const int N = 1e5 + 5;
const int mod = 1000000007;
const double eps = 1e-8;
const double pi = acos( -1.0 );

LL BigMod ( LL b , LL p , LL mod ) {
        LL res = 1 % mod , x = b % mod;
        while ( p ) {
                if ( p & 1 ) res = ( res * x ) % mod;
                x = ( x * x ) % mod; p >>= 1;
        }
        return ( res%mod );
}

LL ModInv( LL val , LL mod ) { return BigMod( val , mod-2 , mod ); }

int main( int argc , char const *argv[] ) {
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
                LL times , n;
                scanf("%lld %lld",&times,&n);
                LL len = 0;
                LL temp = n;
                while( temp ) len++ , temp/= 10;

                /**
                 ans = N * ( 10^(times*len) - 1 ) / ( 10^len - 1 )
                 31 + 31 * 10^2 + 31 * 10^4 + ...+ 31 * 10*(M*len)
                 */

                LL up = BigMod( 10 , times*len , mod );
                up -= 1;
                if( up < 0 ) up += mod;
                LL down = BigMod( 10 , len , mod );
                down -= 1;
                if( down < 0 ) down += mod;

                LL mul = ModInv( down , mod );
                LL cur = ( up%mod * mul%mod )%mod;
                LL ans = ( cur%mod * n%mod )%mod;
                printf("%lld\n",ans);
        }
        return 0;
}







