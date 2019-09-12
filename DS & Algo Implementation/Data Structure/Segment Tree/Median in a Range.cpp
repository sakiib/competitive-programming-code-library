#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
typedef pair < int , int > ii;
const int inf = 1e9;
const LL INF = 1e18;
const int N = 1e5 + 5;
const int mod = 1000000007;
const double eps = 1e-8;
const double pi = acos( -1.0 );

/**
if total number are even median is the tot/2 , if odd then tot/2 + 1
*/
int n ,q;
int a[ N ] , b[ N ];
map <int,int> M , Ans;

struct node {
        node *l , *r;
        int val;
        node(){
                l = nullptr , r = nullptr , val = 0;
        }
        node( node *l , node *r , int val ):l(l), r(r), val(val){}

        node* update( int b , int e , int pos , int v ) {
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

        int query( node *prev , int b , int e , int k ) {
                if( b == e ) return b;
                int mid = ( b + e ) >> 1;
                int cnt = l -> val - prev -> l -> val;
                if( k <= cnt ) {
                        return l -> query( prev -> l , b , mid , k );
                }
                else {
                        return r -> query( prev -> r , mid+1 , e , k - cnt );
                }
        }

} *root[ 10*N ];

int main( int argc , char const *argv[] ) {
        scanf("%d",&n);
        for( int i = 1; i <= n; i++ ) {
                scanf("%d",&a[i]);
                M[ a[i] ];
        }
        int mx = 0;
        for( auto x : M ) {
                M[ x.first ] = ++mx;
                Ans[ mx ] = x.first;
        }
        node *null = new node( );
        null -> l = null -> r = null;
        root[0] = null;

        for( int i = 1; i <= n; i++ ) {
                root[i] = root[i-1] -> update( 1 , mx , M[a[i]] , +1 );
        }
        scanf("%d",&q);
        while( q-- ) {
                int l , r;
                scanf("%d %d",&l,&r);
                int tot = r - l + 1;
                int k = tot/2 + (tot&1);
                int id = root[r] -> query( root[l-1] , 1 , mx , k );
                printf("%d\n",Ans[id]);
        }
        return 0;
}






