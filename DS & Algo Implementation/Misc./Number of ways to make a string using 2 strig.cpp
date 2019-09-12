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

string a , b , c;
int la , lb , lc;
LL dp[ 65 ][ 65 ][ 65 ];

LL solve( int x , int y , int z ) {
        if( z >= lc ) return 1;
        if( x >= la && y >= lb ) return 0;
        if( dp[x][y][z] != -1 ) return dp[x][y][z];
        LL ret = 0;
        for( int i = x; i < la; i++ ) {
                if( a[i] == c[z] ) ret += solve( i + 1 , y , z + 1 );
        }
        for( int i = y; i < lb; i++ ) {
                if( b[i] == c[z] ) ret += solve( x , i + 1 , z + 1 );
        }
        return dp[x][y][z] = ret;
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( NULL );
        int t;
        cin >> t;
        while( t-- ) {
                cin >> a >> b >> c;
                la = a.size();
                lb = b.size();
                lc = c.size();
                memset( dp , -1 , sizeof( dp ) );
                cout << solve( 0 , 0 , 0 ) << endl;
        }
        return 0;
}










