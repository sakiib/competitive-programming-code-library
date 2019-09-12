#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long uLL;
typedef long long int LL;
const int N = 1e5 + 5;
const int inf = 1e9;
const LL INF = 1e18;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int MOD = 1000000007;

/**
In mathematics, a square-free integer (or squarefree integer) is an integer which is
divisible by no perfect square other than 1. That is, its prime factorization
has exactly one factor for each prime that appears in it. For example,
10 = 2 x 5 is square-free, but 18 = 2 x 3 x 3 is not, because 18 is
divisible by 9 = 32. The smallest positive square-free numbers are

1, 2, 3, 5, 6, 7, 10, 11, 13, 14, 15, 17, 19, 21, 22, 23, 26, 29, 30, 31, 33, 34, 35, 37, 38, 39
*/

/// Mobius function is a function which has one of the following values:
/// mobius(x) = -1 : square free number with odd #of prime factors , can be toggled
/// mobius(x) = 1  : square free number with even #of prime factors
/// mobius(x) = 0  : not a square free number
/// Store all the prime till N in vector prime, then call mobiusCalc(N)

/// Application of Mobius function:
/// It is mainly used with inclusion exclusion, when items are the first K primes.
/// Complexity is improved from 2^k to NloglogN
/// Ex1: Number of pair (x,y) whose gcd is 1
/// Ex2: Summation of gcd(x,y) for all pair of 1<=x,y<=N

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
int main( int argc , char const *argv[] ) {
        sieve( );
        mobiusCalc( );
        for( int i = 1; i <= 50; i++ ) cout << i << " " << mobius[i] << endl;
        return 0;
}














