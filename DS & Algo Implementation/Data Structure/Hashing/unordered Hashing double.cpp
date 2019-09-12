#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
const int N = 1e5 + 5;

const int MOD[] = { 1e9 + 7 , 1e9 + 9 };
const int Base[] = { 31 , 37 };
LL P[ N ][ 2 ];

void genPow( ) {
        P[0][1] = P[0][0] = 1;
        for( int i = 1; i < N; i++ ) {
                P[i][0] = ( P[i-1][0] * Base[0] ) % MOD[0];
                P[i][1] = ( P[i-1][1] * Base[1] ) % MOD[1];
        }
}
pair <LL,LL> getHash( string s ) {
        int l = s.size();
        LL Hash1 = 0 , Hash2 = 0;
        for( int i = 0; i < l; i++ ) {
                Hash1 += ( s[i] % MOD[0] * P[ s[i] ][0] % MOD[0] ) % MOD[0];
                Hash2 += ( s[i] % MOD[1] * P[ s[i] ][1] % MOD[1] ) % MOD[1];
        }
        return make_pair( Hash1 , Hash2 );
}
int main( int argc , char const *argv[] ) {
        genPow();
        string a = "aabcccz";
        string b = "zaacbcc";
        string c = "abzaccc";
        string d = "abcazcc";
        string e = "aczccab";
        string f = "acbzcca";
        cout << getHash( a ).first << " "<< getHash( a ).second << endl;
        cout << getHash( b ).first << " "<< getHash( b ).second << endl;
        cout << getHash( c ).first << " "<< getHash( c ).second << endl;
        cout << getHash( d ).first << " "<< getHash( d ).second << endl;
        cout << getHash( e ).first << " "<< getHash( e ).second << endl;
        cout << getHash( f ).first << " "<< getHash( f ).second << endl;
        return 0;
}








