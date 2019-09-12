#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
typedef long long LL;

const int MOD[] = { 1000000007 , 1000000009 };
const int base[] = { 10 , 10 };
const int invbase[] = { 700000005 , 100000001  };

int p[ N ][ 2 ];
int fh[ N ][ 2 ] , bh[ N ][ 2 ];
int invmod[ N ][ 2 ];

char txt[ N ];
int tlen;

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
                p[i][0] = mul( p[i-1][0] , base[0] , MOD[0] );
                p[i][1] = mul( p[i-1][1] , base[1] , MOD[1] );
                invmod[i][0] = mul( invmod[i-1][0] , invbase[0] , MOD[0] );
                invmod[i][1] = mul( invmod[i-1][1] , invbase[1] , MOD[1] );
        }
}
inline void build_hash( ) {
        for( int i = 0 , j = tlen - 1; i < tlen; i++ , j-- ) {
                bh[i][0] = mul( p[j][0] , txt[i] - '0', MOD[0] );
                if( i ) bh[i][0] = add( bh[i][0] , bh[i-1][0] , MOD[0] );
                bh[i][1] = mul( p[j][1] , txt[i] - '0', MOD[1] );
                if( i ) bh[i][1] = add( bh[i][1] , bh[i-1][1] , MOD[1] );
        }
}
inline pair <int,int> get_bhash( int l , int r ) {
        if( l == 0 ) {
                int x = bh[r][0]; x = mul( x, invmod[tlen-r-1][0], MOD[0] );
                int y = bh[r][1]; y = mul( y, invmod[tlen-r-1][1], MOD[1] );
                return {x,y};
        }
        int x = sub( bh[r][0], bh[l-1][0], MOD[0] ); x = mul( x, invmod[tlen-r-1][0], MOD[0] );
        int y = sub( bh[r][1], bh[l-1][1], MOD[1] ); y = mul( y, invmod[tlen-r-1][1], MOD[1] );
        return {x,y};
}

inline bool ok( pair <int,int> x , pair <int,int> y , pair <int,int> z ) {
        return add( x.first , y.first , MOD[0] ) == z.first &&
               add( x.second , y.second , MOD[1] ) == z.second;
}
inline void print( int l , int r ) {
        for( int i = l; i <= r; i++ ) printf("%c",txt[i]);
}
inline bool check( int l , int r ) {
        return ( txt[l] == '0' ) ? l == r : true;
}
int main( int argc , char const *argv[] ) {
        //freopen( "input.txt" , "r" , stdin );
        scanf("%s",txt);
        tlen = strlen( txt );
        gen_pow();
        build_hash();
        for( int l = 1; l < tlen; l++ ) {
                int k = tlen - l;
                int r = max( k / 2 , l ) , lim = 2;
                for( int i = -lim; i <= lim; i++ ) {
                        int a = l , c = r + i , b = tlen - ( a + c );
                        if ( c < 1 || b < 1 || (a + c) >= tlen || (a + b) >= tlen
                            || (a + b + c) > tlen ) continue;
                        if( check( 0 , a - 1 ) && check( a , a + b -1 ) && check( a + b , tlen -1 ) ) {
                        //printf("( %d %d ) , ( %d %d ) = %d %d\n",0,a-1,a,a+b-1,a+b,tlen-1);
                        if( ok( get_bhash( 0 , a - 1 ) , get_bhash( a ,  a + b - 1 ) , get_bhash( a + b , tlen - 1 ) ) ) {
                                    print( 0 , a - 1 );
                                    printf("+");
                                    print( a , a + b - 1 );
                                    printf("=");
                                    print( a + b , tlen - 1 );
                                    return 0;
                        }
                    }
                }
        }
        assert( false );
        return 0;
}









