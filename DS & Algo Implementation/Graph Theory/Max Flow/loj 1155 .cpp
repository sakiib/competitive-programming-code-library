#include <bits/stdc++.h>
using namespace std;

int N , M , B , D , ID , source , sink;

struct data {
        int cap , in , out;
} info[ 105 ];

struct MAXFLOW_DINITZ {
        typedef long long LL;
        static const int MAXN = 3*105;
        static const int INF = 2e9 + 5;

        int nodes , src , snk;
        int dist[ MAXN ] , start[ MAXN ];

        struct Edge {
                int nxt , flow , cap , rev;
        };
        vector <Edge> graph[ MAXN ];

        void initialize( int n ) {
                nodes = n;
                for( int i = 0; i <= nodes; i++ ) graph[i].clear();
        }
        void AddEdge( int u , int v , int w ) {
                Edge p = { v , 0 , w , (int) graph[v].size() };
                Edge q = { u , 0 , 0 , (int) graph[u].size() };
                graph[ u ].push_back( p ); graph[ v ].push_back( q );
        }
        bool BFS( ) {
                memset( dist , -1 , sizeof(dist) );
                queue <int> Q; Q.push( src ); dist[ src ] = 0;
                while( !Q.empty() ) {
                        int u = Q.front(); Q.pop();
                        for( int i = 0; i < graph[u].size(); i++ ) {
                                Edge& e = graph[u][i];
                                int v = e.nxt;
                                if( dist[v] == -1 && e.flow < e.cap ) {
                                        dist[v] = dist[u] + 1;
                                        Q.push( v );
                                }
                        }
                }
                return ( dist[snk] != -1 );
        }
        int DFS( int u , int f ) {
                if( u == snk ) return f;
                for( int& i = start[u]; i < graph[u].size(); i++ ) {
                        Edge& e = graph[u][i];
                        if( e.flow >= e.cap ) continue;
                        int v = e.nxt;
                        if( dist[v] == ( dist[u] + 1 ) ) {
                                int _f = DFS( v , min( f , e.cap - e.flow ) );
                                if( _f ) {
                                        e.flow += _f;
                                        graph[v][e.rev].flow -= _f;
                                        return _f;
                                }
                        }
                }
                return 0;
        }
        int MaxFlow( int _src , int _snk ) {
                src = _src , snk = _snk;
                int res = 0;
                while( BFS( ) ) {
                        memset( start , 0 , sizeof(start) );
                        while( int f = DFS( src , INF ) ) {
                                res += f;
                        }
                }
                return res;
        }
} FLOW;

int main( int argc , char const *argv[] ) {
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
                scanf("%d",&N);
                source = 0 , sink = 2*N + 1 , ID = 0;
                FLOW.initialize( 2*N + 2 );
                for( int i = 1; i <= N; i++ ) {
                        scanf("%d",&info[i].cap);
                        info[i].in = ++ID;
                        info[i].out = ++ID;
                        FLOW.AddEdge( info[i].in , info[i].out , info[i].cap );
                }
                scanf("%d",&M);
                for( int i = 1; i <= M; i++ ) {
                        int a , b , c;
                        scanf("%d %d %d",&a,&b,&c);
                        FLOW.AddEdge( info[a].out , info[b].in , c );
                }
                scanf("%d %d",&B,&D);
                for( int i = 1; i <= B; i++ ) {
                        int x;
                        scanf("%d",&x);
                        FLOW.AddEdge( source , info[x].in , info[x].cap );
                }
                for( int i = 1; i <= D; i++ ) {
                        int x;
                        scanf("%d",&x);
                        FLOW.AddEdge( info[x].out , sink , info[x].cap );
                }
                int mx_flow = FLOW.MaxFlow( source , sink );
                printf("Case %d: %d\n",tc,mx_flow);
        }
        return 0;
}







