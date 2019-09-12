#include <bits/stdc++.h>
using namespace std;

#define Fast_IO ios_base::sync_with_stdio(0); cin.tie(0);

typedef unsigned long long uLL;
typedef long long int LL;
const int N = 1e5 + 5;
const int inf = 1e9;
const LL INF = 1e18;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int MOD = 1000000007;

int  Set( int N , int pos )    { return N |= ( 1 << pos ); }
int  Reset( int N , int pos )  { return N = N & ~( 1 << pos ); }
bool Check( int N , int pos )  { return (bool)( N & ( 1 << pos ) );}
int  Toggle( int N , int pos ) { return ( N ^= ( 1 << pos ) ); }

int b , g;
int mask[ 500 ];

int main( int argc , char const *argv[] ) {
        Fast_IO;
        int t;
        cin >> t;
        while( t-- ) {
                cin >> b >> g;
                memset( mask , 0 , sizeof(mask) );
                for( int i = 0; i < g; i++ ) {
                        int x , y;
                        cin >> x >> y;
                        --x , --y;
                        mask[x] = Set( mask[x] , y );
                }
                //for( int i = 1; i <= b; i++ ) cout << i << " " << bitset <10>(mask[i]) << endl;
                int ans = 0;
                for( int i = 0; i < ( 1 << b ); i++ ) {
                        int cnt = 0;
                        int m = ( 1 << 20 )-1;
                        for( int j = 0; j < b; j++ ) {
                               if( (i&(1<<j)) )  {
                                      cnt++;
                                      m = ( m&mask[j] );
                               }
                        }
                        //cout << cnt << " " << bitset <10>(m) << endl;
                        if( cnt != 0 ) ans = max( ans , cnt + __builtin_popcount( m ) );
                }
                cout << ans <<endl;
        }
        return 0;
}








