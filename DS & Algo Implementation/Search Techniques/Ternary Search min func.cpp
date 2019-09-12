#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
const int inf = (int)1e9;
const LL INF = (LL)1e18;
const int N = 100005;
const LL MOD = 1000000007;
const double EPS = 1e-7;
const double PI = acos( -1.0 );
#define endl                   '\n'
#define ii                     pair< int, int >
#define iii                    pair< int, ii >
#define F                      first
#define S                      second
#define pb                     push_back
#define ll                     pair < LL, LL >
#define sc                     scanf
#define pf                     printf
#define min3(a, b, c)          min( a, min( b, c) )
#define clr( V )               V.clear( )
#define sz( V )                (int)V.size( )
#define min4(a, b, c, d)       min( min3( a, b, c),d )
#define Fix( x )               setprecision( x ) << fixed
#define SREV( V )              sort( V.rbegin() , V.rend() )
#define All( V )               V.begin(),V.end()
#define min5(a, b, c, d, e)    min( min4( a, b, c, d), e )
#define SORT( V )              sort( V.begin(), V.end() )
#define REV( V )               reverse( V.begin(), V.end() )
#define MEM( a, x )            memset( a, x, sizeof( a ) )
#define max3( a, b, c )        max( a, max( b, c) )
#define mp                     make_pair
#define pp                     pop_back
#define max4(a, b, c, d)       max( max3( a, b, c ), d )
#define RIGHTMOST              __builtin_ctzll
#define POPCOUNT               __builtin_popcountll
#define LEFTMOST( x )          ( 63-__builtin_clzll( x ) )
#define max5(a, b, c, d, e)    max( max4( a, b, c, d ), e )
#define SQ( x )                ( ( (x)*(x) ) )
#define CU( x )                ( (x)*(x)*(x) )
#define CLR( a, n )            for( int i = 0; i < n; i++ ) a[i].clear()
#define debug( x )             cerr << "X is : " << x << endl
#define FOR( i, a, b )         for( int i = a; i <= b; i++ )
#define ROF( i, b, a )         for( int i = b; i >= a; i-- )
#define REP( i, a )            for( int i = 0; i < a; i++ )
#define Read                   freopen( "input.txt", "r", stdin )
#define Write                  freopen( "output.txt", "w", stdout )
#define Fast                   ios_base :: sync_with_stdio( 0 ); cin.tie(NULL)
#define PQ( x )                priority_queue< x, vector< x >, greater< x > >
#define Unique( a )            sort( All(a) ), a.erase( unique( All(a) ), a.end() )
#define UB( a, key )           upper_bound( a.begin(), a.end(), key ) - a.begin()
#define LB( a, key )           lower_bound( a.begin(), a.end(), key ) - a.begin()


double calc( LL x ) { return (2.0*x*x-12.0*x+7.0); }

LL TernarySearch( LL l , LL r ) {
    double lo = l , hi = r , midL , midR;
    int iter = 100;
    while( iter-- ) {
        midL = ( 2.0*lo+hi )/3.0 , midR = ( lo+2.0*hi )/3.0;
        if( calc( midL ) < calc( midR ) ) hi = midR;
        else lo = midL;
    }
    if( calc(lo) < calc(hi) ) return lo;
    return hi;
}
LL TernarySearch( ) {
        int t = 400;
        int lo = 1 , hi = n;
        LL ret = -INF;
        while( t-- ) {
              int midL = ( 2*lo + hi )/3 , midR = ( lo + 2*hi )/3;
              LL x = calc( midL ) , y = calc( midR );
              if( x > y )  ret = max( ret , x ) , hi = midR;
              else ret = max( ret , y ) , lo = midL;
        }
        ret = max( ret , max( calc( lo ) , calc( hi ) ) );
        return ret;
}
int main( int argc , char const *argv[] ) {
    int n;
    sc("%d",&n);
    while( n-- ) {
        LL l , r;
        sc("%lld %lld",&l,&r);
        LL ans = TernarySearch( l , r );
        pf("%lld\n",(long long) calc(ans) );
    }
    return 0;
}
