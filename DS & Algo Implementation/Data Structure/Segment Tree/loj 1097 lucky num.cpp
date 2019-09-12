#include <bits/stdc++.h>
using namespace std;

template <typename T> class segment_tree {
    public:
        static const int MX = 2e6 + 5;
        T tree[ 4*MX ];
        void init( ) {
                memset( tree , 0 , sizeof( tree ) );
        }
        void build( int node , int b , int e ) {
                if( b > e ) return;
                if( b == e ) {
                        tree[node] = (b&1) ? 1 : 0;
                        return;
                }
                int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
                build( l , b , m );
                build( r , m + 1 , e );
                tree[node] = tree[l] + tree[r];
        }
        void update( int node , int b , int e , int pos ) {
                if( b > e || pos > e || pos < b ) return;
                if( b == e && b == pos ) {
                        tree[node] = 0;
                        return;
                }
                int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
                update( l , b , m , pos );
                update( r , m + 1 , e , pos );
                tree[node] = tree[l] + tree[r];
        }
        T query( int node , int b , int e , int k ) {
                if( b == e ) return b;
                int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
                if( tree[l] < k ) return query( r , m + 1 , e , k - tree[l] );
                else return query( l , b , m , k );
        }
    private:
        static const int inf = 1e9;
        static const long long INF = 1e18;
};

segment_tree <int> seg;

int main( ) {
        seg.init( );
        seg.build( 1 , 1 , 2e6 );
        int bad , val;
        for( int i = 2; i <= 2e6; i++ ) {
                bad = seg.query( 1 , 1 , 2e6 , i );
                val = bad;
                while( val < seg.tree[1] ) {
                        int k = seg.query( 1 , 1 , 2e6 , val );
                        seg.update( 1 , 1 , 2e6 , k );
                        val += bad;
                        val -= 1;
                }
        }
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
                int n;
                scanf("%d",&n);
                printf("Case %d: %d\n",tc,seg.query( 1 , 1 , 2e6 , n ));
        }
        return 0;
}






