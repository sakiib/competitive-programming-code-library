#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef pair <int,int> pii;
typedef pair <long long,long long> pll;
const int MOD = 1e9 + 7;
const double EPS = 1e-8;
const int N = 1e5 + 5;
const int inf = 1e9;
const long long INF = 1e18;

/**
# of ways to select 3 sides that forms a non-deg( 1 , 2 , 2 ). triangle
for de gen. use a[mid] <= val( 1 . 2 . 3 )
*/
int n , a[ N ];

int bin_search( int lo , int hi , int val ) {
        int l = lo , r = hi , ret1 = -1 , ret2 = -1;
        while( l <= r ) {
                int mid = ( l + r ) >> 1;
                if( a[mid] < val ) ret1 = mid , l = mid + 1;
                else r = mid - 1;
        }
        l = lo , r = hi;
        while( l <= r ) {
                int mid = ( l + r ) >> 1;
                if( a[mid] < val ) ret2 = mid , r = mid - 1;
                else r = mid - 1;
        }
        return ret1 == -1 ? 0 : ret1 - ret2 + 1;
}
int main( int argc , char const *argv[] ) {
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
                scanf("%d",&n);
                for( int i = 1; i <= n; i++ ) scanf("%d",&a[i]);
                sort( a + 1 , a + n + 1 );
                int ans = 0;
                for( int i = 1; i <= n - 2; i++ ) {
                        for( int j = i + 1; j <= n - 1; j++ ) {
                                ans += bin_search( j + 1 , n , a[i] + a[j] );
                        }
                }
                printf("Case %d: %d\n",tc,ans);
        }
        return 0;
}












