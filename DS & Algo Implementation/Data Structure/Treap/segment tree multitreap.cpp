#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define endl "\n"
#define all(V) V.begin(), V.end()
#define Unique(V) sort(all(V)), V.erase(unique(all(V)), V.end())
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long int LL;
const int N = 2e5 + 5;

template <typename T> using
    Treap = tree<T,null_type,
    less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;

Treap <int> t[ 4*N ];
int n , a[ N ];

void build( int node , int b , int e ) {
        if( b > e ) return;
        for( int i = b; i <= e; i++ ) t[node].insert( a[i] );
        if( b == e ) return;
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        build( l , b , m );
        build( r , m + 1 , e );
}
void update( int node , int b , int e , int pos , int nval , int pval ) {
        if( b > e || pos > e || pos < b ) return;
        t[node].erase( t[node].find_by_order( t[node].order_of_key( pval ) ) );
        t[node].insert( nval );
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        if( b == e ) return;
        update( l , b , m , pos , nval , pval );
        update( r , m + 1 , e , pos , nval , pval );
}
int getsmall( int node , int b , int e , int i , int j , int x ) {
        if( i > e || j < b || b > e  ) return 0;
        if( i <= b && j >= e ) return t[node].order_of_key( x );
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        return getsmall( l , b , m , i , j , x ) + getsmall( r , m+1 , e , i , j , x );
}
int getbig( int node , int b , int e , int i , int j , int x ) {
        if( i > e || j < b || b > e  ) return 0;
        if( i <= b && j >= e ) return t[node].size() - t[node].order_of_key( x+1 );
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        return getbig( l , b , m , i , j , x ) + getbig( r , m+1 , e , i , j , x );
}
int main( ) {
        #ifdef OFFLINE
            freopen( "input.txt" , "r" , stdin );
        #endif // OFFLINE
        scanf("%d",&n);
        for( int i = 1; i <= n; i++ ) scanf("%d",&a[i]);
        build( 1 , 1 , n );
        LL ans = 0;
        for( int i = 1; i < n; i++ ) ans += getsmall( 1 , 1 , n , i + 1 , n , a[i] );
        int q;
        scanf("%d",&q);
        while( q-- ) {
                int pos , val;
                scanf("%d %d",&pos,&val);
                ans -= getsmall( 1 , 1 , n , pos + 1 , n , a[pos] );
                ans -= getbig( 1 , 1 , n , 1 , pos - 1 , a[pos] );
                update( 1 , 1 , n , pos , val , a[pos] );
                a[pos] = val;
                ans += getsmall( 1 , 1 , n , pos + 1 , n , a[pos] );
                ans += getbig( 1 , 1 , n , 1 , pos - 1 , a[pos] );
                printf("%lld\n",ans);
        }
        return 0;
}






