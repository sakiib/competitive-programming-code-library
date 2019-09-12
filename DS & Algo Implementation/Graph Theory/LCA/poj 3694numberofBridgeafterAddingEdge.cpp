#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <deque>
#include <functional>
#include <string>
#include <iostream>
#include <cctype>
#include <set>
#include <climits>
#include <iomanip>
#include <cassert>
#include <sstream>
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

vector <int> graph[ 2*N ];
int Time;
int st[ 2*N ] , low[ 2*N ] , p[ 2*N ] , depth[ 2*N ] , par[ 2*N ];
bool visited[ 2*N ] , bridge[ 2*N ];
int n , m , Bridge;

void Tarjan( int s , int pp ) {
        st[s] = low[s] = ++Time;
        visited[s] = true;
        depth[s] = depth[pp] + 1;
        par[s] = pp;
        for( int i = 0; i < graph[s].size(); i++ ) {
                int x = graph[s][i];
                if( x == pp ) continue;
                if( visited[x] ) {
                        low[s] = min( low[s] , st[x] );
                }
                else {
                        par[x] = s;
                        Tarjan( x , s );
                        low[s] = min( low[s] , low[x] );
                        if( low[x] > st[s] ) Bridge++ , bridge[x] = true;
                }
        }
}
void LCA( int u , int v ) {
        if( depth[u] < depth[v] ) swap( u , v );
        while( depth[u] > depth[v] ) {
                if( bridge[u] ) Bridge-- , bridge[u] = false;
                u = par[u];
        }
        while( u != v ) {
                if( bridge[u] ) Bridge-- , bridge[u] = false;
                if( bridge[v] ) Bridge-- , bridge[v] = false;
                v = par[v];
                u = par[u];
        }
}
int main( int argc , char const *argv[] ) {
        int tc = 0;
        while( scanf("%d %d",&n,&m) ) {
                if( n == 0 && m == 0 ) break;
                for( int i = 1; i <= m; i++ ) {
                        int u , v;
                        scanf("%d %d",&u,&v);
                        graph[u].push_back( v );
                        graph[v].push_back( u );
                }
                memset( visited , false , sizeof(visited) );
                memset( bridge , false , sizeof(bridge) );
                depth[0] = 0;
                Time = 0 , Bridge = 0;
                Tarjan( 1 , 0 );

                int q;
                scanf("%d",&q);
                printf("Case %d:\n",++tc);
                for( int i = 1; i <= q; i++ ) {
                        int u , v;
                        scanf("%d %d",&u,&v);
                        LCA( u , v );
                        printf("%d\n",Bridge);
                }
                printf("\n");
                for( int i = 1; i < 2*N; i++ ) graph[i].clear();
        }
        return 0;
}






