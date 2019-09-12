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

int dig[ 20 ];
LL dp[ 20 ][ 2 ][ 2 ][ 1<<10 ];

bool ok( int mask ) {
        int mx = -1 , dist = 0;
        for( int i = 0; i <= 9; i++ ) if( mask&(1<<i) ) dist++ , mx = max( mx , i );
        return dist == mx;
}
LL go( int idx , int lead , int tight , int mask ) {
        if( idx == -1 ) return !lead && ok(mask);
        if( !lead && !tight && dp[idx][lead][tight][mask] != -1 ) return dp[idx][lead][tight][mask];
        LL ret = 0;
        int limit = tight ? dig[idx] : 9;
        for( int i = 0; i <= limit; i++ ) {
                ret += go( idx - 1, lead&&(i==0), tight&&(i==dig[idx]), (lead&&i==0) ? mask: mask|(1<<i) );
        }
        if( !tight ) dp[idx][lead][tight][mask] = ret;
        return ret;
}
LL solve( LL n ) {
        int len = 0;
        while( n ) dig[len++] = n%10 , n /= 10;
        return go( len-1 , 1 , 1 , 0 );
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( nullptr );
        int t;
        cin >> t;
        memset( dp , -1 , sizeof( dp ) );
        while( t-- ) {
                LL n;
                cin >> n;
                cout << solve( n ) << endl;
        }
        return 0;
}











