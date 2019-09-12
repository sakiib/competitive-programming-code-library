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
vector <int> PrimeFact( int n ) {
        vector <int> ret;
        int sq = sqrt( n );
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
vector < pair<int,int> > PrimeFactor( int n ) {
        vector < pair<int,int> > ret;
        int sq = sqrt( n );
        for( int i = 0; i < prime.size() && prime[i] <= sq; i++ ) {
                int cnt = 0;
                if( n%prime[i] == 0 ) {
                        while( n%prime[i] == 0 ) {
                                cnt++;
                                n /= prime[i];
                        }
                        if( cnt > 0 ) ret.push_back( {prime[i],cnt} );
                        sq = sqrt( n );
                }
        }
        if( n > 1 ) ret.push_back( {n,1} );
        return ret;
}
int main( int argc , char const *argv[] ) {
        ios_base :: sync_with_stdio(false); cin.tie(NULL);
        sieve();
        int n;
        cin >> n;
        vector <int> p = PrimeFact( n );
        //for( auto x : p ) cout << x << " ";
        //cout << endl;
        vector < pair<int,int> > P = PrimeFactor( n );
        for( auto x : P ) cout << x.first << " " << x.second << endl;
        return 0;
}






