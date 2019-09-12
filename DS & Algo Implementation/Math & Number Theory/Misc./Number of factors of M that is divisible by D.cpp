#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long uLL;
typedef long long int LL;
typedef pair <int,int> pii;
typedef pair <int,pii> piii;
typedef pair <long long,long long> pll;
typedef pair <long long,pll> plll;
const int N = 1e5 + 5;
const int inf = 1e9;
const long long INF = 1e18;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int MOD = 1000000007;

/**
First let us solve the more general problem: How many factors of M are divisible by D?

Let M=∏ipqii where pi are distinct primes. And similarly, let D=∏iprii.

Immediately, it can be seen that if ri>qi for some i, then M is not divisible by D and the answer is zero.

Hence suppose that ri≤qi∀i. Then it is easy to see that every number of the form ∏ipsii ,
ri≤si≤qi is a factor of M and a multiple of D. The total number of such numbers is  ∏i(qi−ri+1)
*/

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
map <LL,LL> X , Y;

void PrimeFact( LL n , int id ) {
        LL sq = sqrt( n );
        for( int i = 0; i < prime.size() && prime[i] <= sq; i++ ) {
                if( n%prime[i] == 0 ) {
                        if( id == 1 ) X[ prime[i] ]++;
                        else Y[ prime[i] ]++;
                        n /= prime[i];
                        while( n%prime[i] == 0 ) {
                                if( id == 1 ) X[ prime[i] ]++;
                                else Y[ prime[i] ]++;
                                n /= prime[i];
                        }
                        sq = sqrt( n );
                }
        }
        if( n > 1 ) {
                if( id == 1 ) X[ n ]++;
                else Y[ n ]++;
        }
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( NULL );
        sieve( );
        int M , D;
        cin >> M >> D;
        PrimeFact( M , 1 );
        PrimeFact( D , 2 );
        //for( auto x : X ) cout << x.first << " " << x.second << endl;
        //cout << "-------" << endl;
        //for( auto x : Y ) cout << x.first << " " << x.second <<endl;
        for( auto x : Y ) {
                if( X[x.first] < x.second ) return cout << 0 << endl,0;
        }
        int ans = 1;
        for( auto x : X ) {
                ans *= ( x.second - Y[x.first] + 1 );
        }
        cout << ans << endl;
        return 0;
}











