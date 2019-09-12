#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
typedef long long int LL;
const int N = 1e7 + 5;

/**
In number theory we call an integer square-free if it is not divisible
by a perfect square, except 1.
You have to count them!
*/
vector <int> prime;
vector <bool> isprime( N , true );

void sieve( ) {
        isprime[0] = isprime[1] = false;
        prime.push_back( 2 );
        for( int i = 4; i <= N; i += 2 ) isprime[i] = false;
        int sq = sqrt( N );
        for( int i = 3; i <= sq; i += 2 ) {
                if( isprime[i] ) {
                        for( int j = i*i; j <= N; j += 2*i ) {
                                isprime[j] = false;
                        }
                }
        }
        for( int i = 3; i <= N; i += 2 ) if( isprime[i] ) prime.push_back( i );
}

int mobius[ N + 10 ];

void mobiusCalc( ) {
        for( int i = 1; i <= N; i++ ) mobius[i] = 1;
        int sq = sqrt( N );
        for( int i = 0; i < prime.size() && prime[i] <= sq; i++ ) {
                int x = prime[i] * prime[i];
                for( int j = x; j <= N; j += x ) {
                        mobius[j] = 0;
                }
        }
        for( int i = 0; i < prime.size(); i++ ) {
                for( int j = prime[i]; j <= N; j += prime[i] ) {
                        mobius[j] *= -1;
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
        sieve( );
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











