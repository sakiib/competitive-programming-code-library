#include <bits/stdc++.h>
#include <ext/rope>

using namespace std;
using namespace __gnu_cxx;

/**
rope <char> V;
        V.append( "abc" );
        cout << V << endl;
        V.append( "xyz" ); /// last e jora
        cout << V << endl;
        V.insert( 3 , "PQ" ); /// at pos 3
        cout << V << endl;
        cout << V.substr( 1 , 5 ) << endl; /// start at 1( 0 based ) , len 5
        V.erase( 4 , 2 ); /// 4 pos theke 2 len
        cout << V << endl;
*/
int main( ) {
        ios_base::sync_with_stdio(false); cin.tie(NULL);
        rope <char> V;
        string s;
        cin >> s;
        for( char ch : s ) V.push_back( ch );
        string op;
        while( cin >> op ) {
                if( op == "END" ) break;
                if( op == "I" ) {
                        string cur;
                        int pos;
                        cin >> cur >> pos;
                        for( int i = 0; i < cur.size(); i++ ) {
                                V.insert( pos + i , cur[i] );
                        }
                }
                if( op == "P" ) {
                        int l , r;
                        cin >> l >> r;
                        cout << V.substr( l , r - l + 1 ) << "\n";
                }
        }
        return 0;
}
