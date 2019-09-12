#include <bits/stdc++.h>
using namespace std;

/// intention: add a new val in any position & find the max in a range..
/// 1 based index

const int inf = 2e9;

struct node {
        struct node *l , *r;
        int prior , sz , val , res;
};
typedef node* pnode;
pnode root;

inline int get_sz( pnode t ) {
        return t ? t -> sz : 0;
}
inline int get_res( pnode t ) {
        return t ? t -> res : -inf;
}
inline void operation( pnode t ) {
        if( !t ) return;
        t -> sz = 1 + get_sz( t -> l ) + get_sz( t -> r );
        t -> res = max( max( t -> val , get_res( t -> l ) ) , get_res( t -> r ) );
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
inline pnode init( int val ) {
        pnode ret = ( pnode )malloc( sizeof( node ) );
        ret -> prior = rand(); ret -> sz = 1;
        ret -> val = ret -> res = val; ret -> l = ret -> r = NULL;
        return ret;
}
inline void add( pnode &t , int idx , int val ) {
        pnode left , right , mid;
        pnode it = init( val );
        split( t , left , right , idx - 1 );
        combine( mid , left , it );
        combine( t , mid , right );
}
inline int range_MAX( pnode t , int l , int r ) {
        pnode left , right , mid;
        split( t , left , mid , l - 1 );
        split( mid , t , right , r - l + 1 );
        int ans = t -> res;
        combine( mid , left , t );
        combine( t , mid , right );
        return ans;
}
int main( int argc , char const *argv[]) {
        int q;
        scanf("%d",&q);
        char s[10];
        while( q-- ) {
                scanf("%s",s);
                if( s[0] == 'A' ) {
                        int h , pos;
                        scanf("%d %d",&h,&pos);
                        add( root , pos , h );
                }
                else {
                        int l , r;
                        scanf("%d %d",&l,&r);
                        printf("%d\n",range_MAX( root , l , r ) );
                }
        }
        return 0;
}










