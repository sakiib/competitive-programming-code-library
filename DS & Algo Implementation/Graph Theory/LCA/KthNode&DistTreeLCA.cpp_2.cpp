#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
const int level = 20;

int n;
vector < pair<int,int> > graph[ N ];
int parent[ N ][ level+5 ];
int depth[ N ];
int Dist[ N ];

void dfs( int s , int p ) {
    parent[s][0] = p;
    depth[s] = depth[p] + 1;
    for( int i = 0; i < graph[s].size(); i++ ) {
        pair <int,int> k = graph[s][i];
        int next = k.first , cost = k.second;
        if( next == p ) continue;
        Dist[next] = Dist[s] + cost;
        dfs( next , s );
    }
}
void Precompute_LCA( ) {
    for( int i = 1; i <= level; i++ ) {
        for( int node = 1; node <= n; node++ ) {
            if( parent[node][i-1] != -1 ) {
                parent[node][i] = parent[parent[node][i-1]][i-1];
            }
        }
    }
}
int LCA( int u , int v ) {
    if( depth[ v ] < depth[ u ] ) swap( u , v );
    int dif = depth[ v ] - depth[ u ];
    for( int i = 0; i <= level; i++ ) {
        if( ( dif >> i )&1 ) v = parent[ v ][ i ];
    }
    if( u == v ) return u;
    for( int i = level; i >= 0; i-- ) {
        if( parent[ u ][ i ] != parent[ v ][ i ] ) {
            u = parent[ u ][ i ];
            v = parent[ v ][ i ];
        }
    }
    return parent[ u ][ 0 ];
}
int GetDist( int u , int v ) {
    int lca = LCA( u , v );
    int ans = Dist[u] + Dist[v] - 2*Dist[lca];
    return ans;
}
int JumpToKTH( int u , int k ) {
    for( int i = 0; i <= level; i++ ) {
        if( (k >> i)&1 ) u = parent[u][i];
    }
    return u;
}
int GetKthNode( int u , int v , int k ) {
    int lca = LCA( u , v );
    int du = depth[u] - depth[lca] + 1;
    if( k <= du ) return JumpToKTH( u , k-1 );
    int dv = depth[v] - depth[lca];
    k -= du;
    int x = dv - k;
    return JumpToKTH( v , x );
}
void AddEdge( int u , int v , int w ) {
    graph[u].push_back( make_pair( v , w ) );
    graph[v].push_back( make_pair( u , w ) );
}
void Reset( ) {
    memset( parent , -1 , sizeof( parent ) );
    depth[0] = 0;
    memset( Dist , 0 , sizeof( Dist ) );
    for( int i = 1; i < N; i++ ) graph[i].clear();
}
int main( int argc, char const *argv[] ) {
    int t;
    scanf("%d",&t);
    for( int tc = 1; tc <= t; tc++ ) {
        Reset( );
        scanf("%d",&n);
        int u , v , w;
        for( int i = 1; i <= n; i++ ) {
            scanf("%d %d %d",&u,&v,&w) , AddEdge( u, v , w );
        }
        dfs( 1 , 0 );
        Precompute_LCA( );
        char str[ 15 ];
        while( scanf("%s",str) ) {
            if( strcmp( str , "DIST" ) == 0 ) {
                int u , v;
                scanf("%d %d",&u,&v);
                printf("%d\n",GetDist( u , v ) );
            }
            else if( strcmp( str , "KTH" ) == 0 ) {
                int u , v , k;
                scanf("%d %d %d",&u,&v,&k);
                printf("%d\n",GetKthNode( u , v , k ) );
            }
            else break;
        }
    }
    return 0;
}








