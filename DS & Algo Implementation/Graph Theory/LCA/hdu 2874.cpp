//#include <bits/stdc++.h>

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
const int N = 1e4 + 5;
const int mod = 1000000007;
const double eps = 1e-8;
const double pi = acos( -1.0 );

const int lvl = 25;
vector <ii> graph[ N ];
int n , m , q , par[ N ][ lvl+5 ] , depth[ N ] , p[ N ] , dist[ N ];
bool vis[ N ];

void dfs( int s , int p ) {
        vis[s] = true;
        par[s][0] = p;
        depth[s] = depth[p] + 1;
        for( auto x : graph[s] ) {
                int ss = x.first , cc = x.second;
                if( ss == p ) continue;
                dist[ss] = dist[s] + cc;
                dfs( ss , s );
        }
}
void build_ST( ) {
        for( int i = 1; i <= lvl; i++ ) {
                for( int j = 1; j <=n; j++ ) {
                        par[j][i] = par[ par[j][i-1] ][i-1];
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
                if( par[u][i] != 0 && par[u][i] != par[v][i] ) {
                        u = par[u][i];
                        v = par[v][i];
                }
        }
        return par[u][0];
}
int Find( int x ) {
        return ( p[x] == x ? x : p[x] = Find( p[x] ) );
}
void Union( int a , int b ) {
        int u = Find( a ) , v = Find( b );
        if( u != v ) p[u] = v;
}
int main( int argc , char const *argv[] ) {
        while( scanf("%d %d %d",&n,&m,&q) != EOF ) {
                for( int i = 1; i <= n; i++ ) p[i] = i;
                for( int i = 1; i <= m; i++ ) {
                        int u , v , w;
                        scanf("%d %d %d",&u,&v,&w);
                        graph[u].push_back( {v,w} );
                        graph[v].push_back( {u,w} );
                        Union( u , v );
                }
                memset( vis , false , sizeof(vis) );
                for( int i = 1; i <= n; i++ ) if( !vis[i] ) dfs( i , 0 );
                build_ST( );
                for( int i = 1; i <= q; i++ ) {
                        int u , v;
                        scanf("%d %d",&u,&v);
                        if( Find(u) != Find(v) ) printf("Not connected\n");
                        else printf("%d\n",dist[u]+dist[v]-2*dist[LCA(u,v)] );
                }
                for( int i = 1; i < N; i++ ) graph[i].clear();
        }
        return 0;
}








