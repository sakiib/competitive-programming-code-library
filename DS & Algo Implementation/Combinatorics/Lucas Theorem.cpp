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

LL fact[ N ];

LL BigMod ( LL b , LL p , int mod ) {
    LL res = 1 % mod , x = b % mod;
    while ( p ) {
        if ( p & 1 ) res = ( res * x ) % mod;
        x = ( x * x ) % mod; p >>= 1;
    }
    return ( res%mod );
}

LL ModInv( LL val , int mod ) { return BigMod( val , mod-2 , mod ); }

void gen_fact( ) {
        fact[0] = 1%mod;
        for( int i = 1; i < N; i++ ) fact[i] = ( i%mod * fact[i-1]%mod )%mod;
}
LL nCr( int n , int r , int mod ) {
        vector <int> dp( r+1 , 0 );
        dp[0] = 1;
        for( int i = 1; i <= n; i++ ) {
                for( int j = min( i , r ); j > 0; j-- ) {
                        dp[j] = ( dp[j] + dp[j-1] )%mod;
                }
        }
        return dp[r];
}
LL NCR( int n , int r , int mod ) {
        LL val = ( fact[r]%mod * fact[n-r]%mod )%mod;
        LL ans = ( fact[n]%mod * ModInv( val, mod )%mod )%mod;
        return ans;
}
LL Lucas( int n , int r , int mod ) {
        if( r == 0 ) return 1;
        return (Lucas( n/mod , r/mod , mod ) * nCr( n%mod , r%mod , mod ))%mod;
}
int main( int argc , char const *argv[] ) {
        ios_base :: sync_with_stdio(false); cin.tie(NULL);
        gen_fact( );
        int n , r;
        while( cin >> n >> r ) {
                cout << Lucas( n , r , mod ) << endl;
        }
        return 0;
}
/**
mod must be prime , otherwise use CRT.
For nCr( BigValues ) : we can also use , n!/(r!*(n-r)!) with modinv

*/





