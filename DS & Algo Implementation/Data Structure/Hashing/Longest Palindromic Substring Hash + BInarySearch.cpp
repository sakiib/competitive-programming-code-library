#include <bits/stdc++.h>
using namespace std;

typedef long  long LL;
const int N = 1e5 + 5;

string s;
int len;

struct RABIN_KARP_ROLLING_DOUBLE_HASH {
        static const int MAXN = 1e5 + 5;

        const int Base[ 2 ] = { 31 , 29 };
        const int Mod[ 2 ] = { 1000000009 , 1000000007 };
        LL Pow[ MAXN ][ 2 ] , HashF[ MAXN ][ 2 ] , HashR[ MAXN ][ 2 ];

        inline void GeneratePower( ) {
                Pow[ 0 ][ 0 ] = Pow[ 0 ][ 1 ] = 1;
                for( int i = 1; i < MAXN; i++ ) {
                        Pow[ i ][ 0 ] =  Pow[ i-1 ][ 0 ] * Base[ 0 ] % Mod[ 0 ];
                        Pow[ i ][ 1 ] =  Pow[ i-1 ][ 1 ] * Base[ 1 ] % Mod[ 1 ];
                }
        }
        inline pair <LL,LL> GetHash( string s ) {
                LL Hash1 = 0 , Hash2 = 0;
                len = s.size();
                for( int i = 1; i <= len; i++ ) {
                        Hash1 = ( Hash1 * Base[ 0 ] + s[ i-1 ] ) % Mod[ 0 ] , Hash1 %= Mod[ 0 ];
                        Hash2 = ( Hash2 * Base[ 1 ] + s[ i-1 ] ) % Mod[ 1 ] , Hash2 %= Mod[ 1 ];
                }
                return { Hash1 , Hash2 };
        }
        inline void BuildHash( ) {
                HashF[ 0 ][ 0 ] = 0 , HashR[ len+1 ][ 0 ] = 0;
                HashF[ 0 ][ 1 ] = 0 , HashR[ len+1 ][ 1 ] = 0;
                for( int i = 1; i <= len; i++ ) {
                        HashF[ i ][ 0 ] = ( HashF[ i-1 ][ 0 ] * Base[ 0 ] + s[ i-1 ] ) % Mod[ 0 ];
                        HashR[ len-i+1 ][ 0 ] = ( HashR[ len-i+2 ][ 0 ] * Base[ 0 ] + s[ len-i ] ) % Mod[ 0 ];
                        HashF[ i ][ 1 ] = ( HashF[ i-1 ][ 1 ] * Base[ 1 ] + s[ i-1 ] ) % Mod[ 1 ];
                        HashR[ len-i+1 ][ 1 ] = ( HashR[ len-i+2 ][ 1 ] * Base[ 1 ] + s[ len-i ] ) % Mod[ 1 ];
                }
        }
        inline pair <LL,LL> GetFHash( int l , int r ) {
                l ++ , r ++;
                if( l == 1 ) return { HashF[ r ][ 0 ] , HashF[ r ][ 1 ] };
                LL Hash1 = ( HashF[ r ][ 0 ] - HashF[ l-1 ][ 0 ] * Pow[ r-l+1 ][ 0 ] % Mod[ 0 ] );
                Hash1 = ( Hash1 + Mod[ 0 ] ) % Mod[ 0 ];
                LL Hash2 = ( HashF[ r ][ 1 ] - HashF[ l-1 ][ 1 ] * Pow[ r-l+1 ][ 1 ] % Mod[ 1 ] );
                Hash2 = ( Hash2 + Mod[ 1 ] ) % Mod[ 1 ];
                return { Hash1 , Hash2 };
        }
        inline pair <LL,LL> GetBHash( int l , int r ) {
                l ++ , r ++;
                if( r == len ) return { HashR[ l ][ 0 ] , HashR[ l ][ 1 ] };
                LL Hash1 = ( HashR[ l ][ 0 ] - HashR[ r+1 ][ 0 ] * Pow[ r-l+1 ][ 0 ] % Mod[ 0 ] );
                Hash1 = ( Hash1 + Mod[ 0 ] ) % Mod[ 0 ];
                LL Hash2 = ( HashR[ l ][ 1 ] - HashR[ r+1 ][ 1 ] * Pow[ r-l+1 ][ 1 ] % Mod[ 1 ] );
                Hash2 = ( Hash2 + Mod[ 1 ] ) % Mod[ 1 ];
                return { Hash1 , Hash2 };
        }
        inline bool IsPalindrome( int l , int r ) {
                if( r < l ) return false; return ( GetFHash( l , r ) == GetBHash( l , r ) );
        }
} H;


int main( int argc , char const *argv[] ) {
        cin >> len >> s;
        s = " " + s;
        len++;
        H.GeneratePower();
        H.BuildHash();

        int mx = 0;
        for( int i = 1; i <= len; i++ ) { /// center odd length
                int lo = 1 , hi = min( i , len - i + 1 ) , res = 0;
                while( lo <= hi ) {
                        int mid = ( lo+ hi )/2;
                        if( H.IsPalindrome( i - mid + 1 , i + mid - 1 ) ) {
                                res = mid;
                                lo = mid + 1;
                        }
                        else hi = mid - 1;
                }
                mx = max( mx , 2 * res - 1 );
        }
        for( int i = 1; i <= len; i++ ) { /// center even length
                int lo = 0 , hi = min( i , len - i ) , res = 0;
                while( lo <= hi ) {
                        int mid = ( lo+ hi )/2;
                        if( H.IsPalindrome( i - mid + 1 , i + mid ) ) {
                                res = mid;
                                lo = mid + 1;
                        }
                        else hi = mid - 1;
                }
                mx = max( mx , 2 * res );
        }
        cout << mx << endl;
        return 0;
}







