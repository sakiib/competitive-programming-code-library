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

int n , w , k;
int x[ N ] , y[ N ];
int dp[ 105 ][ 105 ];

int go( int pos , int rem ) {
        if( rem == 0 ) return 0;
        if( pos > n ) return 0;
        if( dp[pos][rem] != -1 ) return dp[pos][rem];
        int ret = 0;
        int nxt = upper_bound( y + pos + 1 , y + n + 1 , y[pos]+w ) - y;
        ret = max( go( pos + 1 , rem ) , go( nxt , rem - 1 ) + ( nxt-pos ) );
        return dp[pos][rem] = ret;
}
void solve( ) {
        cin >> n >> w >> k;
        for( int i = 1; i <= n; i++ ) cin >> x[i] >> y[i];
        sort( y + 1 , y + n + 1 );
        memset( dp , -1 , sizeof( dp ) );
        cout << go( 1 , k ) << endl;
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( NULL );
        int t;
        cin >> t;
        for( int tc = 1; tc <= t; tc++ ) {
                cout << "Case " << tc << ": ";
                solve( );
        }
        return 0;
}











