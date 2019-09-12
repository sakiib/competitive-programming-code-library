#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n , q;
int a[ N ];

struct node {
        node *l , *r;
        int sum;
        typedef node* pnode;
        node( ) : l( nullptr ) , r( nullptr ) , sum( sum ){}
        node( node *l , node *r , int sum ) : l( l ) , r( r ) , sum( sum ){}

        void build( int b , int e ) {
                if( b > e ) return;
                if( b == e ) {
                        sum = a[b]; return;
                }
                int m = ( b + e ) >> 1;
                l = new node();
                r = new node();
                l -> build( b , m );
                r -> build( m + 1 , e );
                sum = l -> sum + r -> sum;
        }
        pnode update( int b , int e , int pos , int val ) {
                if( b > e || pos > e || pos < b ) return this;
                if( b == e && b == pos ) {
                        pnode ret = new node( l , r , sum );
                        ret -> sum += val;
                        return ret;
                }
                int m = ( b + e ) >> 1;
                pnode ret = new node();
                ret -> l = l -> update( b , m , pos , val );
                ret -> r = r -> update( m + 1 , e , pos , val );
                ret -> sum = ret -> l -> sum + ret -> r -> sum;
                return ret;
        }
        int query( int b , int e , int i , int j ) {
                if( i > e || j < b || b > e ) return 0;
                if( i <= b && j >= e ) return sum;
                int m = ( b + e ) >> 1;
                int ret = 0;
                ret += l -> query( b , m , i , j );
                ret += r -> query( m + 1 , e , i , j );
                return ret;
        }

} *root[ 10*N ];

int main( int argc , char const *argv[] ) {
        scanf("%d",&n);
        for( int i = 1; i <= n; i++ ) scanf("%d",&a[i]);

        root[0] = new node();
        root[0] -> build( 1 , n );

        scanf("%d",&q);
        int cnt = 0;
        for( int i = 1; i <= q; i++ ) {
                int type;
                scanf("%d",&type);
                if( type == 1 ) {
                        int idx , pos , v;
                        scanf("%d %d %d",&idx,&pos,&v);
                        root[++cnt] = root[idx] -> update( 1 , n , pos , v );
                }
                else if( type == 2 ) {
                        int idx , l , r;
                        scanf("%d %d %d",&idx,&l,&r);
                        printf("%d\n",root[idx] -> query( 1 , n , l , r ) );
                }
        }
        return 0;
}











