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

LL a[ N ];

struct node {
        node *l , *r;
        LL val;
        node(){}
        node( node *l , node *r , int val ):l(l), r(r), val(val){}

        void build( int b , int e ) {
                if( b > e ) return;
                if( b == e ) {
                        val = a[b]; return;
                }
                l = new node();
                r = new node();
                int mid = ( b + e ) >> 1;
                l -> build( b , mid );
                r -> build( mid+1 , e );
                val = ( l -> val + r -> val );
        }

        node* update( int b , int e , int pos , LL v ) {
                if( b > e || pos > e || pos < b ) return this;
                if( b == e && b == pos ) {
                        node *ret = new node( l , r , val );
                        ret -> val += v;
                        return ret;
                }
                int mid = ( b + e ) >> 1;

                node *ret = new node();

                if( pos <= mid ) {
                      ret -> r = r;
                      ret -> l = l -> update( b , mid , pos , v );
                }
                else {
                      ret -> l = l;
                      ret -> r = r -> update( mid+1 , e , pos , v );
                }
                // This works too..
                //ret -> l = l -> update( b , mid , pos , v );
                //ret -> r = r -> update( mid+1 , e , pos , v );
                ret -> val = ( ret -> l -> val + ret -> r -> val );
                return ret;
        }

        LL query( int b , int e , int i , int j ) {
                if( b > e || i > e || j < b ) return 0;
                if( i <= b && j >= e ) return val;
                int mid = ( b + e ) >> 1;
                LL q1 = l -> query( b , mid , i , j );
                LL q2 = r -> query( mid+1 , e , i , j );
                return ( q1 + q2 );
        }

} *root[ N ];

int main( int argc , char const *argv[] ) {
        int n;
        scanf("%d",&n);
        for( int i = 1; i <= n; i++ ) scanf("%lld",&a[i]);
        root[0] = new node();
        root[0] -> build( 1 , n );
        int q;
        scanf("%d",&q);
        int k = 0;
        while( q-- ) {
                int type , idx , x , y;
                scanf("%d %d %d %d",&type,&idx,&x,&y);
                if( type == 1 ) {
                        root[ ++k ] = root[idx] -> update( 1 , n , x , y );
                }
                else {
                        printf("%lld\n",root[idx] -> query( 1 , n , x , y ));
                }
        }
        return 0;
}






