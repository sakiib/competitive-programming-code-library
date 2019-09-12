#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
const int N = 1e5 + 5;

const int sz = N;

string s;
int len;


struct PolyHashConcateCharLeftRight {
        const int Base[ 2 ] = { 31 , 29 };
        const int MOD[ 2 ] = { 1000000009 , 1000000007 };

        LL Pow[ sz ][2 ];

        inline void GeneratePower( ) {
                Pow[ 0 ][ 0 ] = 1 , Pow[ 0 ][ 1 ] = 1;
                for( int i = 1; i < sz; i++ ) {
                        Pow[ i ][ 0 ] = ( Pow[ i-1 ][ 0 ] * Base[ 0 ] ) % MOD[ 0 ];
                        Pow[ i ][ 1 ] = ( Pow[ i-1 ][ 1 ] * Base[ 1 ] ) % MOD[ 1 ];
                }
        }
        inline pair <LL,LL> GetFHash( ) {
                LL Hash1 = 0 , Hash2 = 0;
                for( int i = 0; i < len ; i++ ) {
                        Hash1 += ( Pow[ i ][ 0 ] * s[ i ] ) % MOD[ 0 ] , Hash1 %= MOD[ 0 ];
                        Hash2 += ( Pow[ i ][ 1 ] * s[ i ] ) % MOD[ 1 ] , Hash2 %= MOD[ 1 ];
                }
                return { Hash1 , Hash2 };
        }
        inline pair <LL,LL> GetBHash( ) {
                LL Hash1 = 0 , Hash2 = 0;
                for( int i = len-1 , j = 0 , k = 0; i >= 0; i-- ) {
                        Hash1 += ( Pow[ i ][ 0 ] * s[ k++ ] ) % MOD[ 0 ] , Hash1 %= MOD[ 0 ];
                        Hash2 += ( Pow[ i ][ 1 ] * s[ j++ ] ) % MOD[ 1 ] , Hash2 %= MOD[ 1 ];
                }
                return { Hash1 , Hash2 };
        }
        inline pair <LL,LL> GetFConLeft( pair <LL,LL> prev , int len , char c , int k ) {
                LL mul1 = Pow[ k ][ 0 ] % MOD[ 0 ];
                prev.first = ( prev.first % MOD[ 0 ] * mul1 % MOD[ 0 ] ) % MOD[ 0 ];
                for( int i = 0; i < k; i++ ) {
                        prev.first = ( prev.first % MOD[ 0 ] + c * Pow[ i ][ 0 ] % MOD[ 0 ] ) % MOD[ 0 ];
                }
                LL mul2 = Pow[ k ][ 1 ] % MOD[ 1 ];
                prev.second = ( prev.second % MOD[ 1 ] * mul2 % MOD[ 1 ] ) % MOD[ 1 ];
                for( int i = 0; i < k; i++ ) {
                        prev.second = ( prev.second % MOD[ 1 ] + c * Pow[ i ][ 1 ] % MOD[ 1 ] ) % MOD[ 1 ];
                }
                return { prev.first , prev.second };
        }

        inline pair <LL,LL> GetBConLeft( pair <LL,LL> prev , int len , char c , int k ) {
                for( int i = len; i < ( len + k ); i++ ) {
                        prev.first = ( prev.first % MOD[ 0 ] + c * Pow[ i ][ 0 ] % MOD[ 0 ] ) % MOD[ 0 ];
                        prev.second = ( prev.second % MOD[ 1 ] + c * Pow[ i ][ 1 ] % MOD[ 1 ] ) % MOD[ 1 ];
                }
                return { prev.first , prev.second };
        }

        inline pair <LL,LL> GetFConRight( pair <LL,LL> prev , int len , char c , int k ) {
                for( int i = len; i < ( len + k ); i++ ) {
                        prev.first = ( prev.first % MOD[ 0 ] + c * Pow[ i ][ 0 ] % MOD[ 0 ] ) % MOD[ 0 ];
                        prev.second = ( prev.second % MOD[ 1 ] + c * Pow[ i ][ 1 ] % MOD[ 1 ] ) % MOD[ 1 ];
                }
                return { prev.first , prev.second };
        }

        inline pair <LL,LL> GetBConRight( pair <LL,LL> prev , int len , char c , int k ) {
                LL mul1 = Pow[ k ][ 0 ] % MOD[ 0 ];
                prev.first = ( prev.first % MOD[ 0 ] * mul1 % MOD[ 0 ] ) % MOD[ 0 ];
                for( int i = 0; i < k; i++ ) {
                        prev.first = ( prev.first % MOD[ 0 ] + c * Pow[ i ][ 0 ] % MOD[ 0 ] ) % MOD[ 0 ];
                }
                LL mul2 = Pow[ k ][ 1 ] % MOD[ 1 ];
                prev.second = ( prev.second % MOD[ 1 ] * mul2 % MOD[ 1 ] ) % MOD[ 1 ];
                for( int i = 0; i < k; i++ ) {
                        prev.second = ( prev.second % MOD[ 1 ] + c * Pow[ i ][ 1 ] % MOD[ 1 ] ) % MOD[ 1 ];
                }
                return { prev.first , prev.second };
        }

} H;

int main( int argc, char const *argv[] ) {

        H.GeneratePower( );
        s = "madam";
        len = s.size( );

        pair <LL,LL> f = H.GetFHash( );
        cout << f.first << " "<< f.second << endl;

        pair <LL,LL> b = H.GetBHash( );
        cout << b.first << " " << b.second << endl;

        cout << endl << endl;



        f = H.GetFConRight( f , len , 'a' , 2 );
        cout << f.first << " "<< f.second << endl;

        b = H.GetBConRight( b , len , 'a' , 2 );
        cout << b.first << " " << b.second << endl;

        len += 2;

        cout << endl << endl;


        f = H.GetFConLeft( f , len , 'a' , 2 );
        cout << f.first << " "<< f.second << endl;

        b = H.GetBConLeft( b , len , 'a' , 2 );
        cout << b.first << " " << b.second << endl;

        if( f == b ) cout << "Palindrome"<< endl;
        else cout << "NOT Palindrome" << endl;

        return 0;
}









