#include <bits/stdc++.h>
using namespace std;

const int N = 505;
const int inf = 1e7;

typedef pair <int,int> pii;
typedef pair <int,pii> piii;
int cost[ N ][ 2 ];
vector <pii> graph[ N ];
int relaxed[ N ];

void dijkstra( ) {
        for( int i = 1; i < N; i++ ) cost[i][0] = cost[i][1] = inf;
        priority_queue < piii,vector <piii> , greater <piii> > Q;
        cost[1][0] = 0; /// on the back
        Q.push( piii( 0 , pii( cost[1][0] , 1 ) ) );
        while( !Q.empty() ) {
                piii t = Q.top(); Q.pop();
                int type = t.first;
                int pc = t.second.first;
                int ps = t.second.second;
                for( auto x : graph[ps] ) {
                        pii cur = x;
                        int nc = cur.second;
                        int ns = cur.first;
                        if( cost[ns][type^1] == inf || cost[ns][type^1] > cost[ps][type] + nc ) {
                                cost[ns][type^1] = cost[ps][type] + nc;
                                Q.push( piii( type^1 , pii( cost[ns][type^1] , ns ) ) );
                        }
                }
        }
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( NULL );
        int n , m;
        int tc = 0;
        while( cin >> n >> m ) {
                for( int i = 1; i < N; i++ ) graph[i].clear( );
                memset( relaxed , false , sizeof( relaxed ) );
                for( int i = 1; i <= m; i++ ) {
                        int u , v , w;
                        cin >> u >> v >> w;
                        ++u , ++v;
                        graph[u].push_back( {v,w} );
                        graph[v].push_back( {u,w} );
                }
                dijkstra( );
                int ans = cost[n][0];
                cout << "Set #" << ++tc << endl;
                if( ans >= inf ) cout << '?' << endl;
                else cout << ans << endl;
        }
        return 0;
}










