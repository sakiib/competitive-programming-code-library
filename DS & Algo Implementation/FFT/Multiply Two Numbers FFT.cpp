#include <bits/stdc++.h>
using namespace std;

/**
 this solves spoj MUL ( multiplication of two BIG numbers ( string ) )

 if length is not same pad with zeros.
 runtime : NlogN

 Ex:
 123 * 43 = 5289

 reverse them : 3 2 1 & 3 4 0 ( padd 0 to make equal size )
 make sure to remove leading zeros
 */

const long double PI = acos(-1.0);
typedef long double ld;
typedef long long LL;

struct Complex {
        ld real , img;
        Complex( ) { real = 0.0 , img = 0.0; }
        Complex( ld x ) { real = x , img = 0.0; }
        Complex( ld x , ld y ) { real = x , img = y; }

        inline const void operator += ( Complex &q ) {
                real += q.real , img += q.img;
        }
        inline const void operator -= ( Complex &q ) {
                real -= q.real , img -= q.img;
        }
        inline const Complex operator + ( Complex &q ) {
                return Complex( real + q.real , img + q.img );
        }
        inline const Complex operator - ( Complex &q ) {
                return Complex( real - q.real , img - q.img );
        }
        inline const Complex operator * ( Complex &q ) {
                ld a = ( real * q.real ) - ( img * q.img );
                ld b = ( real * q.img ) + ( img * q.real );
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
                        ld ang = 2 * PI / len * invert; Complex wlen( cos(ang) , sin(ang) );
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
        vector <int> Multiply( const vector <Complex> &x , const vector <Complex> &y ) {
                int n = 1;
                while( n <= ( x.size() + y.size() ) ) n = n * 2;
                vector <Complex> A( n );
                vector <Complex> B( n );
                for( int i = 0; i < x.size(); i++ ) A[ i ] = x[ i ];
                for( int i = 0; i < y.size(); i++ ) B[ i ] = y[ i ];
                FFT( A , n , 1 );
                FFT( B , n , 1 );
                for( int i = 0; i < n; i++ ) A[ i ] = ( A[ i ] * B[ i ] );
                FFT( A , n , -1 );
                /// This part is for getting the digits.
                vector <int> ret( n );
                for( int i = 0; i < n; i++ ) ret[i] = (int)round(A[i].real); /// or add .05
                int cr = 0;
                for( int i = 0; i < ret.size(); i++ ) {
                        ret[i] += cr;
                        cr = ret[i] / 10;
                        ret[i] = ret[i] % 10;
                }
                ret.push_back( cr );
                while( ret.size() > 1 && ret.back( ) == 0 ) ret.pop_back(); /// leading zero bad
                return ret;
        }
} fft;

int main( int argc , char const *argv[] ) {
        int t;
        cin >> t;
        while( t-- ) {
                string a , b;
                cin >> a >> b;

                vector <Complex> V1 , V2;

                for( int i = a.size()-1; i >= 0; i-- ) {
                        V1.push_back( Complex( a[i]-'0' , 0.0 ) );
                }
                for( int i = b.size()-1; i >= 0; i-- ) {
                        V2.push_back( Complex( b[i]-'0' , 0.0 ) );
                }

                /// if length is not equal then pad with zeros.
                while( V1.size() < V2.size() ) V1.push_back( Complex( 0.0 , 0.0 ) );
                while( V2.size() < V1.size() ) V2.push_back( Complex( 0.0 , 0.0 ) );

                vector <int> V = fft.Multiply( V1 , V2 );
                for( int i = V.size()-1; i >= 0; i-- ) cout << V[i];
                cout << endl;
        }
        return 0;
}








