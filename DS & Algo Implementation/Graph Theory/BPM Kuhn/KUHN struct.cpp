#include <bits/stdc++.h>
using namespace std;
/**

O( V * E )
if edges are bidirected add mx to change node value
n , m = left , right
*/
struct bipartite_matchingKUHN {
        static const int N = 1e3 + 5;
        int n , m , match[ N ];
        bool vis[ N ];
        vector <int> graph[ N ];
        void init( int l , int r ) {
                n = l , m = r;
                for( int i = 0; i < N; i++ ) graph[i].clear();
        }
        void add_edge( int u , int v ) {
                graph[u].push_back( v );
        }
        bool find_match( int s ) {
                vis[s] = true;
                for( int i = 0; i < graph[s].size(); i++ ) {
                        int node = graph[s][i] , next = match[node];
                        if( vis[next] ) continue;
                        if( next == 0 || find_match( next ) ) {
                                match[node] = s;
                                return true;
                        }
                }
                return false;
        }
        int maximum_match( ) {
                int matching = 0;
                memset( match , 0 , sizeof(match) );
                for( int i = 1; i <= n; i++ ) {
                        memset( vis , false , sizeof( vis ) );
                        if( find_match( i ) ) matching++;
                }
                return matching;
        }
} kuhn;

int main( int argc , char const *argv[] ) {
        int n , m;
        scanf("%d %d",&n,&m);
        kuhn.init( n , m );
        return 0;
}






