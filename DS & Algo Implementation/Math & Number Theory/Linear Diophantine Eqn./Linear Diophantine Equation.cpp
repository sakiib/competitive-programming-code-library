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
Linear Diophantine Eqn solution.

Handle the case when a & b are negative & zero

Will Overflows when numbers are as big as 1e18

*/

inline LL ExtGCD( LL a , LL b , LL &x , LL &y ) {
        if( b == 0 ) { x = 1 , y = 0; return a; }
        LL x1 , y1 , gcd = ExtGCD( b , a % b , x1 , y1 );
        x = y1;
        y = x1 - ( a / b )*y1;
        return gcd;
}
inline bool Any_Solution( LL a , LL b , LL c , LL &x0 , LL &y0 , LL &g ) {
        g = ExtGCD( abs(a) , abs(b) , x0 , y0 );
        if( c%g != 0 ) return false;
        x0 = x0 * c / g , y0 = y0 * c / g;
        if( a < 0 ) x0 = - x0;
        if( b < 0 ) y0 = - y0;
        return true;
}
inline void Shift_Solution ( LL &x , LL &y , LL a , LL b , LL cnt ) {
        x += cnt * b;
        y -= cnt * a;
}
inline LL All_Solutions( LL a , LL b , LL c , LL minx , LL maxx , LL miny , LL maxy ) {
        LL x , y , g;
        if ( ! Any_Solution ( a , b , c , x , y , g ) ) return 0;
        a /= g;  b /= g;
        LL sign_a = a > 0 ? +1 : -1 , sign_b = b > 0 ? +1 : -1;
        Shift_Solution ( x , y , a , b , ( minx - x ) / b );
        if ( x < minx ) Shift_Solution ( x , y , a , b , sign_b );
        if ( x > maxx ) return 0;
        LL lx1 = x;
        Shift_Solution ( x , y , a , b , ( maxx - x ) / b );
        if ( x > maxx ) Shift_Solution ( x , y , a , b , -sign_b );
        LL rx1 = x;
        Shift_Solution ( x , y , a , b , - ( miny - y ) / a );
        if ( y < miny ) Shift_Solution ( x , y , a , b , -sign_a );
        if ( y > maxy ) return 0;
        LL lx2 = x;
        Shift_Solution ( x , y , a , b , - ( maxy - y ) / a );
        if ( y > maxy ) Shift_Solution ( x , y , a , b , sign_a );
        LL rx2 = x;
        if ( lx2 > rx2 ) swap ( lx2 , rx2 );
        LL lx = max ( lx1 , lx2 ) , rx = min ( rx1, rx2 );
        if ( lx > rx ) return 0;
        return ( rx - lx ) / abs(b) + 1;
}
inline LL All_Solutions_in_Range( LL a , LL b , LL c , LL x1 , LL x2 , LL y1 , LL y2 ) {
        if( a == 0 && b == 0 ) {
                    if( c == 0 ) {
                            LL ans = ( x2-x1+1 )*( y2-y1+1 );
                            return ans;
                    }
                    else return 0;
        }
        if( a == 0 ) {
                    if( c%b == 0 && c/b >= y1 && c/b <= y2 ) {
                            LL ans = ( x2-x1+1 );
                            return ans;
                    }
                    else return 0;
        }
        if( b == 0 ){
                    if( c%a == 0 && c/a >= x1 && c/a <= x2 ) {
                            LL ans = ( y2-y1+1 );
                            return ans;
                    }
                    else return 0;
        }
        LL ans = All_Solutions( a , b , c , x1 , x2 , y1 , y2 );
        return ans;
}
int main( int argc , char const *argv[] ) {
        LL a , b , c , x1 , x2 , y1 , y2;
        cin >> a >> b >> c >> x1 >> x2 >> y1 >> y2;;
        LL cnt = All_Solutions_in_Range( a , b , c , x1 , x2 , y1 , y2 );
        cout << "Total Solution in range :  " << cnt << endl;
        if( cnt > 0 ) cout << "Yes" << endl;
        else cout << "No" << endl;
        return 0;
}






