#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
typedef pair < int , int > ii;
const int inf = 1e9;
const LL INF = 1e18;
const int N = 1e5 + 5;
const int mod = 1000000007;
const double eps = 1e-8;
const double pi = acos( -1.0 );

const int level = 25;
vector <int> graph[ N ];
int parent[ N ][ level+5 ];
int depth[ N ];
int n;

void dfs( int s , int p ) {
        parent[s][0] = p;
        depth[s] = depth[p] + 1;
        for( int i = 0; i < graph[s].size(); i++ ) {
                int next = graph[s][i];
                if( next == p ) continue;
                dfs( next , s );
        }
}
void precompute_LCA( ) {
        for( int i = 1; i <= level; i++ ) {
                for( int node = 1; node <= n; node++ ) {
                        if( parent[node][i-1] != -1 ) {
                                parent[node][i] = parent[ parent[node][i-1] ][i-1];
                        }
                }
        }
}
int LCA( int u , int v ) {
        if( depth[u] > depth[v] ) swap( u , v );
        int dif = depth[v] - depth[u];
        for( int i = 0; i <= level; i++ ) {
                if( (dif>>i)&1 ) v = parent[v][i];
        }
        if( u == v ) return v;
        for( int i = level; i >= 0; i-- ) {
                if( parent[u][i] != parent[v][i] ) {
                        u = parent[u][i];
                        v = parent[v][i];
                }
        }
        return parent[u][0];
}
int main( int argc , char const *argv[] ) {
        ios_base :: sync_with_stdio(false); cin.tie(NULL);
        cin >> n;
        for( int i = 1; i <= n-1; i++ ) {
                int u , v;
                cin >> u >> v;
                graph[u].push_back( v );
                graph[v].push_back( u );
        }
        depth[0] = 0;
        memset( parent , -1 , sizeof(parent) );
        dfs( 1 , 0 );
        precompute_LCA( );
        while( 1 ) {
                int u , v;
                cin >> u >> v;
                cout << "LCA of " << u << " & " << v << " is : " << LCA( u , v ) << endl;
        }
        return 0;
}






