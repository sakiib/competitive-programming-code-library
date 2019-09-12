#include <bits/stdc++.h>
using namespace std;

/**
matimum match E sqrt(V)
lcnt = left set count
rcount = right set count
N = Left Count
*/

struct bipartite_matchingHK {
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
} hk;

int main( ) {
        int n , m , p;
        scanf("%d %d %d",&n,&m,&p);
        hk.init( n , m ); /// cows( left ) , bulls( right )
        for( int i = 1; i <= p; i++ ) {
                int u , v;
                scanf("%d %d",&u,&v);
                hk.add_edge( u , v );
        }
        printf("%d\n",hk.maximum_match());
        return 0;
}








