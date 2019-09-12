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

unordered_map < LL , bool > M;
char str[ sz ];

struct HashSingleReplaceChar {

    const int Base = 31;

    const LL Mod = 74747474747474747LL;

    LL Pow[ sz ];
    inline void GeneratePower( ) {
        Pow[ 0 ]= 1;
        for( int i = 1; i < sz; i++ ) {
            Pow[ i ] = ( Pow[ i-1 ]*Base ) % Mod;
        }
    }
    inline LL GetHash( char *s ) {
        LL Hash = 0;
        for( int i = 0; s[i] ; i++ ) {
            Hash += ( Pow[ i ] * s[i] ) % Mod;
            Hash %= Mod;
        }
        return Hash;
    }
    inline LL GetHashRepChar( char *s , LL prev , int pos , char ch ) {
        LL cur = ( prev - ( s[ pos ] * Pow[ pos ] )%Mod ) % Mod;
        cur = ( cur + Mod ) % Mod;
        LL now = ( cur + ( ch * Pow[ pos ] )%Mod ) % Mod;
        return now;
    }

} Hashing ;


bool Solve( char *s ) {
    LL original = Hashing.GetHash( s );
    for( int i = 0; s[i] ; i++ ) {
        for( char ch = 'a'; ch <= 'c'; ch++ ) {
            if( s[i] == ch ) continue;
            LL now = Hashing.GetHashRepChar( s , original , i , ch );
            if( M[now] ) return true;
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
       LL h = Hashing.GetHash( str );
       M[h] = true;
    }
    while( m-- ) {
        scanf("%s",str);
        if( Solve( str ) ) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}


