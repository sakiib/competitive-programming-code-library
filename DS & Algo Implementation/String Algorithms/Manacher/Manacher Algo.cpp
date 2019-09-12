#include <bits/stdc++.h>
using namespace std;

const int sz = 1e5 + 5; /// max string len
int P[ 2*sz + 5 ]; /// must be atleast 2 times of string s.

string Convert( string s ) {
        string ret = "@";
        for( int i = 0; i < s.size(); i++ ) ret += "#" + s.substr( i , 1 );
        ret += "#$";
        return ret;
}
string convert( string s ) { /// works faster than the above one.
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
        cout << "Converted string : " << Q << endl;
        int c = 0 , r = 0;
        for( int i = 1; i < Q.size() - 1; i++ ) {
                int imir = c - ( i - c );
                if( r > i ) P[i] = min( r - i , P[ imir ] );
                while( Q[ i + 1 + P[i] ] == Q[ i - 1 - P[i] ] ) P[i]++;
                if( i + P[i] > r ) c = i , r = i + P[i];
        }
        int mx_pal = 0 , cen_idx = 0;
        for( int i = 1; i < Q.size() - 1; i++ ) {
                if( P[i] > mx_pal ) mx_pal = P[i] , cen_idx = i;
        }

        cout << "Max Length of palindrome : " << mx_pal << endl;
        cout << "MAX centered at : " << cen_idx << endl;

        cout << "MAX sub_String : " << s.substr( (cen_idx - mx_pal)/2 , mx_pal ) << endl;
        for( int i = 1; i < Q.size() - 1; i++ ) cout << P[i] << " ";
}
int main( int argc , char const *argv[] ) {
        string s = "yyyxxxx";
        Manacher( s );
        return 0;
}







