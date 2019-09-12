#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template <typename T> using
Treap = tree <T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef unsigned long long uLL;
typedef long long int LL;
typedef pair <int,int> pii;
typedef pair <long long,long long> pll;
const int N = 1e5 + 5;
const int inf = 1e9;
const long long INF = 1e18;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int MOD = 1000000007;

int n , k , a[ N ];
int dp[ N ];

int Brute( ) {
        int ret = 0;
        for( int i = 1; i <= n; i++ ) {
                for( int j = i; j <= n; j++ ) {
                        int xo = 0;
                        for( int jj = i; jj <= j; jj++ ) {
                                xo = ( xo ^ a[jj] );
                        }
                        if( xo == k ) ret++;
                }
        }
        return ret;
}
int solve( ) {
        int xo = 0 , ans = 0;
        dp[0] = 1;
        for( int i = 1; i <= n; i++ ) {
                xo = xo^a[i];
                ans += ( dp[xo^k] );
                dp[xo]++;
        }
        return ans;
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( NULL );
        cin >> n >> k;
        for( int i = 1; i <= n; i++ ) cin >> a[i];
        cout << Brute( ) << " " << solve( ) << endl;
        return 0;
}















