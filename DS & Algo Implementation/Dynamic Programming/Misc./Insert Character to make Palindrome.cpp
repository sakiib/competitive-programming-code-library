#include <bits/stdc++.h>
using namespace std;

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

string s;
int len;
int dp[ 105 ][ 105 ];

int go( int x , int y ) {
        if( x >= y ) return 0;
        if( dp[x][y] != -1 ) return dp[x][y];
        int ret = inf;
        if( s[x] == s[y] ) ret = min( ret , go( x + 1 , y - 1 ) );
        else {
                ret = min( ret , min( 1+go( x + 1 , y ) , 1+go( x , y - 1 ) ) );
        }
        return dp[x][y] = ret;
}
void solve( ) {
        cin >> s;
        len = s.size();
        memset( dp , -1 , sizeof( dp ) );
        cout << go( 0 , len - 1 ) << endl;
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( NULL );
        int t;
        cin >> t;
        for( int tc = 1; tc <= t; tc++ ) {
                cout << "Case " << tc << ": ";
                solve( );
        }
        return 0;
}











