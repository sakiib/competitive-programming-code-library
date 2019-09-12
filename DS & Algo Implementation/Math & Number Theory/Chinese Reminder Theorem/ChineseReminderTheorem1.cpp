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

/// coprime modulii

LL ExtGCD( LL a , LL b , LL &p , LL &q ) {
        if( b == 0 ) { p = 1 , q = 0; return a; }
        LL x1 , y1 , gcd = ExtGCD( b , a % b , x1 , y1 );
        p = y1;
        q = x1-(a / b)*y1;
        return gcd;
}
LL CRT( vector <LL> A , vector <LL> M ) { // If this overflows use the code below.
       if( A.size() != M.size() ) return -1;
       LL a1 = A[0] , m1 = M[0];
       int l = A.size();
       for( int i = 1; i < l; i++ ) {
                LL a2 = A[i] , m2 = M[i];
                LL p , q;
                ExtGCD( m1 , m2 , p , q );
                LL x = ( a1*m2*q + a2*m1*p ) % ( m1*m2 );
                a1 = x , m1 = m1*m2;
       }
       if( a1 < 0 ) a1 += m1;
       return a1;
}
LL crt( vector <LL> A , vector <LL> M ) {
        if( A.size() != M.size() ) return -1;
        LL mul = 1 , ret = 0;
        int l = A.size();
        for( int i = 0; i < l; i++ ) mul *= M[i];
        for( int i = 0; i < l; i++ ) {
                LL p , q;
                ExtGCD( M[i] , mul/M[i] , p , q );
                ret += ( A[i] * q * ( mul/M[i] ) );
                ret %= mul;
        }
        if( ret < 0 ) ret += mul;
        return ret;
}
int main( int argc , char const *argv[] ) {
        ios_base :: sync_with_stdio(false); cin.tie(NULL);
        vector <LL> A = { 3 , 2 , 2 };
        vector <LL> M = { 5 , 7 , 8 };
        cout << CRT( A , M ) <<" " << crt( A  , M ) << endl;
        return 0;
}






