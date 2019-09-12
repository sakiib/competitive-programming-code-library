#include <bits/stdc++.h>
using namespace std;

const int inf = 1e7;
const int N = 1e6 + 1;
int n , m , k;
int a[ N ], cnt[ N ];

/**
 Minimum length of subarray which fullfills a condition
 */
void generate_seq( ) {
        for( int i = 1; i <= n; i++ ) {
                if( i <= 3 ) a[i] = i;
                else a[i] = ( a[i-1] + a[i-2] + a[i-3] )%m + 1;
        }
}
bool good( ) {
        for( int i = 1; i <= k; i++ ) if( cnt[i] == 0 ) return false;
        return true;
}
int solve( ) {
        int ans = inf;
        memset( cnt , 0 , sizeof( cnt ) );
        int l = 1 , r = 1;
        while( l <= n && r <= n ) {
                while( r <= n ) {
                        if( good( ) ) break;
                        cnt[ a[r] ]++;
                        r++;
                }
                while( l <= n ) {
                        if( !good( ) ) break;
                        if( good( ) ) ans = min( ans , r - l );
                        cnt[ a[l] ]--;
                        l++;
                }
        }
        return ans;
}
int main( int argc , char const *argv[] ) {
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
                scanf("%d %d %d",&n,&m,&k);
                generate_seq( );
                int mn = solve( );
                if( mn == inf ) printf("Case %d: sequence nai\n",tc);
                else printf("Case %d: %d\n",tc,mn);
        }
        return 0;
}












