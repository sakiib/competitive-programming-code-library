#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n , q , a[ N ] , Next[ N ] , Step[ N ] , Last[ N ] , block_size;

int Block_ID( int id ) {
        int pos = ( (id+block_size-1)/block_size ); return pos;
}
bool Same_BLOCK( int i , int j ) {
        return Block_ID( i ) == Block_ID( j );
}
void setBlock( int i ) {
        if( i+a[i] > n ) {
                Next[i] = n+1, Step[i] = 1, Last[i] = i;
        }
        else if( Same_BLOCK( i , i+a[i] ) ) {
                Next[i] = Next[ i+a[i] ],Step[i] = 1+Step[ i+a[i] ],Last[i] = Last[ i+a[i] ];
        }
        else {
                Next[i] = i+a[i], Step[i] = 1, Last[i] = i;
        }
}
int main( int argc , char const *argv[] ) {
        scanf("%d %d",&n,&q);
        for( int i = 1; i <= n; i++ ) scanf("%d",&a[i]);
        block_size = sqrt( n );
        for( int i = n; i >= 1; i-- ) setBlock( i );
        while( q-- ) {
                int op;
                scanf("%d",&op);
                if( op == 1 ) {
                     int pos;
                     scanf("%d",&pos);
                     int ans = 0 , prev = pos;
                     for( int i = pos; i <= n; i = Next[i] ) ans += Step[i], prev = Last[i];
                     printf("%d %d\n",prev,ans);
                }
                else {
                     int pos , val;
                     scanf("%d %d",&pos,&val);
                     a[pos] = val;
                     for( int i = pos; i >= 1 && Same_BLOCK( pos , i ); i-- ) setBlock( i );
                }
        }
        return 0;
}






