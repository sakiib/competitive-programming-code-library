#include <bits/stdc++.h>
using namespace std;

/**
1 l r x — for each index i such that l ≤ i ≤ r set ai = x.
2 l r — find the minimum among such ai that l ≤ i ≤ r.
*/

const int INF = 2e9;
const int N = 1e5 + 5;

int n , k;
int a[ N ] , tree[ 4*N ];

void bu( int node , int b , int e ) {
        if( b > e ) return;
        if( b == e ) {
                tree[node] = a[b];
                return;
        }
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        bu( l , b , m );
        bu( r , m + 1 , e );
        tree[node] = min( tree[l] , tree[r] );
}
int qu( int node , int b , int e , int i , int j ) {
        if( i > e || j < b || b > e ) return INF;
        if( i <= b && j >= e ) return tree[node];
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        return min( qu( l , b , m , i , j ) ,
                    qu( r , m + 1 , e , i , j ) );
}
int rmq( int i , int j ) {
        if( j - i + 1 >= n ) return tree[1];
        i %= n , j %= n;
        if( i <= j ) return qu( 1 , 0 , n - 1 , i , j );
        else return min( qu( 1 , 0 , n - 1 , i , n - 1 ),
                           qu( 1 , 0 , n - 1 , 0 , j ) );
}
struct node {
        node *l , *r;
        int val; int lazy;
        node( ): l(NULL), r(NULL), val(INF), lazy(-1) {}
        void pushdown( ) {
                if( lazy == -1 ) return;
                if( !l ) l = new node();
                if( !r ) r = new node();
                l -> lazy = r -> lazy = lazy;
                l -> val = r -> val = lazy;
                lazy = -1;
        }
        void combine( int L , int R ) {
                val = INF;
                int M = ( L + R ) >> 1;
                if( l ) val = min( val , l -> val );
                else val = min( val , rmq( L , M ) );
                if( r ) val = min( val , r -> val );
                else val = min( val , rmq( M + 1 , R ) );
        }
} *root;

typedef node* pnode;

void update( pnode &t , int b , int e , int i , int j , int v ) {
        if( i > e || j < b || b > e ) return;
        if( !t ) t = new node();
        if( i <= b && j >= e ) {
                t -> val = v; t -> lazy = v;
                return;
        }
        t -> pushdown( );
        int m = ( b + e ) >> 1;
        update( t -> l , b , m , i , j , v );
        update( t -> r , m + 1 , e , i , j , v );
        t -> combine( b , e );
}
int query( pnode &t , int b , int e , int i , int j ) {
        if( i > e || j < b || b > e ) return INF;
        if( i <= b && j >= e ) {
                if( !t ) return rmq( b , e );
                return t -> val;
        }
        if( !t ) t = new node();
        t -> pushdown( );
        int m = ( b + e ) >> 1;
        int ans =  min( query( t -> l , b , m , i , j ),
				        query( t -> r , m + 1 , e , i , j ) );
		t -> combine( b , e );
		return ans;
}
void update( int l , int r , int x ) {
		update( root , 0 , n * k - 1 , l , r , x );
}
int query( int l , int r ) {
		return query( root , 0 , n * k - 1 , l , r );
}
int main( ) {
        scanf("%d %d",&n,&k);
        root = NULL;
        for( int i = 0; i < n; i++ ) scanf("%d",&a[i]);
        bu( 1 , 0 , n - 1 );
        int q;
        scanf("%d",&q);
        while( q-- ) {
                int typ , l , r , x;
                scanf("%d %d %d",&typ,&l,&r);
                --l , --r;
                if( typ == 1 ) {
                        scanf("%d", &x);
                        update( l , r , x );
                }
                else {
                        printf("%d\n",query( l , r ));
                }
        }
        return 0;
}








