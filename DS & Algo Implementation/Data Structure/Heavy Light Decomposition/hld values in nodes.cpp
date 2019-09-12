#include <bits/stdc++.h>
using namespace std;

template <typename T> class segment_tree {
    public :
        static const int N = 1e5 + 5;
        T tree[ 4*N ] , A[ N ];
        void init( ) {
                memset( tree , 0 , sizeof( tree ) );
        }
};

segment_tree <int> tree;

template <typename T> class heavylight_decomposition {
    public:
        static const int N = 1e5 + 5;
        static const int LOG = 25;
        vector <int> graph[ N ];
        T cost[ N ];
        int Node, sub[ N ] , par[ N ] , dep[ N ];
        int chain, chidx[ N ], Head[ N ], postree[ N ];
        void init( ) {
                chain = 0, Node = 1;
                for( int i = 0; i < N; i++ ) {
                        graph[i].clear( );
                        tree.A[i] = 0, sub[i] = 0, cost[i] = 0;
                        chidx[i] = 0, Head[i] = -1, postree[i] = 0;
                }
        }
        void AddEdge( int u , int v ) {
                graph[ u ].push_back( v ); graph[ v ].push_back( u );
        }
        void dfs( int s , int p ) {
                par[s] = p; sub[s] = 1; dep[s] = dep[p] + 1;
                for( int i = 0; i < graph[s].size(); i++ ) {
                        int v = graph[s][i];
                        if( v != p ) dfs( v , s ) , sub[s] += sub[v];
                }
        }
        void HLD( int s , int p ) {
                if( Head[chain] == -1 ) Head[chain] = s;
                chidx[s] = chain; postree[s] = Node; tree.A[Node++] = cost[s];
                int mxChild = -1;
                for( int i = 0; i < graph[s].size(); i++ ) {
                        int v = graph[s][i];
                        if( v != p ) {
                                if( mxChild == -1 || sub[mxChild] < sub[v] ) mxChild = v;
                        }
                }
                if( mxChild != -1 ) HLD( mxChild , s );
                for( int i = 0; i < graph[s].size(); i++ ) {
                        int v = graph[s][i];
                        if( v != p && v != mxChild ) chain++ , HLD( v , s );
                }
        }
        int LCA( int u , int v ) {
                while( 1 ) {
                        int pu = Head[chidx[u]], pv = Head[chidx[v]];
                        if( pu == pv ) return ( dep[u] < dep[v] ? u : v );
                        if( dep[pu] < dep[pv] ) v = par[pv];
                        else u = par[pu];
                }
        }
        void UpdateHLD( int pos , T v ) {
                tree.Update( 1 , 1 , Node , postree[pos] , v );
        }
        T QueryUP( int u , int v ) {
                if( u == v ) return tree.Query( 1, 1, Node, postree[u], postree[u] );
                int uchain , vchain = chidx[v];
                T ans = 0;
                while( 1 ) {
                        uchain = chidx[u];
                        if( uchain == vchain ) {
                                int st = postree[v], en = postree[u];
                                T ret = tree.Query( 1 , 1 , Node , st , en );
                                ans = ans + ret;
                                break;
                        }
                        int st = postree[Head[uchain]], en = postree[u];
                        T ret = tree.Query( 1 , 1 , Node , st , en );
                        ans = ans + ret;
                        u = Head[uchain] , u = par[u];
                }
                return ans;
        }

        T QueryHLD( int u , int v ) {
                int lca = LCA( u , v );
                T x = QueryUP( u , lca ), y = QueryUP( v , lca ), z = QueryUP( lca , lca );
                return ( x + y - z );
        }
        void UpdateUP( int u , int v , int w ) {
                if( u == v ) {
                        tree.Update( 1 , 1 , Node , postree[u] , postree[u] , w );
                        return;
                }
                int uchain , vchain = chidx[ v ];
                while( true ) {
                        uchain = chidx[ u ];
                        if( uchain == vchain ) {
                                int st = postree[v] , en = postree[ u ];
                                tree.Update( 1 , 1 , Node , st , en , w );
                                break;
                        }
                        int st = postree[Head[uchain]] , en = postree[u];
                        tree.Update( 1 , 1 , Node , st , en , w );
                        u = Head[ uchain ] , u = par[ u ];
                }
        }
        void UpdateHLD( int u , int v , int w ) {
                int lca = LCA( u , v );
                UpdateUP( u , lca , w );
                UpdateUP( v , lca , w );
        }
};

heavylight_decomposition <int> hld;

int main( ) {
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
                int n;
                scanf("%d",&n);
                hld.init( );
                tree.init( );
                for( int i = 1; i <= n; i++ ) scanf("%d",&hld.cost[i]);
                for( int i = 1; i <= n - 1; i++ ) {
                        int u , v;
                        scanf("%d %d",&u,&v);
                        hld.AddEdge( ++u , ++v );
                }
                hld.dfs( 1 , 0 );
                hld.HLD( 1 , 0 );
                tree.Build( 1 , 1 , hld.Node );
                printf("Case %d:\n",tc);
                int q;
                scanf("%d",&q);
                while( q-- ) {
                        int type;
                        scanf("%d",&type);
                        if( type == 0 ) {
                                int u , v;
                                scanf("%d %d",&u,&v);
                                printf("%d\n",hld.QueryHLD( ++u , ++v ) );
                        }
                        else {
                                int pos , val;
                                scanf("%d %d",&pos,&val);
                                hld.UpdateHLD( ++pos , val );
                        }
                }
        }
        return 0;
}






