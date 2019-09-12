#include <bits/stdc++.h>
using namespace std;

#define Fast_IO ios_base::sync_with_stdio(0); cin.tie(0);

/// longest suffix which is also a prefix ( 0 based )
/// we don't consider the whole string
/// this works only to check for full match , for partial match use other one.

/**
const int N = 1e5 + 5;
int pi[ N ];
void prefix_function( string &s ) {
        int n = (int)s.size();
        pi[0] = 0;
        for ( int i = 1; i < n; i++ ) {
                int j = pi[i-1];
                while ( j > 0 && s[i] != s[j] ) j = pi[j-1];
                if ( s[i] == s[j] ) j++;
                pi[i] = j;
        }
}
*/
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
vector <int> find_occurences( string &text , string &pattern ) {
        string cur = pattern + '#' + text;
        int sz1 = text.size(), sz2 = pattern.size();
        vector <int> v;
        vector <int> lps = prefix_function( cur );
        for(int i = sz2 + 1; i <= sz1 + sz2; i++ ) {
                if( lps[i] == sz2 ) v.push_back( i - 2 * sz2 ); /// positions
        }
        return v;
}
int KMP( string &text , string &pattern ) {
        int lt = text.size( ) , lp = pattern.size( );
        vector <int> pi = prefix_function( pattern );
        int i = 0 , j = 0 , ret = 0;
        while( i < lt ) {
                if( pattern[j] == text[i] ) i++ , j++;
                if( j == lp ) {
                        ret++;
                        j = pi[j-1];
                }
                else if( i < lt && pattern[j] != text[i] ) {
                        if( j != 0 ) j = pi[j-1];
                        else i++;
                }
        }
        return ret;
}
/// If text & patterns are numbers.
vector <int> prefix_function( vector<int> &v )  {
        int n = (int)v.size();
        vector <int> pi( n );
        for ( int i = 1; i < n; i++ ) {
                int j = pi[i-1];
                while ( j > 0 && v[i] != v[j] ) j = pi[j-1];
                if ( v[i] == v[j] ) j++;
                pi[i] = j;
        }
        return pi;
}
/// returns each match position.
vector <int> find_occurences( vector<int> &text , vector<int> &pattern ) {
        vector <int> v = pattern;
        v.push_back( -1 );
        for( auto &it : text ) v.push_back( it );
        int sz1 = text.size() , sz2 = pattern.size();
        vector <int> lps = prefix_function( v );
        vector <int> store;
        for( int i = sz2 + 1; i <= sz1 + sz2; i++ ) {
                if( lps[i] == sz2 ) store.push_back( i - 2 * sz2 );
        }
        return store;
}
int main( int argc , char const *argv[] ) {
        string text , pattern;
        cin >> text >> pattern;
        vector <int> V =  find_occurences( text , pattern );
        for( auto x : V ) cout << x << " ";
        return 0;
}








