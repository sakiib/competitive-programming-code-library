#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

#define Check( N, cur ) ( !((N&( 1 << cur)) == 0))

const int N = 3e5 + 5;
const int mx = 20;

int n , q;
int a[ N ];

struct node {
        node *next[ 2 ];
        node( ) {
                next[0] = next[1] = nullptr;
        }
} *root;

struct segment {
        node *root;
} tree[ 4*N ];

inline void add( node *cur , int val ) {
        for( int i = mx; i >= 0; i-- ) {
                int id = Check( val , i );
                if( cur -> next[id] == nullptr ) {
                        cur -> next[id] = new node();
                }
                cur = cur -> next[id];
        }
}
inline int getmaxxor( node *cur , int k ) {
        int ans = 0;
        for( int i = mx; i >= 0; i-- ) {
                int id = Check( k , i );
                if( cur -> next[1^id] != nullptr ) {
                        ans |= ( 1 << i );
                        cur = cur -> next[1^id];
                }
                else if( cur -> next[id] != nullptr ) {
                        cur = cur -> next[id];
                }
        }
        return ans;
}
inline void build( int nod , int b , int e ) {
        if( b > e ) return;
        tree[nod].root = new node();
        for( int i = b; i <= e; i++ ) add( tree[nod].root , a[i] );
        if( b == e ) return;
        int l = nod << 1 , r = l | 1 , m = ( b + e ) >> 1;
        build( l , b , m );
        build( r , m + 1 , e );
}
inline int query( int nod , int b , int e , int i , int j , int k ) {
        if( i > e || j < b || b > e ) return 0;
        if( i <= b && j >= e ) return getmaxxor( tree[nod].root , k );
        int l = nod << 1 , r = l | 1 , m = ( b + e ) >> 1;
        return max( query( l , b , m , i , j , k ) , query( r , m + 1 , e , i , j , k ) );
}
int main( int argc , char const *argv[] ) {
        #ifdef forthright48
            freopen( "input.txt" , "r" , stdin );
        #endif // forthright48
        scanf("%d",&n);
        for( int i = 1; i <= n; i++ ) scanf("%d",&a[i]);
        build( 1 , 1 , n );
        scanf("%d",&q);
        while( q-- ) {
                int l , r , k;
                scanf("%d %d %d",&l,&r,&k);
                printf("%d\n",query( 1 , 1 , n , l , r , k ) );
        }
        return 0;
}










