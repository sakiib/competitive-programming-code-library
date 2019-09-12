#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
typedef pair <int,int> pii;
const int inf = 1e9;
const LL INF = 1e18;
const int N = 1e5 + 5;
const int mod = 1000000007;
const double eps = 1e-8;
const double pi = acos( -1.0 );

/**
0 based index
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
int KMP( string text , string pattern ) {
        int lt = text.size( ) , lp = pattern.size( );
        vector <int> pi = prefix_function( pattern );
        int i = 0 , j = 0 , ret = 0;
        while( i < lt ) {
                if( pattern[j] == text[i] ) i++ , j++;
                if( j == lp ) {
                        ret++;
                        j = pi[j-1];
                        /// i++; // for non-overlapping substring
                }
                else if( i < lt && pattern[j] != text[i] ) {
                        if( j != 0 ) j = pi[j-1];
                        else i++;
                }
        }
        return ret;
}

/**
int KMP( string &text , string &pattern , int pos ) {
        int lt = text.size( ) , lp = pattern.size( );
        vector <int> pi = prefix_function( pattern );
        int i = pos , j = 0 , ret = 0;
        while( i < lt ) {
                if( pattern[j] == text[i] ) i++ , j++;
                if( j == lp ) {
                        return i; /// first pos + 1 of txt where pattern mathces
                        j = pi[j-1];
                }
                else if( i < lt && pattern[j] != text[i] ) {
                        if( j != 0 ) j = pi[j-1];
                        else i++;
                }
        }
        return -1;
}
*/

/**
 1 based index
 */

int Failure[ N ];

void Failure_Function( string pattern , int lp ) {
        Failure[0] = Failure[1] = 0;
        for( int i = 2; i <= lp; i++ ) {
                int j = Failure[i-1];
                while( true ) {
                        if( pattern[j] == pattern[i-1] ) {
                                Failure[i] = j+1;
                                break;
                        }
                        if( j == 0 ) {
                                Failure[i] = 0;
                                break;
                        }
                        j = Failure[j];
                }
        }
}
bool KMP( string text , string pattern ) {
        int lt = text.size( ) , lp = pattern.size( );
        Failure_Function( pattern , lp );
        //for( int i = 1; i <= lp; i++ ) cout << Failure[i] << " "; cout << endl;
        int i = 0 , j = 0;
        while( true ) {
                if( j == lt ) return false;
                if( text[j] == pattern[i] ) {
                        i++ , j++;
                        if( i == lp ) return true;
                }
                else {
                        if( i == 0 ) j++;
                        else i = Failure[i];
                }
        }
        return false;
}
int main( int argc , char const *argv[] ) {
        ios_base :: sync_with_stdio(false); cin.tie(NULL);
        string text , pattern;
        cin >> text >> pattern;
        cout << ( KMP( text , pattern ) == 1 ? "YES" : "NO" )  << endl;
        return 0;
}






