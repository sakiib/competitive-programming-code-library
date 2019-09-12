#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;

int len;
string s;
int dp[ 1000 ][ 5 ];

int solve( int idx , int put ) {
        if( idx >= len ) return 0;
        if( dp[idx][put] != -1 ) return dp[idx][put];
        int ret = inf;
        if( put ) {
                ret = min( solve( idx + 2 , 1 ) + 1 , solve( idx + 1 , 0 ) );
        }
        else {
                if( s[idx-1] == '.' ) ret = min( ret , solve( idx + 2 , 1 ) + 1 );
                else ret = min( ret , solve( idx + 1 , 0 ) );
        }
        return dp[idx][put] = ret;
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( nullptr );
        int t;
        cin >> t;
        for( int tc = 1; tc <= t; tc++ ) {
                cin >> len >> s;
                s = "#" + s;
                s += "#";
                len = s.size();
                cout << "Case " << tc << ": ";
                memset( dp , -1 , sizeof( dp ) );
                int ans = min( 1 + solve( 3 , 1 ) , solve( 2 , 0 ) );
                cout << ans << endl;
        }
        return 0;
}

