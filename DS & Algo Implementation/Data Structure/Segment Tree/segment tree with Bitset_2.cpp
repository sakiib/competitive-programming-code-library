#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;

int n , q;

vector <int> graph[ N ];
bitset <101> tree[ 4*N ] , null; /// Thnx to Aminul vai for the idea of bitset.

int col[ N ];
int st[ N ] , en[ N ] , Time;

/**
 tree er subtree the odd color kotogula ache , tai xor
 update change a nodes color
 */

void flat_it( int s , int p ) { /// make it linear for subtree query
        st[s] = ++Time;
        for( auto x : graph[s] ) {
                if( x != p ) flat_it( x , s );
        }
        en[s] = Time;
}
void build( int node , int b , int e , int pos , int c ) {
        if( b > e || pos > e || pos < b ) return;
        if( b == e && b == pos ) {
                tree[node].reset();
                tree[node].set( c );
                return;
        }
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        build( l , b , m , pos , c );
        build( r , m + 1 , e , pos , c );
        tree[node] = ( tree[l] ^ tree[r] );
}
bitset <101> query( int node , int b , int e , int i , int j ) {
        if( i > e || j < b || b > e ) return null;
        if( i <= b && j >= e ) return tree[node];
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        return ( query( l , b , m , i , j ) ^ query( r , m + 1 , e , i , j ) );
}
void update( int node , int b , int e , int pos , int nc ) {
        if( b > e || pos > e || pos < b ) return;
        if( b == e && b == pos ) {
                tree[node].reset( );
                tree[node].set( nc );
                return;
        }
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        update( l , b , m , pos , nc );
        update( r , m + 1 , e , pos , nc );
        tree[node] = ( tree[l] ^ tree[r] );
}
int main( int argc , char const *argv[] ) {
        scanf("%d %d",&n,&q);
        for( int i = 1; i <= n; i++ ) scanf("%d",&col[i]);
        for( int i = 2; i <= n; i++ ) {
                int x;
                scanf("%d",&x);
                graph[i].push_back( x );
                graph[x].push_back( i );
        }
        flat_it( 1 , 0 );
        for( int i = 1; i <= n; i++ ) build( 1 , 1 , Time , st[i] , col[i] );
        while( q-- ) {
                int type;
                scanf("%d",&type);
                if( type == 0 ) {
                        int node;
                        scanf("%d",&node);
                        int ans = 0;
                        bitset <101> B = query( 1 , 1 , Time , st[node] , en[node] );
                        ans = B.count( );
                        printf("%d\n",ans);
                }
                else {
                        int node;
                        scanf("%d",&node);
                        update( 1 , 1 , Time , st[node] , type );
                }
        }
        return 0;
}






