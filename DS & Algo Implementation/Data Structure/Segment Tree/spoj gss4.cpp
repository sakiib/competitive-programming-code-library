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
LL a[ N ];
LL tree[ 4*N ];
bool small[ 4*N ];

void build( int node , int b , int e ) {
        if( b > e ) return;
        if( b == e ) {
                tree[node] = a[b];
                small[node] = ( tree[node] <= 1 ? true : false );
                return;
        }
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        build( l , b , m );
        build( r , m + 1 , e );
        tree[node] = tree[l] + tree[r];
        small[node] = ( small[l]&small[r] );
}
void update( int node , int b , int e , int i , int j ) {
        if( i > e || j < b || b > e ) return;
        if( small[node] ) return;
        if( b == e ) {
                tree[node] = sqrt( tree[node] );
                small[node] = ( tree[node] <= 1 ? true : false );
                return;
        }
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        update( l , b , m , i , j );
        update( r , m + 1 , e , i , j );
        tree[node] = tree[l] + tree[r];
        small[node] = ( small[l]&small[r] );
}
LL query( int node , int b , int e , int i , int j ) {
        if( i > e || j < b|| b > e ) return 0;
        if( i <= b && j >= e ) return tree[node];
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        return query( l , b , m , i , j ) + query( r , m + 1 , e , i , j );
}
int main( int argc , char const *argv[] ) {
        int tc = 0;
        while( scanf("%d",&n) != EOF ) {
                for( int i = 1; i <= n; i++ ) scanf("%lld",&a[i]);
                build( 1 , 1 , n );
                scanf("%d",&q);
                printf("Case #%d:\n",++tc);
                while( q-- ) {
                        int type;
                        scanf("%d",&type);
                        if( type == 0 ) {
                                int l , r;
                                scanf("%d %d",&l,&r);
                                if( l > r ) swap( l , r );
                                update( 1 , 1 , n , l , r );
                        }
                        else {
                                int l , r;
                                scanf("%d %d",&l,&r);
                                if( l > r ) swap( l , r );
                                printf("%lld\n",query( 1 , 1 , n , l , r ) );
                        }
                }
                memset( tree , 0 , sizeof( tree ) );
                memset( small , false , sizeof( small ) );
        }
        return 0;
}











