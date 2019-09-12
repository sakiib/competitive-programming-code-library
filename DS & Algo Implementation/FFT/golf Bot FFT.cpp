#include <bits/stdc++.h>
using namespace std;

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
        vector <Complex> Multiply( const vector <Complex> &x , const vector <Complex> &y ) {
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
                return A;
        }
} fft;

const int N = 2e5;
int dist[ N + 5 ];
int hole[ N + 5 ];
bool has[ N + 5 ];
bool can[ N + 5 ];

int main( int argc , char const *argv[] ) {
        int n;
        while( scanf("%d",&n) != EOF ) {
                memset( has , false , sizeof(has) );
                memset( can , false , sizeof(can) );
                for( int i = 1; i <= n; i++ ) scanf("%d",&dist[i]) , can[ dist[i] ] = true;
                int m;
                scanf("%d",&m);
                for( int i = 1; i <= m; i++ ) scanf("%d",&hole[i]) , has[ hole[i] ] = true;
                vector <Complex> V1 , V2;
                V1.push_back( Complex( 1.0 , 0.0 ) );
                V2.push_back( Complex( 1.0 , 0.0 ) );
                for( int i = 1; i <= N; i++ ) {
                        if( can[i] ) {
                                V1.push_back( Complex( 1.0 , 0.0) );
                                V2.push_back( Complex( 1.0 , 0.0) );
                        }
                        else {
                                V1.push_back( Complex( 0.0 , 0.0) );
                                V2.push_back( Complex( 0.0 , 0.0) );
                        }
                }
                vector <Complex> V = fft.Multiply( V1 , V2 );
                int ans = 0;
                for( int i = 0; i < V.size() && i <= N; i++ ) {
                        int val = (int)round( V[i].real );
                        if( has[i] && val  ) ans++;
                }
                printf("%d\n",ans);
        }
        return 0;
}








