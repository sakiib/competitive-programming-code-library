#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long uLL;
typedef long long int LL;
typedef pair <int,int> pii;
typedef pair <int,pii> piii;
typedef pair <long long,long long> pll;
typedef pair <long long,pll> plll;
const int N = 3e4 + 5;
const int inf = 1e9;
const long long INF = 1e18;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int MOD = 1000000007;

const int lvl = 30;

vector <pii> graph[ N ];
int dist[ N ];
int n;

int par[ N ][ lvl+5 ] , depth[ N ] , dis[ N ];

void dfs( int s , int p ) {
        par[s][0] = p;
        depth[s] = depth[p] + 1;
        for( auto x : graph[s] ) {
                int ss = x.first , cc = x.second;
                if( ss == p ) continue;
                dis[ss] = dis[s] + cc;
                dfs( ss , s );
        }
}
void build_ST( ) {
        for( int i = 1; i <= lvl; i++ ) {
                for( int j = 1; j <=n; j++ ) {
                        if( par[j][i-1] != -1 ) {
                                par[j][i] = par[ par[j][i-1] ][i-1];
                        }
                }
        }
}
int LCA( int u , int v ) {
        if( depth[u] < depth[v] ) swap( u , v );
        int diff = depth[u] - depth[v];
        for( int i = lvl; i >= 0; i-- ) {
                if( ( 1 << i )&diff ) u = par[u][i];
        }
        if( u == v ) return u;
        for( int i = lvl; i >= 0; i-- ) {
                if( par[u][i] != -1 && par[u][i] != par[v][i] ) {
                        u = par[u][i];
                        v = par[v][i];
                }
        }
        return par[u][0];
}
pair <int,int> dia( int s ) {
        memset( dist , -1 , sizeof(dist) );
        queue <int> Q;
        dist[s] = 0;
        Q.push( s );
        int mx_dist = 0 , last = 0;
        while( !Q.empty() ) {
                int f = Q.front();
                Q.pop();
                for( int i = 0; i < graph[f].size(); i++ ) {
                        pii x = graph[f][i];
                        if( dist[x.first] == -1 ) {
                                dist[x.first] = dist[f] + x.second;
                                if( dist[x.first] > mx_dist ) {
                                        mx_dist = dist[x.first];
                                        last = x.first;
                                }
                                Q.push( x.first );
                        }
                }
        }
        return make_pair( last , mx_dist );
}
void reset( ) {
        for( int i = 1; i < N; i++ ) graph[i].clear();
}
int main( int argc , char const *argv[] ) {
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
                reset( );
                scanf("%d",&n);
                for( int i = 1; i <= n - 1; i++ ) {
                        int u , v , w;
                        scanf("%d %d %d",&u,&v,&w);
                        ++u , ++v;
                        graph[u].push_back( make_pair( v , w ) );
                        graph[v].push_back( make_pair( u , w ) );
                }
                memset( par , -1 , sizeof(par) );
                memset( dis , 0 , sizeof( dis ) );
                dfs( 1 , 0 );
                build_ST( );
                pair <int,int> p = dia( 1 );
                int x = p.first;
                pair <int,int> q = dia( p.first );
                int y = q.first;
                printf("Case %d:\n",tc);
                for( int i = 1; i <= n; i++ ) {
                        int ans1 = dis[i] + dis[x] - 2*dis[ LCA( i , x ) ];
                        int ans2 = dis[i] + dis[y] - 2*dis[ LCA( i , y ) ];
                        printf("%d\n",max(ans1,ans2));
                }
        }
        return 0;
}












