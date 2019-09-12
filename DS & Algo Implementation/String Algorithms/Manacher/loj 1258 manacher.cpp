#include <bits/stdc++.h>
using namespace std;

const int sz = 1e6 + 5;
int P[ 2*sz + 5 ];// must be atleast 2 times of string s.

/*
string Convert( string s ) {
        string ret = "@";
        int len = s.size();
        for( int i = 0; i < len; i++ ) ret += "#" + s.substr( i , 1 );
        ret += "#$";
        return ret;
}*/

string convert( string s ) {
        char ret[ 2*sz + 5 ];
        int id = 0 , len = s.size();
        ret[ id++ ] = '@';
        for( int i = 0; i < len; i++ ) ret[ id++ ] = '#', ret[ id++ ] = s[i];
        ret[ id++ ] = '#' , ret[ id++ ] = '$' , ret[ id ] = '\0';
        string cur = ret;
        return cur;
}
void Manacher( string s ) {
        memset( P , 0 , sizeof( P ) );
        string Q = convert( s );
        int c = 0 , r = 0;
        for( int i = 1; i < Q.size() - 1; i++ ) {
                int imir = c - ( i - c );
                if( r > i ) P[i] = min( r - i , P[ imir ] );
                while( Q[ i + 1 + P[i] ] == Q[ i - 1 - P[i] ] ) P[i]++;
                if( i + P[i] > r ) c = i , r = i + P[i];
        }
        int pos = Q.size() - 2;
        int mx = 0;
        for( int i = 1; i < Q.size() - 1; i++ ) {
                if( P[i] == 0 ) continue;
                if( P[i] + i == pos ) mx = max( mx , P[i] );
        }
        cout << s.size() + s.size() - mx << endl;
}
int main( int argc , char const *argv[] ) {
        ios_base :: sync_with_stdio(false); cin.tie(NULL);
        int t;
        cin >> t;
        for( int tc = 1; tc <= t; tc++ ) {
                cout << "Case " << tc << ": ";
                string s;
                cin >> s;
                Manacher( s );
        }
        return 0;
}
