#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
typedef long long int LL;
const int N = 1e7 + 5;

bool isprime[ N ];
int prime[ N ];
int mobius[ N ] = { 0 , 1 };

void mobiusCalc( ) {
        memset( isprime , true , sizeof( isprime ) );
        int primecnt = 0;
        for( int i = 2; i < N; i++ ) {
                if( isprime[i] ) {
                        prime[ ++primecnt ] = i;
                        mobius[i] = -1;
                }
                for( int j = 1; i * prime[j] < N; j++ ) {
                        isprime[ i*prime[j] ] = false;
                        if( i%prime[j] == 0 ) {
                                mobius[ i*prime[j] ] = 0;
                                break;
                        }
                        else mobius[ i*prime[j] ] -= mobius[i];
                }
        }
}
LL solve( LL n ) {
        LL sq = sqrt( n );
        LL res = 0;
        for( int i = 1; i <= sq; i++ ) {
                LL x = 1LL * i * i;
                res += mobius[i] * ( n/x );
        }
        return res;
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( nullptr );
        mobiusCalc( );
        int t;
        cin >> t;
        while( t-- ) {
                LL n;
                cin >> n;
                cout << solve( n ) << endl;
        }
        return 0;
}











