#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
const int inf = (int)1e9;
const LL INF = (LL)1e18;
const int N = 100005;
const LL MOD = 1000000007;
const double EPS = 1e-7;
const double PI = acos( -1.0 );

inline LL ExtGCD( LL a , LL b , LL &x , LL &y ) {
        if( b == 0 ) { x = 1 , y = 0; return a; }
        LL x1 , y1 , gcd = ExtGCD( b , a % b , x1 , y1 );
        x = y1;
        y = x1-(a / b)*y1;
        return gcd;
}
int main( int argc , char const *argv[] ) {
    LL a , b , c;
    cin >> a >> b >> c;
    LL x , y;
    LL g = ExtGCD( a , b , x , y );
    if( c%g != 0 ) return cout << -1 << endl,0;
    /// Ax+Bx+C = 0 , use -
    /// Ax+By = C , use +
    cout << (-x*(c/g)) << " " << (-y*(c/g)) << endl;
    return 0;
}

