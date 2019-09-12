#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;

/**
 Fibonacci :
 F (n)    = | 1 1 | ^ ( n-1 ) | F1 |
 F (n-1)  = | 1 0 |           | F0 |
 */

int MOD;
struct Matrix { LL M[ 30 ][ 30 ]; };

Matrix m;

struct MatrixExponentiation {
    //static const int MOD = 1e9 + 7;

    inline Matrix Init( ) {
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
    inline Matrix MatAdd( Matrix A , Matrix B , int r , int c ) {
            Matrix ret;
            for( int i = 1; i <= r; i++ ) {
                    for( int j = 1; j <= c; j++ ) {
                            ret.M[ i ][ j ] = ( A.M[ i ][ j ] + B.M[ i ][ j ] );
                    }
            }
            return ret;
    }
    inline Matrix MatSub( Matrix A , Matrix B , int r , int c ) {
            Matrix ret;
            for( int i = 1; i <= r; i++ ) {
                    for( int j = 1; j <= c; j++ ) {
                            ret.M[ i ][ j ] = ( A.M[ i ][ j ] - B.M[ i ][ j ] );
                    }
            }
            return ret;
    }
    inline Matrix MatMul( Matrix A , Matrix B , int r ) {
            Matrix t = Init( );
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
    inline Matrix MatExpo( Matrix A , LL P , int r ) {
            Matrix ret;
            if( P == 1 ) return A;
            ret = MatExpo( A , P/2 , r );
            if( (P&1) ) return MatMul( MatMul( ret , ret , r ) , m , r );
            return MatMul( ret , ret , r );
    }

} mat;

int main( int argc , char const *argv[] ) {

        m = mat.Init( );
        m.M[1][1] = m.M[1][2] = m.M[2][1] = 1;
        //mat.Print( m , 2 , 2 );

        LL n , mod;
        while( scanf("%lld %lld",&n,&mod) != EOF ) {
                if( n == 0 ) {
                        printf("0\n");
                        continue;
                }
                if( n == 1 ) {
                        printf("1\n");
                        continue;
                }
                MOD = ( 1LL << mod );
                Matrix res = mat.MatExpo( m , n-1 , 2 );
                //mat.Print( res , 2 , 2 );
                LL ans = res.M[1][1] % MOD;
                printf("%lld\n",ans);
        }
        return 0;
}
















