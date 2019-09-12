#include <bits/stdc++.h>
using namespace std;

#define trace(...) __f( #__VA_ARGS__ , __VA_ARGS__ )
template <typename Arg1>
void __f( const char* name , Arg1&& arg1 ) {
        cerr << name << " : " << arg1 << "\n";
}
template <typename Arg1, typename... Args>
void __f( const char* na , Arg1&& arg1 , Args&&... args ) {
        const char* c = strchr( na + 1 , ',' );
        cerr.write( na , c - na ) << " : " << arg1 << " , ";
        __f( c + 1 , args... );
}
typedef long long int LL;
typedef pair <int,int> pii;
int MOD;
const int inf = 1e9;
const double EPS = 1e-9;
const double PI = acos(-1.0);
const long long INF = 1e18;
const int N = 1e5 + 5;

struct Matrix { LL M[ 30 ][ 30 ]; };

Matrix m; /// this one will be exponentiated.

struct MATRIX_EXPONENTIATION {

        int MOD;

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

int main( ) {
        #ifdef LOCAL
            freopen( "input.txt" , "r" , stdin );
        #endif // LOCAL
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
                int a1 , b1 , c1;
                scanf("%d %d %d",&a1,&b1,&c1);
                int a2 , b2 , c2;
                scanf("%d %d %d",&a2,&b2,&c2);
                int f0 , f1 , f2;
                scanf("%d %d %d",&f0,&f1,&f2);
                int g0 , g1 , g2;
                scanf("%d %d %d",&g0,&g1,&g2);
                scanf("%d",&MOD);
                mat.MOD = MOD;
                int q;
                scanf("%d",&q);
                m = mat.Initialize( );
                m.M[1][1] = a1 , m.M[1][2] = b1 , m.M[1][6] = c1;
                m.M[2][1] = 1;
                m.M[3][2] = 1;
                m.M[4][3] = c2 , m.M[4][4] = a2 , m.M[4][5] = b2;
                m.M[5][4] = 1;
                m.M[6][5] = 1;
                printf("Case %d:\n",tc);
                while( q-- ) {
                        LL n;
                        scanf("%lld",&n);
                        if( n == 0 ) {
                                printf("%d %d\n",f0%MOD,g0%MOD);
                        }
                        else if( n == 1 ) {
                                printf("%d %d\n",f1%MOD,g1%MOD);
                        }
                        else if( n == 2 ) {
                                printf("%d %d\n",f2%MOD,g2%MOD);
                        }
                        else {
                                Matrix res = mat.MatrixExpo( m , n - 2 , 6 );
                                //mat.Print( res , 6 , 6 );
                                LL x = 1 , y = 1;
                                x = (res.M[1][1]%MOD * f2%MOD + res.M[1][2]%MOD * f1%MOD +
                                     res.M[1][3]%MOD * f0%MOD + res.M[1][4]%MOD * g2%MOD +
                                     res.M[1][5]%MOD * g1%MOD +  res.M[1][6]%MOD * g0%MOD)%MOD;
                                y = (res.M[4][1]%MOD * f2%MOD + res.M[4][2]%MOD * f1%MOD +
                                     res.M[4][3]%MOD * f0%MOD + res.M[4][4]%MOD * g2%MOD +
                                      res.M[4][5]%MOD * g1%MOD + res.M[4][6]%MOD * g0%MOD )%MOD;
                                printf("%lld %lld\n",x,y);
                        }
                }
        }
        return 0;
}









