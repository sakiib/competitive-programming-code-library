#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
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
Given a number N, you are asked to count the number of integers between L and R inclusive
 which are relatively prime to K
*/

LL l , r;
LL k;

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
vector <LL> PrimeFact( LL n ) {
        vector <LL> ret;
        LL sq = sqrt( n );
        for( int i = 0; i < prime.size() && prime[i] <= sq; i++ ) {
                if( n%prime[i] == 0 ) {
                        ret.push_back( prime[i] );
                        n /= prime[i];
                        while( n%prime[i] == 0 ) {
                                ret.push_back( prime[i] );
                                n /= prime[i];
                        }
                        sq = sqrt( n );
                }
        }
        if( n > 1 ) ret.push_back( n );
        return ret;
}

vector <LL> V;

LL LCM( LL a , LL b ) {
        return a / __gcd( a , b ) * b;
}
LL solve( LL n ) {
        int sz = V.size();
        LL res = 0;
        for( int i = 1; i < ( 1 << sz ); i++ ) {
                LL cnt = 0;
                LL lcm = 0;
                for( int j = 0; j < sz; j++ ) {
                        if( i&( 1LL << j ) ) {
                                ++cnt;
                                if( cnt == 1 ) lcm = V[j];
                                else lcm = LCM( lcm , V[j] );
                        }
                }
                // or use count
                if( __builtin_popcount( i )&1 ) res += n/lcm; /// odd bad , even take
                else res -= n/lcm;
        }
        return ( n - res );
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( nullptr );
        sieve( );
        int t;
        cin >> t;
        for( int tc = 1; tc <= t; tc++ ) {
                cin >> l >> r >> k;
                V = PrimeFact( k );
                cout << "Case #" << tc << ": " << solve( r ) - solve( l - 1 ) << endl;
        }
        return 0;
}











