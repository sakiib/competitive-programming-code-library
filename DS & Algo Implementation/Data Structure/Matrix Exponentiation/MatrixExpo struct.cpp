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


/**
 Define the original matrix as necessary
 & fix the matrix domension & the loop
 */
struct Matrix { LL M[ 10 ][ 10 ]; };

Matrix original;

struct MatrixExponentiation {

    inline Matrix Init( ) {
        Matrix ret;
        for( int i = 0; i < 20; i++ ) { for( int j = 0; j < 20; j++ ) {
        ret.M[i][j] = 0; } } return ret;
    }
    inline Matrix Identity( ) {
        Matrix ret;
        for( int i = 1; i <= 2; i++ ) { for( int j = 1; j <= 2; j++ ) {
        if( i == j ) ret.M[i][j] = 1; else ret.M[i][j] = 0; } } return ret;
    }
    inline void Print( Matrix A , int r , int c ) {
        cout <<"........Printing Matrix.............\n"<<endl;
        for( int i = 1; i <= r; i++ ) { for( int j = 1; j <= c; j++ ) {
        printf("%lld  ",A.M[i][j]); } printf("\n\n"); }
        cout <<"........Done Printing Matrix........"<<endl;
    }
    inline Matrix MatAdd( Matrix A , Matrix B ) {
        Matrix ret;
        for( int i = 1; i <= 2; i++ ) { for( int j = 1; j <= 2; j++ ) {
        ret.M[i][j] = A.M[i][j] + B.M[i][j]; }  } return ret;
    }
    inline Matrix MatSub( Matrix A , Matrix B ) {
        Matrix ret;
        for( int i = 1; i <= 2; i++ ) { for( int j = 1; j <= 2; j++ ) {
        ret.M[i][j] = A.M[i][j] - B.M[i][j]; }  } return ret;
    }

    inline Matrix MatMul( Matrix A , Matrix B , int r ) {
        Matrix temp = Init( );
        for( int i = 1; i <= r; i++ ) {
            for( int j = 1; j <= r; j++ ) {
                for( int k = 1; k <= r; k++ ) {
                    temp.M[i][j] = ( temp.M[i][j]%MOD+( A.M[i][k]%MOD*B.M[k][j]%MOD )%MOD )%MOD;
                }
            }
        } return temp;
    }
    inline Matrix MatExpo( Matrix A , LL P , int r ) {
        Matrix ret;
        if( P == 1 ) return A;
        ret = MatExpo( A , P/2 , r );
        if( P&1 ) return MatMul( MatMul( ret , ret , r ) , original , r ); return MatMul( ret , ret , r );
    }
};

MatrixExponentiation mat;


int main( int argc , char const *argv[] ) {

    original = mat.Init( );


    return 0;
}


