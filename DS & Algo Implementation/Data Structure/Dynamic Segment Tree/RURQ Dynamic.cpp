#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
const int N = 1e5 + 5;

/**
 Dynamic/sparse Segtree (with lazy propagation )
 array : 1 based indexed
 operations :
 type 1 -> update : add val in L to R
 type 2 -> query : sum of elements in L to R
 */
struct Node {
        Node *l , *r;
        LL sum;
        LL lazy;
        Node ( ) {
                l = NULL , r = NULL , sum = 0 , lazy = 0;
        }
        Node( LL b , LL e ) {
                l = NULL , r = NULL , sum = 0 , lazy = 0;
        }
        void Merge( int b , int e ) {
                sum = 0;
                int mid = ( b + e ) >> 1;
                if( l ) sum += l -> sum;
                if( r ) sum += r -> sum;
        }
} *root;

typedef Node* pNode;

int n , q;
LL a[ N ];

void Propagate( pNode &cur , int b , int e ) {
        if( cur -> lazy == 0 ) return;
        int mid = ( b + e ) >> 1;
        if( !( cur -> l ) ) cur -> l = new Node();
        if( !( cur -> r ) ) cur -> r = new Node();
        cur -> l -> sum += ( cur -> lazy * ( mid - b + 1 ) );
        cur -> r -> sum += ( cur -> lazy * ( e - mid ) );
        cur -> l -> lazy += cur -> lazy;
        cur -> r -> lazy += cur -> lazy;
        cur -> lazy = 0;
}
void Build( pNode &cur , int b , int e ) {
        if( b > e ) return;
        if( !cur ) cur = new Node();
        if( b == e ) {
                cur -> sum = a[b];
                return;
        }
        int m = ( b + e ) >> 1;
        Build( cur -> l , b , m );
        Build( cur -> r , m + 1 , e );
        cur -> Merge( b , e );
}
void Update( pNode &cur , int b , int e , int i , int j , int val ) {
        if( i > e || j < b || b > e ) return;
        if( !cur ) cur = new Node();
        if( i <= b && j >= e ) {
                cur -> sum += ( 1LL * val * ( e - b + 1 ) );
                cur -> lazy += val;
                return;
        }
        Propagate( cur , b , e );
        int mid = ( b + e ) >> 1;
        Update( cur -> l , b , mid , i , j , val );
        Update( cur -> r , mid + 1 , e , i , j , val );
        cur -> Merge( b , e );
}
LL Query( pNode &cur , int b , int e , int i , int j ) {
        if( i > e || j < b || b > e ) return 0;
        if( !cur ) return 0;
        if( i <= b && j >= e ) return cur -> sum;
        Propagate( cur , b , e );
        int mid = ( b + e ) >> 1;
        LL x = Query( cur -> l , b , mid , i , j );
        LL y = Query( cur -> r , mid + 1 , e , i , j );
        return ( x + y );
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( NULL );
        root = NULL;
        cin >> n >> q;
        for( int i = 1; i <= n; i++ ) cin >> a[i];
        Build( root , 1 , n );
        for( int i = 1; i <= q; i++ ) {
                int type;
                cin >> type;
                if( type == 1 ) { ///range update
                        int l , r , val;
                        cin >> l >> r >> val;
                        Update( root , 1 , n , l , r , val );
                }
                else { /// range sum query
                        int l , r;
                        cin >> l >> r;
                        cout << Query( root , 1 , n , l , r ) << endl;
                }
        }
        return 0;
}














