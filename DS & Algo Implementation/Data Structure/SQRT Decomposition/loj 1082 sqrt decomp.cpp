#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int inf = 1e9;
const int block_size = 350;

int n , q , a[ N ];
int BLOCK[ 505 ];

void Calc( ) {
        for( int i = 1; i <= 500; i++ ) BLOCK[i] = inf;
}
int Block_ID( int id ) {
        int pos = ( ( id + block_size - 1 )/block_size );
        return pos;
}
void SetBlock( int id , int v ) {
        int pos = Block_ID( id ); BLOCK[pos] = min( BLOCK[pos] , v );
}
pair <int,int> StartEndofBlock( int id ) {
        int st = ( id - 1 ) * block_size + 1;
        int en = min( n , ( st + block_size - 1 ) );
        return {st,en};
}
int SolveQuery( int l , int r ) {
        int block_A = Block_ID( l ) , block_B = Block_ID( r );
        if( block_A == block_B ) {
                int ret = inf;
                for( int i = l; i <= r; i++ ) ret = min( ret , a[i] );
                return ret;
        }
        int ret = inf;
        for( int i = l; ; i++ ) {
                int pos = Block_ID( i );
                if( pos != block_A ) break;
                ret = min( ret , a[i] );
        }
        for( int i = block_A+1; i < block_B; i++ ) ret = min( ret , BLOCK[i] );
        int f = block_size * ( block_B - 1 );
        for( int i = f+1; i <= r; i++ ) ret = min( ret , a[i] );
        return ret;
}
int main( int argc , char const *argv[] ) {
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
                scanf("%d %d",&n,&q);
                Calc( );
                for( int i = 1; i <= n; i++ ) {
                        scanf("%d",&a[i]);
                        SetBlock( i , a[i] );
                }
                printf("Case %d:\n",tc);
                while( q-- ) {
                      int l , r;
                      scanf("%d %d",&l,&r);
                      if( l > r ) swap( l , r );
                      printf("%d\n",SolveQuery( l , r ) );
                }
        }
        return 0;
}






