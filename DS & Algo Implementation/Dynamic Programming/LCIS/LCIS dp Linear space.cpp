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

int n , m;
int a[ 505 ] , b[ 505 ];
int dp[ 505 ] , par[ 505 ];
int lcis[ 505 ];

void LCIS( ) {
        for( int i = 1; i <= m; i++ ) dp[i] = 0;
        for( int i = 1; i <= n; i++ ) {
                int cur = 0 , last = -1;
                for( int j = 1; j <= m; j++ ) {
                        if( a[i] == b[j] ) {
                                if( cur + 1 > dp[j] ) dp[j] = cur + 1 , par[j] = last;
                        }
                        if( a[i] > b[j] ) {
                                if( dp[j] > cur ) cur = dp[j] , last = j;
                        }
                }
        }
        int mx = 0 , idx = -1;
        for( int i = 1; i <= m; i++ ) if( dp[i] > mx ) mx = dp[i] , idx = i;
        cout << mx << endl;
        for( int i = 1; idx != -1; i++ ) lcis[i] = b[idx], idx = par[idx];
        for( int i = mx; i >= 1; i-- ) cout << lcis[i] << " ";
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( nullptr );
        cin >> n;
        for( int i = 1; i <= n; i++ ) cin >> a[i];
        cin >> m;
        for( int i = 1; i <= m; i++ ) cin >> b[i];
        LCIS( );
        return 0;
}












