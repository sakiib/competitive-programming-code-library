#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define All(V) V.begin(),V.end()
#define Unique(V) sort( All(V)),V.erase( unique( All(V) ),V.end() )
#define Fast_IO ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long int LL;
const int N = 1e5 + 5;
const int inf = 1e9;
const LL INF = 1e18;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int MOD = 1000000007;

/**
 suppose we need to know num%all digits.
 then we can use LCM( 2 to 9 ) = 2520 as mod val , after that rem%dig
 determines the remainder of dig mod val.
 mask for presence of digits , it's 0 based marking to save memory.
 */

int  Set( int N , int pos )    { return N |= ( 1 << pos ); }
int  Reset( int N , int pos )  { return N = N & ~( 1 << pos ); }
bool Check( int N , int pos )  { return (bool)( N & ( 1 << pos ) );}
int  Toggle( int N , int pos ) { return ( N ^= ( 1 << pos ) ); }

LL a[ 10 ];
inline LL GCD( LL x , LL y ) { return __gcd( x , y ); }
inline LL LCM( LL x , LL y ) { return x / GCD( x , y ) * y;}

int k;
int len;
vector <int> dig;
LL dp[17+2][1+1][2520+5][(1<<9)+5];

LL DP( int idx , int smaller , int rem , int mask ) {
        if( idx >= len ) {
                int cnt = 0;
                for( int d = 1; d <= 9; d++ ) {
                        if( Check( mask , d-1 ) && rem%d == 0 ) cnt++;
                }
                return ( cnt >= k ? 1 : 0 );
        }
        if( dp[idx][smaller][rem][mask] != -1 ) return dp[idx][smaller][rem][mask];
        LL ret = 0;
        if( smaller ) {
                for( int i = 0; i <= 9; i++ ) {
                        int curmask = mask;
                        if( i != 0 ) curmask = Set( mask , i-1 );
                        ret += DP( idx + 1 , 1 , (rem*10+i)%2520 , curmask );
                }
        }
        else {
                for( int i = 0; i < dig[idx]; i++ ) {
                        int curmask = mask;
                        if( i != 0 ) curmask = Set( mask , i-1 );
                        ret += DP( idx + 1 , 1 , (rem*10+i)%2520 , curmask );
                }
                int curmask = mask;
                if( dig[idx] != 0 ) curmask = Set( mask , dig[idx]-1 );
                ret += DP( idx + 1 , 0 , (rem*10+dig[idx])%2520 , curmask );
        }
        return dp[idx][smaller][rem][mask] = ret;
}
LL solve( LL x ) {
        dig.clear();
        while( x ) dig.push_back( x%10 ) , x /= 10;
        reverse( dig.begin() , dig.end() );
        len = dig.size();
        memset( dp , -1 , sizeof(dp) );
        return DP( 0 , 0 , 0 , 0 );
}
int main( int argc , char const *argv[] ) {
        Fast_IO;
        int t;
        cin >> t;
        while( t-- ) {
                LL l , r;
                cin >> l >> r >> k;
                cout << solve( r ) - solve( l - 1 ) << endl;
        }
        return 0;
}






