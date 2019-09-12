#include <bits/stdc++.h>
using namespace std;

struct HeavyLightDecomposition {
        static const int N = 30005;

        int n , pos_base , chn_no , val[ N ];
        int par[ N ] , big_child[ N ] , sub[ N ] , depth[ N ]; // Tree
        int chn_ID[ N ] , chn_head[ N ] , chn_pos[ N ]; // HLD
        int a[ N ] , tree[ 4*N ]; // Segment tree
        vector <int> graph[ N ];

        void Init( int _n ) {
                n = _n , pos_base = 0 , chn_no = 1 , depth[0] = 0;
                for( int i = 0; i < N; i++ ) {
                        graph[i].clear();
                        par[ i ] = chn_head[ i ] = big_child[ i ] = -1;
                }
                memset( tree , 0 , sizeof tree );
        }

        void AddEdge( int u , int v ) {
                ++u , ++v;
                graph[ u ].push_back( v );
                graph[ v ].push_back( u );
        }

        void dfs( int s , int p ) {
                par[ s ] = p , sub[ s ] = 1;
                depth[ s ] = depth[ p ] + 1;
                int mx = -1;
                for( int i = 0; i < graph[ s ].size(); i++ ) {
                        int v = graph[ s ][ i ];
                        if( v != p ) {
                                dfs( v , s );
                                sub[ s ] += sub[ v ];
                                if( sub[ v ] > mx ) {
                                        mx = sub[ v ] , big_child[ s ] = v;
                                }
                        }
                }
        }

        void HL_Decomposition( int s , int p ) {
                chn_ID[ s ] = chn_no;
                chn_pos[ s ] = ++pos_base;
                a[ pos_base ] = val[ s ];
                if( chn_head[ chn_no ] == -1 ) chn_head[ chn_no ] = s;

                if( big_child[ s ] != -1 ) HL_Decomposition( big_child[ s ] , s );

                for( int i = 0; i < graph[ s ].size(); i++ ) {
                        int v = graph[ s ][ i ];
                        if( v != p && v != big_child[ s ] ) {
                                chn_no++;
                                HL_Decomposition( v , s );
                        }
                }
        }

        void Build( int node , int b , int e ) {
                if( b > e ) return;
                if( b == e ) {
                        tree[ node ] = a[ b ]; return;
                }
                int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
                Build( l , b , m );
                Build( r , m+1 , e );
                tree[ node ] = tree[ l ] + tree[ r ];
        }

        void Update( int node , int b , int e , int pos , int nval ) {
                if( b > e || pos > e || pos < b ) return;
                if( b == e && b == pos ) {
                        tree[node] = nval; return;
                }
                int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
                Update( l , b , m , pos , nval );
                Update( r , m+1 , e , pos , nval );
                tree[ node ] = tree[ l ] + tree[ r ];
        }

        void UpdateHLD( int node , int b , int e , int pos , int nval ) {
                Update( node , b , e , chn_pos[ pos ] , nval );
        }

        int Query( int node , int b , int e , int i , int j ) {
                if( i > e || j < b || b > e ) return 0;
                if( i <= b && j >= e ) return tree[ node ];
                int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
                int q1 = Query( l , b , m , i , j );
                int q2 = Query( r , m+1 , e , i , j );
                return ( q1 + q2 );
        }

        int QueryHLD( int u , int v ) {
                int ans = 0;
                while( chn_ID[ u ] != chn_ID[ v ] ) {
                        int hu = chn_head[ chn_ID[u] ];
                        int hv = chn_head[ chn_ID[v] ];
                        if( depth[ hu ] > depth[ hv ] ) {
                                ans += Query( 1 , 1 , pos_base , chn_pos[ hu ] , chn_pos[ u ] );
                                u = par[ hu ];
                        }
                        else {
                                ans += Query( 1 , 1 , pos_base , chn_pos[ hv ] , chn_pos[ v ] );
                                v = par[ hv ];
                        }
                }
                int L , R;
                if( depth[ u ] < depth[ v ] ) L = chn_pos[ u ] , R = chn_pos[ v ];
                else L = chn_pos[ v ] , R = chn_pos[ u ];
                ans += Query( 1 , 1 , pos_base , L , R );
                return ans;
        }

} hld;

int main( int argc , char const *argv[] ) {
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
                int n;
                scanf("%d",&n);

                hld.Init( n );

                for( int i = 1; i <= n; i++ ) scanf("%d",&hld.val[i]);

                for( int i = 1; i <= n-1; i++ ) {
                        int u , v;
                        scanf("%d %d",&u,&v);
                        hld.AddEdge( u , v );
                }

                hld.dfs( 1 , 0 );
                hld.HL_Decomposition( 1 , 0 );
                hld.Build( 1 , 1 , hld.pos_base );

                printf("Case %d:\n",tc);

                int q;
                scanf("%d",&q);
                for( int i = 1; i <= q; i++ ) {
                        int op;
                        scanf("%d",&op);
                        if( op == 1 ) {
                                int pos , new_val;
                                scanf("%d %d",&pos,&new_val);
                                hld.UpdateHLD( 1 , 1 , hld.pos_base , ++pos , new_val );
                        }
                        else {
                                int u , v;
                                scanf("%d %d",&u,&v);
                                printf("%d\n",hld.QueryHLD( ++u , ++v ));
                        }
                }

        }
        return 0;
}






