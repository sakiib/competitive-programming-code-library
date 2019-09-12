#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
typedef pair < int , int > ii;
const int inf = 1e9;
const LL INF = 1e18;
const int N = 3e5 + 5;
const int mod = 1000000007;
const double eps = 1e-8;
const double pi = acos( -1.0 );

int n , q;
int a[ N ];

struct node {
        node *l , *r;
        int val;
        node(){
                l = nullptr , r = nullptr , val = 0;
        }
        node( node *l , node *r , int val ):l(l), r(r), val(val){}

        inline node* update( int b , int e , int pos , int v ) {
                if( b > e || pos > e || pos < b ) return this;
                if( b == e && b == pos ) {
                        node *ret = new node( l , r , val );
                        ret -> val += v;
                        return ret;
                }
                int mid = ( b + e ) >> 1;
                node *ret = new node( );
                if( pos <= mid ) {
                        ret -> r = r;
                        ret -> l = l -> update( b , mid , pos , v );
                }
                else {
                        ret -> l = l;
                        ret -> r = r -> update( mid+1 , e , pos , v );
                }
                ret -> val = ( ret -> l -> val + ret -> r -> val );
                return ret;
        }

        inline int query( node *prev , int b , int e , int k ) {
                if( b > e ) return -1;
                if( b == e ) {
                        if( val - prev -> val >= k ) return b;
                        else return -1;
                }
                int mid = ( b + e ) >> 1;
                int lefsum = 0;
                if( l ) lefsum += l -> val;
                if( prev -> l ) lefsum -= prev -> l -> val;
                if( lefsum >= k ) {
                        int res = l -> query( prev -> l , b , mid , k );
                        if( res != -1 ) return res;
                }
                int righsum = 0;
                if( r ) righsum += r -> val;
                if( prev -> r ) lefsum -= prev -> r -> val;
                if( righsum >= k ) {
                        int res = r -> query( prev -> r , mid + 1 , e , k );
                        if( res != -1 ) return res;
                }
                return -1;
        }


} *root[ 10*N + 5 ];

int main( int argc , char const *argv[] ) {
        scanf("%d %d",&n,&q);
        for( int i = 1; i <= n; i++ ) scanf("%d",&a[i]);
        node *null = new node( );
        null -> l = null -> r = null;
        root[0] = null;
        for( int i = 1; i <= n; i++ ) {
                root[i] = root[i-1] -> update( 1 , N , a[i] , +1 );
        }
        while( q-- ) {
                int l , r , k;
                scanf("%d %d %d",&l,&r,&k);
                int ans = root[r] -> query( root[l-1] , 1 , N , ((r-l+1)/k+1) );
                printf("%d\n",ans);
        }
        return 0;
}








