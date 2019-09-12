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

int n , q;
int a[ N ];

struct Node {
        Node *l , *r;
        int MN;
        Node( ) {
                l = NULL , r = NULL , MN = inf;
        }
        Node( int idx ) {
                l = NULL , r = NULL , MN = a[idx];
        }
        void Merge( int b , int e ) {
                MN = inf;
                int m = ( b + e ) >> 1;
                if( l ) MN = min( MN , l -> MN );
                if( r ) MN = min( MN , r -> MN );
        }
} *root;

typedef Node* pnode;

int query( pnode &cur , int b , int e , int i , int j ) {
        if( i > e || j < b || b > e ) return inf;
        if( i <= b && j >= e ) return cur -> MN;
        int m = ( b + e ) >> 1;
        return min( query( cur -> l , b , m , i , j ) , query( cur -> r , m + 1 , e , i , j ) );
}
void update( pnode &cur , int b , int e , int pos , int val ) {
        if( pos > e || pos < b || b > e ) return;
        if( !cur ) cur = new Node( );
        if( b == e && b == pos ) {
                cur -> MN = a[b];
                return;
        }
        int m = ( b + e ) >> 1;
        update( cur -> l , b , m , pos , val );
        update( cur -> r , m + 1 , e , pos , val );
        cur -> Merge( b , e );
}
int solve( int l , int r ) {
        return query( root , 1 , n , l , r );
}
int main( int argc , char const *argv[] ) {
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
                scanf("%d %d",&n,&q);
                root = NULL;
                for( int i = 1; i <= n; i++ ) {
                        scanf("%d",&a[i]);
                        update( root , 1 , n , i , a[i] );
                }
                printf("Case %d:\n",tc);
                while( q-- ) {
                        int l , r;
                        scanf("%d %d",&l,&r);
                        printf("%d\n",solve( l , r ) );
                }
        }
        return 0;
}











