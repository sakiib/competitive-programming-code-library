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
        ios_base :: sync_with_stdio(false); cin.tie(NULL);

        return 0;
}





