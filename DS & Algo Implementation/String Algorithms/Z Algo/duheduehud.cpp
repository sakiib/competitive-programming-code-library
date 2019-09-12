#include <bits/stdc++.h>
using namespace std;

/**
if a prefix occurs in S more often as a substring,
then the probability that this prefix is the secret password is higher
(the probability that a chosen prefix is the secret password is an increasing
function of its number of occurrences in S)

if two prefixes have the same number of occurrences in S,
then the longer prefix has a higher probability of being the secret password
*/

const int N = 1e5 + 5;
int cnt[ N ];

vector <int> z_function( string &s ) {
        int n = (int)s.size( );
        vector<int> z( n );
        for( int i = 1 , l = 0 , r = 0; i < n; i++ ) {
                if( i <= r ) z[i] = min( r - i + 1 , z[i-l] );
                while( i + z[i] < n && s[z[i]] == s[i+z[i]] ) z[i]++;
                if( i + z[i] - 1 > r ) l = i , r = i + z[i] - 1;
        }
        return z;
}
int main( int argc , char const *argv[] ) {
        int t;
        cin >> t;
        while( t-- ) {
                int n;
                string s;
                cin >> n >> s;
                vector <int> z = z_function( s );
                memset( cnt , 0 , sizeof( cnt ) );
                int len = 2*N;
                for( int i = 0; i < z.size(); i++ ) if( z[i] > 0 ) len = min( len , z[i] );
                if( len == 0 ) cout << s << endl;
                else cout << s.substr( 0 , len ) << endl;
        }
        return 0;
}






