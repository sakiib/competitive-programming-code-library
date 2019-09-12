#include <bits/stdc++.h>
using namespace std;

/**
Jury picked a polynomial f(x)=a0+a1⋅x+a2⋅x2+⋯+ak⋅xk. k≤10 and all ai are integer numbers
and 0≤ai<106+3. It's guaranteed that there is at least one i such that ai>0.

Now jury wants you to find such an integer x0 that f(x0)≡0mod(106+3) or report that there is not such x0.

You can ask no more than 50 queries: you ask value xq and jury tells you value f(xq)mod(106+3).

Note that printing the answer doesn't count as a query.
*/

typedef long long int LL;
const int MOD = 1e6 + 3;

const int MXROW = 1010;
const int MXCOL = 1010;

LL a[ MXROW ][ MXCOL ];

inline LL bigmod( LL b , LL p , LL MOD ) {
        LL res = 1%MOD , x = b%MOD;
        while ( p ) {
                if ( p & 1 ) res = ( res * x )%MOD;
                x = ( x * x )%MOD; p >>= 1;
        }
        return res%MOD;
}
inline int gaussian( int n , int m , int MOD , vector <LL> &res ) {
        res.assign( m , 0 );
        vector <LL> pos( m , -1 );
        int i , j , k , l , p , free_var = 0; LL d;
        const long long MODSQ = 1LL * MOD * MOD;
        for( j = 0 , i = 0; j < m && i < n; j++ ) {
            for( k = i , p = i; k < n; k++ ) {
                    if( a[k][k] > a[p][j] ) p = k;
            }
            if( a[p][j] ) {
            pos[j] = i;
            for( l = j; l <= m; l++ ) swap( a[p][l] , a[i][l] );
            d = bigmod( a[i][j] , MOD - 2 , MOD );
            for( k = 0; k < n && d; k++ ) {
                if( k != i && a[k][j] ) {
                        LL x = ( a[k][j]%MOD * d%MOD )%MOD;
                        for( l = j; l <= m && x; l++ ) {
                                if( a[i][l] )
                                a[k][l] = ( MODSQ + a[k][l] - ( a[i][l] * x )%MOD )%MOD;
                        }
                    }
                } i++;
            }
        }
        for( i = 0; i < m; i++ ) {
                if( pos[i] == -1 ) free_var++;
                else res[i] = ( a[pos[i]][m] * bigmod(a[pos[i]][i] , MOD - 2 , MOD) )%MOD;
        }
        for( i = 0; i < n; i++ ) {
                LL val = 0;
                for( j = 0; j < m; j++ ) val = ( val + ( res[j] * a[i][j] )%MOD )%MOD;
                if( val != a[i][m] ) return -1;
        }
        return free_var;
}
int main( int argc , char const *argv[] ) {
        int n = 50 , m = 11;
        for( int i = 0; i < 50; i++ ) {
                LL mul = 1; /// be careful :: mul is any value besides 0 ( zero )
                for( int j = 0; j < 11; j++ ) {
                        a[i][j] = mul;
                        mul = ( mul%MOD * i%MOD )%MOD;
                }
                cout << "? " << i << endl;
                LL fx;
                cin >> fx;
                a[i][m] = fx;
        }
        vector <LL> res;
        int free_var = gaussian( n , m , MOD , res );
        assert( free_var == 0 );
        for( int i = 0; i < MOD; i++ ) {
                LL fx = 0 , mul = 1;
                for( int j = 0; j < m; j++ ) {
                        fx += ( 1LL * mul * res[j] )%MOD , fx %= MOD;
                        mul = ( 1LL * mul * i )%MOD;
                }
                if( fx == 0 ) {
                        cout << "! " << i << endl;
                        return 0;
                }
        }
        cout << "! -1" << endl;
        return 0;
}









