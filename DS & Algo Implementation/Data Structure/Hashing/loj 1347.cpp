#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 5005;

const int Mod[ 2 ] = { 1000000007 , 1000000009 };
const int Base[ 2 ] = { 59 , 43 };
char a[ N ] , b[ N ] , c[ N ] , s[ 3*N ];
LL Pow[ 3*N ][ 2 ];
LL HashF[ 3*N ][ 2 ];
int len , lena , lenb , lenc;

void BuildHash( ) {
        lena = strlen( a );
        lenb = strlen( b );
        lenc = strlen( c );
        len = lena + lenb + lenc;
        HashF[0][0] = 0;
        HashF[0][1] = 0;
        for( int i = 1; i <= len; i++ ) {
                    HashF[i][0] = ( HashF[i-1][0] * Base[0] + s[i-1] ) % Mod[0];
                    HashF[i][1] = ( HashF[i-1][1] * Base[1] + s[i-1] ) % Mod[1];
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
void genPower( ) {
        Pow[ 0 ][ 0 ] = Pow[ 0 ][ 1 ] = 1;
        for( int i = 1; i < 3*N; i++ ) {
                    Pow[ i ][ 0 ] =  Pow[ i-1 ][ 0 ] * Base[ 0 ] % Mod[ 0 ];
                    Pow[ i ][ 1 ] =  Pow[ i-1 ][ 1 ] * Base[ 1 ] % Mod[ 1 ];
        }
}
bool ok( int l ) {
        unordered_map <LL,int> M;
        for( int i = 0; i + l - 1 < lena; i++ ) {
                LL Hash = GetFHash( i , i + l - 1 );
                if( M[Hash] == 0 ) M[Hash]++;
        }
        int got = 0;
        for( int i = lena; i + l - 1 < lena + lenb; i++ ) {
                LL Hash = GetFHash( i , i + l - 1 );
                if( M[Hash] == 1 ) M[Hash]++;
        }
        for( int i = lena + lenb; i + l - 1 < len; i++ ) {
                LL Hash = GetFHash( i , i + l - 1 );
                if( M[Hash] == 2 ) return true;
        }
        return false;
}
int solve( ) {
        int lo = 0 , hi = min( lena , min( lenb , lenc ) ) , ret = 0;
        while( lo <= hi ) {
                int mid = ( lo + hi ) >> 1;
                if( ok( mid ) ) ret = mid , lo = mid + 1;
                else hi = mid - 1;
        }
        return ret;
}
int main( int argc , char const *argv[] ) {
        genPower( );
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
                scanf("%s %s %s",a,b,c);
                strcpy( s , a );
                strcat( s , b );
                strcat( s , c );
                BuildHash( );
                printf("Case %d: %d\n",tc,solve( ) );
        }
        return 0;
}










