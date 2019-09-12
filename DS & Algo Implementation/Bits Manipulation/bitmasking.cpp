#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
typedef pair< int,int > ii;
typedef pair< int,ii > iii;
const int inf = 1e9;
const LL INF = 1e18;
const int N = 100005;
const int MOD = 1e9+7;
const double EPS = 1e-6;
const double PI = acos(-1.0);

int  Set( int N , int pos )    { return N |= ( 1 << pos ); }
int  Reset( int N , int pos )  { return N = N & ~( 1 << pos ); }
bool Check( int N , int pos )  { return (bool)( N & ( 1 << pos ) );}
int  Toggle( int N , int pos ) { return ( N ^= ( 1 << pos ) ); }

#define RIGHTMOST              __builtin_ctzll // rightmost setbit position
#define POPCOUNT               __builtin_popcountll // total setbit use ll for long long
#define LEFTMOST( x )          ( 63-__builtin_clzll( x ) ) // leftmost setbit position

#define   CheckBit( N , p )      ( !( ( N & ( 1 << p ) ) == 0 ) )
#define   ONBit( N , p )         ( N = N | ( 1 << p ) )
#define   OFFBit( N , p )        ( N = N & ~( 1 << p ) )

int main( int argc, char const *argv[] ) {

    return 0;
}

