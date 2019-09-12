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

int n , w , l;
int BIT[ N ][ N ];

/**
 Kadane's 2D
 N^3 logN
 */

void Update( int idx , int idy , int val ) {
        int y = idy;
        for( ; idx <= N; idx += ( idx & -idx ) ) {
                idy = y;
                for( ; idy <= N ; idy += ( idy & -idy ) ) {
                        BIT[idx][idy] += val;
                }
        }
}
int Query( int idx , int idy ) {
        int y = idy;
        int sum = 0;
        for( ; idx > 0; idx -= ( idx & -idx ) ) {
                idy = y;
                for( ; idy > 0 ; idy -= ( idy & -idy ) ) {
                        sum += BIT[idx][idy];
                }
        }
        return sum;
}
int go( int ux , int uy ) {
        int ret = 0;
        for( int i = ux; i <= n; i++ ) { /// Finding appropriate bottom right corner.
                for( int j = uy; j <= n; j++ ) {
                        int bad = 0;
                        bad += Query( i , j );
                        bad -= Query( ux-1 , j );
                        bad -= Query( i , uy-1 );
                        bad += Query( ux-1 , uy-1 );
                        /// length & width of the rectangle or square.
                        /// sum of values = bad.
                        /// use appropriate condition.
                        int len = abs( j - uy ) + 1 , width = abs( i - ux ) + 1;

                        if( len == width ) {
                                if( bad <= l ) ret = max( ret , len );
                        }
                }
        }
        return ret;
}
int Kadane( ) {
        int ans = 0;
        /// Top Left Corner..
        for( int i = 1; i <= n; i++ ) {
                for( int j = 1; j <= n; j++ ) {
                        ans = max( ans , go( i , j ) );
                }
        }
        return ans;
}
int main( int argc , char const *argv[] ) {
        Fast_IO;
        int t;
        cin >> t;
        while( t-- ) {
                cin >> n >> w >> l;
                memset( BIT , 0 , sizeof(BIT) );
                for( int i = 1; i <= w; i++ ) {
                        int x , y;
                        cin >> x >> y;
                        Update( x , y , +1 );
                }
                int X = Kadane( );
                cout << X * X << endl;
        }
        return 0;
}







