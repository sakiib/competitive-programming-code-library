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

You have an empty set. You have to support  queries in the form -
1 X: Insert an element  in the set. It is guranteed that  isn't already present in the set.
2 X: Delete an element  from the set. It is guranteed that  is present in the set.
3 Y: Find and print sum of maximum  elements in the set. If there are less than  elements
 in the set, you need to print sum of all elements.

*/

struct Node {
        Node *l , *r;
        int cnt;
        LL val;
        Node( ) {
                l = NULL , r = NULL , cnt = 0 , val = 0;
        }
        void Merge( int b , int e ) {
                cnt = 0 , val = 0;
                int m = ( b + e ) >> 1;
                if( l ) cnt += l -> cnt , val += l -> val;
                if( r ) cnt += r -> cnt , val += r -> val;
        }
} *root;

typedef Node* pnode;

void update( pnode &cur , int b , int e , int pos , int add ) {
        if( pos > e || pos < b || b > e ) return;
        if( !cur ) cur = new Node( );
        if( pos == b && b == e ) {
                if( add == 1 ) cur -> cnt = 1 , cur -> val = pos;
                else cur -> cnt = 0 , cur -> val = 0;
                return;
        }
        int m = ( b + e ) >> 1;
        update( cur -> l , b , m , pos , add );
        update( cur -> r , m + 1 , e , pos , add );
        cur -> Merge( b , e );
}

/**
can be done like this without Binary Search..
call :
int pos = calc( root , 1 , inf , k );

LL calc( pnode &cur , int b , int e , int k ) {
        if( b == e ) return b;
        int m = ( b + e ) >> 1;
        if( !cur ) cur = new Node();
        if( !cur -> l ) cur -> l = new Node();
        if( !cur -> r ) cur -> r = new Node();
        if( cur -> r -> cnt >= k ) return calc( cur -> r , m + 1 , e , k );
        else return calc( cur -> l , b , m , k - cur -> r -> cnt );
}
*/
LL calc( pnode &cur , int b , int e , int i , int j ) {
        if( i > e || j < b || b > e ) return 0;
        if( !cur ) cur = new Node();
        if( i <= b && j >= e ) return cur -> cnt;
        int m = ( b + e ) >> 1;
        return ( calc( cur -> l , b , m , i , j ) + calc( cur -> r , m + 1 , e , i , j ) );
}
LL query( pnode &cur , int b , int e , int i , int j ) {
        if( i > e || j < b || b > e ) return 0;
        if( !cur ) cur = new Node();
        if( i <= b && j >= e ) return cur -> val;
        int m = ( b + e ) >> 1;
        return ( query( cur -> l , b , m , i , j ) + query( cur -> r , m + 1 , e , i , j ) );
}
LL solve( int k ) {
        LL lo = 1 , hi = inf , pos = 1;
        while( lo <= hi ) {
                LL mid = ( lo + hi ) >> 1;
                LL cur = calc( root , 1 , inf , mid , inf );
                if( cur <= k ) {
                        pos = mid;
                        hi = mid - 1;
                }
                else lo = mid + 1;
        }
        return query( root , 1 , inf , pos , inf );
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( NULL );

        root = NULL;

        int q;
        cin >> q;
        while( q-- ) {
                int type;
                cin >> type;
                if( type == 1 ) {
                        int val;
                        cin >> val;
                        update( root , 1 , inf , val , +1 );
                }
                else if( type == 2 ) {
                        int val;
                        cin >> val;
                        update( root , 1 , inf , val , -1 );
                }
                else if( type == 3 ) {
                        int k;
                        cin >> k;
                        cout << solve( k ) << endl;
                }
        }
        return 0;
}











