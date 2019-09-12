#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int n , k;

struct node {
        node *l , *r;
        LL sum;
        LL lazy;
        node( ) : l(NULL), r(NULL), sum(0), lazy(0) {}
        void combine( int L , int R ) {
                int M = ( L + R ) >> 1;
                sum = 0;
                if( l ) sum += l -> sum;
                if( r ) sum += r -> sum;
        }
        void pushdown( int L , int R ) {
                if( lazy == 0 ) return;
                int M = ( L + R ) >> 1;
                if( !l ) l = new node();
                if( !r ) r = new node();
                l -> sum += 1LL * lazy * ( M - L + 1 );
                r -> sum += 1LL * lazy * ( R - M );
                l -> lazy += lazy;
                r -> lazy += lazy; lazy = 0;
        }
};

node* root;
typedef node* pnode;

void update( pnode &t , int b , int e , int i , int j , int val ) {
        if( i > e || j < b || b > e ) return;
        if( !t ) t = new node();
        if( i <= b && j >= e ) {
                t -> sum += 1LL * ( e - b + 1 ) * val;
                t -> lazy += val;
                return;
        }
        int m = ( b + e ) >> 1;
        t -> pushdown( b , e );
        update( t -> l , b , m , i , j , val );
        update( t -> r , m + 1 , e , i , j , val );
        t -> combine( b , e );
}
LL query( pnode &t , int b , int e , int i , int j ) {
        if( i > e || j < b || b > e ) return 0;
        if( i <= b && j >= e ) {
                if( !t ) return 0;
                else return t -> sum;
        }
        if( !t ) t = new node();
        t -> pushdown( b , e );
        int m = ( b + e ) >> 1;
        LL ret = query( t -> l , b , m , i , j ) +
                 query( t -> r , m + 1 , e , i , j );
        t -> combine( b , e );
        return ret;
}
LL tot( LL l , LL r ) {
        return r*(r+1)/2 - l*(l-1)/2;
}
int main( ) {
        //freopen( "input.txt" , "r" , stdin );
        root = NULL;
        scanf("%d %d",&n,&k);
        while( k-- ) {
                int type;
                scanf("%d",&type);
                if( type == 1 ) {
                        int l , r , v;
                        scanf("%d %d %d",&l,&r,&v);
                        update( root , 1 , n , l , r , v );
                }
                else {
                        int l , r;
                        scanf("%d %d",&l,&r);
                        LL cur = query( root , 1 , n , l , r );
                        printf("%lld\n",tot(l,r)-cur);
                }
        }
        return 0;
}









