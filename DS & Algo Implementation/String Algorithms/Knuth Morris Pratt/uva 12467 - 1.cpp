#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

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
        ios_base::sync_with_stdio( false ); cin.tie( NULL );
        int t;
        cin >> t;
        while( t-- ) {
                string s;
                cin >> s;
                int len = s.size();
                int lo = 1 , hi = len;
                string ans = "";
                while( lo <= hi ) {
                        int mid = ( lo + hi ) >> 1;
                        string t( s.begin() , s.begin() + mid );
                        //cout << t << endl;
                        reverse( t.begin() , t.end() );
                        if( KMP( s , t ) ) ans = t , lo = mid + 1;
                        else hi = mid - 1;
                }
                cout << ans << endl;
        }
        return 0;
}














