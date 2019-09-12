#include <bits/stdc++.h>
using namespace std;

const int N = 30005;
const int block_size = 350;
int n , q , a[ N ];
int BIT[ block_size+10 ][ N+10 ];

int PQuery ( int block , int idx ) {
        int ret = 0;
        for( ; idx > 0; idx -= ( idx & -idx ) ) ret += BIT[ block ][ idx ];
        return ret;
}
int RQuery ( int block , int l , int r ) {
        return ( PQuery( block , r ) - PQuery( block , l-1 ) );
}
void PUpdate ( int block , int idx , int val ) {
        for( ; idx <= N; idx += ( idx & -idx ) ) BIT[ block ][ idx ] += val;
}
int Block_ID( int id ) {
        int pos = ( (id+block_size-1)/block_size );
        return pos;
}
void set_block( int id , int num ) {
        int block = Block_ID( id );
        PUpdate( block , num , +1 );
}
int getAns( int l , int r , int k ) {
        int block_a = Block_ID( l ) , block_b = Block_ID( r );
        if( block_a == block_b ) {
                int sum = 0;
                for( int i = l; i <= r; i++ ) sum += ( a[i] > k ? 1 : 0 );
                return sum;
        }
        int ret = 0;
        for( int i = l; ; i++ ) {
                int pos = Block_ID( i );
                if( pos != block_a ) break;
                ret += ( a[i] > k ? 1 : 0 );
        }
        for( int i = block_a+1; i < block_b; i++ ) ret += RQuery( i , k+1 , N );
        int f = block_size*( block_b-1 );
        for( int i = f+1; i <= r; i++ ) ret += ( a[i] > k ? 1 : 0 );
        return ret;
}
void Update( int pos , int val ) {
        int block = Block_ID( pos );
        int prev = a[pos];
        PUpdate( block , prev , -1 );
        PUpdate( block , val , +1 );
        a[pos] = val;
}
int main( int argc , char const *argv[] ) {
        scanf("%d",&n);
        for( int i = 1; i <= n; i++ ) scanf("%d",&a[i]) , set_block( i , a[i] );
        scanf("%d",&q);
        while( q-- ) {
                int op;
                scanf("%d",&op);
                if( op == 0 ) {
                        int pos , val;
                        scanf("%d %d",&pos,&val);
                        Update( pos , val );
                }
                else {
                        int l , r , val;
                        scanf("%d %d %d",&l,&r,&val);
                        if( l > r ) swap( l , r );
                        printf("%d\n",getAns( l , r , val ) );
                }
        }
        return 0;
}







