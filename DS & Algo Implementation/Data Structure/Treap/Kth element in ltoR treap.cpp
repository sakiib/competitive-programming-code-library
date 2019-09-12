#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
const int inf = 2e9;

struct treap {
        struct node {
                node *l , *r;
                int val; int prior; int sz;
                node( ) : val(0), prior(0), sz(0), l(NULL), r(NULL) {}
        };

        node* root;
        typedef node* pnode;

        void nullify( pnode t ) {
                if( t == NULL ) return;
                nullify( t -> l ); nullify( t -> r );
                t -> l = NULL; t -> r = NULL; t = NULL;
        }
        void clr( ) {
                nullify( root );
                root = NULL;
        }
        pnode init( int val ) {
                pnode ret = (pnode)malloc( sizeof(node) );
                ret -> val = val; ret -> sz = 1; ret -> prior = rand();
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
        int order( pnode t , int k ) {
                if( t == NULL ) return 0;
                if( t -> val <= k ) {
                        return get_sz( t -> l ) + 1 + order( t -> r , k );
                }
                else {
                        return order( t -> l , k );
                }
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
        int order( int k ) {
                return order( root , k );
        }
};

treap tree[ 4*N ];
int a[ N ];

void update( int node , int b , int e , int pos , int val ) {
        if( b > e || pos > e || pos < b ) return;
        if( b == e && b == pos ) {
                tree[node].add( val );
                return;
        }
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        update( l , b , m , pos , val );
        update( r , m + 1 , e , pos , val );
        tree[node].add( val );
}
int KTH( int node , int b , int e , int i , int j , int k ) {
        if( b == e ) return b;
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        int ans = tree[l].order( j ) - tree[l].order( i );
        if( ans >= k ) return KTH( l , b , m , i , j , k );
        else return KTH( r , m + 1 , e , i , j , k - ans );
}
int brute( int l , int r , int k ) {
        vector <int> V;
        for( int i = l; i <= r; i++ ) V.push_back( a[i] );
        sort( V.begin() , V.end() );
        if( k > V.size() ) return -10000000;
        return V[k-1];
}
int get_rand( int l , int r ) {
        return rand()%(r-l+1) + l;
}
int main( ) {
        //freopen( "input.txt" , "r" , stdin );
        int n;
        scanf("%d",&n);
        for( int i = 1; i <= n; i++ ) scanf("%d",&a[i]);
        for( int i = 1; i <= n; i++ ) update( 1 , 1 , n , a[i] , i );
        for( int i = 1; i <= n; i++ ) {
                for( int j = i; j <= n; j++ ) {
                        int k = get_rand( 1 , j - i + 1 );
                        int x = brute( i , j , k );
                        int y = KTH( 1 , 1 , n , i - 1 , j , k );
                        printf("x : y : %d %d\n",x,y);
                        assert( x == y );
                }
        }
        return 0;
}







