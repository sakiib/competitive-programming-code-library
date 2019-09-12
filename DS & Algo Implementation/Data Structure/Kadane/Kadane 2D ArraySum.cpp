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

int Kadane( ) {
        for( int i = 1; i <= r; i++ ) {
                for( int j = 1; j <= c; j++ ) {
                        sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + a[i][j];
                }
        }
        int mx = 0;
        for( int i = 1; i <= r; i++ ) {
                for( int j = 1; j <= c; j++ ) {
                        for( int k = i; k <= r; k++ ) {
                                for( int l = j; l <= c; l++ ) {
                                        int tot = sum[k][l] - sum[i-1][l] - sum[k][j-1] + sum[i-1][j-1];
                                        int len = ( k - i + 1 );
                                        int width = ( l - j + 1 );
                                        if( len == width ) { /// Only for Square.
                                                if( tot <= bad ) mx = max( mx , len );
                                        }
                                }
                        }
                }
        }
        return mx;
}
int main( int argc , char const *argv[] ) {
        Fast_IO;
        int t;
        cin >> t;
        while( t-- ) {
                cin >> n >> w >> bad;
                r = n , c = n;
                memset( sum , 0 , sizeof(sum) );
                memset( a , 0 , sizeof(a) );
                for( int i = 1; i <= w; i++ ) {
                        int x , y;
                        cin >> x >> y;
                        a[x][y] = 1;
                }
                int X = Kadane( );
                cout << X * X << endl;
        }
        return 0;
}







