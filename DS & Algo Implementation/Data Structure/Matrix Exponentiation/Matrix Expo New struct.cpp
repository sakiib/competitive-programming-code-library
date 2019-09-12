#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;

/**
 Define the original matrix ( m ) as necessary.
 & fix the matrix domension & the loop carefully.

 Fibonacci :
 F (n)    = | 1 1 | ^ ( n-1 ) | F1 |
 F (n-1)  = | 1 0 |           | F0 |
 */

struct Matrix { LL M[ 30 ][ 30 ]; };

Matrix m; /// this one will be exponentiated.

struct MATRIX_EXPONENTIATION {

        static const int INF = 2e9 + 5;
        static const int MOD = 1e9 + 7;

        inline Matrix Initialize( ) {
                Matrix ret;
                for( int i = 1; i <= 20; i++ ) for( int j = 1; j <= 20; j++ )
                ret.M[ i ][ j ] = 0;  return ret;
        }
        inline Matrix Identity( int r , int c ) {
                Matrix ret;
                for( int i = 1; i <= r; i++ ) for( int j = 1; j <= c; j++ )
                ( i == j ? ret.M[ i ][ j ] = 1  :  0  );  return ret;
        }
        inline void Print( Matrix A , int r , int c ) {
                printf("...........Printing Matrix................\n\n");
                for( int i = 1; i <= r; i++ ) {
                        for( int j = 1; j <= c; j++ ) {
                                printf("( %d , %d ) : %lld   ",i,j,A.M[ i ][ j ]);
                        }
                        printf("\n\n");
                }
                printf("...........Done Printing Matrix...........\n\n");
        }
        inline Matrix MatrixAdd( Matrix A , Matrix B , int r , int c ) {
                Matrix ret;
                for( int i = 1; i <= r; i++ ) {
                        for( int j = 1; j <= c; j++ ) {
                                ret.M[ i ][ j ] = ( A.M[ i ][ j ] + B.M[ i ][ j ] );
                        }
                }
                return ret;
        }
        inline Matrix MatrixSub( Matrix A , Matrix B , int r , int c ) {
                Matrix ret;
                for( int i = 1; i <= r; i++ ) {
                        for( int j = 1; j <= c; j++ ) {
                                ret.M[ i ][ j ] = ( A.M[ i ][ j ] - B.M[ i ][ j ] );
                        }
                }
                return ret;
        }
        inline Matrix MatrixMul( Matrix A , Matrix B , int r ) {
                Matrix t = Initialize( );
                for( int i = 1; i <= r; i++ ) {
                        for( int j = 1; j <= r; j++ ) {
                                for( int k = 1; k <= r; k++ ) {
                                        LL c = ( A.M[ i ][ k ] % MOD * B.M[ k ][ j ] % MOD ) % MOD;
                                        t.M[ i ][ j ] = ( t.M[ i ][ j ] % MOD + c % MOD ) % MOD;
                                }
                        }
                }
                return t;
        }
        inline Matrix MatrixExpo( Matrix A , LL P , int r ) {
                Matrix ret;
                if( P == 1 ) return A;
                ret = MatrixExpo( A , P/2 , r );
                if( ( P&1 ) ) return MatrixMul( MatrixMul( ret , ret , r ) , m , r );
                return MatrixMul( ret , ret , r );
        }
} mat;

int main( int argc , char const *argv[] ) {

        m = mat.Initialize( );

        return 0;
}










