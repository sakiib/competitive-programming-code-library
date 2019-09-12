#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long uLL;
typedef long long int LL;
const int N = 1e5 + 5;
const int inf = 1e9;
const LL INF = 1e18;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int MOD = 1000000007;
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define Fix( x ) setprecision( x ) << fixed
#define mem( a , x ) memset( a , x , sizeof( a ) )
#define sz( V ) (int)V.size( )
#define all( V ) V.begin( ),V.end( )
#define Unique( V ) sort( all( V ) ), V.erase( unique( all( V ) ), V.end() )
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" , ";__f(comma+1, args...);
}

#define leftmost( x )  ( 63 - __builtin_clzll( x ) )
int  Set( int N , int pos )    { return N |= ( 1 << pos ); }
int  Reset( int N , int pos )  { return N = N & ~( 1 << pos ); }
bool Check( int N , int pos )  { return (bool)( N & ( 1 << pos ) );}
int  Toggle( int N , int pos ) { return ( N ^= ( 1 << pos ) ); }

LL a , b , c;
LL dp[ 32 ][ 32 ][ 32 ][ 2 ];
int High;

LL solve( int pos , int remA , int remB , int carry ) {
        if( remA < 0 || remB < 0 ) return 0LL;
        if( pos > High ) {
                if( remA != 0 || remB != 0 || carry != 0 ) return 0LL;
                return 1LL;
        }
        if( dp[pos][remA][remB][carry] != -1 ) return dp[pos][remA][remB][carry];
        LL ret = 0;
        for( int i = 0; i <= 1; i++ ) {
                for( int j = 0; j <= 1; j++ ) {
                        if( ( ( i + j + carry )&1) == (( c&( 1 << pos )) > 0 ) ) {
                                ret += solve( pos + 1 , remA - i , remB - j , ( i+j+carry )/2 );
                        }
                }
        }
        return dp[pos][remA][remB][carry] = ret;
}
int main( int argc , char const *argv[] ) {
        int t;
        scanf("%d",&t);
        while( t-- ) {
                scanf("%lld %lld %lld",&a,&b,&c);
                int bitA = __builtin_popcount( a );
                int bitB = __builtin_popcount( b );
                High = leftmost( c );
                //trace( bitA , bitB , High );
                memset( dp , -1 , sizeof(dp) );
                printf("%lld\n",solve( 0 , bitA , bitB , 0 ) );
        }
        return 0;
}













