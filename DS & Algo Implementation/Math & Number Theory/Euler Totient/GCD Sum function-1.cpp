#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
typedef long long LL;

/**
  This is a Naive One but AC on uva 11424 - extreme gcd
  for n : find

  G = 0;
  for (i = 1; i < N; i++)
    for (j = i+1; j <= N; j++)
       G += gcd(i, j);

  logic :
  n = pi^ai * ... etc ( prime factors )
  G( n ) = profuct All : ( ai + 1 ) * pi ^ ai - ai * pi ^ ( ai - 1 )
  in this problem we ignored G(n,n) we subtracted it separately

  so , for every value from 2 to n , we calculated this & tokk cumsum

  coz : n = 5
  1.2 , 1.3 , 1.4 , 1.5
  2.3 , 2.4 ,2.5
  3.4 , 3.5
  4.5

  so , these values summation is the ansewer.

  for the spoj problem use PHI() to avoid TLE
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
LL Power ( LL b , LL p ) {
        LL res = 1, x = b;
        while ( p ) {
                if ( p & 1 ) res = ( res * x );
                x = ( x * x ); p >>= 1;
        }
        return ( res );
}

LL ans[ N ];

LL go( int val ) {
        vector < pair <int,int> > P = PrimeFactor( val );
        LL res = 1;
        for( auto x : P ) {
                LL p = Power( x.first , x.second );
                res *= ( ( x.second + 1 ) * p - x.second * p/x.first );
        }
        return res - val;
}
void calc( ) {
        for( int i = 2; i < N; i++ ) ans[i] = go( i );
        for( int i = 2; i < N; i++ ) ans[i] += ans[i-1];
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( NULL );
        sieve( );
        calc( );
        int n;
        while( cin >> n ) {
                if( n == 0 ) break;
                cout << ans[n] << endl;
        }
        return 0;
}











