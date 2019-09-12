#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
typedef pair< int,int > ii;
typedef pair< int,ii > iii;
const int inf = 1e9;
const LL INF = 1e18;
const int N = 100005;
const int MOD = 1e9+7;
const double EPS = 1e-6;
const double PI = acos(-1.0);

LL cost[ N ];
vector < pair < LL,LL > > graph[ N ];

void BFS01( int s ) {
    memset( cost , -1 , sizeof( cost ) );
    deque < int > Q;
    cost[s] = 0;
    Q.push_front( s );
    while( !Q.empty() ) {
        int f = Q.front();
        Q.pop_front();
        for( int i = 0; i < graph[f].size(); i++ ) {
            pair < LL,LL > p = graph[f][i];
            LL c = p.second;
            int s = p.first;
            if( cost[s] == -1 || cost[s] > cost[f]+c ) {
                cost[s] = cost[f]+c;
                if( c == 0 ) Q.push_front( s );
                else Q.push_back( s );
            }
        }
    }
}
int main( int argc, char const *argv[] ) {
    int n , m;
    scanf("%d %d",&n,&m);
    for( int i = 1; i <= m; i++ ) {
        int u , v;
        scanf("%d %d",&u,&v);
        graph[u].push_back( {v,0} );
        graph[v].push_back( {u,1} );
    }
    BFS01( 1 );
    printf("%lld\n",cost[n]);
    return 0;
}

