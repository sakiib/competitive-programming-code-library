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
 Use this when BigMod can overflow in intermideate calculation.
 */

inline LL MulMod( LL a , LL b , LL c ) {
            LL x = 0 , y = a%c;
            while( b > 0 ) {
                    if( b&1 ) x = ( x + y ) % c; y = ( y << 1 ) % c;
                    b = b >> 1;
            }
            return x;
}
inline LL Modulo( LL a , LL b , LL c ) {
            LL x = 1 , y = a % c;
            while( b > 0 ) {
                    if( b&1 ) x = MulMod( x , y , c ); y = MulMod( y , y , c );
                    b = b >> 1;
            }
            return x;
}
int main( int argc , char const *argv[] ) {
        Fast_IO;
        int t;
        cin >> t;
        while( t-- ) {
                LL n;
                cin >> n;
                LL ans = Modulo( n , 2 , MOD );
                cout << ans << endl;
        }
        return 0;
}





