#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long uLL;
typedef long long int LL;
typedef pair <int,int> pii;
typedef pair <int,pii> piii;
typedef pair <long long,long long> pll;
typedef pair <long long,pll> plll;
const int N = 3e5 + 5;
const int inf = 1e9;
const long long INF = 1e18;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int MOD = 1000000007;

int n , m , k;
vector <pll> graph[ N ];
vector <int> tree[ N ];
LL cost[ N ];
int par[ N ];
bool relaxed[ N ];
map <pii,int> ID;
vector <int> ans;

void dijkstra( ) {
        for( int i = 1; i < N; i++ ) cost[i] = INF;
        cost[1] = 0;
        priority_queue < pll , vector <pll> , greater <pll> > Q;
        Q.push( {cost[1],1} );
        while( !Q.empty() ) {
                pll t = Q.top(); Q.pop();
                LL pc = t.first;
                int ps = t.second;
                if( relaxed[ps] ) continue;
                relaxed[ps] = true;
                for( auto x : graph[ps] ) {
                        int ns = x.first;
                        LL nc = x.second;
                        if( cost[ns] == INF || cost[ns] > cost[ps] + nc ) {
                                cost[ns] = cost[ps] + nc;
                                par[ns] = ps;
                                Q.push( {cost[ns],ns} );
                        }
                }
        }
}
void print( int s , int p ) {
        if( p != 0 ) ans.push_back( ID[ {min(s,p),max(s,p)} ] );
        if( k == 0 ) return;
        for( auto x : tree[s] ) {
                if( x != p && k > 0 ) k-- , print( x , s );
        }
}
void dijkstraTree( ) {
        par[1] = -1;
        for( int i = 2; i <= n; i++ ) {
                tree[i].push_back( par[i] );
                tree[ par[i] ].push_back( i );
        }
        print( 1 , 0 );
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( NULL );
        cin >> n >> m >> k;
        for( int i = 1; i <= m; i++ ) {
                int u , v , w;
                cin >> u >> v >> w;
                graph[u].push_back( {v,w} );
                graph[v].push_back( {u,w} );
                ID[ {min(u,v),max(u,v)} ] = i;
        }
        dijkstra();
        dijkstraTree();
        cout << ans.size() << endl;
        for( auto x : ans ) cout << x << " ";
        return 0;
}











