#include <bits/stdc++.h>
using namespace std;

#define Fast_IO ios_base::sync_with_stdio(0); cin.tie(0);

string s;
int n;
int len;
int dp[ 1005 ][ 1005 ];

int ok( int pos , int val ) {
        if( pos >= len ) return ( val%n == 0 ? 1 : 0 );
        int ret = 0;
        if( dp[pos][val] != -1 ) return dp[pos][val];
        if( s[pos] == '?' ) {
                for( int i = 0 + ( pos == 0 ); i <= 9; i++ ) {
                        ret |= ok( pos+1 , (val*10%n+i)%n );
                }
        }
        else {
               ret |= ok( pos+1 , (val*10%n+(s[pos]-'0') )%n );
        }
        return dp[pos][val] = ret;
}
void Print( int pos , int val ) {
        if( pos >= len ) {
                cout << endl;
                exit(0);
        }
        if( s[pos] != '?' ) {
                cout << s[pos];
                Print( pos + 1 , (val*10%n+(s[pos]-'0')%n ) );
        }
        else {
                for( int i = 0 + ( pos == 0 ); i <= 9; i++ ) {
                        if( ok( pos + 1 , (val*10+i)%n ) == 1 ) {
                                cout << i;
                                Print( pos + 1 , ( val*10%n+i)%n );
                                return;
                                /// Return coz we need only one answer
                                /// we need smallest answer so , uterate from 0 to 9
                                /// for maximum value we can go from 9 to 0
                        }
                }
        }
}
int main( int argc , char const *argv[] ) {
        Fast_IO;
        cin >> s >> n;
        len = s.size();
        memset( dp , -1 , sizeof(dp) );
        if( ok( 0 , 0 ) ) Print( 0 , 0 );
        else cout << "*" << endl;
        return 0;
}








