#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

struct HeavyLightDecomposition {
        static const int N = 1e5 + 5;
        static const int inf = 1e9 + 5;
        static const int lgN = 20;
        typedef pair <int,int> ii;

        int n , Node;
        //int cost[ N ];
        int otherEnd[ N ];
        int A[ N ] , sub[ N ] , par[ N ] , depth[ N ] , EdgeId[ N ];
        int chainNo , chainInd[ N ] , chainHead[ N ] , posInTree[ N ];
        vector < ii > graph[ N ];
        vector < int > Edge[ N ];
        int tree[ 4*N ];

        void initialize( int _n ) {
                n = _n;
                memset( tree , 0 , sizeof(tree) );
                chainNo = 0 , Node = 1;
                for( int i = 0; i < N; i++ ) {
                        graph[i].clear(); Edge[i].clear();
                        A[i] = 0 , sub[i] = 0 , depth[i] = 0 , EdgeId[i] = 0;
                        chainInd[i] = 0 , chainHead[i] = -1 , posInTree[i] = 0;
                }
        }
        void AddEdge( int u , int v , int w ) {
                graph[ u ].push_back( {v,w} ) , graph[ v ].push_back( {u,w} );
        }
        void dfs( int s , int p ) {
                par[s] = p , sub[s] = 1 , depth[s] = depth[p] + 1;
                for( int i = 0; i < graph[s].size(); i++ ) {
                        ii k = graph[s][i];
                        int v = k.first , w = k.second;
                        if( v != p ) {
                                EdgeId[ Edge[s][i] ] = graph[s][i].first;
                                dfs( v , s );
                                sub[s] += sub[v];
                        }
                }
        }
        void HLD( int s , int p , int cost ) {
                if( chainHead[ chainNo ] == -1 ) chainHead[ chainNo ] = s;
                chainInd[ s ] = chainNo;
                posInTree[ s ] = Node;
                A[ Node++ ] = cost;
                int mxChild = -1 , ncost;
                for( int i = 0; i < graph[s].size(); i++ ) {
                        ii k = graph[s][i];
                        int v = k.first , w = k.second;
                        if( v != p ) {
                                if( mxChild == -1 || sub[ mxChild ] < sub[ v ] ) {
                                        mxChild = v;
                                        ncost = w;
                                }
                        }
                }
                if( mxChild != -1 ) HLD( mxChild , s , ncost );
                for( int i = 0; i < graph[s].size(); i++ ) {
                        ii k = graph[s][i];
                        int v = k.first , w = k.second;
                        if( v != p && v != mxChild ) {
                                chainNo++;
                                HLD( v , s , w );
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
                        tree[ node ] = A[ b ]; return;
                }
                int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
                Build( l , b , m );
                Build( r , m+1 , e );
                tree[ node ] = max( tree[ l ] , tree[ r ] );
        }
        int Query( int node , int b , int e , int i , int j ) {
                if( b > e || i > e || j < b ) return -inf;
                if( i <= b && j >= e ) return tree[ node ];
                int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
                int q1 = Query( l , b , m , i , j );
                int q2 = Query( r , m+1 , e , i , j );
                return max( q1 , q2 );
        }
        void Update( int node , int b , int e , int pos , int v ) {
                if( b > e || pos > e || pos < b ) return;
                if( b == e && b == pos ) {
                        tree[ node ] = v; return;
                }
                int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
                Update( l , b , m , pos , v );
                Update( r , m+1 , e , pos , v );
                tree[ node ] = max( tree[ l ] , tree[ r ] );
        }
        int QueryUP( int u , int v ) {
                if( u == v ) return 0;
                int uchain , vchain = chainInd[ v ];
                int ans = -inf;
                while( 1 ) {
                        uchain = chainInd[ u ];
                        if( uchain == vchain ) {
                                int st = posInTree[ v ] , en = posInTree[ u ];
                                int ret = Query( 1 , 1 , Node-1 , st + 1 , en );
                                ans = max( ans , ret );
                                break;
                        }
                        int st = posInTree[ chainHead[ uchain ] ] , en = posInTree[ u ];
                        int ret = Query( 1 , 1 , Node-1 , st , en );
                        ans = max( ans , ret );
                        u = chainHead[ uchain ] , u = par[ u ];
                }
                return ans;
        }
        void UpdateHLD( int pos , int v ) {
                pos = EdgeId[ pos ];
                Update( 1 , 1 , Node-1 , posInTree[ pos ] , v );
        }
        int QueryHLD( int u , int v ) {
                int lca = LCA( u , v );
                int x = QueryUP( u , lca ), y = QueryUP( v , lca );
                return max( x , y );
        }

} hld;

int main( int argc , char const *argv[] ) {
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
                int n;
                scanf("%d",&n);

                hld.initialize( n );

                for( int i = 1; i <= n-1; i++ ) {
                        int u , v , w;
                        scanf("%d %d %d",&u,&v,&w);
                        hld.AddEdge( u , v , w );
                        hld.Edge[u].push_back( i );
                        hld.Edge[v].push_back( i );
                }

                hld.dfs( 1 , 0 );
                hld.HLD( 1 , 0 , -1 );
                hld.Build( 1 , 1 , hld.Node-1 );

                char str[ 10 ];
                while( 1 ) {
                        scanf("%s",str);
                        if( strcmp( str , "DONE" ) == 0 ) break;
                        else if( strcmp( str , "QUERY" ) == 0 ) {
                                int l , r;
                                scanf("%d %d",&l,&r);

                                printf("%d\n",hld.QueryHLD( l , r ) );
                        }
                        else {
                                int no , val;
                                scanf("%d %d",&no,&val);
                                hld.UpdateHLD( no , val );
                        }
                }
        }
        return 0;
}

/**

You are given a tree (an acyclic undirected connected graph) with N nodes, and edges numbered 1, 2, 3...N-1.

We will ask you to perfrom some instructions of the following form:

CHANGE i ti : change the cost of the i-th edge to ti
or
QUERY a b : ask for the maximum edge cost on the path from node a to node b


1
8
1 2 1
1 3 2
3 8 3
2 4 5
2 5 4
5 6 6
5 7 7
*/







