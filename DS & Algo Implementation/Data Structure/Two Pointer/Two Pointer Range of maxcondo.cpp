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

int n , k;
int a[ 3*N ];
int cnt[ 3*N ][ 2 ];

int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( NULL );
        cin >> n >> k;
        for( int i = 1; i <= n; i++ ) {
                cin >> a[i];
                for(int j = 0; j <= 1; j++ ) {
                        cnt[i][j] += ( cnt[i-1][j] + ( a[i] == j ) );
                }
        }
        int l = 1 , r = 1 , x = 0 , y = 0 , mx = 0;
        while( l <= n && r <= n ) {
                while( r <= n ) {
                        if( cnt[r][0] - cnt[l-1][0] > k ) break;
                        r++;
                }
                if( r - l > mx ) mx = r - l , x = l , y = r - 1;
                l++;
        }
        cout << mx << endl;
        for( int i = 1; i <= n; i++ ) {
                if( i >= x && i <= y ) cout << 1 << " ";
                else cout << a[i] << " ";
        }
        return 0;
}











