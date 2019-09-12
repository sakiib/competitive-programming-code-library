#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
const int N = 1e5 + 5;

const int Base = 31;
const int MOD = 1e9 + 7;

LL P[ N ];

void genPow( ) {
        P[0] = 1;
        for( int i = 1; i < N; i++ ) P[i] = ( P[i-1] * Base ) % MOD;
}
LL getHash( string s ) {
        int l = s.size();
        LL Hash = 0;
        for( int i = 0; i < l; i++ ) Hash += ( s[i] % MOD * P[ s[i] ] % MOD ) % MOD;
        return Hash;
}
int main( int argc , char const *argv[] ) {
        genPow();
        string a = "abc";
        string b = "acb";
        string c = "bac";
        string d = "bca";
        string e = "cab";
        string f = "cba";
        cout << getHash( a ) << endl;
        cout << getHash( b ) << endl;
        cout << getHash( c ) << endl;
        cout << getHash( d ) << endl;
        cout << getHash( e ) << endl;
        cout << getHash( f ) << endl;
        return 0;
}







