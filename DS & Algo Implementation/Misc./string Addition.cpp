#include <bits/stdc++.h>
using namespace std;

string Add( string a , string b ) {
        while( a.size() < b.size() ) a = '0' + a;
        while( b.size() < a.size() ) b = '0' + b;;
        string ret = "";
        int hand = 0;
        for( int i = a.size()-1; i >= 0; i-- ) {
                int x = a[i]-'0';
                int y = b[i]-'0';
                int tot = x + y + hand;
                if( tot >= 10 ) ret += ( ( tot%10 ) + '0' ) , hand = tot/10;
                else ret += ( tot+'0' ) , hand = 0;
        }
        if( hand > 0 ) ret += ( hand + '0' );
        reverse( ret.begin() , ret.end() );
        return ret;
}
int main( int argc , char const *argv[] ) {
        ios_base :: sync_with_stdio(false); cin.tie(NULL);
        cout << Add( "123" , "200" ) << endl;;
        return 0;
}






