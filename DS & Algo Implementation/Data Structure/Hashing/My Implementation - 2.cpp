#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
const int N = 1e5 + 5;

const int MOD[] = { 1000000007 , 1000000009 };
const int base[] = { 43 , 37 };
const int invbase[] = { 395348840 , 297297300  };

int tlen;
char txt[ N ];

int p[ N ][ 2 ];
int fh[ N ][ 2 ] , bh[ N ][ 2 ];
int invmod[ N ][ 2 ];

inline int add( int x , int y , int MOD ) {
        x += y;
        return x >= MOD ? x - MOD : x;
}
inline int sub( int x , int y , int MOD ) {
        x -= y;
        return x < 0 ? x + MOD : x;
}
inline int mul( int x , int y , int MOD ) {
        return ( 1LL * x * y ) % MOD;
}
inline void gen_pow( ) {
        p[0][0] = p[0][1] = invmod[0][0] = invmod[0][1] = 1;
        for( int i = 1; i < N; i++ ) {
                for( int id = 0; id < 2; id++ ) {
                        p[i][id] = mul( p[i-1][id] , base[id] , MOD[id] );
                        invmod[i][id] = mul( invmod[i-1][id] , invbase[id] , MOD[id] );
                }
        }
}
inline LL fhash( char *s ) {
        int l = strlen( s ) , x = 0 , y = 0;
        for( int i = 0; i < l; i++ ) {
                x = add( x , mul( p[i][0] , s[i] , MOD[0] ) , MOD[0] );
                y = add( y , mul( p[i][1] , s[i] , MOD[1] ) , MOD[1] );
        }
        return (1LL*x << 31LL)|(1LL*y);
}
inline LL bhash( char *s ) {
        int l = strlen( s ) , x = 0 , y = 0;
        for( int i = l - 1 , j = 0; i >= 0; i-- , j++ ) {
                x = add( x , mul( p[j][0] , s[i] , MOD[0] ) , MOD[0] );
                y = add( y , mul( p[j][1] , s[i] , MOD[1] ) , MOD[1] );
        }
        return (1LL*x << 31LL)|(1LL*y);
}
inline void build_hash( char *txt ) {
        tlen = strlen( txt );
        for( int i = 0 , j = tlen - 1; i < tlen; i++ , j-- ) {
                for( int id = 0; id < 2; id++ ) {
                        fh[i][id] = mul( p[i][id] , txt[i] , MOD[id] );
                        if( i ) fh[i][id] = add( fh[i][id] , fh[i-1][id] , MOD[id] );
                        bh[i][id] = mul( p[j][id] , txt[i] , MOD[id] );
                        if( i ) bh[i][id] = add( bh[i][id] , bh[i-1][id] , MOD[id] );
                }
        }
}
inline LL get_fhash( int l , int r ) {
        if( l == 0 ) return (1LL*fh[r][0] << 31)|(1LL*fh[r][1]);
        int x = sub( fh[r][0], fh[l-1][0], MOD[0] ); x = mul( x, invmod[l][0], MOD[0] );
        int y = sub( fh[r][1], fh[l-1][1], MOD[1] ); y = mul( y, invmod[l][1], MOD[1] );
        return (1LL*x << 31LL)|(1LL*y);
}
inline LL get_bhash( int l , int r ) {
        if( l == 0 ) {
                int x = bh[r][0]; x = mul( x, invmod[tlen-r-1][0], MOD[0] );
                int y = bh[r][1]; y = mul( y, invmod[tlen-r-1][1], MOD[1] );
                return (1LL*x << 31LL)|(1LL*y);
        }
        int x = sub( bh[r][0], bh[l-1][0], MOD[0] ); x = mul( x, invmod[tlen-r-1][0], MOD[0] );
        int y = sub( bh[r][1], bh[l-1][1], MOD[1] ); y = mul( y, invmod[tlen-r-1][1], MOD[1] );
        return (1LL*x << 31LL)|(1LL*y);
}

int main( int argc , char const *argv[] ) {

        return 0;
}















