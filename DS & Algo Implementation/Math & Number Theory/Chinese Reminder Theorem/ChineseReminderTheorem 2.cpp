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

/// Non coprime modulii
/// LCM of All Mods must fit in long long otherwise WA

LL ExtGCD( LL a , LL b , LL &p , LL &q ) {
        if( b == 0 ) { p = 1 , q = 0; return a; }
        LL x1 , y1 , gcd = ExtGCD( b , a % b , x1 , y1 );
        p = y1;
        q = x1-(a / b)*y1;
        return gcd;
}
LL CRT( vector <LL> A , vector <LL> M ) {
        if( A.size() != M.size() ) return -1;
        int len = A.size();
        LL m = M[0] , r = A[0] , p , q , d;
        for( int i = 1; i < len; i++ ) {
                d = ExtGCD( m , M[i] , p , q );
                if( ( A[i] - r ) % d ) return -1;
                p = ( A[i] - r ) / d * p % ( M[i] / d );
                r += ( p * m );
                m = m / d * M[i];
                r %= m;
        }
        return ( r <= 0 ? r + m : r );
}
int main( int argc , char const *argv[] ) {
        vector <LL> A = { 11 , 2 , 36 , 20 , 76 };
        vector <LL> M = { 19 , 54 , 40 , 24 , 80};
        cout << CRT( A , M ) << endl;
        return 0;
}






