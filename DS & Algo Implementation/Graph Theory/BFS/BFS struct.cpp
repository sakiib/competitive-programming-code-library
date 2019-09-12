#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

struct BreadthFirstSearch {
        static const int MAXN = 1e5 + 5;
        typedef long long LL;
        typedef pair <int,int> ii;
        typedef pair <LL,LL> ll;

        int n , m;
        vector <int> graph[ MAXN ];

        int cost[ MAXN ];

        void initialize( int _n , int _m ) {
                n = _n , m = _m;
                for( int i = 0; i < MAXN; i++ ) {
                        graph[i].clear();
                        cost[i] = -1;
                }
        }
        void AddEdge( int u , int v ) {
                graph[u].push_back( v ) , graph[v].push_back( u );
        }
        void BFS( int s ) {
                queue <int> Q;
                cost[ s ] = 0;
                Q.push( s );
                while( !Q.empty() ) {
                        int f = Q.front();
                        Q.pop();
                        for( auto x : graph[ f ] ) {
                                if( cost[x] == -1 || cost[x] > cost[f] + 1 ) {
                                        cost[f] = cost[x] + 1;
                                        Q.push( x );
                                }
                        }
                }
        }
} bfs;

int main( int argc , char const *argv[] ) {
        int n , m;
        scanf("%d %d",&n,&m);
        bfs.initialize( n , m );
        for( int i = 1; i <= m; i++ ) {
                int u , v;
                scanf("%d %d",&u,&v);
                bfs.AddEdge( u , v );
        }
        int s;
        scanf("%d",&s);
        bfs.BFS( s );
        return 0;
}






