#include <bits/stdc++.h>
using namespace std;


// z[i] = the length of the longest common prefix between s and the suffix of s starting at i.
// z[i] = longest substring starting at i'th position which is also a prefix prefix of the string

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
        string s = "abcabcabc";
        vector <int> z = z_function( s );
        for( int i = 0; i < z.size(); i++ ) cout << i << " " << z[i] << endl;
        return 0;
}












