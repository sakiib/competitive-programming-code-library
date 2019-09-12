#include <bits/stdc++.h>
using namespace std;

struct HopcroftKarp {
        static const int MAXN = 1e3 + 5;
        static const int INF = 2e9 + 9;

        int nodes , dist[ MAXN ] , match[ MAXN ];
        vector <int> graph[ MAXN ];

        void initialize( int n ) {
                nodes = n;
                for( int i = 0; i < MAXN; i++ ) graph[i].clear();
        }
        void AddEdge( int u , int v ) {
                graph[ u ].push_back( v );
                graph[ v ].push_back( u );
        }
        bool BFS( ) {
                queue <int> Q; dist[ 0 ] = INF;
                for( int i = 1; i <= nodes; i++ ) {
                        if( match[i] ) dist[i] = INF;
                        else Q.push( i ) , dist[i] = 0;
                }
                while( !Q.empty() ) {
                        int u = Q.front(); Q.pop();
                        if( !u ) continue;
                        for( int i = 0; i < graph[u].size(); i++ ) {
                                int v = graph[u][i];
                                if( dist[ match[v] ] != INF ) continue;
                                dist[ match[v] ] = dist[u] + 1;
                                Q.push( match[v] );
                        }
                }
                return ( dist[0] != INF );
        }
        bool DFS( int u ) {
                if( u ) {
                        for( int i = 0; i < graph[u].size(); i++ ) {
                                int v = graph[u][i];
                                if( dist[ match[v] ] == dist[u] + 1 ) {
                                       if( DFS( match[v] ) ) {
                                            match[v] = u;
                                            match[u] = v;
                                            return true;
                                       }
                                }
                        }
                        dist[u] = INF; return false;
                }
                return true;
        }
        int MaximumMatch( ) {
                memset( match , 0 , sizeof(match) );
                int cnt = 0;
                while( BFS( ) ) {
                        for( int i = 1; i <= nodes; i++ ) {
                                if( !match[i] && DFS( i ) ) cnt++;
                        }
                }
                return cnt;
        }
} HP;

int a[ 105 ] , b[ 105 ];

int main( int argc , char const *argv[] ) {
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
               int n , m;
               scanf("%d",&n);
               for( int i = 1; i <= n; i++ ) scanf("%d",&a[i]);
               scanf("%d",&m);
               for( int i = 1; i <= m; i++ ) scanf("%d",&b[i]);
               HP.initialize( n );
               for( int i = 1; i <= n; i++ ) {
                    for( int j = 1; j <= m; j++ ) {
                            if( b[j]%a[i] == 0 ) HP.AddEdge( i , j + n );
                    }
               }
               int mx_matching = HP.MaximumMatch( );
               printf("Case %d: %d\n",tc,mx_matching);
        }
        return 0;
}






