#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int inf = 1e9;

int n , sum;
int a[ N ];

int two_pointers( ) {
        int l = 1 , r = 1 , ans = inf , tot = 0;
        while( l <= n && r <= n ) {
                while( r <= n ) {
                        tot += a[r];
                        r++;
                        if( tot >= sum ) break;
                }
                while( l <= n ) {
                        if( tot < sum ) break;
                        if( tot >= sum ) ans = min( ans , r - l );
                        tot -= a[l];
                        l++;
                }
        }
        return ans;
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( NULL );
        while( cin >> n >> sum ) {
                for( int i = 1; i <= n; i++ ) cin >> a[i];
                int ans = two_pointers( );
                if( ans == inf ) ans = 0;
                cout << ans << endl;
        }
        return 0;
}










