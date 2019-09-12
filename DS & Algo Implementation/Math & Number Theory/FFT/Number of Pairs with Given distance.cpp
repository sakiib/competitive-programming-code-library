#include <bits/stdc++.h>
using namespace std;

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

/**

we are required to find all pairs of ones such that the distance between them is d
and we have to perform this for every d from 0 to n-1. We have to represent our problem in
some polynomial form. The distance between two ones is defined as abs(i-j) where i and j are the
respective indices of the ones

 two polynomials :

 A(x) = a1 x^1 + a2 x^2 + a3 x^3 + a4 x^4
 B(x) = b1 x^-1 + b2 x^-2 + b3 x^-3 + b4 x^-4

 Example:
 7
 1011011

 A(x) = 1 x^1 + 0 x^2 + 1 x^3 + 1 x^4 + 0 x^5 + 1 x^6 + 1 x^7
 B(x) = 1 x^-1 + 0 x^-2 + 1 x^-3 + 1 x^-4 + 0 x^-5 + 1 x^-6 + 1 x^-7

 by multiplying them we get the polynomial C(x) , whose power is defines by d
 & corresponding coefficients are the number of pairs with that distance
*/

int main( int argc , char const *argv[] ) {
        int len;
        string s;
        cin >> len >> s;
        vector <Complex> a , b;
        for( int i = 0; i < len; i++ ) a.push_back( s[i] - '0' );
        for( int i = len - 1; i >= 0; i-- ) b.push_back( s[i] - '0' );
        vector <Complex> res = fft.Multiply( a , b );
        for( int i = len - 1; i >= 0; i-- ) cout << abs((round)(res[i].real)) << " ";
        return 0;
}








