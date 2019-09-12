#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef pair <int,int> pii;
typedef pair <long long,long long> pll;
const int MOD = 1e9 + 7;
const double EPS = 1e-8;
const int N = 1e5 + 5;
const int inf = 1e9;
const long long INF = 1e18;

struct linear_recurrence_berlekamp_massey {
        typedef long long LL;
        static const int SZ = 2e5 + 5;
        static const int MOD = 1e9 + 7; /// mod must be a prime
        LL m , a[SZ] , h[SZ] , t_[SZ] , s[SZ] , t[SZ];

        inline LL bigmod( LL b , LL p , LL mod ) {
            LL res = 1%mod , x = b%mod;
            while( p ) {
                if ( p&1 ) res = (res * x)%mod; x = (x * x)%mod; p >>= 1;
            }
            return (res%mod);
        }
        inline vector <LL> BM( vector <LL> &x ) {
            LL lf , ld;
            vector <LL> ls , cur;
            for( int i = 0; i < int(x.size()); ++i ) {
                LL t = 0;
                for( int j = 0; j < int(cur.size()); ++j ) t=(t + x[i-j-1] * cur[j])%MOD;
                if( (t - x[i])%MOD == 0 ) continue;
                if( !cur.size() ) {
                    cur.resize( i + 1 );
                    lf = i; ld = (t - x[i])%MOD;
                    continue;
                }
                LL k = -(x[i] - t) * bigmod( ld , MOD - 2 , MOD )%MOD;
                vector <LL> c(i - lf - 1);
                c.push_back( k );
                for( int j = 0; j < int(ls.size()); ++j ) c.push_back(-ls[j] * k%MOD);
                if( c.size() < cur.size() ) c.resize( cur.size() );
                for( int j = 0; j < int(cur.size()); ++j ) c[j] = (c[j] + cur[j])%MOD;
                if(i - lf + (int)ls.size() >= (int)cur.size() ) ls = cur, lf = i, ld = (t-x[i])%MOD;
                cur = c;
            }
            for( int i = 0; i < int(cur.size()); ++i ) cur[i] = (cur[i]%MOD + MOD)%MOD;
            return cur;
        }
        inline void mull( LL *p , LL *q ) {
            for( int i = 0;i < m + m; ++i ) t_[i] = 0;
            for( int i = 0; i < m; ++i ) if( p[i] )
                    for( int j = 0; j < m; ++j ) t_[i+j] = (t_[i+j] + p[i] * q[j])%MOD;
            for( int i = m + m - 1; i >= m; --i ) if( t_[i] )
                    for( int j = m - 1; ~j; --j ) t_[i-j-1] = (t_[i-j-1] + t_[i] * h[j])%MOD;
            for( int i = 0; i < m; ++i ) p[i] = t_[i];
        }
        inline LL calc( LL K ){
            for( int i = m; ~i; --i ) s[i] = t[i] = 0;
            s[0] = 1; if( m != 1 ) t[1] = 1; else t[0] = h[0];
            while( K ) {
                if( K&1 ) mull( s , t );
                mull( t , t ); K >>= 1;
            }
            LL su = 0;
            for( int i = 0; i < m; ++i ) su = (su + s[i] * a[i])%MOD;
            return (su%MOD + MOD)%MOD;
        }
        inline LL work( vector <LL> &x , LL n ) {
            if( n < int(x.size()) ) return x[n];
            vector <LL> v = BM( x ); m = v.size(); if( !m ) return 0;
            for( int i = 0; i < m; ++i ) h[i] = v[i], a[i] = x[i];
            return calc( n );
        }
} rec;

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
        //freopen( "input.txt" , "r" , stdin );
        m = mat.Initialize( );
        m.M[1][1] = m.M[1][2] = m.M[2][1] = 1;
        int t;
        scanf("%d",&t);
        while( t-- ) {
                LL l , r;
                scanf("%lld %lld",&l,&r);
                vector <LL> V;
                LL prev = 0;
                for( LL i = l; i <= min( l + 10 , r ); i++ ) {
                        if( i == 0 ) {
                                prev += 0;
                        }
                        else if( i == 1 ) {
                                prev += 1;
                        }
                        else if( i == 2 ) {
                                prev += 1;
                        }
                        else {
                                Matrix res = mat.MatrixExpo( m , i - 1 , 2 );
                                LL ans = res.M[1][1] % MOD;
                                prev += ans;
                                prev %= MOD;
                        }
                        V.push_back( prev );
                }
                int tot = r - l + 1;
                printf("%lld\n",rec.work( V , 1LL*tot - 1 ));
        }
        return 0;
}









