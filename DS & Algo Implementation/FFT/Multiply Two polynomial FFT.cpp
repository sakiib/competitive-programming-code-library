#include <bits/stdc++.h>
using namespace std;

/**
 this solves spoj POLYMUL ( multiplication of two n degree polynomial )
  given only coefficients in this form.

  1 * x^2 + 2 * x + 3
  3 * x^2 + 2 * x + 1

  in : 2 ( degree ) so , take n+1 term including the const.
       1 2 3
       3 2 1
  out : 3 8 14 8 3

 if degree is not same pad with zeros. ( 2 * n - 1 )
 runtime : NlogN
 */

const long double PI = acos(-1.0);
typedef long double ld;
typedef long long LL;

struct Complex {
        long double real , img;
        Complex( ) { real = 0.0 , img = 0.0; }
        Complex( long double x ) { real = x , img = 0.0; }
        Complex( long double x , long double y ) { real = x , img = y; }

        const void operator += ( Complex &q ) {
                    real += q.real , img += q.img;
        }
        const void operator -= ( Complex &q ) {
                    real -= q.real , img -= q.img;
        }
        const Complex operator + ( Complex &q ) {
                    return Complex( real + q.real , img + q.img );
        }
        const Complex operator - ( Complex &q ) {
                    return Complex( real - q.real , img - q.img );
        }
        const Complex operator * ( Complex &q ) {
                    long double a = ( real * q.real ) - ( img * q.img );
                    long double  b = ( real * q.img ) + ( img * q.real );
                    return Complex( a , b );
        }
};

struct FAST_FOURIER_TRANSFORM {
        void FFT( vector <Complex> &V , int n , int invert ) {
                int i , j , l , len;
                for( i = 1 , j = 0; i < n; i++ ) {
                        for( l = n >> 1; j >= l; l >>= 1 ) { j -= l; }
                        j += l;  if( i < j ) swap( V[ i ] , V[ j ] );
                }
                for( len = 2; len <= n; len <<= 1 ) {
                        long double ang = 2 * PI / len * invert; Complex wlen( cos(ang) , sin(ang) );
                        for( i = 0; i < n; i += len ) { Complex w(1);
                             for( j = 0; j < len / 2; j++ ) {
                                Complex u = V[ i + j ];
                                Complex v = V[ i + j + len / 2 ] * w;
                                V[ i + j ] = ( u + v );
                                V[ i + j + len / 2 ] = ( u - v );
                                w = w * wlen;
                            }
                        }
                }
                if( invert == -1 ) for( i = 0; i < n; i++ ) V[i].real /= n;
        }
        vector <Complex> Multiply( const vector <Complex> &x , const vector <Complex> &y ) {
                int n = 1;
                while( n <= ( x.size() + y.size() ) ) n <<= 1;
                vector <Complex> A( n );
                vector <Complex> B( n );
                for( int i = 0; i < x.size(); i++ ) A[ i ] = x[ i ];
                for( int i = 0; i < y.size(); i++ ) B[ i ] = y[ i ];
                FFT( A , n , 1 );
                FFT( B , n , 1 );
                for( int i = 0; i < n; i++ ) A[ i ] = ( A[ i ] * B[ i ] );
                FFT( A , n , -1 );
                return A;
        }
} fft;


int main( int argc , char const *argv[] ) {
        int t;
        cin >> t;
        while( t-- ) {
                int n;
                cin >> n;
                n++;
                vector <Complex> V1 , V2;

                for( int i = 0; i < n; i++ ) {
                        LL val;
                        cin >> val;
                        //V1.push_back( Complex( val , 0.0 ) );
                        V1.push_back( val );
                }
                for( int i = 0; i < n; i++ ) {
                        LL val;
                        cin >> val;
                        //V2.push_back( Complex( val , 0.0 ) );
                        V2.push_back( val );
                }
                vector <Complex> V = fft.Multiply( V1 , V2 );
                for( int i = 0; i <= 2*n - 2; i++ ) {
                        if( i ) cout << " ";
                        cout << (LL)round( V[i].real );
                }
                cout << endl;
        }
        return 0;
}







