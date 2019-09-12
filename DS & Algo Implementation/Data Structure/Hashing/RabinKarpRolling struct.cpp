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

/**
 try to use char array & avoid string
 if TLE work without MOD
*/

string s;
int len;
const int sz = N;

struct RabinKarpRollingHash {

        static const int Base = 31;
        static const LL Mod = 1000000009;

        LL Pow[ sz ] , HashF[ sz ] , HashR[ sz ];

        inline void GeneratePower( ) {
                Pow[ 0 ]= 1;
                for( int i = 1; i < sz; i++ ) Pow[ i ] =  Pow[ i-1 ]*Base % Mod;
        }
        inline LL GetHash( string s ) {
                LL Hash = 0;
                len = s.size();
                for( int i = 1; i <= len; i++ ) {
                        Hash = ( Hash * Base + s[ i-1 ] ) % Mod; Hash %= Mod;
                }
                return Hash;
        }
        inline void BuildHash( ) {
                HashF[ 0 ] = 0 , HashR[ len+1 ] = 0;
                for( int i = 1; i <= len; i++ ) {
                        HashF[ i ] = ( HashF[ i-1 ] * Base + s[ i-1 ] ) % Mod;
                        HashR[ len-i+1 ] = ( HashR[ len-i+2 ] * Base + s[ len-i ] ) % Mod;
                }
        }
        inline LL GetFHash( int l , int r ) {
                l ++ , r ++;
                if( l == 1 ) return HashF[ r ];
                LL Hash = ( HashF[ r ] - HashF[ l-1 ] * Pow[ r-l+1 ] % Mod );
                Hash = ( Hash + Mod ) % Mod;
                return Hash;
        }
        inline LL GetBHash( int l , int r ) {
                l ++ , r ++;
                if( r == len ) return HashR[ l ];
                LL Hash = ( HashR[ l ] - HashR[ r+1 ] * Pow[ r-l+1 ] % Mod );
                Hash = ( Hash + Mod ) % Mod;
                return Hash;
        }
        inline bool IsPalindrome( int l , int r ) {
                return ( r < l ? false : GetFHash( l , r ) == GetBHash( l , r ) );
        }
} H;


/**

string s;
const int sz = 10*N;
const int Base = 31;

LL Pow[ sz ] , HashF[ sz ] , HashR[ sz ];


inline void GeneratePower( ) {
            Pow[ 0 ]= 1;
            for( int i = 1; i < sz; i++ ) Pow[ i ] =  Pow[ i-1 ] * Base;
}
inline LL GetHash( string s ) {
            LL Hash = 0;
            len = s.size();
            for( int i = 1; i <= len; i++ ) Hash = ( Hash * Base + s[ i-1 ] );
            return Hash;
}
inline void BuildHash( ) {
            HashF[ 0 ] = 0 , HashR[ len+1 ] = 0;
            for( int i = 1; i <= len; i++ ) {
                    HashF[ i ] = ( HashF[ i-1 ] * Base+s[ i-1 ] );
                    HashR[ len-i+1 ] = ( HashR[ len-i+2 ] * Base + s[ len-i ] );
            }
}
inline LL GetFHash( int l , int r ) {
            l ++ , r ++;
            if( l == 1 ) return HashF[ r ];
            LL Hash = ( HashF[ r ] - HashF[ l-1 ] * Pow[ r-l+1 ] );
            return Hash;
}
inline LL GetBHash( int l , int r ) {
            l ++ , r ++;
            if( r == len ) return HashR[ l ];
            LL Hash = ( HashR[ l ] - HashR[ r+1 ] * Pow[ r-l+1 ] );
            return Hash;
}
inline bool IsPalindrome( int l , int r ) {
            if( r < l ) return false;
            return ( GetFHash( l , r ) == GetBHash( l , r ) );
}

*/

int main( int argc , char const *argv[] ) {

    H.GeneratePower( );

    s = "madam";
    len = s.size();
    H.BuildHash();

    cout << H.GetFHash( 0 , 4 ) <<endl;
    cout << H.GetBHash( 0 , 4 ) << endl;

    return 0;
}


