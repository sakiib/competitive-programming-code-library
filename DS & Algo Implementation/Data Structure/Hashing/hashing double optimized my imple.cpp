#include <bits/stdc++.h>
using namespace std;

struct string_double_hashing {
        typedef long long LL;
        static const int N = 1e5 + 5;
        const int MOD[2] = { 1000000007, 1000000009 };
        const int base[2] = { 43 , 37 }, invbase[2] = { 395348840 , 297297300 };
        int tlen, p[ N ][ 2 ], fh[ N ][ 2 ], bh[ N ][ 2 ], invmod[ N ][ 2 ];

        inline int mul( int x, int y, int M ) { return ( 1LL * x * y ) % M; }
        inline int add( int x, int y, int M ) { x += y; return x >= M ? x - M : x; }
        inline int sub( int x, int y, int M ) { x -= y; return x < 0 ? x + M : x; }

        inline void gen_pow( ) {
                p[0][0] = p[0][1] = invmod[0][0] = invmod[0][1] = 1;
                for( int i = 1; i < N; i++ ) {
                        p[i][0] = mul( p[i-1][0] , base[0] , MOD[0] );
                        p[i][1] = mul( p[i-1][1] , base[1] , MOD[1] );
                        invmod[i][0] = mul( invmod[i-1][0] , invbase[0] , MOD[0] );
                        invmod[i][1] = mul( invmod[i-1][1] , invbase[1] , MOD[1] );
                }
        }
        inline void build_hash( char *txt ) {
                tlen = strlen( txt );
                for( int i = 0 , j = tlen - 1; i < tlen; i++ , j-- ) {
                        fh[i][0] = mul( p[i][0] , txt[i] , MOD[0] );
                        if( i ) fh[i][0] = add( fh[i][0] , fh[i-1][0] , MOD[0] );
                        fh[i][1] = mul( p[i][1] , txt[i] , MOD[1] );
                        if( i ) fh[i][1] = add( fh[i][1] , fh[i-1][1] , MOD[1] );
                        bh[i][0] = mul( p[j][0] , txt[i] , MOD[0] );
                        if( i ) bh[i][0] = add( bh[i][0] , bh[i-1][0] , MOD[0] );
                        bh[i][1] = mul( p[j][1] , txt[i] , MOD[1] );
                        if( i ) bh[i][1] = add( bh[i][1] , bh[i-1][1] , MOD[1] );
                }
        }
        inline LL get_fhash( int l , int r ) {
                if( l == 0 ) return (1LL*fh[r][0] << 31)|(1LL*fh[r][1]);
                int x = sub( fh[r][0], fh[l-1][0], MOD[0] );
                x = mul( x, invmod[l][0], MOD[0] );
                int y = sub( fh[r][1], fh[l-1][1], MOD[1] );
                y = mul( y, invmod[l][1], MOD[1] ); return ( 1LL*x << 31LL )|(1LL*y);
        }
        inline LL get_bhash( int l , int r ) {
                if( l == 0 ) {
                        int x = bh[r][0]; x = mul( x, invmod[tlen-r-1][0], MOD[0] );
                        int y = bh[r][1]; y = mul( y, invmod[tlen-r-1][1], MOD[1] );
                        return (1LL*x << 31LL)|(1LL*y);
                }
                int x = sub( bh[r][0], bh[l-1][0], MOD[0] );
                x = mul( x, invmod[tlen-r-1][0], MOD[0] );
                int y = sub( bh[r][1], bh[l-1][1], MOD[1] );
                y = mul( y, invmod[tlen-r-1][1], MOD[1] ); return (1LL*x << 31LL)|(1LL*y);
        }
        inline LL fhash( char *s ) {
                int l = strlen( s ) , x = 0 , y = 0;
                for( int i = 0; i < l; i++ ) {
                        x = add( x , mul( p[i][0] , s[i] , MOD[0] ) , MOD[0] );
                        y = add( y , mul( p[i][1] , s[i] , MOD[1] ) , MOD[1] );
                } return ( 1LL*x << 31LL )|(1LL*y);
        }
        inline LL bhash( char *s ) {
                int l = strlen( s ) , x = 0 , y = 0;
                for( int i = l - 1 , j = 0; i >= 0; i-- , j++ ) {
                        x = add( x , mul( p[j][0] , s[i] , MOD[0] ) , MOD[0] );
                        y = add( y , mul( p[j][1] , s[i] , MOD[1] ) , MOD[1] );
                } return ( 1LL*x << 31LL )|(1LL*y);
        }
} H;

int main( int argc , char const *argv[] ) {

        return 0;
}









