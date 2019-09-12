#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long uLL;
typedef long long int LL;
typedef pair <int,int> pii;
typedef pair <int,pii> piii;
typedef pair <long long,long long> pll;
typedef pair <long long,pll> plll;
const int N = 1e6 + 5;
const int inf = 1e9;
const long long INF = 1e18;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int MOD = 1000000007;

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

void factFactorize( int n ) {
        for( int i = 0; i < prime.size() && prime[i] <= n; i++ ) {
                int x = n;
                int freq = 0;
                while( x / prime[i] ) {
                        freq += x / prime[i];
                        x = x / prime[i];
                }
                X[ prime[i] ] += freq;
        }
}
void PrimeFact( LL n ) {
        LL sq = sqrt( n );
        for( int i = 0; i < prime.size() && prime[i] <= sq; i++ ) {
                if( n%prime[i] == 0 ) {
                        Y[ prime[i] ]++;
                        n /= prime[i];
                        while( n%prime[i] == 0 ) {
                                Y[ prime[i] ]++;
                                n /= prime[i];
                        }
                        sq = sqrt( n );
                }
        }
        if( n > 1 ) Y[ n ]++;
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( NULL );
        sieve( );
        LL n , d;
        while( cin >> n >> d ) {
                if( n == 0 && d == 0 ) break;
                X.clear() , Y.clear();

                factFactorize( n );
                PrimeFact( d );

                LL ans = 1;
                for( auto x : Y ) {
                        if( X[x.first] < x.second ) {
                                ans = 0;
                                break;
                        }
                }
                if( ans == 0 ) {
                        cout << 0 <<endl;
                        continue;
                }
                for( auto x : X ) {
                        ans *= ( x.second - Y[x.first] + 1 );
                }
                cout << ans << endl;
        }
        return 0;
}











