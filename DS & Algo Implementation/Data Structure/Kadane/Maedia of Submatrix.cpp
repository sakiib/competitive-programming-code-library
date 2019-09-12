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

int r , c;
int a[ 105 ][ 105 ];
int sum[ 105 ][ 105 ][ 505 ];

void reset( int r , int c ) {
        for( int i = 1; i <= r; i++ ) {
                for( int j = 1; j <= c; j++ ) {
                        for( int k = 1; k <= 500; k++ ) {
                                sum[i][j][k] = 0;
                        }
                }
        }
}
void calc( ) {
        for( int i = 1; i <= r; i++ ) {
                for( int j = 1; j <= c; j++ ) {
                        for( int k = 1; k <= 500; k++ ) {
                                sum[i][j][k] += sum[i][j-1][k];
                        }
                }
        }
        for( int i = 1; i <= r; i++ ) {
                for( int j = 1; j <= c; j++ ) {
                        for( int k = 1; k <= 500; k++ ) {
                                sum[i][j][k] += sum[i-1][j][k];
                        }
                }
        }
        for( int i = 1; i <= r; i++ ) {
                for( int j = 1; j <= c; j++ ) {
                        for( int k = 1; k <= 500; k++ ) {
                                sum[i][j][k] += sum[i][j][k-1];
                        }
                }
        }
}
int getSum( int x1 , int y1 , int x2 , int y2 , int key ) { /// LL , UR
        return sum[x2][y2][key] - sum[x2][y1-1][key] - sum[x1-1][y2][key] + sum[x1-1][y1-1][key];
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( nullptr );
        int t;
        cin >> t;
        for( int tc = 1; tc <= t; tc++ ) {
                int q;
                cin >> r >> c >> q;
                reset( r , c );
                for( int i = 1; i <= r; i++ ) {
                        for( int j = 1; j <= c; j++ ) {
                                cin >> a[i][j];
                                sum[i][j][a[i][j]]++;
                        }
                }
                calc( );
                while( q-- ) {
                        int x1 , y1 , x2 , y2;
                        cin >> x1 >> y1 >> x2 >> y2;
                        int tot = ( y2 - y1 + 1 ) * ( x2 - x1 + 1 );
                        int med = ( tot + 1 )/2;
                        int lo = 1 , hi = 500 , ans = -1;
                        while( lo <= hi ) {
                                int mid = ( lo + hi ) >> 1;
                                int sum = getSum( x1 , y1 , x2 , y2 , mid );
                                if( sum >= med ) ans = mid , hi = mid - 1;
                                else lo = mid + 1;
                        }
                        cout << ans << endl;
                }
        }
        return 0;
}











