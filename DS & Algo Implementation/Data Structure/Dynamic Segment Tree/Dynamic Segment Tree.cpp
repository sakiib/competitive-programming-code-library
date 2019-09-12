#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long uLL;
typedef long long int LL;
typedef pair <int,int> pii;
typedef pair <int,pii> piii;
typedef pair <long long,long long> pll;
typedef pair <long long,pll> plll;
const int N = 1e5 + 5;
const int inf = 1e9;
const long long INF = 1e18;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int MOD = 1000000007;

/**
Dynamic Segment Tree Implementation
Range Sum Update + Range Sum Query by Lazy Propagation
Update : Add or Subtract a value in L - R
Query : Sum of elements in L - R
Initially for each i , a[i] = i
*/

LL calc( LL x ) {
        return 1LL * x * ( x + 1 )/2;
}
struct Node {
        Node *l , *r;
        LL sum;
        LL lazy;
        Node ( ) {
                l = NULL , r = NULL , sum = 0 , lazy = 0;
        }
        Node( LL b , LL e ) {
                l = NULL , r = NULL , sum = calc( e ) - calc( b - 1 ) , lazy = 0;
        }
        void Merge( int b , int e ) {
                sum = 0;
                int mid = ( b + e ) >> 1;
                if( l ) sum += l -> sum;
                else sum += ( calc( mid ) - calc( b - 1 ) );
                if( r ) sum += r -> sum;
                else sum += ( calc( e ) - calc( mid ) );
        }
} *root;

typedef Node* pNode;
int n , q;

void Propagate( pNode &cur , int b , int e ) {
        if( cur -> lazy == 0 ) return;
        int mid = ( b + e ) >> 1;
        if( !( cur -> l ) ) cur -> l = new Node( b , mid );
        if( !( cur -> r ) ) cur -> r = new Node( mid + 1 , e );
        cur -> l -> sum -= ( cur -> lazy * ( mid - b + 1 ) );
        cur -> r -> sum -= ( cur -> lazy * ( e - mid ) );
        cur -> l -> lazy += cur -> lazy;
        cur -> r -> lazy += cur -> lazy;
        cur -> lazy = 0;
}
void Update( pNode &cur , int b , int e , int i , int j , int val ) {
        if( i > e || j < b || b > e ) return;
        if( !cur ) cur = new Node( b , e );
        if( i <= b && j >= e ) {
                cur -> sum -= ( 1LL * val * ( e - b + 1 ) );
                cur -> lazy += val;
                return;
        }
        Propagate( cur , b , e );
        int mid = ( b + e ) >> 1;
        Update( cur -> l , b , mid , i , j , val );
        Update( cur -> r , mid + 1 , e , i , j , val );
        cur -> Merge( b , e );
        /**
        /// or this...
        cur -> sum = 0;
        if( cur -> l ) cur -> sum += cur -> l -> sum;
        else  cur -> sum += ( calc( mid ) - calc( b - 1 ) );
        if( cur -> r ) cur -> sum += cur -> r -> sum;
        else cur -> sum += ( calc( e ) - calc( mid ) );
        */
}
LL Query( pNode &cur , int b , int e , int i , int j ) {
        if( i > e || j < b || b > e ) return 0;
        if( !cur ) cur = new Node( b , e );
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
        for( int i = 1; i <= q; i++ ) {
                int type;
                cin >> type;
                if( type == 1 ) {
                        int l , r , val;
                        cin >> l >> r >> val;
                        Update( root , 1 , n , l , r , val );
                }
                else {
                        int l , r;
                        cin >> l >> r;
                        cout << Query( root , 1 , n , l , r ) << endl;
                }
        }
        return 0;
}











