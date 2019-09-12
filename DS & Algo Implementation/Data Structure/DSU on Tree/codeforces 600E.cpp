#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;

/**
 Calc calculates the intermidiate results.
 FindAns calculates the answer of the current Node.

 For many problems Calc might not be needed.we'll just get the final result FindAns.
 */

struct DSU_ON_TREE {
        static const int MAXN = 1e5 + 5;
        typedef long long LL;

        int nodes;
        int SubTree[ MAXN ] , Color[ MAXN ] , Cnt[ MAXN ];
        LL Ans[ MAXN ] , MX , SUM;
        bool Heavy[ MAXN ];
        vector <int> graph[ MAXN ];

        void Initialize( int n ) {
                nodes = n , MX = 0 , SUM = 0;
                memset( Cnt , 0 , sizeof( Cnt ) );
                memset( SubTree , 0 , sizeof( SubTree ) );
                for( int i = 0; i < MAXN; i++ ) graph[ i ].clear();
        }
        void AddEdge( int u , int v ) {
                graph[ u ].push_back( v ); graph[ v ].push_back( u );
        }
        void SubTreeSize( int s , int p ) {
               SubTree[ s ] = 1;
               for( auto x : graph[ s ] ) {
                        if( x != p ) {
                                SubTreeSize( x , s );
                                SubTree[ s ] += SubTree[ x ];
                        }
               }
        }
        void FindAns( int s ) {
                Ans[ s ] = SUM;
        }
        void Calc( int s ) {
                if( Cnt[ Color[s] ] > MX ) MX = Cnt[ Color[s] ] , SUM = Color[s];
                else if( Cnt[ Color[s] ] == MX ) SUM += Color[s];
        }
        void Add( int s , int p , int v ) {
                Cnt[ Color[s] ] += v;
                Calc( s );
                for( auto x : graph[ s ] ) if( x != p && !Heavy[ x ] ) Add( x , s , v );
        }
        void Remove( int s , int p , int v ) {
                Cnt[ Color[s] ] -= v;
                for( auto x : graph[ s ] ) if( x != p && !Heavy[ x ] ) Remove( x , s , v );
        }
        void DSU_DFS( int s , int p , bool keep ) {
                int mx = -1 , HeavyChild = -1;
                for( auto x : graph[ s ] ) {
                        if( x != p && SubTree[ x ] > mx ) {
                                mx = SubTree[ x ] , HeavyChild = x;
                        }
                }
                for( auto x : graph[ s ] ) {
                        if( x != p && x != HeavyChild ) DSU_DFS( x , s , false );
                }
                if( HeavyChild != -1 ) {
                        DSU_DFS( HeavyChild , s , true );
                        Heavy[ HeavyChild ] = true;
                }
                Add( s , p , +1 );
                FindAns( s );
                if( HeavyChild != -1 ) Heavy[ HeavyChild ] = false;
                if( !keep ) Remove( s , p , +1 ) , MX = 0 , SUM = 0;
        }
} dsu;

int main( int argc , char const *argv[] ) {
        int n;
        scanf("%d",&n);
        dsu.Initialize( n );
        for( int i = 1; i <= n; i++ ) scanf("%d",&dsu.Color[i]);
        for( int i = 1; i <= n-1; i++ ) {
                int u , v;
                scanf("%d %d",&u,&v);
                dsu.AddEdge( u , v );
        }
        dsu.SubTreeSize( 1 , 0 );
        dsu.DSU_DFS( 1 , 0 , true );
        for( int i = 1; i <= n; i++ ) printf("%lld ",dsu.Ans[i]);
        return 0;
}






