#include <bits/stdc++.h>
using namespace std;

struct SCC_KOSARAJU {
        static const int MAXN = 1e5 + 5;
        int n , m , component , ID;

        vector <int> graph[ MAXN ];
        vector <int> rev_graph[ MAXN ];
        vector <int> compo[ MAXN ];
        vector <int> c_graph[ MAXN ];

        bool visited[ MAXN ];
        int compoID[ MAXN ] , inDegree[ MAXN ] , outDegree[ MAXN ];;
        stack <int> st;

        void initialize( int _n , int _m ) {
                n = _n , m = _m;
                component = 0;
                ID = 0;
                memset( inDegree , 0 , sizeof( inDegree ) );
                memset( outDegree , 0 , sizeof( outDegree ) );
                for( int i = 0; i < MAXN; i++ ) {
                        graph[ i ].clear() , rev_graph[ i ].clear();
                        compo[ i ].clear() , c_graph[ i ].clear();
                }
        }
        void AddEdge( int u , int v ) {
                graph[ u ].push_back( v );
                rev_graph[ v ].push_back( u );
        }
        void TopoSort( int s ) {
                visited[ s ] = true;
                for( auto x : graph[ s ] ) if( !visited[ x ] ) TopoSort( x );
                st.push( s );
        }
        void Kosaraju( int s ) {
                visited[ s ] = true;
                compo[ component ].push_back( s );
                for( auto x : rev_graph[ s ] ) if( !visited[ x ] ) Kosaraju( x );
        }
        void SCCGraph( ) {
                for( int i = 1; i <= component; i++ ) {
                        for( auto x : compo[ i ] ) {
                                compoID[ x ] = i;
                        }
                }
                for( int i = 1; i <= n; i++ ) {
                        for( auto x : graph[ i ] ) {
                                if( compoID[ x ] != compoID[ i ] ) {
                                        inDegree[ compoID[ x ] ]++;
                                        outDegree[ compoID[ i ] ]++;
                                        c_graph[ compoID[ i ] ].push_back( compoID[ x ] );
                                }
                        }
                }
        }
        void SCC( ) {
                memset( visited , false , sizeof(visited) );
                for( int i = 1; i <= n; i++ ) if( !visited[i] ) TopoSort( i );
                memset( visited , false , sizeof(visited) );
                while( !st.empty() ) {
                        int tp = st.top();
                        st.pop();
                        if( !visited[ tp ] ) component++ , Kosaraju( tp );
                }
        }
} scc;

int main( int argc , char const *argv[] ) {
        int n , m;
        scanf("%d %d",&n,&m);
        scc.initialize( n , m );
        for( int i = 1; i <= m; i++ ) {
                int u , v;
                scanf("%d %d",&u,&v);
                scc.AddEdge( u , v );
        }
        scc.SCC( );
        scc.SCCGraph( );
        return 0;
}






