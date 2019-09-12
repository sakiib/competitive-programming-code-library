#include <bits/stdc++.h>
using namespace std;

/// intention: sum query in l to r , update first element , shift all elements right
/// 1 based treap index

const int inf = 2e9;
typedef long long LL;
const int N = 1e5 + 5;

struct node {
        node *l , *r;
        int prior , sz;
        LL val , res; /// res keeps the sum here...
};
typedef node* pnode;
pnode root;

inline int get_sz( pnode t ) {
        return t ? t -> sz : 0;
}
inline LL get_res( pnode t ) {
        return t ? t -> res : 0;
}
inline void operation( pnode t ) {
        if( !t ) return;
        t -> sz = 1 + get_sz( t -> l ) + get_sz( t -> r );
        t -> res = t -> val + get_res( t -> l ) + get_res( t -> r );
}
inline void split( pnode t , pnode &l , pnode &r , int pos , int add = 0 ) {
        if( !t ) { l = r = NULL; return; }
        int curpos = add + get_sz( t -> l ) + 1;
        if( curpos <= pos ) split( t -> r , t -> r , r , pos , curpos ) , l = t;
        else split( t -> l , l , t -> l , pos , add ) , r = t;
        operation( t );
}
inline void combine( pnode &t , pnode l , pnode r ) {
        if( !l || !r ) t = l ? l : r;
        else if( l -> prior > r -> prior ) combine( l -> r , l -> r , r ) , t = l;
        else combine( r -> l , l , r -> l ) , t = r;
        operation( t );
}
inline pnode init( LL val ) {
        pnode ret = ( pnode )malloc( sizeof( node ) );
        ret -> prior = rand(); ret -> sz = 1;
        ret -> val = ret -> res = val; ret -> l = ret -> r = NULL;
        return ret;
}
inline void add( pnode &t , int idx , LL val ) {
        pnode left , right , mid;
        pnode it = init( val );
        split( t , left , right , idx - 1 );
        combine( mid , left , it );
        combine( t , mid , right );
}
inline LL range_SUM( pnode t , int l , int r ) {
        pnode left , right , mid;
        split( t , left , mid , l - 1 );
        split( mid , t , right , r - l + 1 );
        LL ans = t -> res;
        combine( mid , left , t );
        combine( t , mid , right );
        return ans;
}

LL a[ N ];

int main( int argc , char const *argv[]) {
        int n;
        scanf("%d",&n);
        for( int i = 1; i <= n; i++ ) scanf("%lld",&a[i]);
        for( int i = 1; i <= n; i++ ) add( root , i , a[i] );
        int q;
        scanf("%d",&q);
        while( q-- ) {
                int op;
                scanf("%d",&op);
                if( op == 1 ) {
                        int l , r;
                        scanf("%d %d",&l,&r);
                        printf("%lld\n",range_SUM( root , l , r ) );
                }
                else {
                        LL val;
                        scanf("%lld",&val);
                        add( root , 1 , val );
                }
        }
        return 0;
}











