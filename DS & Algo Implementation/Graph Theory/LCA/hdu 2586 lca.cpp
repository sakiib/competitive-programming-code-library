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
const int N = 1e5 + 5;
const int mod = 1000000007;
const double eps = 1e-8;
const double pi = acos( -1.0 );

const int lvl = 25;
vector < ii > graph[ N ];
int n , m , par[ N ][ lvl+5 ] , depth[ N ] , dist[ N ];

void dfs( int s , int p ) {
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
                        //if( par[j][i-1] != -1 ) {
                                par[j][i] = par[ par[j][i-1] ][i-1];
                        //}
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
                if( par[u][i] != -1 && par[u][i] != par[v][i] ) {
                        u = par[u][i];
                        v = par[v][i];
                }
        }
        return par[u][0];
}
int main( int argc , char const *argv[] ) {
        int t;
        scanf("%d",&t);
        while( t-- ) {
                scanf("%d %d",&n,&m);
                for( int i = 1; i <= n-1; i++ ) {
                        int u , v , w;
                        scanf("%d %d %d",&u,&v,&w);
                        graph[u].push_back( {v,w} );
                        graph[v].push_back( {u,w} );
                }
                //memset( par , -1 , sizeof(par) );
                dfs( 1 , 0 );
                build_ST( );
                for( int i = 1; i <= m; i++ ) {
                        int u , v;
                        scanf("%d %d",&u,&v);
                        printf("%d\n",dist[u]+dist[v]-2*dist[LCA(u,v)] );
                }
                for( int i = 1; i < N; i++ ) graph[i].clear();
        }
        return 0;
}






