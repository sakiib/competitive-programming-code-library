#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
string s;
int dp[ N ];

void solve( ) {
        memset( dp , 0 , sizeof( dp ) );
        int len = s.size();
        for( int i = len - 1; i >= 0; i-- ) {
                int add = dp[i+1];
                int j = i + add + 1;
                if( s[i] == '(' ) {
                        if( j < len && s[j] == ')' ) dp[i] = add + dp[j+1] + 2;
                }
                else if( s[i] == '{' ) {
                        if( j < len && s[j] == '}' ) dp[i] = add + dp[j+1] + 2;
                }
                else if( s[i] == '[' ) {
                        if( j < len && s[j] == ']' ) dp[i] = add + dp[j+1] + 2;
                }
                else if( s[i] == '<' ) {
                        if( j < len && s[j] == '>' ) dp[i] = add + dp[j+1] + 2;
                }
        }
        for( int i = 0; i < len; i++ ) cout << dp[i] << endl;
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( NULL );
        int t;
        cin >> t;
        for( int tc = 1; tc <= t; tc++ ) {
                cout << "Case " << tc << ":" <<endl;
                cin >> s;
                solve( );
        }
        return 0;
}











