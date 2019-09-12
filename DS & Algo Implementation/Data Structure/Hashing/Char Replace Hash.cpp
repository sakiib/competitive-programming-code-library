#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 6e5 + 5;
const LL Mod[ 2 ] = { 1000000009 , 1000000007 };
const int Base[ 2 ] = { 37 , 31 };

int n , q;
char s[ N ];
LL Pow[ N ][ 2 ];
set <LL> S;

void genPower( ) {
        Pow[0][0] = Pow[0][1] = 1;
        for( int i = 1; i < N; i++ ) {
                Pow[i][0] =  Pow[i-1][0] * Base[0] % Mod[0];
                Pow[i][1] =  Pow[i-1][1] * Base[1] % Mod[1];
        }
}
pair <LL,LL> calcHash( char *s ) {
        int len = strlen( s );
        LL hash1 = 0 , hash2 = 0;
        for( int i = 0; i < len; i++ ) {
                hash1 = ( hash1 + Pow[i][0] % Mod[0] * s[i] % Mod[0] ) % Mod[0];
                hash2 = ( hash2 + Pow[i][1] % Mod[1] * s[i] % Mod[1] ) % Mod[1];
        }
        return make_pair( hash1 , hash2 );
}
bool ok( char *s ) {
        pair <LL,LL> cur = calcHash( s );
        int len = strlen( s );
        for( int i = 0; i < len; i++ ) {
                for( char j = 'a'; j <= 'c'; j++ ) {
                        if( s[i] == j ) continue;
                        pair <LL,LL> temp = cur;
                        temp.first -= ( Pow[i][0] % Mod[0] * s[i] % Mod[0] );
                        if( temp.first < 0 ) temp.first += Mod[0];
                        temp.first = ( temp.first % Mod[0] + Pow[i][0] % Mod[0] * j % Mod[0] ) % Mod[0];
                        temp.second -= ( Pow[i][1] % Mod[1] * s[i] % Mod[1] );
                        if( temp.second < 0 ) temp.second += Mod[1];
                        temp.second = ( temp.second % Mod[1] + Pow[i][1] * j % Mod[1] ) % Mod[1];
                        LL res = ( temp.first << 31 ) | temp.second;
                        if( S.find( res ) != S.end( ) ) return true;
                }
        }
        return false;
}
int main( int argc , char const *argv[] ) {
        genPower( );
        scanf("%d %d",&n,&q);
        for( int i = 1; i <= n; i++ ) {
                scanf("%s",s);
                pair <LL,LL> X = calcHash( s );
                S.insert( ( X.first << 31 ) | X.second );
        }
        while( q-- ) {
                scanf("%s",s);
                if( ok( s ) ) printf("YES\n");
                else printf("NO\n");
        }
        return 0;
}







