#include <bits/stdc++.h>
using namespace std;

const int N = 8e4 + 5;
const int inf = 2e9;

int tree[ 4*N ];
int n , a[ N ];

void build( int node , int b , int e ) {
        if( b > e ) return;
        if( b == e ) {
                tree[node] = a[b];
                return;
        }
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        build( l , b , m );
        build( r , m + 1 , e );
        tree[node] = max( tree[l] , tree[r] );
}

int idx = -1;
int f;

void go( int node , int b , int e , int val ) {
        if( b > e ) return;
        if( b == e ) {
                if( tree[node] >= val ) idx = b;
                else idx = -1;
                return;
        }
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        if( tree[l] >= val ) go( l , b , m , val );
        else go( r , m + 1 , e , val );
}
void query( int node , int b , int e , int i , int j , int val ) {
        if( i > e || j < b || b > e ) return;
        if( f ) return;
        if( i == b && j == e ) {
                if( tree[node] >= val ) {
                        go( node , b , e , val );
                        f = 1;
                }
                else idx = e;
                return;
        }
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        query( l , b , m , i , min( j , m ) , val );
        query( r , m + 1 , e , max( m + 1 , i ) , j , val );
}
int main( ) {
        scanf("%d",&n);
        for( int i = 1; i <= n; i++ ) scanf("%d",&a[i]);
        build( 1 , 1 , n );
        long long ans = 0;
        for( int i = 1; i < n; i++ ) {
                idx = -1 , f = 0;
                query( 1 , 1 , n , i + 1 , n , a[i] );
                if( idx == -1 ) {
                        ans += n - i;
                }
                else {
                        if( a[idx] >= a[i] ) ans += ( idx - i - 1 );
                        else ans += ( n - i );
                }
        }
        printf("%lld\n",ans);
        return 0;
}






