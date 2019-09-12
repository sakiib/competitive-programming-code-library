#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;
const int N = 1e5 + 5;

const int level = 25;
int n;
vector < pair<int,int> > graph[ N ];
int parent[ N ][ level+5 ];
int depth[ N ];
int MX[ N ][ level+5 ] , MN[ N ][ level+5 ];

void dfs( int s , int p ) {
        parent[s][0] = p;
        depth[s] = depth[p] + 1;
        for( int i = 0; i < graph[s].size(); i++ ) {
                pair <int,int> next = graph[s][i];
                int ss = next.first , cc = next.second;
                if( ss == p ) continue;
                MX[ss][0] = MN[ss][0] = cc;
                dfs( ss , s );
        }
}
void precompute( ) {
        for( int i = 1; i <= level; i++ ) {
                for( int node = 1; node <= n; node++ ) {
                        if( parent[node][i-1] != -1 ) {
                                parent[node][i] = parent[ parent[node][i-1] ][i-1];
                                MX[node][i] = max( MX[node][i-1] , MX[ parent[node][i-1] ][i-1] );
                                MN[node][i] = min( MN[node][i-1] , MN[ parent[node][i-1] ][i-1] );
                        }
                }
        }
}
pair <int,int> get_ans( int u , int v ) {
        int mx = -inf , mn = inf;
        if( depth[u] > depth[v] ) swap( u , v );
        int dif = depth[v] - depth[u];
        for( int i = level; i >= 0; i-- ) {
                if( (dif>>i)&1 ) {
                        mx = max( mx , MX[v][i] ) , mn = min( mn , MN[v][i] );
                        v = parent[v][i];
                }
        }
        if( u == v ) return {mx,mn};
        for( int i = level; i >= 0; i-- ) {
                if( parent[u][i] != parent[v][i] ) {
                        mx = max( mx , MX[u][i] ) , mn = min( mn , MN[u][i] );
                        mx = max( mx , MX[v][i] ) , mn = min( mn , MN[v][i] );
                        u = parent[u][i] , v = parent[v][i];
                }
        }
        mx = max( mx , MX[u][0] ) , mx = max( mx , MX[v][0] );
        mn = min( mn , MN[u][0] ) , mn = min( mn , MN[v][0] );
        return {mx,mn};
}
int main( int argc , char const *argv[] ) {
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
              for( int i = 1; i < N; i++ ) graph[i].clear();
              scanf("%d",&n);
              for( int i = 1; i <= n-1; i++ ) {
                    int u , v , w;
                    scanf("%d %d %d",&u,&v,&w);
                    graph[u].push_back( {v,w} ) , graph[v].push_back( {u,w} );
              }
              memset( parent , -1 , sizeof(parent) );
              dfs( 1 , 0 ); precompute( );

              int q;
              scanf("%d",&q);
              printf("Case %d:\n",tc);
              for( int i = 1; i <= q; i++ ) {
                    int u , v;
                    scanf("%d %d",&u,&v);
                    pair <int,int> ans = get_ans( u , v );
                    printf("%d %d\n",ans.second,ans.first);
              }
        }
        return 0;
}






