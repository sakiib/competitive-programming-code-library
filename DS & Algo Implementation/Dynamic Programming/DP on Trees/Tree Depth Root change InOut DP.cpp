#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
typedef unsigned long long uLL;
typedef long long int LL;
typedef pair <int,int> pii;
typedef pair <int,pii> piii;
typedef pair <long long,long long> pll;
typedef pair <long long,pll> plll;
const int N = 1e5 + 5;
const int inf = 1e9;
const long long INF = 1e18;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int MOD = 1000000007;

/**
DP on trees -> Type - B
Tree Depth when root can be any node
depth[i] = max( in[i] , out[i] )
*/
int n;
vector <int> graph[ N ];
int in[ N ] , out[ N ];

void dfs1( int s , int p ) {
        in[s] = 0;
        for( auto x : graph[s] ) {
                if( x != p ) {
                        dfs1( x , s );
                        in[s] = max( in[s] , 1 + in[x] );
                }
        }
}
void dfs2( int s , int p ) {
        int mx1 = -1 , mx2 = -1;
        for( auto x : graph[s] ) {
                if( x == p ) continue;
                if( in[x] >= mx1 ) mx2 = mx1 , mx1 = in[x];
                else if( in[x] > mx2 ) mx2 = in[x];
        }
        for( auto x : graph[s] ) {
                if( x == p ) continue;
                int use = mx1;
                if( mx1 == in[x] ) use = mx2;
                out[x] = max( 1 + out[s] , 2 + use );
                dfs2( x , s );
        }
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( nullptr );
        cin >> n;
        for( int i = 1; i <= n - 1; i++ ) {
                int u , v;
                cin >> u >> v;
                graph[u].push_back( v );
                graph[v].push_back( u );
        }
        dfs1( 1 , 0 );
        dfs2( 1 , 0 );
        for( int i = 1; i <= n; i++ ) cout << max( in[i] , out[i] ) << " ";
        return 0;
}
/**
input :

10
1 2
1 3
1 4
2 5
2 6
3 7
4 8
7 9
7 10

output :
3 4 3 4 5 5 4 5 5 5

*/









