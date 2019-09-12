#include <bits/stdc++.h>
using namespace std;

const int N = 500 + 5;
int n , q , a[ N ][ N ];

template <typename T> class segment_tree {
    public:
        static const int N = 505;
        T tree[ 4*N ];
        void init( ) {
                memset( tree , 0 , sizeof( tree ) );
        }
        void build( int node , int b , int e , int row ) {
                if( b > e ) return;
                if( b == e ) {
                        tree[node] = a[row][b];
                        return;
                }
                int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
                build( l , b , m , row );
                build( r , m + 1 , e , row );
                tree[node] = max( tree[l] , tree[r] );
        }
        T query( int node , int b , int e , int i , int j ) {
                if( i > e || j < b || b > e ) return -inf;
                if( i <= b && j >= e ) return tree[node];
                int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
                return max( query( l , b , m , i , j ) ,
                            query( r , m + 1 , e , i , j ) );
        }
    private:
        static const int inf = 1e9;
};

segment_tree <int> tree[ N ];

int main( ) {
        //freopen( "input.txt" ,"r", stdin );
        //freopen( "output.txt" , "w" , stdout );
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
                scanf("%d %d",&n,&q);
                for( int i = 1; i <= n; i++ ) {
                        for( int j = 1; j <= n; j++ ) {
                                scanf("%d",&a[i][j]);
                        }
                }
                for( int i = 1; i <= n; i++ ) tree[i].init();
                for( int i = 1; i <= n; i++ ) tree[i].build( 1 , 1 , n , i );
                printf("Case %d:\n",tc);
                while( q-- ) {
                        int l , r , s;
                        scanf("%d %d %d",&l,&r,&s);
                        int ans = -1e9;
                        for( int i = l; i <= l + s - 1; i++ ) {
                                ans = max( ans , tree[i].query( 1 , 1 , n , r , r + s - 1 ) );
                        }
                        printf("%d\n",ans);
                }
        }
        return 0;
}







