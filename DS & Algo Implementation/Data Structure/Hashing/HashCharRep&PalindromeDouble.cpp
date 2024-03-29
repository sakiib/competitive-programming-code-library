#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
const int N = 100005;

const int sz = N;

string s;
int len;

struct HashDoubleReplaceChar {
    const int Base[ 2 ] = { 31 , 29 };
    const int MOD[ 2 ] = { 1000000009 , 1000000007 };

    LL Pow[ 2 ][ sz ];

    inline void GeneratePower( ) {
            Pow[ 0 ][ 0 ] = 1 , Pow[ 1 ][ 0 ] = 1;
            for( int i = 1; i < sz; i++ ) {
                    Pow[ 0 ][ i ] = ( Pow[ 0 ][ i-1 ] * Base[ 0 ] ) % MOD[ 0 ];
                    Pow[ 1 ][ i ] = ( Pow[ 1 ][ i-1 ] * Base[ 1 ] ) % MOD[ 1 ];
            }
    }
    inline pair <LL,LL> GetFHash( ) {
            LL Hash1 = 0 , Hash2 = 0;
            for( int i = 0; i < len ; i++ ) {
                    Hash1 += ( Pow[ 0 ][ i ] * s[ i ] ) % MOD[ 0 ] , Hash1 %= MOD[ 0 ];
                    Hash2 += ( Pow[ 1 ][ i ] * s[ i ] ) % MOD[ 1 ] , Hash2 %= MOD[ 1 ];
            }
            return { Hash1 , Hash2 };
    }
    inline pair <LL,LL> GetBHash( ) {
            LL Hash1 = 0 , Hash2 = 0;
            for( int i = len-1 , j = 0 , k = 0; i >= 0; i-- ) {
                    Hash1 += ( Pow[ 0 ][ i ] * s[ k++ ] ) % MOD[ 0 ] , Hash1 %= MOD[ 0 ];
                    Hash2 += ( Pow[ 1 ][ i ] * s[ j++ ] ) % MOD[ 1 ] , Hash2 %= MOD[ 1 ];
            }
            return { Hash1 , Hash2 };
    }
    inline pair <LL,LL> GetFHashRepChar( pair <LL,LL> prev , int pos , char ch ) {
            LL cur1 = ( prev.first - ( s[ pos ] * Pow[ 0 ][ pos ] ) % MOD[ 0 ] ) % MOD[ 0 ];
            cur1 = ( cur1 + MOD[ 0 ] ) % MOD[ 0 ];
            LL now1 = ( cur1 + ( ch * Pow[ 0 ][ pos ] ) % MOD[ 0 ] ) % MOD[ 0 ];
            LL cur2 = ( prev.second - ( s[ pos ] * Pow[ 1 ][ pos ] ) % MOD[ 1 ] ) % MOD[ 1 ];
            cur2 = ( cur2 + MOD[ 1 ] ) % MOD[ 1 ];
            LL now2 = ( cur2 + ( ch * Pow[ 1 ][ pos ] ) % MOD[ 1 ] ) % MOD[ 1 ];
            return { now1 , now2 };
    }
    inline pair <LL,LL> GetBHashRepChar( pair <LL,LL> prev , int pos , char ch ) {
            LL cur1 = ( prev.first - ( s[ pos ] * Pow[ 0 ][ len-1-pos ] ) % MOD[ 0 ] ) % MOD[ 0 ];
            cur1 = ( cur1 + MOD[ 0 ] ) % MOD[ 0 ];
            LL now1 = ( cur1 + ( ch * Pow[ 0 ][ len-1-pos ] ) % MOD[ 0 ] ) % MOD[ 0 ];
            LL cur2 = ( prev.second - ( s[ pos ] * Pow[ 1 ][ len-1-pos ] ) % MOD[ 1 ] ) % MOD[ 1 ];
            cur2 = ( cur2 + MOD[ 1 ] ) % MOD[ 1 ];
            LL now2 = ( cur2 + ( ch * Pow[ 1 ][ len-1-pos ] ) % MOD[ 1 ] ) % MOD[ 1 ];
            return { now1 , now2 };
    }

} H;


int main( int argc , char const *argv[] ) {

        H.GeneratePower( );

        s = "ama";
        len = s.size( );

        pair <LL,LL> org = H.GetFHash( );
        cout <<"f org : "<< org.first << " " << org.second << endl;

        pair <LL,LL> borg = H.GetBHash( );
        cout <<"b org : "<< borg.first << " " << borg.second << endl;

        if( org == borg ) cout << "Palindrome" << endl;
        else cout << "NOT Palindrome" << endl;


        pair <LL,LL> cur = H.GetFHashRepChar( org , 1 , 'x' );
        cout <<" f now : "<< cur.first << " " << cur.second << endl;

        pair <LL,LL> now = H.GetBHashRepChar( borg , 1 , 'x' );
        cout << " b now : " << now.first << " " << now.second << endl;
        return 0;
}












