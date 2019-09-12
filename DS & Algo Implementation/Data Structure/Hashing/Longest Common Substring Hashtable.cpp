#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 5005;

const int Mod[ 2 ] = { 1000000007 , 1000000009 };
const int Base[ 2 ] = { 31 , 37 };
char s[ 5 ][ N ] , p[ N ];
LL Pow[ N ][ 2 ];
LL HashF[ N ][ 2 ][ 5 ] , HashR[ N ][ 2 ][ 5 ];
int lena , lenb , lenc;

/////////////////////////// HashTable //////////////////////////////

#define PAD 66667
#define MAX 200010
#define MOD 1000033

unsigned int hashtable1[MOD + PAD] , hashtable2[ MOD + PAD];

inline unsigned int smhash(unsigned int h){
        h ^= h >> 16;
        h *= 0x85ebca6b;
        h ^= h >> 13;
        h *= 0xc2b2ae35;
        h ^= h >> 16;
        return h + 1;
}
inline void insert1(unsigned int x){
        x = smhash(x);
        int i = x % MOD;
        while (hashtable1[i] && hashtable1[i] != x) i++;
        hashtable1[i] = x;
}
inline void insert2(unsigned int x){
        x = smhash(x);
        int i = x % MOD;
        while (hashtable2[i] && hashtable2[i] != x) i++;
        hashtable2[i] = x;
}
inline bool find1(unsigned int x){
        x = smhash(x);
        int i = x % MOD;
        while (hashtable1[i] && hashtable1[i] != x) i++;
        return hashtable1[i] == x;
}
inline bool find2(unsigned int x){
        x = smhash(x);
        int i = x % MOD;
        while (hashtable2[i] && hashtable2[i] != x) i++;
        return hashtable2[i] == x;
}

////////////////////////////////////////////////////////////////////

void BuildHash( int id ) {
        int len = strlen( s[id] );
        HashF[0][0][id] = 0 , HashR[len+1][0][id] = 0;
        HashF[0][1][id] = 0 , HashR[len+1][1][id] = 0;
        for( int i = 1; i <= len; i++ ) {
                    HashF[i][0][id] = ( HashF[i-1][0][id] * Base[0] + s[id][i-1] ) % Mod[0];
                    HashR[len-i+1][0][id] = ( HashR[len-i+2][0][id] * Base[0] + s[id][len-i] ) % Mod[0];
                    HashF[i][1][id] = ( HashF[i-1][1][id] * Base[1] + s[id][i-1] ) % Mod[1];
                    HashR[len-i+1][1][id] = ( HashR[len-i+2][1][id] * Base[1] + s[id][len-i] ) % Mod[1];
        }
}
LL GetFHash( int l , int r , int id ) {
        l ++ , r ++;
        if( l == 1 ) return ( HashF[ r ][ 0 ][ id ] << 31 ) | HashF[ r ][ 1 ][ id ];
        LL Hash1 = ( HashF[ r ][ 0 ][ id ] - HashF[ l-1 ][ 0 ][ id ] * Pow[ r-l+1 ][ 0 ] % Mod[ 0 ] );
        Hash1 = ( Hash1 + Mod[ 0 ] ) % Mod[ 0 ];
        LL Hash2 = ( HashF[ r ][ 1 ][ id ] - HashF[ l-1 ][ 1 ][ id ] * Pow[ r-l+1 ][ 1 ] % Mod[ 1 ] );
        Hash2 = ( Hash2 + Mod[ 1 ] ) % Mod[ 1 ];
        return ( Hash1 << 31 ) | Hash2;
}
LL GetBHash( int l , int r , int id ) {
        l ++ , r ++;
        int len = strlen( s[id] );
        if( r == len ) return ( HashR[ l ][ 0 ][ id ] << 31 ) | HashR[ l ][ 1 ][ id ];
        LL Hash1 = ( HashR[ l ][ 0 ][ id ] - HashR[ r+1 ][ 0 ][ id ] * Pow[ r-l+1 ][ 0 ] % Mod[ 0 ] );
        Hash1 = ( Hash1 + Mod[ 0 ] ) % Mod[ 0 ];
        LL Hash2 = ( HashR[ l ][ 1 ][ id ] - HashR[ r+1 ][ 1 ][ id ] * Pow[ r-l+1 ][ 1 ] % Mod[ 1 ] );
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
bool ok( int l ) {
        for( int i = 0; i + l - 1 < lena; i++ ) {
                LL Hash = GetFHash( i , i + l - 1 , 0 );
                if( !find1( Hash ) ) insert1( Hash );
        }
        for( int i = 0; i + l - 1 < lenb; i++ ) {
                LL Hash = GetFHash( i , i + l - 1 , 1 );
                if( !find2( Hash ) ) insert2( Hash );
        }
        for( int i = 0; i + l - 1 < lenc; i++ ) {
                LL Hash = GetFHash( i , i + l - 1 , 2 );
                if( find1( Hash ) && find2( Hash ) ) return true;
        }
        return false;
}
int solve( ) {
        lena = strlen( s[0] ) , lenb = strlen( s[1] ) , lenc = strlen( s[2] );
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
                scanf("%s %s %s",s[0],s[1],s[2]);
                BuildHash( 0 );
                BuildHash( 1 );
                BuildHash( 2 );
                memset( hashtable1 , 0 , sizeof( hashtable1 ) );
                memset( hashtable2 , 0 , sizeof( hashtable2 ) );
                printf("Case %d: %d\n",tc,solve( ) );
        }
        return 0;
}




