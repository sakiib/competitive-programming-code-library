#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
const int N = 2e5 + 5;
const int MOD = 1000000007;

#define x first
#define y second

int r , c , k;
LL Fact[ 2*N ];
LL modInv[ 2*N ]; /// take it 2 times

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
LL Ways( int x1 , int y1 , int x2 , int y2 ) { // Number of ways to go to (x2,y2) from (x1,y1)
        if( x1 > x2 || y1 > y2 ) return 0;
        LL step = ( x2 - x1 + y2 - y1 );
        LL r = ( y2 - y1 );
        return nCr( step , r );
}
int main( int argc , char const *argv[] ) {
        preCalc( );

        return 0;
}








