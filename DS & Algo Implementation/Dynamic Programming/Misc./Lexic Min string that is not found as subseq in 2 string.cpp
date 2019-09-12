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
int ca[ N ][ 2 ] , cb[ N ][ 2 ];
int dp[ N ][ N ][ 2 ];

int ok( int x , int y , int dig ) {
        if( x == -1 && y == -1 ) return 0;
        if( dp[x+1][y+1][dig] != -1 ) return dp[x+1][y+1][dig];
        int ret = inf;
        int ida0 = -1 , ida1 = -1;
        if( x != -1 ) {
                int lo = x + 1 , hi = a.size() - 1;
                while( lo <= hi ) {
                        int mid = ( lo + hi ) >> 1;
                        if( ca[mid][0] - ca[x][0] >= 1 ) ida0 = mid , hi = mid - 1;
                        else lo = mid + 1;
                }
                lo = x + 1 , hi = a.size() - 1;
                while( lo <= hi ) {
                        int mid = ( lo + hi ) >> 1;
                        if( ca[mid][1] - ca[x][1] >= 1 ) ida1 = mid , hi = mid - 1;
                        else lo = mid + 1;
                }
        }
        int idb0 = -1 , idb1 = -1;
        if( y != -1 ) {
                int l = y + 1 , r = b.size() - 1;
                while( l <= r ) {
                        int mid = ( l + r ) >> 1;
                        if( cb[mid][0] - cb[y][0] >= 1 ) idb0 = mid , r = mid - 1;
                        else l = mid + 1;
                }
                l = y + 1 , r = b.size() - 1;
                while( l <= r ) {
                        int mid = ( l + r ) >> 1;
                        if( cb[mid][1] - cb[y][1] >= 1 ) idb1 = mid , r = mid - 1;
                        else l = mid + 1;
                }
        }
        for( int i = 0; i <= 1; i++ ) {
                ret = min( ret , 1 + ok( i == 0 ? ida0 : ida1 , i == 0 ? idb0 : idb1 , i ) );
        }
        return dp[x+1][y+1][dig] = ret;
}
void print( int x , int y , int dig , int mn ) {
        if( x == -1 && y == -1 ) return;
        int ida0 = -1 , ida1 = -1;
        if( x != -1 ) {
                int lo = x + 1 , hi = a.size() - 1;
                while( lo <= hi ) {
                        int mid = ( lo + hi ) >> 1;
                        if( ca[mid][0] - ca[x][0] >= 1 ) ida0 = mid , hi = mid - 1;
                        else lo = mid + 1;
                }
                lo = x + 1 , hi = a.size() - 1;
                while( lo <= hi ) {
                        int mid = ( lo + hi ) >> 1;
                        if( ca[mid][1] - ca[x][1] >= 1 ) ida1 = mid , hi = mid - 1;
                        else lo = mid + 1;
                }
        }
        int idb0 = -1 , idb1 = -1;
        if( y != -1 ) {
                int l = y + 1 , r = b.size() - 1;
                while( l <= r ) {
                        int mid = ( l + r ) >> 1;
                        if( cb[mid][0] - cb[y][0] >= 1 ) idb0 = mid , r = mid - 1;
                        else l = mid + 1;
                }
                l = y + 1 , r = b.size() - 1;
                while( l <= r ) {
                        int mid = ( l + r ) >> 1;
                        if( cb[mid][1] - cb[y][1] >= 1 ) idb1 = mid , r = mid - 1;
                        else l = mid + 1;
                }
        }
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
        for( int i = 1; i < a.size(); i++ ) {
                for( int j = 0; j <= 1; j++ ) {
                        ca[i][j] += ca[i-1][j] + ( j == ( a[i] - '0' ) );
                }
        }
        for( int i = 1; i < b.size(); i++ ) {
                for( int j = 0; j <= 1; j++ ) {
                        cb[i][j] += cb[i-1][j] + ( j == ( b[i] - '0' ) );
                }
        }
        memset( dp , -1 , sizeof( dp ) );
        int ida0 = -1 , ida1 = -1 , idb0 = -1 , idb1 = -1;
        for( int i = 1; i < a.size(); i++ ) {
                if( a[i] == '0' ) {
                        ida0 = i;
                        break;
                }
        }
        for( int i = 1; i < a.size(); i++ ) {
                if( a[i] == '1' ) {
                        ida1 = i;
                        break;
                }
        }
        for( int i = 1; i < b.size(); i++ ) {
                if( b[i] == '0' ) {
                        idb0 = i;
                        break;
                }
        }
        for( int i = 1; i < b.size(); i++ ) {
                if( b[i] == '1' ) {
                        idb1 = i;
                        break;
                }
        }
        int mn0 = ok( ida0 , idb0 , 0 ) + 1;
        int mn1 = ok( ida1 , idb1 , 1 ) + 1;
        if( mn0 <= mn1 ) {
                cout << 0;
                print( ida0 , idb0 , 0 , mn0 - 1 );
        }
        else {
                cout << 1;
                print( ida1 , idb1 , 1 , mn1 - 1 );
        }
        return 0;
}












