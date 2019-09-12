#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
typedef unsigned long long uLL;
typedef long long int LL;
typedef pair <int,int> pii;
typedef pair <int,pii> piii;
typedef pair <long long,long long> pll;
typedef pair <long long,pll> plll;
const int N = 205;
const int inf = 0x3f3f3f3f;
const long long INF = 1e18;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int MOD = 1000000007;

int n , k;
LL a[ N ];
LL cnt5[ N ] , cnt2[ N ];
LL dp[ 2 ][ 201 ][ 201 * 30 ];

int calc( int idx , LL val , int x ) {
        int ret = 0;
        while( val%x == 0 ) ret++ , val /= x;
        return ret;
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( nullptr );
        cin >> n >> k;
        for( int i = 1; i <= n; i++ ) cin >> a[i];
        for( int i = 1; i <= n; i++ ) {
                cnt5[i] = calc( i , a[i] , 5 );
                cnt2[i] = calc( i , a[i] , 2 );
        }
        for( int i = 0; i <= 1; i++ ) {
                for( int j = 0; j <= k; j++ ) {
                        for( int d = 0; d <= 200*30; d++ ) {
                                dp[i][j][d] = -INF;
                        }
                }
        }
        dp[0][0][0] = 0 , dp[1][0][0] = 0;
        int id = 0;
        for( int i = 1; i <= n; i++ ) {
                id = (id^1);
                for( int j = 1; j <= k; j++ ) {
                        for( int d = 0; d <= 200*30; d++ ) {
                                if( cnt5[i] <= d ) {
                                        dp[id][j][d] = max( dp[(id^1)][j][d] ,
                                        dp[(id^1)][j-1][d-cnt5[i]] + cnt2[i] );
                                }
                                else dp[id][j][d] = dp[(id^1)][j][d];
                        }
                }
        }
        LL ans = 0;
        for( int i = 0; i <= 200*30; i++ ) {
                ans = max( ans , min( i*1LL , dp[id][k][i] ) );
        }
        cout << ans << endl;
        return 0;
}











