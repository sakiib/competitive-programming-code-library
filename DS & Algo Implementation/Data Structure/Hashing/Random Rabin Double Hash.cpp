#include <bits/stdc++.h>
using namespace std;

std::mt19937 rng( chrono::steady_clock::now().time_since_epoch().count() );
#define ran(a, b) rng() % ( (b) - (a) + 1 ) + (a)

const int N = 1e5 + 5;
typedef long long LL;

int Mod[ 2 ] = { 1000000007 , 1000000009 };
int Base[ 2 ] = { 37 , 43 };
int mod1[] = { 1000000007 , 1000000009 , 1000000021 , 1000000033 , 1000000087 };
int mod2[] = { 1000000093 , 1000000097 , 1000000103 , 1000000123 , 1000000181 };
int base1[] = { 23 , 29 , 31 , 37 , 41 };
int base2[] = { 43 , 47 , 53 , 59 , 61 , 67 };

char s[ N ];
LL Pow[ N ][ 2 ];
LL HashF[ N ][ 2 ] , HashR[ N ][ 2 ];
int len;

inline void build_hash( ) {
        len = strlen( s );
        HashF[0][0] = 0 , HashR[len+1][0] = 0;
        HashF[0][1] = 0 , HashR[len+1][1] = 0;
        for( int i = 1; i <= len; i++ ) {
                    HashF[i][0] = ( HashF[i-1][0] * Base[0] + s[i-1] ) % Mod[0];
                    HashR[len-i+1][0] = ( HashR[len-i+2][0] * Base[0] + s[len-i] ) % Mod[0];
                    HashF[i][1] = ( HashF[i-1][1] * Base[1] + s[i-1] ) % Mod[1];
                    HashR[len-i+1][1] = ( HashR[len-i+2][1] * Base[1] + s[len-i] ) % Mod[1];
        }
}
inline LL get_hash( char *st ) {
        LL Hash1 = 0 , Hash2 = 0;
        int l = strlen( st );
        for( int i = 1; i <= l; i++ ) {
                    Hash1 = ( Hash1 * Base[ 0 ] + st[ i-1 ] ) % Mod[ 0 ] , Hash1 %= Mod[ 0 ];
                    Hash2 = ( Hash2 * Base[ 1 ] + st[ i-1 ] ) % Mod[ 1 ] , Hash2 %= Mod[ 1 ];
        }
        return ( Hash1 << 31 ) | Hash2;
}
inline LL get_fhash( int l , int r ) {
        l ++ , r ++;
        if( l == 1 ) return ( HashF[ r ][ 0 ] << 31 ) | HashF[ r ][ 1 ];
        LL Hash1 = ( HashF[ r ][ 0 ] - HashF[ l-1 ][ 0 ] * Pow[ r-l+1 ][ 0 ] % Mod[ 0 ] );
        Hash1 = ( Hash1 + Mod[ 0 ] ) % Mod[ 0 ];
        LL Hash2 = ( HashF[ r ][ 1 ] - HashF[ l-1 ][ 1 ] * Pow[ r-l+1 ][ 1 ] % Mod[ 1 ] );
        Hash2 = ( Hash2 + Mod[ 1 ] ) % Mod[ 1 ];
        return ( Hash1 << 31 ) | Hash2;
}
inline LL get_rhash( int l , int r ) {
        l ++ , r ++;
        if( r == len ) return ( HashR[ l ][ 0 ] << 31 ) | HashR[ l ][ 1 ];
        LL Hash1 = ( HashR[ l ][ 0 ] - HashR[ r+1 ][ 0 ] * Pow[ r-l+1 ][ 0 ] % Mod[ 0 ] );
        Hash1 = ( Hash1 + Mod[ 0 ] ) % Mod[ 0 ];
        LL Hash2 = ( HashR[ l ][ 1 ] - HashR[ r+1 ][ 1 ] * Pow[ r-l+1 ][ 1 ] % Mod[ 1 ] );
        Hash2 = ( Hash2 + Mod[ 1 ] ) % Mod[ 1 ];
        return ( Hash1 << 31 ) | Hash2;
}
inline void gen_pow( ) {
        shuffle( mod1 , mod1 + 5 , rng ) , shuffle( mod2 , mod2 + 5 , rng );
        shuffle( base1 , base1 + 5 , rng ) , shuffle( base2 , base2 + 5 , rng );
        Mod[0] = mod1[ ran( 0 , 4 ) ] , Mod[1] = mod2[ ran( 0, 4 ) ];
        Base[0] = base1[ ran( 0 , 4 ) ] , Base[1] = base2[ ran( 0 , 4 ) ];
        Pow[ 0 ][ 0 ] = Pow[ 0 ][ 1 ] = 1;
        for( int i = 1; i < N; i++ ) {
                    Pow[ i ][ 0 ] =  Pow[ i-1 ][ 0 ] * Base[ 0 ] % Mod[ 0 ];
                    Pow[ i ][ 1 ] =  Pow[ i-1 ][ 1 ] * Base[ 1 ] % Mod[ 1 ];
        }
}

int main( int argc , char const *argv[] ) {

        return 0;
}












