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
knapsack for huge capacity but smaller values

we need to see for all possible value that can be made , min cap needed
if min cap is <= cap we will update our answer
*/

int n;
LL cap;
LL v[ N ] , w[ N ];
LL dp[ 101 ][ N ];

LL solve( int idx , int rem ) {
        if( rem < 0 ) return INF;
        if( rem == 0 ) return 0;
        if( idx > n ) return rem == 0 ? 0 : INF;
        if( dp[idx][rem] != -1 ) return dp[idx][rem];
        LL ret = INF;
        ret = solve( idx + 1 , rem );
        ret = min( ret , solve( idx + 1 , rem - v[idx] ) + w[idx] );
        return dp[idx][rem] = ret;
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( NULL );
        cin >> n >> cap;
        LL tot = 0;
        for( int i = 1; i <= n; i++ ) cin >> w[i] >> v[i] , tot += v[i];
        LL ans = 0;
        memset( dp , -1, sizeof( dp ) );
        for( LL i = tot; i >= 0; i-- ) {
                LL mn_weight = solve( 1 , i );
                if( mn_weight <= cap ) ans = max( ans , i );
        }
        cout << ans << endl;
        return 0;
}











