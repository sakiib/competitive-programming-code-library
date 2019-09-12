#include <bits/stdc++.h>
using namespace std;

/**
 CRT_1 -> For COPRIME modulii , lcm must fit in long long.
          returns the smallest ans modulo
 CRT_2 -> For Not COMPRIME modulii , lcm must fil in long long
          returns the smallest ans modulo
 CRT_3 -> For Not COMPRIME modulii , lcm can be beyond LONG LONG
          returns the smallest ans modulo
 if ans needs to be POSITIVE then change condition to ( ans <= 0 )?
 In case solution doesn't exist return (-1,-1)
 There are Infinitely many solutions.
 We are getting only the smallest one here.

*/

struct CHINESE_REMAINDER_THEOREM {
        typedef long long LL;
        typedef pair <LL,LL> pll;

        inline LL GCD( LL a , LL b ) { return ( b == 0 ) ? a : GCD( b , a % b ); }
        inline LL LCM( LL a , LL b ) { return a / GCD( a , b ) * b; }
        inline LL Normalize( LL x , LL m ) { x = x%m; return ( x < 0 ? x+m : x ); }

        inline LL ExtGCD( LL a , LL b , LL &p , LL &q ) {
                if( b == 0 ) { p = 1 , q = 0; return a; }
                LL x1 , y1 , gcd = ExtGCD( b , a % b , x1 , y1 );
                p = y1 , q = x1 - ( a / b ) * y1;
                return gcd;
        }
        inline pair <LL,LL> CRT_1( vector <LL> A , vector <LL> M ) {
                if( A.size() != M.size() ) return {-1LL,-1LL};
                LL mul = 1 , ret = 0 , p , q; int l = A.size();
                for( int i = 0; i < l; i++ ) mul *= M[i];
                for( int i = 0; i < l; i++ ) {
                        ExtGCD( M[i] , mul / M[i] , p , q );
                        ret += ( A[i] * q * ( mul / M[i] ) ) , ret %= mul;
                }
                return { (ret < 0 ? ret + mul : ret ) , mul };
        }
        inline pair <LL,LL> CRT_2( vector <LL> A , vector <LL> M ) {
                if( A.size() != M.size() ) return {-1LL,-1LL};
                int len = A.size(); LL m = M[0] , r = A[0] , p , q , d;
                for( int i = 1; i < len; i++ ) {
                        d = ExtGCD( m , M[i] , p , q );
                        if( ( A[i] - r ) % d ) return {-1LL,-1LL};
                        p = ( A[i] - r ) / d * p % ( M[i] / d );
                        r += ( p * m ); m = m / d * M[i]; r %= m;
                }
                return { ( r < 0 ? r + m : r ) , m };
        }
        inline pair <LL,LL> CRT_3( vector <LL> A , vector <LL> M  ) {
                if( A.size() != M.size() ) return {-1LL,-1LL};
                LL ans = A[0] , lcm = M[0] , p , q;
                for( int i = 0; i < A.size(); i++ ) {
                        LL g = ExtGCD( lcm , M[i] , p , q ); LL x1 = p;
                        if( ( A[i] - ans )%g != 0 ) return {-1LL,-1LL};
                        ans = Normalize( ans+x1*( A[i]-ans )/g%( M[i]/g )*lcm , lcm*M[i]/g );
                        lcm = LCM( lcm , M[i] );
                }
                return { (ans < 0 ? ans + lcm : ans ) , lcm };
        }
} crt;

int main( int argc , char const *argv[] ) {

        return 0;
}






