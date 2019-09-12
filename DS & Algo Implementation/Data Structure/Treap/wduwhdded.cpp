#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
const int inf = 2e9;

struct treap {
        struct node {
                int val;
                int prior;
                int sz;
                node *l , *r;
                node( ) : val(0), prior(0), sz(0), l(NULL), r(NULL) {}
        };
        node* root;
        typedef node* pnode;
        void nullify( pnode t ) {
                if( t == NULL ) return;
                nullify( t -> l );
                nullify( t -> r );
                t -> l = NULL;
                t -> r = NULL;
                t = NULL;
        }
        void clr( ) {
                nullify( root );
                root = NULL;
        }
        pnode init( int val ) {
                pnode ret = (pnode)malloc( sizeof(node) );
                ret -> val = val;
                ret -> sz = 1;
                ret -> prior = rand();
                ret -> l = ret -> r = NULL;
                return ret;
        }
        int get_sz( pnode t ) {
                return t ? t -> sz : 0;
        }
        void upd_sz( pnode t ) {
                if( t ) {
                    t -> sz = get_sz( t -> l ) + 1 + get_sz( t -> r );
                }
        }
        void split( pnode t , pnode &l , pnode &r , int key ) {
                if( !t ) l = r = NULL;
                else if( t -> val <= key ) {
                        split( t -> r , t -> r , r , key ) , l = t;
                }
                else {
                        split( t -> l , l , t -> l , key ) , r = t;
                }
                upd_sz( t );
        }
        void unite( pnode &t , pnode l , pnode r ) {
                if( !l || !r ) t = l ? l : r;
                else if( l -> prior > r -> prior ) {
                        unite( l -> r , l -> r , r ) , t = l;
                }
                else {
                        unite( r -> l , l , r -> l ) , t = r;
                }
                upd_sz( t );
        }
        void add( pnode &t , pnode it ) {
                if( !t ) t = it;
                else if( it -> prior > t -> prior ) {
                        split( t , it -> l , it -> r , it -> val ) , t = it;
                }
                else {
                        add( t -> val <= it -> val ? t -> r : t -> l , it );
                }
                upd_sz( t );
        }
        void del( pnode &t , int key ) {
                if( !t ) return;
                else if( t -> val == key ) {
                        pnode temp = t;
                        unite( t , t -> l , t -> r ); free( temp );
                }
                else {
                        del( t -> val < key ? t -> r : t -> l , key );
                }
                upd_sz( t );
        }
        bool have( pnode t , int key ) {
                if( !t ) return false;
                else if( t -> val == key ) return true;
                else {
                        have( t -> val < key ? t -> r : t -> l , key );
                }
        }
        int less_than( pnode t , int key ) {
                if( !t ) return 0;
                if( t -> val >= key ) return less_than( t -> l , key );
                return get_sz( t -> l ) + 1 + less_than( t -> r , key );
        }
        int less_than_eq( pnode t , int key ) {
                if( !t ) return 0;
                if( t -> val > key ) return less_than_eq( t -> l , key );
                else return get_sz( t -> l ) + 1 + less_than_eq( t -> r , key );
        }
        int kth( pnode t , int k ) {
                int cnt = get_sz( t -> l );
                if( cnt == k - 1 ) return t -> val;
                else if( cnt >= k ) return kth( t -> l , k );
                else return kth( t -> r , k - cnt - 1 );
        }
        void add( int val ) {
                add( root , init( val ) );
        }
        void del( int val ) {
                if( have( root , val ) ) del( root , val );
        }
        bool have( int val ) {
                return have( root , val );
        }
        int less_than( int val ) {
                return less_than( root , val );
        }
        int less_than_eq( int val ) {
                return less_than_eq( root , val );
        }
        int kth( int k ) {
                return get_sz( root ) < k ? -inf : kth( root , k );
        }
};

treap tree[ 4*N ];
int a[ N ];

void build( int node , int b , int e ) {
        if( b > e ) return;
        for( int i = b; i <= e; i++ ) tree[node].add( a[i] );
        if( b == e ) return;
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        build( l , b , m );
        build( r , m + 1 , e );
}
int query( int node , int b , int e , int i , int j , int val ) {
        if( i > e || j < b || b > e ) return 0;
        if( i <= b && j >= e ) return tree[node].less_than_eq( val );
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        return query( l , b , m , i , j , val ) + query( r , m + 1 , e , i , j , val );
}
int main( ) {
        for( int i = 1; i < 4*N; i++ ) tree[i].clr( );
        int n , m;
        scanf("%d %d",&n,&m);
        for( int i = 1; i <= n; i++ ) scanf("%d",&a[i]);
        build( 1 , 1 , n );
        for( int i = 1; i <= m; i++ ) {
                int val;
                scanf("%d",&val);
                printf("%d ",query( 1 , 1 , n , 1 , n , val ));
        }
        return 0;
}




