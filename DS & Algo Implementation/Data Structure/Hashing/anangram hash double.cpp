#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
const int N = 1e5 + 5;

const int base[] = { 257 , 311 };
const int invbase[] = { 70038911 , 742765280 };
const int MOD[] = { 1000000007 , 1000000009 };

int n , q , a[ N ];
int p[ N ][ 2 ] , invmod[ N ][ 2 ] , h[ N ][ 2 ];

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
        p[0][0] = 1 , p[0][1] = 1 , invmod[0][0] = 1 , invmod[0][1] = 1;
        for( int i = 1; i < N; i++ ) {
                for( int id = 0; id < 2; id++ ) {
                        p[i][id] = mul( p[i-1][id] , base[id] , MOD[id] );
                        invmod[i][id] = mul( invmod[i-1][id] , invbase[id] , MOD[id] );
                }
        }
}
inline void build_hash( ) {
        for( int i = 1; i <= n; i++ ) {
                for( int id = 0; id < 2; id++ ) {
                        h[i][id] = add( h[i][id], add( h[i-1][id], p[a[i]][id], MOD[id] ), MOD[id] );
                }
        }
}
inline LL get_ana_hash( int l , int r ) {
        int x = sub( h[r][0] , h[l-1][0] , MOD[0] ) , y = sub( h[r][1] , h[l-1][1] , MOD[1] );
        return ( 1LL * x << 31 ) | ( 1LL * y );
}
int main( int argc , char const *argv[] ) {
        scanf("%d %d",&n,&q);
        gen_pow();
        for( int i = 1; i <= n; i++ ) scanf("%d",&a[i]);
        build_hash();
        while( q-- ) {
                int a , b , c , d;
                scanf("%d %d %d %d",&a,&b,&c,&d);
                if( get_ana_hash( a , b ) == get_ana_hash( c , d ) ) puts("Yes");
                else puts("No");
        }
        return 0;
}











