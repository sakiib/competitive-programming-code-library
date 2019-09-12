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

vector <int> graph[ N ];
bool visited[ N ];
stack <int> S;
/// can use a vector then reverse is to get the order..

void Topological_Sort( int s ) {
    visited[ s ] = true;
    for( int i = 0; i < graph[ s ].size(); i++ ) {
        int next = graph[ s ][ i ];
        if( !visited[ next ] ) {
            Topological_Sort( next );
        }
    }
    S.push( s );
}

void dfs( int s ) {
    visited[ s ] = true;
    for( int i = 0; i < graph[ s ].size(); i++ ) {
        int next = graph[ s ][ i ];
        if( !visited[ next ] ) {
            dfs( next );
        }
    }
}
int main( int argc, char const *argv[] ) {
    int t;
    scanf("%d",&t);
    for( int tc = 1; tc <= t; tc++ ) {
        int n , m;
        scanf("%d%d",&n,&m);
        for( int i = 1; i <= m; i++ ) {
            int u , v;
            scanf("%d%d",&u,&v);
            graph[ u ].push_back( v );
        }
        for( int i = 1; i <= n; i++ ) {
            if( !visited[ i ] ) {
                Topological_Sort( i );
            }
        }
        memset( visited , false , sizeof( visited ) );
        int ans = 0;
        while( !S.empty() ) {
            int top = S.top();
            S.pop();
            if( !visited[ top ] ) {
                ans ++;
                dfs( top );
            }
        }
        printf("Case %d: %d\n",tc,ans);
        memset( visited , false ,sizeof( visited ) );
        for( int i = 0; i < N; i++ ) graph[i].clear();
    }
    return 0;
}

