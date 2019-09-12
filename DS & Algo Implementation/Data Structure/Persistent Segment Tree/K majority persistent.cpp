#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;


struct node {
        node *l , *r;
        int val;
        node( ) : l( nullptr ) , r( nullptr ) , val( 0 ) {}
        node( node *l , node *r , int val ) : l( l ) , r( r ) , val( val ) {}
        inline node* update( int b , int e , int pos ) {
                if( b > e || pos > e || pos < b ) return this;
                if( b == e && b == pos ) {
                        node *ret = new node( l , r , val );
                        ret -> val += 1;
                        return ret;
                }
                node *ret = new node();
                int mid = ( b + e ) >> 1;
                if( !l ) l = new node();
                if( !r ) r = new node();
                if( pos <= mid ) {
                        ret -> r = r , ret -> l = l -> update( b , mid , pos );
                }
                else {
                        ret -> l = l , ret -> r = r -> update( mid + 1 , e , pos );
                }
                if( ret -> l ) ret -> val += ret -> l -> val;
                if( ret -> r ) ret -> val += ret -> r -> val;
                return ret;
        }
        inline int query( node *prev , int b , int e , int cnt ) {
                if( b > e ) return -1;
                if( b == e ) return ( val - prev -> val >= cnt ? b : -1 );
                int mid = ( b + e ) >> 1;
                int lsum = ( l ? val : 0 ) - ( prev -> l ? prev -> val : 0 );
                if( lsum >= cnt ) {
                        int got = l -> query( prev -> l , b , mid , cnt );
                        if( got != -1 ) return got;
                }
                int rsum = ( r ? val : 0 ) - ( prev -> r ? prev -> val : 0 );
                if( rsum >= cnt ) {
                        int got = r -> query( prev -> r , mid + 1 , e , cnt );
                        if( got != -1 ) return got;
                }
                return -1;
        }

} *root[ 6*N ];

int n , q;
int a[ N ];

int main( int argc , char const *argv[] ) {
        #ifdef forthright48
            freopen( "input.txt" , "r" , stdin );
        #endif // forthright48
        scanf("%d %d",&n,&q);
        for( int i = 1; i <= n; i++ ) scanf("%d",&a[i]);
        root[0] = new node();
        for( int i = 1; i <= n; i++ ) {
                root[i] = root[i-1] -> update( 1 , N , a[i] );
        }
        for( int i = 1; i <= q; i++ ) {
                int l , r , k;
                scanf("%d %d %d",&l,&r,&k);
                int ans = root[r] -> query( root[l-1] , 1 , N , (r-l+1)/k+1 );
                printf("%d\n",ans);
        }
        return 0;
}










