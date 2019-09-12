#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long uLL;
typedef long long int LL;
const int N = 1e5 + 5;
const int inf = 1e9;
const long long INF = 1e18;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int MOD = 1000000007;

int n , q;
int tree[ 4*N ] , lazy[ 4*N ];

void pushdown( int node , int b , int e ) {
        if( lazy[node] == 0 ) return;
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        tree[l] = ( m - b + 1 ) - tree[l];
        tree[r] = ( e - m ) - tree[r];
        lazy[l] ^= 1;
        lazy[r] ^= 1;
        lazy[node] = 0;
}
void update( int node , int b , int e , int i , int j ) {
        if( i > e || j < b || b > e ) return;
        if( i <= b && j >= e ) {
                tree[node] = ( e - b + 1 ) - tree[node];
                lazy[node] ^= 1;
                return;
        }
        pushdown( node , b , e );
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        update( l , b , m , i , j );
        update( r , m + 1 , e , i , j );
        tree[node] = tree[l] + tree[r];
}
int query( int node , int b , int e , int i , int j ) {
        if( i > e || j < b || b > e ) return 0;
        if( i <= b && j >= e ) return tree[node];
        pushdown( node , b , e );
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        return query( l , b , m , i , j ) + query( r , m + 1 , e , i , j );
}
int main( int argc , char const *argv[] ) {
        scanf("%d %d",&n,&q);
        while( q-- ) {
                int type , l , r;
                scanf("%d %d %d",&type,&l,&r);
                if( type == 0 ) update( 1 , 1 , n , l , r );
                else printf("%d\n",query( 1 , 1 , n , l , r ) );
        }
        return 0;
}






