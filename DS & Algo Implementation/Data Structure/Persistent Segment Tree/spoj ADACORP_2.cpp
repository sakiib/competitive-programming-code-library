#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
typedef unsigned long long uLL;
typedef long long int LL;
typedef pair <int,int> pii;
typedef pair <int,pii> piii;
typedef pair <long long,long long> pll;
typedef pair <long long,pll> plll;
const int N = 2e5 + 5;
const int inf = 1e9;
const long long INF = 1e18;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int MOD = 1000000007;

int n , q;
int a[ N ];

struct Node {
        Node *l , *r;
        int sum;
        Node( ) : l( nullptr ) , r( nullptr ) , sum( 0 ) {}
        Node( Node *l , Node *r , int sum ) : l( l ) , r( r ) , sum( sum ) {}
};

Node* tree[ 4*N ];

void update( Node *cur , int b , int e , int pos , int val ) {
        if( b > e || pos > e || pos < b ) return;
        if( !cur ) cur = new Node();
        if( b == e && b == pos ) {
                cur -> sum += val;
                return;
        }
        if( !(cur->l) ) cur->l = new Node();
        if( !(cur->r) ) cur->r = new Node();
        int m = ( b + e ) >> 1;
        update( cur -> l , b , m , pos , val );
        update( cur -> r , m + 1 , e , pos , val );
        cur -> sum = 0;
        if( cur -> l ) cur -> sum += cur -> l -> sum;
        if( cur -> r ) cur -> sum += cur -> r -> sum;
}
int query( Node *cur , int b , int e , int i , int j ) {
        if( !cur ) return 0;
        if( i > e || j < b || b > e ) return 0;
        if( i <= b && j >= e ) return cur -> sum;
        int m = ( b + e ) >> 1;
        int ret = 0;
        if( cur -> l ) ret += query( cur -> l , b , m , i , j );
        if( cur -> r ) ret += query( cur -> r , m + 1 , e , i , j );
        return ret;
}

map <int,int> M;
int id;

int create( int x ) {
        if( M[x] != 0 ) return M[x];
        M[x] = ++id;
        tree[ M[x] ] = new Node();
        return M[x];
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( nullptr );
        cin >> n >> q;
        for( int i = 1; i <= n; i++ ) {
                cin >> a[i];
                int id = create( a[i] );
                update( tree[id] , 1 , n , i , +1 );
                a[i] = id;
        }
        while( q-- ) {
                int pos , val;
                cin >> pos >> val;
                ++pos;
                update( tree[ a[pos] ] , 1 , n , pos , -1 );
                int id = create( val );
                a[pos] = id;
                cout << query( tree[id] , 1 , n , 1 , pos - 1 ) << endl;
                update( tree[id] , 1 , n , pos , +1 );
        }
        return 0;
}











