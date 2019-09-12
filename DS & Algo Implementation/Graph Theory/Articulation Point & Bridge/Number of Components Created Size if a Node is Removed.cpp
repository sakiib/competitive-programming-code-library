#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 1e4 + 5;
int n , sub[ N ];
vector <int> graph[ N ];
vector <int> compo[ N ];
// compo contains the size of other components created if Node i is removed.

void dfs( int s , int p ) {
        sub[s] = 1;
        for( auto x : graph[s] ) if( x != p ) dfs( x , s ) , sub[s] += sub[x];
}
void process( int s , int p ) {
        for( auto x : graph[s] ) {
                if( x == p ) continue;
                compo[x].push_back( n + 1 - sub[x] );
                compo[s].push_back( sub[x] );
                process( x , s );
        }
}
pair <int,LL> go( ) {
        int ret = 0;
        LL mx = 0;
        for( int i = 0; i <= n; i++ ) {
                int tot = 0;
                for( int j = 0; j < compo[i].size(); j++ ) {
                        for( int k = j + 1; k < compo[i].size(); k++ ) {
                                tot += ( 1LL * compo[i][k] * compo[i][j] );
                        }
                }
                if( tot > mx ) mx = tot , ret = i;
        }
        return make_pair( ret , mx );
}
int main( int argc , char const *argv[] ) {
        scanf("%d",&n);
        for( int i = 1; i <= n; i++ ) {
                int u , v;
                scanf("%d %d",&u,&v);
                graph[u].push_back( v );
                graph[v].push_back( u );
        }
        dfs( 0 , -1 );
        process( 0 , -1 );
        for( int i = 0; i <= n; i++ ) sort( compo[i].begin(), compo[i].end() );
        pair <int,LL> critical = go( );
        int node = critical.first;
        LL ans = critical.second;
        int sz = compo[node].size();
        LL bad = 1LL * compo[node][sz-1] * compo[node][sz-2];
        printf("%lld %lld\n",ans,(ans-bad));
        return 0;
}










