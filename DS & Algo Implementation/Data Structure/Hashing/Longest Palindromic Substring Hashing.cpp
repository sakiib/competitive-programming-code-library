#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 1e5 + 5;
const int Mod[ 2 ] = { 1000000007 , 1000000009 };
const int Base[ 2 ] = { 31 , 37 };
char s[ N ];
LL Pow[ N ][ 2 ];
LL HashF[ N ][ 2 ] , HashR[ N ][ 2 ];
int len;

void BuildHash( ) {
        HashF[0][0] = 0 , HashR[len+1][0] = 0;
        HashF[0][1] = 0 , HashR[len+1][1] = 0;
        for( int i = 1; i <= len; i++ ) {
                    HashF[i][0] = ( HashF[i-1][0] * Base[0] + s[i-1] ) % Mod[0];
                    HashR[len-i+1][0] = ( HashR[len-i+2][0] * Base[0] + s[len-i] ) % Mod[0];
                    HashF[i][1] = ( HashF[i-1][1] * Base[1] + s[i-1] ) % Mod[1];
                    HashR[len-i+1][1] = ( HashR[len-i+2][1] * Base[1] + s[len-i] ) % Mod[1];
        }
}
LL GetHash( string s ) {
        LL Hash1 = 0 , Hash2 = 0;
        len = s.size();
        for( int i = 1; i <= len; i++ ) {
                    Hash1 = ( Hash1 * Base[ 0 ] + s[ i-1 ] ) % Mod[ 0 ] , Hash1 %= Mod[ 0 ];
                    Hash2 = ( Hash2 * Base[ 1 ] + s[ i-1 ] ) % Mod[ 1 ] , Hash2 %= Mod[ 1 ];
        }
        return ( Hash1 << 31 ) | Hash2;
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
bool IsPalindrome( int l , int r ) {
        return ( r < l ?  false : GetFHash( l , r ) == GetBHash( l , r ) );
}
void genPower( ) {
        Pow[ 0 ][ 0 ] = Pow[ 0 ][ 1 ] = 1;
        for( int i = 1; i < N; i++ ) {
                    Pow[ i ][ 0 ] =  Pow[ i-1 ][ 0 ] * Base[ 0 ] % Mod[ 0 ];
                    Pow[ i ][ 1 ] =  Pow[ i-1 ][ 1 ] * Base[ 1 ] % Mod[ 1 ];
        }
}

vector <int> odd , even;

bool ok( int l ) {
        if( l > len ) return false;
        for( int i = 0; i + l - 1 < len; i++ ) {
                if( IsPalindrome( i , i + l - 1 ) ) return true;
        }
        return false;
}
int Odd( ) {
        int lo = 0 , hi = odd.size() - 1 , ret = 0;
        while( lo <= hi ) {
                int mid = ( lo + hi ) >> 1;
                if( ok( odd[mid] ) ) ret = odd[mid] , lo = mid + 1;
                else hi = mid - 1;
        }
        return ret;
}
int Even( ) {
        int lo = 0 , hi = even.size() - 1 , ret = 0;
        while( lo <= hi ) {
                int mid = ( lo + hi ) >> 1;
                if( ok( even[mid] ) ) ret = even[mid] , lo = mid + 1;
                else hi = mid - 1;
        }
        return ret;
}
int main( int argc , char const *argv[] ) {
        genPower( );
        for( int i = 1 , j = 2; i <= 100000 && j <= 100000; i += 2 , j += 2 ) {
                odd.push_back( i );
                even.push_back( j );
        }
        scanf("%s %s",s,t);
        BuildHash( );
        printf("%d\n",max( Odd() , Even() ));
        return 0;
}















