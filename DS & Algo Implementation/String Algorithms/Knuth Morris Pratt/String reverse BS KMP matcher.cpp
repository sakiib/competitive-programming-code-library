#include <bits/stdc++.h>
using namespace std;

vector <int> prefix_function( string &s ) {
        int n = (int)s.size();
        vector <int> pi( n );
        for ( int i = 1; i < n; i++ ) {
                int j = pi[i-1];
                while ( j > 0 && s[i] != s[j] ) j = pi[j-1];
                if ( s[i] == s[j] ) j++;
                pi[i] = j;
        }
        return pi;
}
bool ok( string &text , string &pattern ) {
        string cur = pattern + '#' + text;
        int sz1 = text.size(), sz2 = pattern.size();
        vector <int> v;
        vector <int> lps = prefix_function( cur );
        for(int i = sz2 + 1;i <= sz1 + sz2; i++ ) {
                if( lps[i] == sz2 ) return true;
        }
        return false;
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( NULL );
        int t;
        cin >> t;
        while( t-- ) {
                string s;
                cin >> s;
                int len = s.size();
                int lo = 0 , hi = len;
                string ans = "";
                while( lo <= hi ) {
                        int mid = ( lo + hi ) >> 1;
                        string t( s.begin() , s.begin() + mid );
                        reverse( t.begin() , t.end() );
                        if( ok( s , t ) ) ans = t , lo = mid + 1;
                        else hi = mid - 1;
                }
                cout << ans << endl;
        }
        return 0;
}











