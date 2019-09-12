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

int n , q;
vector <int> graph[ N ];
int par[ N ][ 30 ] , depth[ N ] , dist[ N ];

void dfs( int s , int p ) {
        par[s][0] = p;
        depth[s] = depth[p] + 1;
        for( auto x : graph[s] ) {
                if( x != p ) {
                        dist[x] += ( dist[s] + 1 );
                        dfs( x , s );
                }
        }
}
void build_ST( ) {
        for( int i = 1; i <= 25; i++ ) {
                for( int j = 1; j <= n; j++ ) {
                        if( par[j][i-1] != -1 )
                        par[j][i] = par[ par[j][i-1] ][i-1];
                }
        }
}
int LCA( int u , int v ) {
        if( depth[u] < depth[v] ) swap( u , v );
        int diff = depth[u] - depth[v];
        for( int i = 25; i >= 0; i-- ) {
                if( ( 1 << i )&diff ) u = par[u][i];
        }
        if( u == v ) return u;
        for( int i = 25; i >= 0; i-- ) {
                if( par[u][i] != par[v][i] && par[u][i] != -1 ) {
                        u = par[u][i];
                        v = par[v][i];
                }
        }
        return par[u][0];
}
int GetKthNode( int u , int v , int k ) {
        if( depth[u] < depth[v] ) swap( u , v );
        for( int i = 25; i >= 0; i-- ) {
                if( ( 1 << i )&k ) u = par[u][i];
        }
        return u;
}
void Swing( int u , int v , int lca , int d ) {
        int x = GetKthNode( u , v , d/2 );
        int y = GetKthNode( u , v , d/2+1 );
        printf("The fleas jump forever between %d and %d.\n",min(x,y),max(x,y));
}
void Meet( int u , int v , int lca , int d ) {
        int x = GetKthNode( u , v , d/2 );
        printf("The fleas meet at %d.\n",x);
}
int main( int argc , char const *argv[] ) {
        while( scanf("%d",&n) ) {
                if( n == 0 ) break;
                for( int i = 1; i <= n-1; i++ ) {
                        int u , v;
                        scanf("%d %d",&u,&v);
                        graph[u].push_back( v );
                        graph[v].push_back( u );
                }
                memset( par , -1 , sizeof(par ) );
                memset( dist , 0 , sizeof(dist) );
                dfs( 1 , 0 );
                build_ST( );

                scanf("%d",&q);
                while( q-- ) {
                        int u , v;
                        scanf("%d %d",&u,&v);
                        int lca = LCA( u , v );
                        int d = dist[u] + dist[v] - 2*dist[lca];
                        if( d&1 ) Swing( u , v , lca , d );
                        else Meet( u , v , lca , d );
                }
                for( int i = 1; i < N; i++ ) graph[i].clear();
        }
        return 0;
}
/**
8
1 2
1 3
2 4
2 5
3 6
3 7
5 8
*/





