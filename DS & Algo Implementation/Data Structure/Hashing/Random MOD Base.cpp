#include <bits/stdc++.h>
using namespace std;

#define ran(a, b) ((((rand() << 15) ^ rand()) % ((b) - (a) + 1)) + (a))
typedef long long LL;
const int N = 1e6 + 5;

int Mod[ 2 ];
int Base[ 2 ];
char s[ N ] , p[ N ];
LL Pow[ N ][ 2 ];
LL HashF[ N ][ 2 ] , HashR[ N ][ 2 ];
int len;

inline int nextPrime( int n ){
        for ( int i = n; ;i++ ){
                for ( int j = 2; ;j++ ){
                    if ( ( j * j ) > i ) return i;
                    if ( ( i % j ) == 0 ) break;
                }
        }
        return -1;
}
void BuildHash( ) {
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
LL GetFHash( int l , int r ) {
        l ++ , r ++;
        if( l == 1 ) return ( HashF[ r ][ 0 ] << 31 ) | HashF[ r ][ 1 ];
        LL Hash1 = ( HashF[ r ][ 0 ] - HashF[ l-1 ][ 0 ] * Pow[ r-l+1 ][ 0 ] % Mod[ 0 ] );
        Hash1 = ( Hash1 + Mod[ 0 ] ) % Mod[ 0 ];
        LL Hash2 = ( HashF[ r ][ 1 ] - HashF[ l-1 ][ 1 ] * Pow[ r-l+1 ][ 1 ] % Mod[ 1 ] );
        Hash2 = ( Hash2 + Mod[ 1 ] ) % Mod[ 1 ];
        return ( Hash1 << 31 ) | Hash2;
}
LL GetBHash( int l , int r ) {
        l ++ , r ++;
        if( r == len ) return ( HashR[ l ][ 0 ] << 31 ) | HashR[ l ][ 1 ];
        LL Hash1 = ( HashR[ l ][ 0 ] - HashR[ r+1 ][ 0 ] * Pow[ r-l+1 ][ 0 ] % Mod[ 0 ] );
        Hash1 = ( Hash1 + Mod[ 0 ] ) % Mod[ 0 ];
        LL Hash2 = ( HashR[ l ][ 1 ] - HashR[ r+1 ][ 1 ] * Pow[ r-l+1 ][ 1 ] % Mod[ 1 ] );
        Hash2 = ( Hash2 + Mod[ 1 ] ) % Mod[ 1 ];
        return ( Hash1 << 31 ) | Hash2;
}
LL GetHash( int l ) {
        LL Hash1 = 0 , Hash2 = 0;
        for( int i = 1; i <= l; i++ ) {
                    Hash1 = ( Hash1 * Base[ 0 ] + p[ i-1 ] ) % Mod[ 0 ] , Hash1 %= Mod[ 0 ];
                    Hash2 = ( Hash2 * Base[ 1 ] + p[ i-1 ] ) % Mod[ 1 ] , Hash2 %= Mod[ 1 ];
        }
        return ( Hash1 << 31 ) | Hash2;
}
void genPower( ) {
        Pow[ 0 ][ 0 ] = Pow[ 0 ][ 1 ] = 1;
        for( int i = 1; i < N; i++ ) {
                    Pow[ i ][ 0 ] =  Pow[ i-1 ][ 0 ] * Base[ 0 ] % Mod[ 0 ];
                    Pow[ i ][ 1 ] =  Pow[ i-1 ][ 1 ] * Base[ 1 ] % Mod[ 1 ];
        }
}
int main( int argc , char const *argv[] ) {
        srand(time(0));
        Mod[0] = nextPrime(2078526727 + ran(1, 32345678));
        Mod[1] = nextPrime(2117566807 + ran(1, 672829));
        Base[0] = nextPrime(1572872831 + ran(13, 9173912));
        Base[1] = nextPrime(1971536491 + ran(13, 9173912));

        genPower( );
        int l;
        while( scanf("%d",&l) != EOF ) {
                scanf("%s",p);
                LL x = GetHash( l );
                scanf("%s",s);
                BuildHash( );
                for( int i = 0; i + l - 1 < len; i++ ) {
                        LL y = GetFHash( i , i + l - 1 );
                        if( x == y ) printf("%d\n",i);
                }
                printf("\n");
        }
        return 0;
}





