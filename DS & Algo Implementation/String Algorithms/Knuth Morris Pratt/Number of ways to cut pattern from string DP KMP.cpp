#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 3e5 + 5;
const int MOD = 1e9 + 7;

bool found[ N ];
LL dp[ N ][ 2 ];
int n , m;

vector <int> prefix_function( string &s ) {
        int n = (int)s.size();
        vector <int> pi( n );
        pi[0] = 0;
        for ( int i = 1; i < n; i++ ) {
                int j = pi[i-1];
                while ( j > 0 && s[i] != s[j] ) j = pi[j-1];
                if ( s[i] == s[j] ) j++;
                pi[i] = j;
        }
        return pi;
}
void KMP( string text , string pattern ) {
        int lt = text.size( ) , lp = pattern.size( );
        vector <int> pi = prefix_function( pattern );
        int i = 0 , j = 0;
        while( i < lt ) {
                if( pattern[j] == text[i] ) i++ , j++;
                if( j == lp ) {
                        found[i-1] = true; /// pattern Ending pos
                        j = pi[j-1];
                }
                else if( i < lt && pattern[j] != text[i] ) {
                        if( j != 0 ) j = pi[j-1];
                        else i++;
                }
        }
}
LL solve( int idx , int taken ) {
        if( idx >= n ) return taken ? 1 : 0;
        if( dp[idx][taken] != -1 ) return dp[idx][taken];
        LL ret = 0;
        if( found[idx] ) {
                ret += solve( idx + 1 , taken ) + solve( idx + m , 1 );
                ret %= MOD;
        }
        else ret += solve( idx + 1 , taken ) , ret %= MOD;
        return dp[idx][taken] = ret%MOD;
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( NULL );
        int t;
        cin >> t;
        while( t-- ) {
                string text , pattern;
                cin >> text >> pattern;
                n = text.size();
                m = pattern.size();
                memset( found , false , sizeof( found ) );
                memset( dp , -1 , sizeof( dp ) );
                KMP( text , pattern );
                cout << solve( 0 , 0 ) << endl;
        }
        return 0;
}










