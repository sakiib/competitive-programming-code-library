#include <bits/stdc++.h>
using namespace std;

struct hopcroftkarp_bpm {
        static const int N = 5e4 + 5;
        static const int inf = 2e9;
        vector <int> graph[ N ];
        int lcnt , rcnt , left[ N ] , right[ N ] , dist[ N ];
        void init( int l , int r ) {
                lcnt = l , rcnt = r;
                for( int i = 0; i < N; i++ ) graph[i].clear();
        }
        void add_edge( int u , int v ) {
                graph[u].push_back( v );
        }
        bool bfs( ) {
                queue <int> Q;
                for( int i = 1; i <= lcnt; i++ ) {
                        if( left[i] == 0 ) dist[i] = 0 , Q.push( i );
                        else dist[i] = inf;
                }
                dist[0] = inf;
                while( !Q.empty() ) {
                        int u = Q.front(); Q.pop();
                        if( u != 0 ) {
                                for( int i = 0; i < graph[u].size(); i++ ) {
                                        int v = graph[u][i];
                                        if( dist[right[v]] == inf ) {
                                                 dist[right[v]] = dist[u] + 1;
                                                 Q.push( right[v] );
                                        }
                                }
                        }
                }
                return dist[0] != inf;
        }
        bool dfs( int u ) {
                if( u == 0 ) return true;
                for( int i = 0; i < graph[u].size(); i++ ) {
                        int v = graph[u][i];
                        if( dist[right[v]] == dist[u] + 1 ) {
                                if( dfs( right[v] ) ) {
                                        right[v] = u;
                                        left[u] = v;
                                        return true;
                                }
                        }
                }
                dist[u] = inf;
                return false;
        }
        int maximum_match( ) {
                int match = 0;
                memset( left , 0 , sizeof( left ) );
                memset( right , 0 , sizeof( right ) );
                while( bfs() ) {
                        for( int i = 1; i <= lcnt; i++ ) {
                                if( left[i] == 0 && dfs( i ) ) match++;
                        }
                }
                return match;
        }
} HK;

int main( int argc , char const *argv[] ) {
        map <string,int> M;
        M[ "XXL" ] = 1;
        M[ "XL" ] = 2;
        M[ "L" ] = 3;
        M[ "M" ] = 4;
        M[ "S" ] = 5;
        M[ "XS" ] = 6;
        char s[ 10 ];
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
                int n , m;
                scanf("%d %d",&n,&m);
                HK.init( m , n );
                for( int i = 1; i <= m; i++ ) {
                        scanf("%s",s);
                        for( int j = 1; j <= n; j++ ) {
                                HK.add_edge( i , ( 6 * ( j-1 ) ) + M[s] + m );
                        }
                        scanf("%s",s);
                        for( int j = 1; j <= n; j++ ) {
                                HK.add_edge( i , ( 6 * ( j-1 ) ) + M[s] + m );
                        }
                }
                int match = HK.maximum_match( );
                if( match == m ) printf("Case %d: YES\n",tc);
                else printf("Case %d: NO\n",tc);
        }
        return 0;
}







