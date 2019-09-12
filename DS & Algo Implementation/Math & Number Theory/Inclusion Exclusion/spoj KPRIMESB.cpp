#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
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

int n;
int k;
LL a[ N ];

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
int BS( int x ) {
        int lo = 0 , hi = prime.size() - 1 , ret = 0;
        while( lo <= hi ) {
                int m = ( lo + hi ) >> 1;
                if( prime[m] <= x ) ret = m , lo = m + 1;
                else hi = m - 1;
        }
        return ret + 1;
}
LL LCM( LL x , LL y ) {
        return x/__gcd( x , y ) * y;
}
int solve( ) {
        int ans = 0;
        for( int i = 1; i < ( 1LL << k ); i++ ) {
                LL lcm = -1 , cnt = 0;
                for( int j = 0; j < k; j++ ) {
                        if( i&( 1LL << j ) ) {
                               ++cnt;
                                if( cnt == 1 ) lcm = a[j];
                                else lcm = LCM( lcm , a[j] );
                                if( lcm > N ) {
                                        lcm = -1;
                                        break;
                                }
                        }
                }
                if( lcm == -1 ) continue;
                if( cnt&1 ) ans += n/lcm;
                else ans -= n/lcm;
        }
        ans = ( n - ans + k - 1 );
        ans -= BS( n );
        return ans;
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( nullptr );
        sieve( );
        int t;
        cin >> t;
        for( int tc = 1; tc <= t; tc++ ) {
                cin >> n >> k;
                for( int i = 0; i < k; i++ ) cin >> a[i];
                cout << "Case " << tc << ": ";
                if( n == 0 ) cout << 0 << endl;
                else cout << solve( ) << endl;
        }
        return 0;
}











