#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
const int N = 1e5 + 5;

/**
 abc

 then , at first : F =  a*p^0+b*p^1+c*p^2
                   B = c*p^0+b*p^1+a*p^2
 now , it we want to get abcd
 then            : F = a*p^0+b*p^1+c*p^2+d*p^3
                   B : d*p^0+c*p^1+b*p^2+a*p^3
                   to get b multiply the poly by Power[1] ( length of added char )
do the reverse to concate char at left position of the string
 */

const int sz = N;

string s;
int len;


struct PolyHashConcateChar {
        const int Base = 31;
        const LL Mod = 1000000009;

        LL Pow[ sz ];

        inline void GeneratePower( ) {
                Pow[ 0 ]= 1;
                for( int i = 1; i < sz; i++ ) Pow[ i ] =  Pow[ i-1 ] * Base;
        }
        inline LL GetFHash( ) {
                LL Hash = 0;
                for( int i = 0; i < len; i++ ) Hash += ( s[i] * Pow[i] );
                return Hash;
        }
        inline LL GetBHash( ) {
                LL Hash = 0;
                for( int i = len-1 , j = 0; i >= 0; i-- , j++ ) Hash += ( s[j] * Pow[i] );
                return Hash;
        }
        inline pair<LL,LL> GetFBConcL( LL pF , LL pB , int len , char c , int k ) {
                LL mul = Pow[k];
                pF *= mul;
                for( int i = 0; i < k; i++ ) pF += ( c * Pow[i] );
                for( int i = len; i < ( len + k ); i++ ) pB += ( c * Pow[i] );
                return make_pair( pF , pB );
        }
        inline pair<LL,LL> GetFBConcR( LL pF , LL pB , int len , char c , int k ) {
                LL mul = Pow[k];
                for( int i = len; i < ( len + k ); i++ ) pF += ( c * Pow[i] );
                pB *= mul;
                for( int i = 0; i < k; i++ ) pB += ( c * Pow[i] );
                return make_pair( pF , pB );
        }

} H;

int main( int argc, char const *argv[] ) {

        H.GeneratePower( );
        s = "madam";
        len = s.size( );

        return 0;
}









