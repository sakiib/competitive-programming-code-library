#include <bits/stdc++.h>
using namespace std;

/**
PROPERTY 1: (a*b*c*d...*p*q) % MOD = (a%MOD)(b%MOD)(c%MOD).....(q%MOD);

but this is not the case with LCM.

LCM(a,b)=a*b/GCD(a,b).

LCM(LCM(a,b),c)=LCM(a,b)*c/GCD(LCM(a,b),c).

Whenever LCM becomes greater than the MOD, the above mentioned property
gets destroyed. You must try to find LCM in terms of products of different numbers in numerator only.

This can be done by factorizing all the numbers and keeping the record of
highest powers of various factors.

LCM = (2^a)(3^b).... Now you can easily multiply them iteratively and
also keep the limit under MOD by using property 1
*/

const int N = 1e4 + 5;
typedef long long LL;
const int MOD = 1000000007;

int n;
int a[ N ];

vector <int> prime;
vector <bool> isprime( N , true );

void sieve( ) {
        isprime[0] = isprime[1] = false;
        prime.push_back( 2 );
        for( int i = 4; i <= N; i +=2 ) isprime[i] = false;
        int sq = sqrt( N );
        for( int i = 3; i <= sq; i += 2 ) {
                if( isprime[i] ) {
                        for( int j = i*i; j <= N; j += 2*i ) {
                                isprime[j] = false;
                        }
                }
        }
        for( int i = 3; i <= N; i += 2 ) {
                if( isprime[i] ) prime.push_back( i );
        }
}

int MAX[ N ];

void PrimeFact( int n ) {
        int sq = sqrt( n );
        int sz = prime.size();
        for( int i = 0; i < sz && prime[i] <= sq; i++ ) {
                int val = prime[i] , p = 0;
                if( n%prime[i] == 0 ) {
                        p++;
                        n /= prime[i];
                        while( n%prime[i] == 0 ) {
                                p++;
                                n /= prime[i];
                        }
                        MAX[val] = max( MAX[val] , p );
                        sq = sqrt( n );
                }
        }
        if( n > 1 ) MAX[n] = max( MAX[n] , 1 );
}
LL BigMod ( LL b , LL p , LL mod ) {
        LL res = 1 % mod , x = b % mod;
        while ( p ) {
                if ( p & 1 ) res = ( res * x ) % mod;
                x = ( x * x ) % mod; p >>= 1;
        }
        return ( res%mod );
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( NULL );
        sieve( );
        int t;
        cin >> t;
        while( t-- ) {
                cin >> n;
                memset( MAX , 0 , sizeof( MAX ) );
                for(int i = 1; i <= n; i++ ) PrimeFact( i );
                LL ans = 1;
                //for( auto x : M ) cout << x.first << " "<< x.second << endl;
                for( int i = 2; i < N; i++ ) ans = ( ans%MOD * BigMod( i , MAX[i] , MOD )%MOD )%MOD;
                cout << ans%MOD << endl;
        }
        return 0;
}











