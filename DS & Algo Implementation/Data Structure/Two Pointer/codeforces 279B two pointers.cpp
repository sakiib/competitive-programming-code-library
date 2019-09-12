#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int inf = 1e9;
int n , t;
int a[ N ];

/**
 Maximum Length of subarray whose sum <= t
 */
int two_pointers( ) {
        int l = 1 , r = 1 , ans = -inf;
        int sum = 0;
        while( l <= n && r <= n ) {
                while( r <= n ) {
                        if( sum + a[r] > t ) break;
                        sum += a[r];
                        r++;
                }
                ans = max( ans , r - l );
                sum -= a[l];
                l++;
        }
        return ans;
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( NULL );
        cin >> n >> t;
        for( int i = 1; i <= n; i++ ) cin >> a[i];
        cout << two_pointers( ) << endl;
        return 0;
}










