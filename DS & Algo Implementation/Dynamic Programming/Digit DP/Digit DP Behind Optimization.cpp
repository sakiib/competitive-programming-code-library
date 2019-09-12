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

LL a , b;
int k;
LL dp[ 20 ][ 1 << 10 ][ 2 ][ 2 ];
int dig[ 20 ];

int calc( int cur , int d ) {
        for( int i = d; i <= 9; i++ ) {
                if( cur&( 1 << i ) ) return (cur^(1<<i)|(1<<d));
        }
        return cur|(1<<d);
}
LL go( int idx , int mask , bool lead , bool tight ) {
        if( idx == -1 ) return __builtin_popcount( mask ) == k;
        if( !tight && !lead && dp[idx][mask][lead][tight] != -1 ) return dp[idx][mask][lead][tight];
        LL ret = 0;
        int up = tight ? dig[idx] : 9;
        for( int i = 0; i <= up; i++ ) {
                ret += go( idx - 1 , lead&&i == 0 ? 0 : calc( mask , i ) , lead&&(i==0) , tight&&(dig[idx]==i) );
        }
        if( !tight ) dp[idx][mask][lead][tight] = ret;
        return ret;
}
LL solve( LL x ) {
        int len = 0;
        while( x ) dig[len++] = x%10 , x/= 10;
        return go( len - 1 , 0 , 1 , 1 ); /// len-1 , mask , lead , tight
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( nullptr );
        int t;
        cin >> t;
        memset( dp , -1 , sizeof( dp ) );
        for( int tc = 1; tc <= t; tc++ ) {
                cin >> a >> b >> k;
                cout << "Case #" << tc << ": ";
                cout << solve( b ) - solve( a - 1 ) << endl;
        }
        return 0;
}











