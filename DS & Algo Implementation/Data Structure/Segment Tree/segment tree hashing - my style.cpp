#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int MOD = 1e9 + 7;
const int base = 37;
const int invbase = 621621626;

int len , q;
char s[ N ] , ch[ 5 ];
int a[ N ];
int p[ N ];
int invmod[ N ];
int tree[ 4*N ] , rtree[ 4*N ];

inline int mul( int x , int y , int MOD ) {
        return ( 1LL * x * y )%MOD;
}
inline int add( int x , int y , int MOD ) {
        x += y;
        return x >= MOD ? x - MOD : x;
}
inline int sub( int x , int y , int MOD ) {
        x -= y;
        return x < 0 ? x + MOD : x;
}
inline void gen_pow( ) {
        p[0] = 1 , invmod[0] = 1;
        for( int i = 1; i < N; i++ ) {
                p[i] = mul( p[i-1] , base , MOD );
                invmod[i] = mul( invmod[i-1] , invbase , MOD );
        }
}
inline void build( int node , int b , int e ) {
        if( b > e ) return;
        if( b == e ) {
                tree[node] = mul( a[b] , p[b-1] , MOD );
                rtree[node] = mul( a[b] , p[len-b] , MOD );
                return;
        }
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        build( l , b , m );
        build( r , m + 1 , e );
        tree[node] = add( tree[l] , tree[r] , MOD );
        rtree[node] = add( rtree[l] , rtree[r] , MOD );
}
inline void update( int node , int b , int e , int pos , int val ) {
        if( pos > e || pos < b || b > e ) return;
        if( b == e && b == pos ) {
                tree[node] = mul( val , p[b-1] , MOD );
                rtree[node] = mul( val , p[len-b] , MOD );
                return;
        }
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        update( l , b , m , pos , val );
        update( r , m + 1 , e , pos , val );
        tree[node] = add( tree[l] , tree[r] , MOD );
        rtree[node] = add( rtree[l] , rtree[r] , MOD );
}
inline int query( int node , int b , int e , int i , int j , int id ) {
        if( i > e || j < b || b > e ) return 0;
        if( i <= b && j >= e ) return id == 1 ? tree[node] : rtree[node];
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        int x = query( l , b , m , i , j , id );
        int y = query( r , m + 1 , e , i , j , id );
        return add( x , y , MOD );
}
int main( int argc , char const *argv[] ) {
        //freopen( "input.txt" , "r" , stdin );
        gen_pow();
        int t;
        scanf("%d",&t);
        while( t-- ) {
                scanf("%d %d",&len,&q);
                scanf("%s",s+1);
                for( int i = 1; i <= len; i++ ) a[i] = ( s[i]-'a'+1 );
                memset( tree , 0 , sizeof( tree ) );
                memset( rtree , 0 , sizeof( rtree ) );
                build( 1 , 1 , len );
                while( q-- ) {
                        int type;
                        scanf("%d",&type);
                        if( type == 1 ) {
                                int pos;
                                scanf("%d %s",&pos,ch);
                                a[pos] = ( ch[0]-'a'+1 );
                                update( 1 , 1 , len , pos , a[pos] );
                        }
                        else {
                                int l , r;
                                scanf("%d %d",&l,&r);
                                int fh = query( 1 , 1 , len , l , r , 1 );
                                int bh = query( 1 , 1 , len , l , r , 2 );
                                fh = mul( fh , invmod[l-1] , MOD );
                                bh = mul( bh , invmod[len-r] , MOD );
                                if( fh == bh ) puts("Adnan Wins");
                                else puts("ARCNCD!");
                        }
                }
        }
        return 0;
}










