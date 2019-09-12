#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef pair <int,int> pii;
typedef pair <long long,long long> pll;
const int MOD = 1e9 + 7;
const double EPS = 1e-8;
const int N = 4010;
const int inf = 1e9;
const long long INF = 1e18;

string a , b;
int apos0[ N ] , apos1[ N ] , bpos0[ N ] , bpos1[ N ];
int dp[ N ][ N ][ 2 ];

int ok( int x , int y , int dig ) {
        if( x == -1 && y == -1 ) return 0;
        if( dp[x+1][y+1][dig] != -1 ) return dp[x+1][y+1][dig];
        int ret = inf;
        int ida0 = -1 , ida1 = -1;
        if( x != -1 ) ida0 = apos0[x] , ida1 = apos1[x];
        int idb0 = -1 , idb1 = -1;
        if( y != -1 ) idb0 = bpos0[y] , idb1 = bpos1[y];
        for( int i = 0; i <= 1; i++ ) {
                ret = min( ret , 1 + ok( i == 0 ? ida0 : ida1 , i == 0 ? idb0 : idb1 , i ) );
        }
        return dp[x+1][y+1][dig] = ret;
}
void print( int x , int y , int dig , int mn ) {
        if( x == -1 && y == -1 ) return;
        int ida0 = -1 , ida1 = -1;
        if( x != -1 ) ida0 = apos0[x] , ida1 = apos1[x];
        int idb0 = -1 , idb1 = -1;
        if( y != -1 ) idb0 = bpos0[y] , idb1 = bpos1[y];
        for( int i = 0; i <= 1; i++ ) {
                if( ok( i == 0 ? ida0 : ida1 , i == 0 ? idb0 : idb1 , i ) == mn - 1 ) {
                        cout << i;
                        print( i == 0 ? ida0 : ida1 , i == 0 ? idb0 : idb1 , i , mn - 1 );
                        return;
                }
        }
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( nullptr );
        cin >> a >> b;
        a = "@" + a;
        b = "@" + b;
        memset( dp , -1 , sizeof( dp ) );
        int nxt0 = -1 , nxt1 = -1;
        for( int i = a.size() - 1; i >= 0; i-- ) {
                apos0[i] = nxt0 , apos1[i] = nxt1;
                if( a[i] == '0' ) nxt0 = i;
                if( a[i] == '1' ) nxt1 = i;
        }
        nxt0 = -1 , nxt1 = -1;
        for( int i = b.size() - 1; i >= 0; i-- ) {
                bpos0[i] = nxt0 , bpos1[i] = nxt1;
                if( b[i] == '0' ) nxt0 = i;
                if( b[i] == '1' ) nxt1 = i;
        }
        int mn0 = ok( apos0[0] , bpos0[0] , 0 ) + 1;
        int mn1 = ok( apos1[0] , bpos1[0] , 1 ) + 1;
        if( mn0 <= mn1 ) cout << 0 , print( apos0[0] , bpos0[0] , 0 , mn0 - 1 );
        else cout << 1 , print( apos1[0] , bpos1[0] , 1 , mn1 - 1 );
        return 0;
}












