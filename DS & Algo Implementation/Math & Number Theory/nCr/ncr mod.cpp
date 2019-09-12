#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
const int inf = (int)1e9;
const LL INF = (LL)2e18;
const int N = 100005;
const int mod = 1000000007;
const double eps = 1e-8;
const double pi = acos( -1.0 );
#define ii                       pair < int, int >
#define iii                      pair < int, ii >
#define FOR( i, a, b )           for( int i = a; i <= b; i++ )
#define ROF( i, a, b )           for( int i = a; i >= b; i-- )
#define pb                       push_back
#define mp                       make_pair
#define line                     cerr << "***** here *****" << endl;
#define all( V )                 V.begin(), V.end()
#define Unique( a )              sort(all(a)),a.erase(unique(all(a)),a.end())
#define sc                       scanf
#define pf                       printf
#define Fix( x )                 setprecision( x ) << fixed
#define mem( a, x )              memset( a, x, sizeof( a ) )

LL fact[ N ];

LL BigMod ( LL b , LL p , LL mod ) {
    LL res = 1 % mod , x = b % mod;
    while ( p ) {
        if ( p & 1 ) res = ( res * x ) % mod;
        x = ( x * x ) % mod; p >>= 1;
    }
    return ( res%mod );
}

LL ModInv( LL val , LL mod ) { return BigMod( val , mod-2 , mod ); }

void genfact( ) {
    fact[0] = 1LL;
    for( int i = 1; i < N; i++ ) fact[i] = ( fact[i-1]%mod * i%mod )%mod;
}
int main( int argc, char const *argv[] ) {
    genfact( );
    int n , r;
    while( cin >> n >> r ) {
        LL val = ( fact[r]%mod * fact[n-r]%mod )%mod;
        LL ans = ( fact[n]%mod * ModInv( val, mod )%mod )%mod;
        cout << ans << endl;
    }
    return 0;
}






