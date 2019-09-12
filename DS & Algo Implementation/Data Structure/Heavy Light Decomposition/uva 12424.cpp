#include <bits/stdc++.h>
using namespace std;

struct HeavyLightDecomposition {
        static const int N = 1e5 + 5;
        static const int lgN = 20;
        typedef pair <int,int> ii;
        static const int inf = 1e9 + 5;

        int n , Node;

        int col[ N ];
        int A[ N ] , sub[ N ] , par[ N ] , depth[ N ];
        int chainNo , chainInd[ N ] , chainHead[ N ] , posInTree[ N ];
        int cnt[ 15 ];

        vector <int> graph[ N ];

        int tree[ 4 *N ][ 15 ];

        void initialize( int _n ) {
                n = _n;
                memset( tree , 0 , sizeof(tree) );
                chainNo = 0 , Node = 1;
                for( int i = 0; i < N; i++ ) {
                        graph[i].clear();
                        A[i] = 0 , sub[i] = 0 , col[i] = 0 , depth[i] = 0;
                        chainInd[i] = 0 , chainHead[i] = -1 , posInTree[i] = 0;
                }
        }
        void AddEdge( int u , int v ) {
                graph[ u ].push_back( v ) , graph[ v ].push_back( u );
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
                A[ Node++ ] = col[ s ];
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
        void Build( int node , int b , int e ) {
                if( b > e ) return;
                if( b == e ) {
                        tree[ node ][ A[ b ] ] += 1; return;
                }
                int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
                Build( l , b , m );
                Build( r , m+1 , e );
                for( int i = 1; i <= 10; i++ ) tree[ node ][ i ] = tree[ l ][ i ] + tree[ r ][ i ];
        }
        int Query( int node , int b , int e , int i , int j , int c ) {
                if( b > e || i > e || j < b ) return 0;
                if( i <= b && j >= e ) return tree[ node ][ c ];
                int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
                int q1 = Query( l , b , m , i , j , c );
                int q2 = Query( r , m+1 , e , i , j , c );
                return q1 + q2;
        }
        void Update( int node , int b , int e , int pos , int pc ,  int v ) {
                if( b > e || pos > e || pos < b ) return;
                if( b == e && b == pos ) {
                        tree[ node ][ pc ] -= 1;
                        tree[ node ][ v ] += 1;
                        return;
                }
                int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
                Update( l , b , m , pos , pc , v );
                Update( r , m+1 , e , pos , pc , v );
                for( int i = 1; i <= 10; i++ ) tree[ node ][ i ] = tree[ l ][ i ] + tree[ r ][ i ];
        }
        void QueryUP( int u , int v , int f ) {
                if( u == v ) {
                        for( int i = 1; i <= 10; i++ ) {
                              if( f ) cnt[i] += Query( 1 , 1 , Node , posInTree[ u ] , posInTree[ u ] , i );
                              else if( !f ) cnt[i] -= Query( 1 , 1 , Node , posInTree[ u ] , posInTree[ u ] , i );
                        }
                        return;
                }
                int uchain , vchain = chainInd[ v ];
                while( 1 ) {
                        uchain = chainInd[ u ];
                        if( uchain == vchain ) {
                                int st = posInTree[ v ] , en = posInTree[ u ];
                                for( int i = 1; i <= 10; i++ ) {
                                        if( f ) cnt[i] += Query( 1 , 1 , Node , st , en , i );
                                        else if( !f ) cnt[i] -= Query( 1 , 1 , Node , st , en , i );
                                }
                                break;
                        }
                        int st = posInTree[ chainHead[ uchain ] ] , en = posInTree[ u ];
                        for( int i = 1; i <= 10; i++ ) {
                                if( f ) cnt[i] += Query( 1 , 1 , Node , st , en , i );
                                else if( !f ) cnt[i] -= Query( 1 , 1 , Node , st , en , i );
                        }
                        u = chainHead[ uchain ] , u = par[ u ];
                }
                return;
        }
        void UpdateHLD( int pos , int prevc ,  int v ) {
                Update( 1 , 1 , Node , posInTree[ pos ] , prevc ,  v );
        }
        int QueryHLD( int u , int v ) {
                memset( cnt , 0 , sizeof(cnt) );
                int lca = LCA( u , v );
                QueryUP( u , lca , 1 );
                QueryUP( v , lca , 1 );
                QueryUP( lca , lca , 0 );
                int mx = 0;
                for( int i = 1; i <= 10; i++ ) mx = max( mx , cnt[i] );
                return mx;
        }
        void BuildHLD( ) {
                Build( 1 , 1 , Node );
        }

} hld;

int main( int argc , char const *argv[] ) {
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
                int n , q;
                scanf("%d %d",&n,&q);

                hld.initialize( n );

                for( int i = 1; i <= n; i++ ) scanf("%d",&hld.col[i]);

                for( int i = 1; i <= n-1; i++ ) {
                        int u , v;
                        scanf("%d %d",&u,&v);
                        hld.AddEdge( u , v );
                }

                hld.dfs( 1 , 0 );
                hld.HLD( 1 , 0 );
                hld.BuildHLD( );

                while( q-- ) {
                        int op;
                        scanf("%d",&op);
                        if( op == 1 ) {
                                int u , v;
                                scanf("%d %d",&u,&v);
                                printf("%d\n",hld.QueryHLD( u , v ) );
                        }
                        else {
                                int u , c;
                                scanf("%d %d",&u,&c);
                                hld.UpdateHLD( u , hld.col[u] ,  c );
                                hld.col[u] = c;
                        }
                }
        }
        return 0;
}
/**

You are given a tree with N nodes. The tree nodes are numbered from 1 to N and have colors C1, C2,
. . . , CN initially. You have to handle M instructions on the tree of the following forms:
• 0 u c: Change the color of node u to c.
• 1 u v: Output the maximum number of times a color appeared on the unique path from node u
to node v.


1
7 10
6 4 5 1 8 4 6
7 1
6 7
5 6
4 6
3 1
2 4

*/
