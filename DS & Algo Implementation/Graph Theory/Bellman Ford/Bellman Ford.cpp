#include <bits/stdc++.h>
using namespace std;

/**

 single source shortest path.
 complexity : O( V * E ) , worse than dijkstra ,
 but works for negative cycle.

 For Marking Nodes in Negative Cycle < INF is must.
 We can also use , BFS & count how many times a node is updated
 hence , we can decide which nodes are in Negative Cycle.

 Don't use INF for just checking Negative Cycle or just use the Marking Node Part.

*/

const int N = 1e5 + 5;
typedef long long LL;
const int INF = 1e9;

int n , m;

struct Edge {
        int u , v , w;
        Edge(){}
        Edge( int u , int v , int w ): u(u) , v(v) , w(w){}
};

int cost[ N ];
vector <Edge> V;
bool Neg[ N ];

int BellmanFord( int s ) {
        for( int i = 1; i <= n; i++ ) cost[ i ] = INF;
        cost[ 1 ] = 0; /// start node.
        for( int i = 1; i < n; i++ ) {
                for( int j = 0; j < m; j++ ) {
                        if( cost[ V[j].u ] + V[j].w < cost[ V[j].v ] && cost[ V[j].u] < INF ) {
                               cost[ V[j].v ] = cost[ V[j].u ] + V[j].w;
                        }
                }
        }
        for( int i = 0; i < V.size(); i++ ) { /// or run  ( < m ) same thing.
                if( cost[ V[i].u ] + V[i].w < cost[ V[i].v ]  ) return -1;
                /// Negative cycle
        }
        /// Marking Nodes in Negative Cycle.
        for( int i = 1; i < n; i++ ) {
                for( int j = 0; j < V.size(); j++ ) {
                        if( cost[ V[j].u ] + V[j].w < cost[ V[j].v ] && cost[ V[j].u ] < INF  ) {
                               cost[ V[j].v ] = cost[ V[j].u ] + V[j].w;
                               Neg[ V[j].v ] = true; /// is in negative cycle
                        }
                }
        }
        return 0; /// No Negative Cycle.
}
int main( int argc , char const *argv[] ) {
        scanf("%d %d",&n,&m);
        for( int i = 1; i <= m; i++ ) {
                int u , v , w;
                scanf("%d %d %d",&u,&v,&w);
                V.push_back( Edge( u , v , w ) );
        }
        int ans = BellmanFord( 1 ); /// 1 is the source.
        if( ans == -1 ) printf("Negative Cycle Detected\n");
        else {
                /// printf("cost of Target Node");
        }
        return 0;
}






