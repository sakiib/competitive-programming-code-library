#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 2e6 + 6;
const int MOD[2] = { 1000000009 , 1000000007 };
const int Base[2] = { 43 , 37 };
LL Pow[ N ][ 2 ];

void genPow( ) {
        Pow[0][0] = 1 , Pow[0][1] = 1;
        for( int i = 1; i < N; i++ ) {
                Pow[i][0] = ( Pow[i-1][0] * Base[0] ) % MOD[0];
                Pow[i][1] = ( Pow[i-1][1] * Base[1] ) % MOD[1];
        }
}
LL getFHash( string s ) {
        int len = s.size();
        LL hash1 = 0 , hash2 = 0;
        for( int i = 0; i < len; i++ ) {
                hash1 += ( Pow[i][0] * s[i] ) % MOD[0] , hash1 %= MOD[0];
                hash2 += ( Pow[i][1] * s[i] ) % MOD[1] , hash2 %= MOD[1];
        }
        return ( hash1 << 31 ) | hash2;
}
LL getBHash( string s ) {
        int len = s.size();
        LL hash1 = 0 , hash2 = 0;
        for( int i = len - 1; i >= 0; i-- ) {
                hash1 += ( Pow[len-1-i][0] * s[i] ) % MOD[0] , hash1 %= MOD[0];
                hash2 += ( Pow[len-1-i][1] * s[i] ) % MOD[1] , hash2 %= MOD[1];
        }
        return ( hash1 << 31 ) | hash2;
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( NULL );
        genPow( );
        string x = "am";
        cout << getFHash( x ) << " " << getBHash( x ) << endl;

        /// restoring original hashes..
        LL mod = ( 1LL << 31 );
        string a = "abcdydedyegdvyed";
        LL Hash = getFHash( a ); /// ( hash1 << 31 ) | hash2
        LL bb = Hash%mod; /// hash2
        LL c = ( Hash^bb );
        LL cc = ( c >> 31 ); /// hash1
        cout << cc << " " << bb << endl; /// hash1 & hash2

        return 0;
}











