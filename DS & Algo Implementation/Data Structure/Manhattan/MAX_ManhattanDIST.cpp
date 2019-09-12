#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
const int inf = 1e9;
/**
 Maximum Manhattan distance between any two points in L to R
 Points are d - Dimensional
 1 - update a new point
 2 - range query
 */

int  Set( int N , int pos ) { return N |= ( 1 << pos ); }
int  Reset( int N , int pos ) { return N = N & ~( 1 << pos ); }
bool Check( int N , int pos ) { return (bool)( N & ( 1 << pos ) );}

int n , d;
int a[ N ][ 10 ];
int tree[ 4*N ][ ( 1 << 4 ) + 5 ][ 2 ];

void build( int node , int b , int e , int id ) {
        if( b > e ) return;
        if( b == e ) {
                for( int i = 0; i < d; i++ ) {
                        if( Check( id , i ) ) {
                                tree[node][id][0] += a[b][i];
                                tree[node][id][1] += a[b][i];
                        }
                        else {
                                tree[node][id][0] -= a[b][i];
                                tree[node][id][1] -= a[b][i];
                        }
                }
                return;
        }
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        build( l , b , m , id );
        build( r , m + 1 , e , id );
        tree[node][id][1] = max( tree[l][id][1] , tree[r][id][1] );
        tree[node][id][0] = min( tree[l][id][0] , tree[r][id][0] );
}
void update( int node , int b , int e , int pos , int id ) {
        if( pos > e || pos < b || b > e ) return;
        if( b == e && pos == b ) {
                tree[node][id][0] = 0;
                tree[node][id][1] = 0;
                for( int i = 0; i < d; i++ ) {
                        if( Check( id , i ) ) {
                                tree[node][id][0] += a[b][i];
                                tree[node][id][1] += a[b][i];
                        }
                        else {
                                tree[node][id][0] -= a[b][i];
                                tree[node][id][1] -= a[b][i];
                        }
                }
                return;
        }
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        update( l , b , m , pos , id );
        update( r , m + 1 , e , pos , id );
        tree[node][id][1] = max( tree[l][id][1] , tree[r][id][1] );
        tree[node][id][0] = min( tree[l][id][0] , tree[r][id][0] );
}
pair <int,int> query( int node , int b , int e , int i , int j , int id ) {
        if( i > e || j < b ) return {-inf,inf};
        if( i <= b && j >= e ) return { tree[node][id][1] , tree[node][id][0] };
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        pair <int,int> ret = {-inf,inf};
        pair <int,int> L = query( l , b , m , i , j , id );
        pair <int,int> R = query( r , m + 1 , e , i , j , id );
        ret.first = max( ret.first , max( L.first , R.first ) );
        ret.second = min( ret.second , min( L.second , R.second ) );
        return ret;
}
int main( int argc , char const *argv[] ) {
        scanf("%d %d",&n,&d);
        for(int i = 1; i <= n; i++ ) {
                for( int j = 0; j < d; j++ ) {
                        scanf("%d",&a[i][j]);
                }
        }
        for( int i = 0; i < ( 1 << ( d - 1 ) ); i++ ) build( 1 , 1 , n , i );
        int q;
        scanf("%d",&q);
        while( q-- ) {
                int type;
                scanf("%d",&type);
                if( type == 1 ) {
                        int pos;
                        scanf("%d",&pos);
                        for( int i = 0; i < d; i++ ) scanf("%d",&a[pos][i]);
                        for( int i = 0; i < ( 1 << ( d - 1 ) ); i++ ) update( 1 , 1 , n , pos , i );
                }
                else {
                        int l , r;
                        scanf("%d %d",&l,&r);
                        int ans = -inf;
                        for( int i = 0; i < ( 1 << ( d - 1 ) ); i++ ) {
                                pair <int,int> p = query( 1 , 1 , n , l , r , i );
                                ans = max( ans , abs( p.first - p.second ) );
                        }
                        printf("%d\n",ans);
                }
        }
        return 0;
}










