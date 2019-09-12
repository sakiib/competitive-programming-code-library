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

vector <int> graph[ N ];
set <int> articulation_point;
int Time;
int st[ N ] , low[ N ];
bool visited[ N ];

void dfs( int s , int p = -1 ) {
        st[s] = low[s] = ++Time;
        visited[s] = true;
        int child = 0;
        for( int i = 0; i < graph[s].size(); i++ ) {
                int x = graph[s][i];
                if( x == p ) continue;
                if( visited[x] ) {
                        low[s] = min( low[s] , st[x] );
                }
                else {
                        dfs( x , s );
                        low[s] = min( low[s] , low[x] );
                        if( low[x] >= st[s] && p != -1 ) {
                                articulation_point.insert( s );
                        }
                        child++;
                }
        }
        if( p == -1 && child > 1 ) articulation_point.insert( s );
}
int main( int argc , char const *argv[] ) {
        ios_base :: sync_with_stdio(false); cin.tie(NULL);
        int t;
        cin >> t;
        for( int tc = 1; tc <= t; tc++ ) {
                for( int i = 1; i < N; i++ ) graph[i].clear();
                articulation_point.clear();
                Time = 0;
                memset( visited , false , sizeof(visited) );
                int n , m;
                cin >> n >> m;
                for( int i = 1; i <= m; i++ ) {
                        int u , v;
                        cin >> u >> v;
                        graph[u].push_back( v );
                        graph[v].push_back( u );
                }
                dfs( 1 );
                cout << "Case " << tc << ": " << articulation_point.size() << endl;
                //for( auto x : articulation_point ) cout << x << " ";
        }
        return 0;
}







