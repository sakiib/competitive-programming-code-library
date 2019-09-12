#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long uLL;
typedef long long int LL;
typedef pair <int,int> pii;
typedef pair <int,pii> piii;
typedef pair <long long,long long> pll;
typedef pair <long long,pll> plll;
const int N = 2e5 + 5;
const int inf = 1e9;
const long long INF = 1e18;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int MOD = 1000000007;

int n , m;
vector <pll> graph[ N ];
LL cost[ N ];
bool relaxed[ N ];

void dijkstra( ) {
        priority_queue < pll , vector <pll> , greater <pll> > Q;
        for( int i = 1; i <= n; i++ ) Q.push( {cost[i],i} );
        while( !Q.empty() ) {
                pll t = Q.top(); Q.pop();
                int ps = t.second;
                LL pc = t.first;
                if( relaxed[ ps ] ) continue;
                relaxed[ ps ] = true;
                for( auto x : graph[ps] ) {
                        int ns = x.first;
                        LL nc = x.second;
                        if( cost[ns] > cost[ps] + nc ) {
                                cost[ns] = cost[ps] + nc;
                                Q.push( {cost[ns],ns} );
                        }
                }
        }
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( NULL );
        cin >> n >> m;
        for( int i = 1; i <= m; i++ ) {
                int u , v;
                LL w;
                cin >> u >> v >> w;
                graph[u].push_back( {v,2*w} );
                graph[v].push_back( {u,2*w} );
        }
        for( int i = 1; i <= n; i++ ) cin >> cost[i];
        dijkstra();
        for( int i = 1; i <= n; i++ ) cout << cost[i] << " ";
        return 0;
}











