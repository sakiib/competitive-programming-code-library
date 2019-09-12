#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
string text , pattern;
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
int KMP( string text , string pattern ) {
        int lt = text.size( ) , lp = pattern.size( );
        Failure_Function( pattern , lp );
        int i = 0 , j = 0 , ret = 0;
        while( true ) {
                if( j == lt ) return ret;
                if( text[j] == pattern[i] ) {
                        i++ , j++;
                        if( i == lp ) {
                                ret++;
                                i++;
                        }
                }
                else {
                        if( i == 0 ) j++;
                        else i = Failure[i];
                }
        }
        return 0;
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( NULL );
        while( cin >> text ) {
                if( text == "#" ) break;
                cin >> pattern;
                int ans = KMP( text , pattern );
                cout << ans <<endl;
        }
        return 0;
}








