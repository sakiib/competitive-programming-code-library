#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
const int inf = (int)1e9;
const LL INF = (LL)1e18;
const int N = 100005;
const LL MOD = 1000000007;
const double EPS = 1e-7;
const double PI = acos( -1.0 );


const int sz = 6e5+5;

unordered_map < LL , bool > M[ 2 ];
char str[ sz ];

struct HashDoubleReplaceChar {
    const int Base[ 2 ] = { 31 , 29 };
    const int MOD[ 2 ] = { 1000000009 , 1000000007 };

    LL Pow[ 2 ][ sz ];
    // Precumpute Powers for appropriate range
    inline void GeneratePower( ) {
            Pow[ 0 ][ 0 ] = 1 , Pow[ 1 ][ 0 ] = 1;
            for( int i = 1; i < sz; i++ ) {
                    Pow[ 0 ][ i ] = ( Pow[ 0 ][ i-1 ] * Base[ 0 ] ) % MOD[ 0 ];
                    Pow[ 1 ][ i ] = ( Pow[ 1 ][ i-1 ] * Base[ 1 ] ) % MOD[ 1 ];
            }
    }
    // gives hash value of a string
    inline LL GetHash( char *s , int foo ) {
        LL Hash = 0;
        for( int i = 0; s[i] ; i++ ) {
            Hash += ( Pow[ foo ][ i ] * s[i] ) % Mod;
            Hash %= Mod;
        }
        return Hash;
    }
    // Pos er char ta 'ch' diye replace kore hash value ber korbo
    inline LL GetHashRepChar( char *s , LL prev , int foo , int pos , char ch ) {
        LL cur = ( prev - ( s[ pos ] * Pow[ foo ][ pos ] )%Mod ) % Mod;
        cur = ( cur + Mod ) % Mod;
        LL now = ( cur + ( ch * Pow[ foo ][ pos ] )%Mod ) % Mod;
        return now;
    }

} Hashing ;


bool Solve( char *s ) {
    LL original1 = Hashing.GetHash( s , 0 );
    LL original2 = Hashing.GetHash( s , 1 );
    for( int i = 0; s[i] ; i++ ) {
        for( char ch = 'a'; ch <= 'c'; ch++ ) {
            if( s[i] == ch ) continue;
            LL now1 = Hashing.GetHashRepChar( s , original1 , 0 , i , ch );
            LL now2 = Hashing.GetHashRepChar( s , original2 , 1 , i , ch );
            if( M[0][now1] && M[1][now2] ) return true;
        }
    }
    return false;
}
int main( int argc , char const *argv[] ) {

    Hashing.GeneratePower( );


    int n , m;
    scanf("%d %d",&n,&m);
    for( int i = 1; i <= n; i++ ) {
       scanf("%s",str);
       LL h1 = Hashing.GetHash( str , 0 );
       LL h2 = Hashing.GetHash( str , 1 );
       M[0][h1] = true , M[1][h2] = true;
    }
    while( m-- ) {
        scanf("%s",str);
        if( Solve( str ) ) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}


