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
vector < pair<int,int> > bridge;
int Time;
int st[ N ] , low[ N ];
bool visited[ N ];

void dfs( int s , int p = -1 ) {
        st[s] = low[s] = ++Time;
        visited[s] = true;
        for( int i = 0; i < graph[s].size(); i++ ) {
                int x = graph[s][i];
                if( x == p ) continue;
                if( visited[x] ) {
                        low[s] = min( low[s] , st[x] );
                }
                else {
                        dfs( x , s );
                        low[s] = min( low[s] , low[x] );
                        if( low[x] > st[s] ) {
                                bridge.push_back( {min(s,x),max(s,x)} );
                        }
                }
        }
}
int main( int argc , char const *argv[] ) {
        ios_base :: sync_with_stdio(false); cin.tie(NULL);
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
                memset( visited , false , sizeof(visited) );
                Time = 0;
                for( int i = 0; i < N; i++ ) graph[i].clear();
                bridge.clear();
                int n;
                scanf("%d",&n);
                for( int i = 1; i <= n; i++ ) {
                        int u , v , k;
                        char ch;
                        scanf("%d%c%c%d%c",&u,&ch,&ch,&k,&ch);
                        while( k-- ) {
                                scanf("%d",&v);
                                graph[u].push_back( v );
                                graph[v].push_back( u );
                        }
                }
                for( int i = 0; i < n; i++ ) {
                        if( !visited[i] ) dfs( i );
                }
                sort( bridge.begin() , bridge.end() );
                printf("Case %d:\n",tc);
                printf("%d critical links\n",bridge.size());
                for( int i = 0; i < bridge.size(); i++ ) {
                        printf("%d - %d\n",bridge[i].first,bridge[i].second);
                }
        }
        return 0;
}






