#include <bits/stdc++.h>
using namespace std;

#define Fast_IO ios_base::sync_with_stdio(0); cin.tie(0);

typedef unsigned long long uLL;
typedef long long int LL;
const int N = 2e3 + 5;
const int inf = 1e9;
const LL INF = 1e18;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int MOD = 1000000007;

int n , w , bad , r , c;
int sum[ N ][ N ];
int a[ N ][ N ];

int getsum( int x , int y ) {
        int lo = 0 , hi = n , ret = 0;
        for( int i = 1; i <= 50; i++ ) {
                int mid = ( lo + hi )/2;
                int nx = x + mid;
                int ny = y + mid;
                if( nx > n || ny > n ) {
                        hi = mid - 1;
                        continue;
                }
                int tot = sum[nx][ny] - sum[x-1][ny] - sum[nx][y-1] + sum[x-1][y-1];
                if( tot <= bad ) {
                        ret = max( ret , ( nx - x +1 ) );
                        lo = mid + 1;
                }
                else hi = mid - 1;
        }
        return ret;
}
int Kadane( ) {
        for( int i = 1; i <= r; i++ ) {
                for( int j = 1; j <= c; j++ ) {
                        sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + a[i][j];
                }
        }
        int mx = 0;
        for( int i = 1; i <= r; i++ ) {
                for( int j = 1; j <= c; j++ ) {
                        mx = max( mx , getsum( i , j ) );
                }
        }
        return mx;
}
int main( int argc , char const *argv[] ) {
        int t;
        scanf("%d",&t);
        while( t-- ) {
                scanf("%d %d %d",&n,&w,&bad);
                r = n , c = n;
                memset( sum , 0 , sizeof(sum) );
                memset( a , 0 , sizeof(a) );
                for( int i = 1; i <= w; i++ ) {
                        int x , y;
                        scanf("%d %d",&x,&y);
                        a[x][y] = 1;
                }
                int X = Kadane( );
                printf("%d\n",(X*X));
        }
        return 0;
}








