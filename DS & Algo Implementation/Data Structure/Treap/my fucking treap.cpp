#include <bits/stdc++.h>
using namespace std;

struct node {
        int val;
        int prior;
        int sz;
        node *l , *r;
        node( ) : val(0), prior(0), sz(0), l(NULL), r(NULL) {}
};

/// can keep a element multiple times
node* root;
typedef node* pnode;

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
void nullify( pnode t ) {
        if( t == NULL ) return;
        nullify( t -> l );
        nullify( t -> r );
        t -> l = NULL;
        t -> r = NULL;
        t = NULL;
}
inline void clr() {
        nullify( root );
        root = NULL;
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
int main( ) {
        clr();
        char s[5];
        int q;
        scanf("%d",&q);
        while( q-- ) {
                scanf("%s",s);
                if( s[0] == 'I' ) {
                        int val;
                        scanf("%d",&val);
                        if( !have( root , val ) ) add( root , init(val) );
                }
                if( s[0] == 'D' ) {
                        int val;
                        scanf("%d",&val);
                        if( have( root , val ) ) del( root , val );
                }
                if( s[0] == 'K' ) {
                        int k;
                        scanf("%d",&k);
                        if( get_sz(root) < k ) printf("invalid\n");
                        else printf("%d\n",kth( root , k ) );
                }
                if( s[0] == 'C' ) {
                        int c;
                        scanf("%d",&c);
                        printf("%d\n",less_than( root , c ) );
                }
        }
        return 0;
}








