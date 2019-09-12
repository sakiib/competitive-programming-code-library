#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
typedef pair < int , int > ii;
const int inf = 1e9;
const LL INF = 1e18;
const int N = 1e5 + 5;
const int mod = 1000000007;
const double eps = 1e-8;
const double pi = acos( -1.0 );

/**
 phi( n )  = n * all( ( pi - 1 )/pi ) , pi are the primefactors.
 phi( n ) = phi( a ) * phi( b )  , if a , b are the primefactors of n

 */
int PHI[ N ];
bool mark[ N ];

inline LL PHI( LL x ) { /// generate sieve prime first.
        vector <LL> val;
        LL temp = x , vag = 1;
        for( int i = 0; i < prime.size(); i++ ) {
                if( x%prime[i] == 0 ) {
                        vag *= prime[i];
                        val.push_back( prime[i] );
                        x /= prime[i];
                        while( x%prime[i] == 0 ) x /= prime[i];
                }
        }
        if( x > 1 ) val.push_back( x ) , vag *= x;
        for( int i = 0; i < val.size(); i++ ) temp *= ( val[i] - 1 );
        temp /= vag;
        return temp;
}
inline void SievePhi( int sz ) {
        for( int i = 1; i <= sz; i++ ) PHI[i] = i;
        PHI[1] = 1 , mark[1] = true;
        for( int i = 2; i <= sz; i++ ) {
                if( !mark[i] ) {
                        for( int j = i; j <= sz; j +=i ) {
                                mark[j] = true , PHI[j] = PHI[j]/i*(i-1);
                        }
                }
        }
}
inline void SievePHI( int SZ ) {
        for( int i = 1; i <= SZ; i++ ) PHI[i] = i;
        for( int i = 1; i <= SZ; i++ ) {
                for( int j = 2*i; j <= SZ; j += i ) {
                        PHI[j] -= PHI[i];
                }
        }
}
int main( int argc , char const *argv[] ) {
        ios_base :: sync_with_stdio(false); cin.tie(NULL);
        memset( mark , false , sizeof(mark) );
        SievePhi( 100 );
        for( int i = 1; i <= 40; i++ ) cout << i << " "<< PHI[i] << endl;
        return 0;
}





