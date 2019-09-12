#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
typedef pair < int , int > ii;
const int inf = 1e9;
const LL INF = 1e18;
const int N = 1e6 + 10;
const int mod = 1000000007;
const double eps = 1e-8;
const double pi = acos( -1.0 );

int n , q , a[ N ];

struct Node {
        int val;
        Node *l , *r;
        Node(){}
        Node( Node *l , Node *r , int val ):l(l),r(r),val(val){}
} *Version[ N ];

void Build( Node* node , int b , int e ) {
        if( b > e ) return;
        if( b == e ) {
                node -> val = a[b]; return;
        }
        int mid = ( b + e ) >> 1;
        node -> l = new Node( NULL , NULL , 0 );
        node -> r = new Node( NULL , NULL , 0 );
        Build( node -> l , b , mid );
        Build( node -> r , mid+1 , e );
        node -> val = ( node -> l -> val + node -> r -> val );
}
int Query( Node* node , int b , int e , int i , int j ) {
        if( b > e || i > e || j < b ) return 0;
        if( i <= b && j >= e ) return node -> val;
        int mid = ( b + e ) >> 1;
        int q1 = Query( node -> l , b , mid , i , j );
        int q2 = Query( node -> r , mid+1 , e , i , j );
        return ( q1 + q2 );
}
void update( Node* prev , Node* cur , int b , int e , int pos , int nval ) {
        if( b > e || pos > e || pos < 0 ) return;
        if( b == e && b == pos ) {
                cur -> val = ( prev -> val + nval ); return;
        }
        int mid = ( b + e ) >> 1;
        if( pos <= mid ) {
                cur -> r = prev -> r;
                cur -> l = new Node( NULL , NULL , 0 );
                update( prev -> l , cur -> l , b , mid , pos , nval );
        }
        else {
                cur -> l = prev -> l;
                cur -> r = new Node( NULL , NULL , 0 );
                update( prev -> r , cur -> r , mid+1 , e , pos , nval );
        }
        cur -> val = ( cur -> l -> val + cur -> r -> val );
}
int main( int argc , char const *argv[] ) {
        scanf("%d",&n);
        for( int i = 1; i <= n; i++ ) scanf("%d",&a[i]);
        Node *root = new Node( NULL , NULL , 0 );
        Build( root , 1 , n );
        Version[0] = root;
        int now = 0;
        scanf("%d",&q);
        while( q-- ) {
                int op;
                scanf("%d",&op);
                if( op == 1 ) {
                        int pv , pos , val;
                        scanf("%d %d %d",&pv,&pos,&val);
                        Version[ ++now ] = new Node( NULL , NULL , 0 );
                        update( Version[pv] , Version[now] , 1 , n , pos , val );
                }
                else {
                        int v , l , r;
                        scanf("%d %d %d",&v,&l,&r);
                        printf("%d\n",Query( Version[v] , 1 , n , l , r ) );
                }
        }
        return 0;
}






