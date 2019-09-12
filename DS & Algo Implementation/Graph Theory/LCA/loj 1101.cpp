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

const int k = 25;
int n , q , m;
vector < pair<int,int> > graph[ N ];
int parent[ N ][ k+5 ] , MX[ N ][ k+5 ];
int depth[ N ] , p[ N ] , node;

struct data {
        int u , v , w;
        data(){}
        data( int u , int v , int w ) : u(u),v(v),w(w){}
        bool operator <( const data &q ) const {
                return w < q.w;
        }
};
vector <data> V;

void dfs( int s , int p ) {
        parent[s][0] = p;
        depth[s] = depth[p] + 1;
        for( int i = 0; i < graph[s].size(); i++ ) {
                pair <int,int> x = graph[s][i];
                if( x.first != p ) {
                        MX[x.first][0] = x.second;
                        dfs( x.first , s );
                }
        }
}
void calc( ) {
        for( int i = 1; i <= k; i++ ) {
                for( int j = 1; j <= n; j++ ) {
                        parent[j][i] = parent[parent[j][i-1]][i-1];
                        MX[j][i] = max( MX[j][i-1] , MX[parent[j][i-1]][i-1] );
                }
        }
}
int LCA( int u , int v ) {
        if( depth[u] < depth[v] ) swap( u , v );
        int mx = 0;
        int diff = depth[u] - depth[v];
        for( int i = k; i >= 0; i-- ) {
                if( ( diff >> i )&1 ) {
                        mx = max( mx , MX[u][i] );
                        u = parent[u][i];
                }
        }
        if( u == v ) return mx;
        for( int i = k; i >= 0; i-- ) {
                if( parent[u][i] != 0 && parent[u][i] != parent[v][i] ) {
                        mx = max( mx , MX[u][i] );
                        mx = max( mx , MX[v][i] );
                        u = parent[u][i];
                        v = parent[v][i];
                }
        }
        mx = max( mx , max( MX[u][0] , MX[v][0] ) );
        return mx;
}
int Find( int x ) {
        return ( p[x] == x ? x : p[x] = Find( p[x] ) );
}
void Union( int x , int y ) {
        int u = Find( x ) , v = Find( y );
        if( u != v ) p[u] = v;
}
void MST_Kruskal( ) {
        sort( V.begin() , V.end() );
        for( int i = 0; i < V.size(); i++ ) {
                if( Find( V[i].u ) != Find( V[i].v ) ) {
                        Union( V[i].u , V[i].v );
                        graph[V[i].u].push_back( {V[i].v,V[i].w} );
                        graph[V[i].v].push_back( {V[i].u,V[i].w} );
                }
        }
}
void Reset( ) {
        for( int i = 1; i < N; i++ ) graph[i].clear();
        for( int i = 1; i < N; i++ ) p[i] = i;
        memset( parent , 0 , sizeof(parent) );
        memset( MX , 0 , sizeof(MX) );
        V.clear();
}
int main( int argc , char const *argv[] ) {
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
                Reset( );
                scanf("%d %d",&n,&m);
                for( int i = 1; i <= m; i++ ) {
                    int u , v , w;
                    scanf("%d %d %d",&u,&v,&w);
                    V.push_back( data(u,v,w) );
                }
                MST_Kruskal( );
                dfs( 1 , 0 );
                calc( );
                scanf("%d",&q);
                printf("Case %d:\n",tc);
                while( q-- ) {
                        int u , v;
                        scanf("%d %d",&u,&v);
                        printf("%d\n",LCA(u,v));
                }
        }
        return 0;
}
