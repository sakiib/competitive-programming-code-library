#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;

struct DSU_ON_TREE {
        static const int MAXN = 5e5 + 5;
        typedef long long LL;

        int n , q;
        char str[ MAXN ];

        int nodes;
        int SubTree[ MAXN ] , Color[ MAXN ] , Cnt[ MAXN ][ 30 ] , Level[ MAXN ];
        LL Ans[ MAXN ] , MX , SUM;
        bool Heavy[ MAXN ];
        vector <int> graph[ MAXN ];
        vector < pair<int,int> > Query[ MAXN ];

        void Initialize( ) {
                MX = 0 , SUM = 0;
                memset( Cnt , 0 , sizeof( Cnt ) );
                memset( SubTree , 0 , sizeof( SubTree ) );
                memset( Heavy , false , sizeof( Heavy ) );
                for( int i = 0; i < MAXN; i++ ) graph[ i ].clear() , Query[ i ].clear();
        }
        void AddEdge( int u , int v ) {
                graph[ u ].push_back( v ); graph[ v ].push_back( u );
        }
        void SubTreeSize( int s , int p , int lvl ) {
               SubTree[ s ] = 1;
               Level[ s ] = lvl;
               for( auto x : graph[ s ] ) {
                        if( x != p ) {
                                SubTreeSize( x , s , lvl + 1 );
                                SubTree[ s ] += SubTree[ x ];
                        }
               }
        }
        void FindAns( int s ) {
                for( auto x : Query[s] ) {
                        int l = x.first , idx = x.second , odd = 0;
                        for( int i = 1; i <= 26; i++ ) {
                                if( Cnt[ l ][ i ]%2 == 1 ) odd++;
                        }
                        if( odd > 1 ) Ans[ idx ] = 0;
                        else Ans[ idx ] = 1;
                }
        }
        void Add( int s , int p , int v ) {
                int id = str[ s-1 ] - 'a' + 1;
                Cnt[ Level[s] ][ id ] += v;
                for( auto x : graph[ s ] ) if( x != p && !Heavy[x] ) Add( x , s , v );
        }
        void Remove( int s , int p , int v ) {
                int id = str[ s-1 ] - 'a' + 1;
                Cnt[ Level[s] ][ id ] -= v;
                for( auto x : graph[ s ] ) if( x != p && !Heavy[x] ) Remove( x , s , v );
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
                if( !keep ) Remove( s , p , +1 );
        }

        void solve( ) {
                scanf("%d %d",&n,&q);
                for( int i = 2; i <= n; i++ ) {
                        int x;
                        scanf("%d",&x);
                        AddEdge( i , x );
                }
                scanf("%s",str);
                SubTreeSize( 1 , 0 , 1 );
                for( int i = 1;i <= q; i++ ) {
                        int u , lvl;
                        scanf("%d %d",&u,&lvl);
                        Query[u].push_back( {lvl,i} );
                }
                DSU_DFS( 1 , 0 , true );
                for( int i = 1; i <= q; i++ ) {
                        if( Ans[i] == 0 ) printf("No\n");
                        else printf("Yes\n");
                }
        }
} dsu;

int main( int argc , char const *argv[] ) {
        dsu.Initialize( );
        dsu.solve( );
        return 0;
}














