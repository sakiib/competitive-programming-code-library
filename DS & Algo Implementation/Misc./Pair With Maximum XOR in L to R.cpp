#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template <typename T> using
Treap = tree <T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef unsigned long long uLL;
typedef long long int LL;
typedef pair <int,int> pii;
typedef pair <long long,long long> pll;
const int N = 1e5 + 5;
const int inf = 1e9;
const long long INF = 1e18;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int MOD = 1000000007;

LL l , r;
string a , b;
LL dp[ 65 ][ 2 ][ 2 ][ 2 ][ 2 ];

string DecToBin( LL n ) {
        string s = "";
        while( n ) s += ( n%2 + '0' ) , n /= 2;
        reverse( s.begin() , s.end() );
        while( s.size() < 64 ) s = '0' + s;
        return s;
}
LL solve( int idx , int fl1 , int fl2 , int fr1 , int fr2 ) {
        if( idx >= 64 ) return 0LL;
        if( dp[idx][fl1][fl2][fr1][fr2] != -1 ) return dp[idx][fl1][fl2][fr1][fr2];
        int min1 = 0 , max1 = 1 , min2 = 0 , max2 = 1;
        if( fl1 == 0 && a[idx] == '1' ) min1 = 1;
        if( fl2 == 0 && b[idx] == '0' ) max1 = 0;
        if( fr1 == 0 && a[idx] == '1' ) min2 = 1;
        if( fr2 == 0 && b[idx] == '0' ) max2 = 0;
        LL ret = 0;
        for( int i = min1; i <= max1; i++ ) {
                for( int j = min2; j <= max2; j++ ) {
                        int v = ( i^j );
                        LL add = 0;
                        if ( v ) add = ( 1LL << ( 63 - idx ) );
                        int nfl1 = fl1 , nfl2 = fl2 , nfr1 = fr1 , nfr2 = fr2;
                        if( i > a[idx] - '0' ) nfl1 = 1;
                        if( i < b[idx] - '0' ) nfl2 = 1;
                        if( j > a[idx] - '0' ) nfr1 = 1;
                        if( j < b[idx] - '0' ) nfr2 = 1;
                        ret = max( ret , add + solve( idx + 1 , nfl1 , nfl2 , nfr1 , nfr2 ) );
                }
        }
        return dp[idx][fl1][fl2][fr1][fr2] = ret;
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( NULL );
        cin >> l >> r;
        a = DecToBin( l );
        b = DecToBin( r );
        memset( dp , -1 , sizeof( dp ) );
        cout << solve( 0 , 0 , 0 , 0 , 0 ) << endl;
        return 0;
}













