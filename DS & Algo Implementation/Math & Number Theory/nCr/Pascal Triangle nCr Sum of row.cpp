#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
const int N = 2e6 + 5;
const int MOD = 1e9 + 7;

LL Fact[ 2*N ];
LL modInv[ 2*N ];
LL a[ N ];
int n;

LL BigMod( LL b , LL p , LL mod ) {
        LL res = 1 % mod , x = b % mod;
        while ( p ) {
                if ( p&1 ) res = ( res * x ) % mod;
                x = ( x * x ) % mod;
                p >>= 1;
        }
        return ( res % mod );
}
LL ModInv( LL val , LL mod ) {
        return BigMod( val , mod - 2 , mod );
}
void preCalc( ) {
        Fact[0] = 1LL;
        for( int i = 1; i < 2*N; i++ ){
                Fact[i] = ( Fact[i-1] % MOD * i % MOD ) % MOD;
        }
        modInv[N-1] = ModInv( Fact[N-1] , MOD );
        for( int i = N-2; i >= 0; i-- ) {
                modInv[i] = ( modInv[i+1] % MOD * (i+1) % MOD ) % MOD;
        }
}
LL nCr( LL n , LL r ) {
        if( r > n ) return 0;
        LL val = Fact[n];
        val = ( val % MOD * modInv[r] % MOD ) % MOD;
        val = ( val % MOD * modInv[n-r] % MOD ) % MOD;
        return val;
}
int main( int argc , char const *argv[] ) {
        preCalc( );
        int t;
        scanf("%d",&t);
        while( t-- ) {
                scanf("%d",&n);
                for( int i = 1; i <= n; i++ ) scanf("%lld",&a[i]);
                LL ans = 0;
                for( int i = 1; i <= n; i++ ) {
                        ans = ( ans % MOD + a[i] % MOD * nCr( n + 1 , i ) % MOD ) % MOD;
                }
                printf("%lld\n",ans);
        }
        return 0;
}















