#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

const int N = 1e5 + 5;
const int block_size = 350;

int n , q;
int a[ N ] , b[ N ];
int x[ N ] , y[ N ] , k[ N ];
int BLOCK[ 350 ] , temp[ N ];

int Block_ID( int id ) {
        return id/block_size;
}
inline void update( int l , int r , int col ) {
        int block_a = Block_ID( l ) , block_b = Block_ID( r );
        if( block_a == block_b ) {
                for( int i = l; i <= r; i++ ) temp[i] = col;
                return;
        }
        for( int i = l; i < ( block_a + 1 )*block_size; i++ ) temp[i] = col;
        for( int i = block_a + 1; i < block_b; i++ ) BLOCK[i] = col;
        for( int i = block_b * block_size; i <= r; i++ ) temp[i] = col;
}
inline int query( int pos ) {
        return max( temp[pos] , BLOCK[ Block_ID(pos) ] );
}
int main( int argc , char const *argv[] ) {
        //freopen( "input.txt" , "r" , stdin );
        scanf("%d %d",&n,&q);
        for( int i = 1; i <= n; i++ ) scanf("%d",&a[i]);
        for( int i = 1; i <= n; i++ ) scanf("%d",&b[i]);
        memset( BLOCK , 0 , sizeof( BLOCK ) );
        for( int i = 1; i <= q; i++ ) {
                int type;
                scanf("%d",&type);
                if( type == 1 ) {
                        scanf("%d %d %d",&x[i],&y[i],&k[i]);
                        update( y[i] , y[i] + k[i] - 1 , i );
                }
                else {
                        int pos;
                        scanf("%d",&pos);
                        int col = query( pos );
                        if( col == 0 ) printf("%d\n",b[pos]);
                        else {
                                int val = pos - y[col] + 1;
                                int idx = x[col] + val - 1;
                                printf("%d\n",a[idx]);
                        }
                }
        }
        return 0;
}










