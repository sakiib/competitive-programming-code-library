#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int inf = 1e9;

bool Check(int N,int pos){return (N & (1<<pos)) != 0;}
int Set(int N,int pos){return N=N | (1<<pos);}
int Reset(int N,int pos){return N= N & ~(1<<pos);}

int a[ N ][ 10 ];
int MX[ N ] , MN[ N ];
int n , d;

int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( NULL );
        cin >> n >> d;
        for( int i = 1; i <= n; i++ ) {
                for( int j = 0; j < d; j++ ) {
                        cin >> a[i][j];
                }
        }
        for( int i = 0; i < 32; i++ ) MX[i] = -inf , MN[i] = inf;
        for( int i = 1; i <= n; i++ ) {
                for( int j = 0; j < ( 1 << ( d - 1 ) ); j++ ) {
                        int x = a[i][0];
                        for( int k = 0; k < ( d - 1 ); k++ ) {
                               if( Check( j , k ) ) x += a[i][k+1];
                               else x -= a[i][k+1];
                        }
                        MX[j] = max( MX[j] , x );
                        MN[j] = min( MN[j] , x );
                }
        }
        int ans = -inf;
        for( int i = 0; i < ( 1 << ( d - 1 ) ); i++ ) {
                ans = max( ans , MX[i] - MN[i] );
        }
        cout << ans << endl;
        return 0;
}










