#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 1e6 + 5;

const int Mod[ 2 ] = { 1000000007 , 1000000009 };
const int Base[ 2 ] = { 31 , 37 };
char s[ N ] , p[ N ];
LL Pow[ N ][ 2 ];
LL HashF[ N ][ 2 ] , HashR[ N ][ 2 ];
int len;

inline void BuildHash( ) {
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
pair <LL,LL> GetFHash( int l , int r ) {
        l ++ , r ++;
        if( l == 1 ) return { HashF[ r ][ 0 ] , HashF[ r ][ 1 ] };
        LL Hash1 = ( HashF[ r ][ 0 ] - HashF[ l-1 ][ 0 ] * Pow[ r-l+1 ][ 0 ] % Mod[ 0 ] );
        Hash1 = ( Hash1 + Mod[ 0 ] ) % Mod[ 0 ];
        LL Hash2 = ( HashF[ r ][ 1 ] - HashF[ l-1 ][ 1 ] * Pow[ r-l+1 ][ 1 ] % Mod[ 1 ] );
        Hash2 = ( Hash2 + Mod[ 1 ] ) % Mod[ 1 ];
        return { Hash1 , Hash2 };
}
pair <LL,LL> GetBHash( int l , int r ) {
        l ++ , r ++;
        if( r == len ) return { HashR[ l ][ 0 ] , HashR[ l ][ 1 ] };
        LL Hash1 = ( HashR[ l ][ 0 ] - HashR[ r+1 ][ 0 ] * Pow[ r-l+1 ][ 0 ] % Mod[ 0 ] );
        Hash1 = ( Hash1 + Mod[ 0 ] ) % Mod[ 0 ];
        LL Hash2 = ( HashR[ l ][ 1 ] - HashR[ r+1 ][ 1 ] * Pow[ r-l+1 ][ 1 ] % Mod[ 1 ] );
        Hash2 = ( Hash2 + Mod[ 1 ] ) % Mod[ 1 ];
        return { Hash1 , Hash2 };
}
pair <LL,LL> GetHash( int l ) {
        LL Hash1 = 0 , Hash2 = 0;
        for( int i = 1; i <= l; i++ ) {
                    Hash1 = ( Hash1 * Base[ 0 ] + p[ i-1 ] ) % Mod[ 0 ] , Hash1 %= Mod[ 0 ];
                    Hash2 = ( Hash2 * Base[ 1 ] + p[ i-1 ] ) % Mod[ 1 ] , Hash2 %= Mod[ 1 ];
        }
        return { Hash1 , Hash2 };
}
void genPower( ) {
        Pow[ 0 ][ 0 ] = Pow[ 0 ][ 1 ] = 1;
        for( int i = 1; i < N; i++ ) {
                    Pow[ i ][ 0 ] =  Pow[ i-1 ][ 0 ] * Base[ 0 ] % Mod[ 0 ];
                    Pow[ i ][ 1 ] =  Pow[ i-1 ][ 1 ] * Base[ 1 ] % Mod[ 1 ];
        }
}
int main( int argc , char const *argv[] ) {
        genPower( );
        int l;
        while( scanf("%d",&l) != EOF ) {
                scanf("%s",p);
                pair <LL,LL> x = GetHash( l );
                scanf("%s",s);
                BuildHash( );
                for( int i = 0; i + l - 1 < len; i++ ) {
                        pair <LL,LL> y = GetFHash( i , i + l - 1 );
                        if( x == y ) cout << i << endl;
                }
                cout << endl;
        }
        return 0;
}









