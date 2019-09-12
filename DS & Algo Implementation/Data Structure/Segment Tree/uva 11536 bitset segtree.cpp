#include <bits/stdc++.h>
using namespace std;

const int inf = 1e7;
const int N = 1e6 + 1;
int n , m , k;
int a[ N ];
bitset <101> tree[ 4*N ] , null;

void generate_seq( ) {
        for( int i = 1; i <= n; i++ ) {
                if( i <= 3 ) a[i] = i;
                else a[i] = ( a[i-1] + a[i-2] + a[i-3] )%m + 1;
        }
}
void build( int node , int b , int e ) {
        if( b > e ) return;
        if( b == e ) {
                tree[node].reset();
                if( a[b] <= k ) tree[node].set( a[b] );
                return;
        }
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        build( l , b , m );
        build( r , m + 1 , e );
        tree[node] = ( tree[l] | tree[r] );
}
bitset <101> query( int node , int b , int e , int i , int j ) {
        if( i > e || j < b || b > e ) return null;
        if( i <= b && j >= e ) return tree[node];
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        return ( query( l , b , m , i , j ) | query( r , m + 1 , e , i , j ) );
}
int solve( ) {
        int ans = inf;
        for( int i = 1; i + k - 1 <= n; i++ ) {
                int lo = i , hi = n , ret = inf;
                while( lo <= hi ){
                        int mid = ( lo + hi ) >> 1;
                        bitset <101> b = query( 1 , 1 , n , i , mid );
                        if( b.count() == k ) ret = mid - i + 1 , hi = mid - 1;
                        else lo = mid + 1;
                }
                ans = min( ans , ret );
        }
        return ans;
}
int main( int argc , char const *argv[] ) {
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
                scanf("%d %d %d",&n,&m,&k);
                generate_seq( );
                build( 1 , 1 , n );
                int mn = solve( );
                if( mn == inf ) printf("Case %d: sequence nai\n",tc);
                else printf("Case %d: %d\n",tc,mn);
        }
        return 0;
}











