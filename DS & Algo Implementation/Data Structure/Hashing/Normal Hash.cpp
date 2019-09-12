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

const int Base = 31;

LL power[ N ];

map < LL  , LL > M;


void GeneratePower( ) {
    power[0] = 1LL;
    for( int i = 1; i < N; i++ ) power[i] = power[i-1]*Base;
}
LL GetHash( string s ) {
    int len = s.size();
    LL Hash = 0;
    for( int i = 0; i < len; i++ ) Hash += ( power[i] * s[i] );
    return Hash;
}
int main( int argc, char const *argv[] ) {
    GeneratePower( );
    int n;
    cin >> n;
    while( n-- ) {
        string s;
        cin >> s;
        LL Hash = GetHash( s );
        if( M[ Hash ] == 0 ) cout << "OK" << endl;
        else cout << s <<M[ Hash ] << endl;
        M[ Hash ]++;
    }
    return 0;
}







