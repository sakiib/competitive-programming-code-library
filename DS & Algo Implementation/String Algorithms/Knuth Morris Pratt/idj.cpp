#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef pair <int,int> pii;
typedef pair <long long,long long> pll;
const int MOD = 1e9 + 7;
const double EPS = 1e-8;
const int N = 1e5 + 5;
const int inf = 1e9;
const long long INF = 1e18;

/**
Number of times pattern #i occurs in l - r of text
*/

int n , q;
string txt;
string s[ 55 ];
vector <pii> V[ 55 ];

vector <int> prefix_function( string &s ) {
        int n = (int)s.size( );
        vector <int> pi( n );
        for ( int i = 1; i < n; i++ ) {
                int j = pi[i-1];
                while ( j > 0 && s[i] != s[j] ) j = pi[j-1];
                if ( s[i] == s[j] ) j++;
                pi[i] = j;
        }
        return pi;
}
void KMP( string &text , string &pattern , int id ) {
        int lt = text.size( ) , lp = pattern.size( );
        vector <int> pi = prefix_function( pattern );
        int i = 1 , j = 0 , ret = 0;
        while( i < lt ) {
                if( pattern[j] == text[i] ) i++ , j++;
                if( j == lp ) {
                        int pos = i-1;
                        V[id].push_back( {pos-lp+1,pos} );
                        j = pi[j-1];
                }
                else if( i < lt && pattern[j] != text[i] ) {
                        if( j != 0 ) j = pi[j-1];
                        else i++;
                }
        }
}
int getans( int id , int l , int r ) {
        if( V[id].size() == 0 ) return 0;
        int lo = 0 , hi = V[id].size() - 1 , x = -1 , y = -1;
        while( lo <= hi ) {
                int mid = ( lo + hi ) >> 1;
                if( V[id][mid].first >= l ) x = mid , hi = mid - 1;
                else lo = mid + 1;
        }
        lo = 0 , hi = V[id].size() - 1;
        while( lo <= hi ) {
                int mid = ( lo + hi ) >> 1;
                if( V[id][mid].second <= r ) y = mid , lo = mid + 1;
                else hi = mid - 1;
        }
        if( x == -1 || y == -1 ) return 0;
        if( x > y ) return 0;
        return y - x + 1;
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( nullptr );
        #ifdef forthright48
            freopen( "input.txt" , "r" , stdin );
        #endif // forthright48
        cin >> txt;
        txt = "#" + txt;
        cin >> n >> q;
        for( int i = 1; i <= n; i++ ) cin >> s[i];
        for( int i = 1; i <= n; i++ ) KMP( txt , s[i] , i );
        while( q-- ) {
                int id , l , r;
                cin >> id >> l >> r;
                cout << getans( id , l , r ) << endl;
        }
        return 0;
}











