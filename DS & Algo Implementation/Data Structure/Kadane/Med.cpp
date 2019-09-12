#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int n;
int a[ 305 ][ 305 ];
int sum[ 305 ][ 305 ][ 20 ];

void calc( ) {
        for( int i = 1; i <= n; i++ ) {
                for( int j = 1; j <= n; j++ ) {
                        for( int k = 1; k <= 15; k++ ) {
                                sum[i][j][k] += sum[i][j-1][k];
                        }
                }
        }
        for( int i = 1; i <= n; i++ ) {
                for( int j = 1; j <= n; j++ ) {
                        for( int k = 1; k <= 15; k++ ) {
                                sum[i][j][k] += sum[i-1][j][k];
                        }
                }
        }
        /**
        /// this is sum off all numbers less than eq k , without just kon number koto bar ase.
        for( int i = 1; i <= n; i++ ) {
                for( int j = 1; j <= n; j++ ) {
                        for( int k = 1; k <= 15; k++ ) {
                                sum[i][j][k] += sum[i][j][k-1];
                        }
                }
        }*/
}
int getSum( int x1 , int y1 , int x2 , int y2 , int key ) { /// LL , UR
        return sum[x2][y2][key] - sum[x2][y1-1][key] - sum[x1-1][y2][key] + sum[x1-1][y1-1][key];
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( nullptr );
        cin >> n;
        memset( sum , 0 , sizeof( sum ) );
        for( int i = 1; i <= n; i++ ) {
                for( int j = 1; j <= n; j++ ) {
                        cin >> a[i][j];
                        sum[i][j][a[i][j]]++;
                }
        }
        calc( );
        int q;
        cin >> q;
        while( q-- ) {
                int x1 , y1 , x2 , y2;
                cin >> x1 >> y1 >> x2 >> y2;
                int ans = 0;
                for( int i = 1; i <= 10; i++ ) {
                        if( getSum( x1 , y1 , x2 , y2 , i ) > 0 ) ans++;
                }
                cout << ans << endl;
        }
        return 0;
}












