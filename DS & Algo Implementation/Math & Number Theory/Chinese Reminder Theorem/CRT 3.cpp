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

/**
 Works for NON coprime modulii && corpime as well.
 LCM can exceed long long but will be handled.
 Smallest number mod lcm will be returned.
 */

LL Normalize( LL x , LL m ) { x = x % m; if( x < 0 ) x = x + m; return x; }

LL GCD( LL a , LL b ) { return ( b == 0 ) ? a : GCD( b , a % b ); }

LL LCM( LL a , LL b ) { return a / GCD( a , b ) * b; }

inline LL ExtGCD( LL a , LL b , LL &p , LL &q ) {
        if( b == 0 ) { p = 1 , q = 0; return a; }
        LL x1 , y1 , gcd = ExtGCD( b , a % b , x1 , y1 );
        p = y1;
        q = x1 - (a / b)*y1;
        return gcd;
}
pair <LL,LL> CRT( vector <LL> A , vector <LL> M  ) {
        if( A.size() != M.size() ) return {-1LL,-1LL};
        LL ans = A[0] , lcm = M[0] , p , q;
        for( int i = 0; i < A.size(); i++ ) {
                LL g = ExtGCD( lcm , M[i] , p , q );
                LL x1 = p;
                if( ( A[i] - ans )%g != 0 ) return {-1LL,-1LL};
                ans = Normalize( ans+x1*(A[i]-ans)/g%(M[i]/g)*lcm , lcm*M[i]/g );
                lcm = LCM( lcm , M[i] );
        }
        return {(ans < 0 ? ans + lcm : ans ),lcm};
}
int main( int argc , char const *argv[] ) {
        vector <LL> A;
        vector <LL> M;
        int n;
        cin >> n;
        for( int i = 1; i <= n; i++ ) {
                LL rem , mod;
                cin >> rem >> mod;
                A.push_back( rem );
                M.push_back( mod );
        }
        pair <LL,LL> P = CRT( A , M );
        cout << P.first << " " << P.second << endl;
        return 0;
}






