#include <bits/stdc++.h>
using namespace std;

/**
 This Solves uvalive 5061
 update , add a number in the path of two nodes
 query , total value on each node.
 */
struct HEAVYLIGHT_DECOMPOSITION {
        static const int MAXN = 5e4 + 5;
        static const int LOG = 20;
        typedef pair <int,int> ii;
        static const int INF = 1e9 + 5;

        int n , Node;
        int cost[ MAXN ];
        int A[ MAXN ] , sub[ MAXN ] , par[ MAXN ] , depth[ MAXN ];
        int chainNo , chainInd[ MAXN ] , chainHead[ MAXN ] , posInTree[ MAXN ];
        vector <int> graph[ MAXN ];
        int tree[ 4*MAXN ] , lazy[ 4*MAXN ];

        void Initialize( int _n ) {
                n = _n;
                memset( tree , 0 , sizeof(tree) );
                memset( lazy , 0 , sizeof(lazy) );
                chainNo = 0 , Node = 1;
                for( int i = 0; i < MAXN; i++ ) {
                        graph[i].clear();
                        A[i] = 0 , sub[i] = 0 , cost[i] = 0;
                        chainInd[i] = 0 , chainHead[i] = -1 , posInTree[i] = 0;
                }
        }
        void AddEdge( int u , int v ) {
                graph[ u ].push_back( v ); graph[ v ].push_back( u );
        }
        void dfs( int s , int p ) {
                par[s] = p , sub[s] = 1 , depth[s] = depth[p] + 1;
                for( int i = 0; i < graph[s].size(); i++ ) {
                        int v = graph[s][i];
                        if( v != p ) {
                                dfs( v , s );
                                sub[s] += sub[v];
                        }
                }
        }
        void HLD( int s , int p ) {
                if( chainHead[ chainNo ] == -1 ) chainHead[ chainNo ] = s;
                chainInd[ s ] = chainNo;
                posInTree[ s ] = Node;
                A[ Node++ ] = cost[ s ];
                int mxChild = -1;
                for( int i = 0; i < graph[s].size(); i++ ) {
                        int v = graph[s][i];
                        if( v != p ) {
                                if( mxChild == -1 || sub[ mxChild ] < sub[ v ] ) {
                                        mxChild = v;
                                }
                        }
                }
                if( mxChild != -1 ) HLD( mxChild , s );
                for( int i = 0; i < graph[s].size(); i++ ) {
                        int v = graph[s][i];
                        if( v != p && v != mxChild ) {
                                chainNo++;
                                HLD( v , s );
                        }
                }
        }
        int LCA( int u , int v ) {
                while( 1 ) {
                        int pu = chainHead[ chainInd[u] ] , pv = chainHead[ chainInd[v] ];
                        if( pu == pv ) return ( depth[ u ] < depth[ v ] ? u : v );
                        if( depth[ pu ] < depth[ pv ] ) v = par[ pv ];
                        else u = par[ pu ];
                }
        }
        void Propagate( int node , int b , int e ) {
                if( lazy[ node ] != 0 ) {
                        tree[node] += ( lazy[ node ] * ( e - b + 1 ) );
                        if( b != e ) {
                                lazy[ 2 * node ] += lazy[ node ];
                                lazy[ 2 * node + 1 ] += lazy[ node ];
                        }
                        lazy[ node ] = 0;
                }
        }
        void Build( int node , int b , int e ) {
                if( b > e ) return;
                if( b == e ) {
                        tree[ node ] = A[ b ]; return;
                }
                int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
                Build( l , b , m );
                Build( r , m+1 , e );
                tree[ node ] = tree[ l ] + tree[ r ];
        }
        int Query( int node , int b , int e , int i , int j ) {
                Propagate( node , b , e );
                if( b > e || i > e || j < b ) return 0;
                if( i <= b && j >= e ) return tree[node];
                int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
                return Query( l , b , m , i , j ) + Query( r , m + 1 , e , i , j );
        }
        void Update( int node , int b , int e , int i , int j , int v ) {
                Propagate( node , b , e );
                if( i > e || j < b || b > e ) return;
                if( i <= b && j >= e ) {
                        tree[ node ] += ( v * ( e - b + 1 ) );
                        if( b != e ) {
                                lazy[ 2 * node ] += v;
                                lazy[ 2 * node + 1 ] += v;
                        }
                        return;
                }
                int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
                Update( l , b , m , i , j , v );
                Update( r , m + 1 , e , i , j , v );
                tree[ node ] = tree[ l ] + tree[ r ];
        }
        int QueryUP( int u , int v ) {
                if( u == v ) return Query( 1 , 1 , Node , posInTree[ u ] , posInTree[ u ] );
                int uchain , vchain = chainInd[ v ];
                int ans = 0;
                while( true ) {
                        uchain = chainInd[ u ];
                        if( uchain == vchain ) {
                                int st = posInTree[ v ] , en = posInTree[ u ];
                                int ret = Query( 1 , 1 , Node , st , en );
                                ans = ans + ret;
                                break;
                        }
                        int st = posInTree[ chainHead[ uchain ] ] , en = posInTree[ u ];
                        int ret = Query( 1 , 1 , Node , st , en );
                        ans = ans + ret;
                        u = chainHead[ uchain ] , u = par[ u ];
                }
                return ans;
        }
        void UpdateUP( int u , int v , int w ) {
                if( u == v ) {
                        Update( 1 , 1 , Node , posInTree[ u ] , posInTree[ u ] , w );
                        return;
                }
                int uchain , vchain = chainInd[ v ];
                while( true ) {
                        uchain = chainInd[ u ];
                        if( uchain == vchain ) {
                                int st = posInTree[ v ] , en = posInTree[ u ];
                                Update( 1 , 1 , Node , st , en , w );
                                break;
                        }
                        int st = posInTree[ chainHead[ uchain ] ] , en = posInTree[ u ];
                        Update( 1 , 1 , Node , st , en , w );
                        u = chainHead[ uchain ] , u = par[ u ];
                }
        }
        void UpdateHLD( int u , int v , int w ) {
                int lca = LCA( u , v );
                UpdateUP( u , lca , w );
                UpdateUP( v , lca , w );
                UpdateUP( lca , lca , -w );
        }
        int QueryHLD( int u , int v ) {
                int lca = LCA( u , v );
                int x = QueryUP( u , lca ), y = QueryUP( v , lca ), z = QueryUP( lca , lca );
                return ( x + y - z );
        }

} hld;

int main( int argc , char const *argv[] ) {
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
                int n;
                scanf("%d",&n);

                hld.Initialize( n );

                for( int i = 1; i <= n-1; i++ ) {
                        int u , v;
                        scanf("%d %d",&u,&v);

                        hld.AddEdge( ++u , ++v );
                }

                hld.dfs( 1 , 0 );
                hld.HLD( 1 , 0 );
                hld.Build( 1 , 1 , hld.Node );

                int q;
                scanf("%d",&q);
                while( q-- ) {
                        int u , v , w;
                        scanf("%d %d %d",&u,&v,&w);
                        hld.UpdateHLD( ++u , ++v , w );
                }
                printf("Case #%d:\n",tc);
                for( int i = 1; i <= n; i++ ) {
                        printf("%d\n",hld.QueryHLD( i , i ) );
                }
        }
        return 0;
}













