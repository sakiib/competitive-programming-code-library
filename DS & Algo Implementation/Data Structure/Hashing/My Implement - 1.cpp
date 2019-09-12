#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
const int N = 1e6 + 5;

const int MOD[] = { 1000000007 , 1000000009 };
const int base[] = { 37 , 43 };
const int invbase[] = { 621621626 , 139534885 };

int plen , tlen;
char pat[ N ] , txt[ N ];
int p[ N ][ 2 ];
int h[ N ][ 2 ];
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
        p[0][0] = p[0][1] = 1; invmod[0][0] = invmod[0][1] = 1;
        for( int i = 1; i < N; i++ ) {
                p[i][0] = mul( p[i-1][0] , base[0] , MOD[0] );
                p[i][1] = mul( p[i-1][1] , base[1] , MOD[1] );
                invmod[i][0] = mul( invmod[i-1][0] , invbase[0] , MOD[0] );
                invmod[i][1] = mul( invmod[i-1][1] , invbase[1] , MOD[1] );
        }
}
inline void build_hash( ) {
        for( int i = 0; i < tlen; i++ ) {
                h[i][0] = mul( p[i][0] , txt[i] , MOD[0] );
                if( i ) h[i][0] = add( h[i][0] , h[i-1][0] , MOD[0] );
                h[i][1] = mul( p[i][1] , txt[i] , MOD[1] );
                if( i ) h[i][1] = add( h[i][1] , h[i-1][1] , MOD[1] );
        }
}
inline LL get_fhash( int l , int r ) {
        if( l == 0 ) return (1LL*h[r][0] << 31)|(1LL*h[r][1]);
        int x = sub( h[r][0], h[l-1][0], MOD[0] ); x = mul( x, invmod[l][0], MOD[0] );
        int y = sub( h[r][1], h[l-1][1], MOD[1] ); y = mul( y, invmod[l][1], MOD[1] );
        return (1LL*x << 31)|(1LL*y);
}
inline LL get_hash( char *s ) {
        int l = strlen( s );
        int x = 0 , y = 0;
        for( int i = 0; i < l; i++ ) {
                x = add( x , mul( p[i][0] , s[i] , MOD[0] ) , MOD[0] );
                y = add( y , mul( p[i][1] , s[i] , MOD[1] ) , MOD[1] );
        }
        return (1LL*x << 31)|(1LL*y);
}
int main( int argc , char const *argv[] ) {
        #ifdef forthright48
            freopen( "input.txt" , "r" , stdin );
        #endif // forthright48
        gen_pow();
        while( scanf("%d",&plen) != EOF ) {
                scanf("%s %s",pat,txt);
                tlen = strlen( txt );
                build_hash();
                LL Hash = get_hash( pat );
                for( int i = 0; i + plen - 1 < tlen; i++ ) {
                        if( get_fhash( i , i + plen - 1 ) == Hash ) printf("%d\n",i);
                }
                printf("\n");
        }
        return 0;
}










