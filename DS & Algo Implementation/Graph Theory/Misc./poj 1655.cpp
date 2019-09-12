#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long uLL;
typedef long long int LL;
typedef pair <int,int> pii;
typedef pair <int,pii> piii;
typedef pair <long long,long long> pll;
typedef pair <long long,pll> plll;
const int N = 2e4 + 5;
const int inf = 1e9;
const long long INF = 1e18;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int MOD = 1000000007;

int n;
vector <int> graph[ N ] , compo[ N ];
int sub[ N ];

void dfs( int s , int p ) {
        sub[s] = 1;
        for( int i = 0; i < graph[s].size(); i++ ) {
                int x = graph[s][i];
                if( x != p ) {
                        dfs( x , s );
                        sub[s] += sub[x];
                }
        }
}
void process( int s , int p ) {
        for( int i = 0; i < graph[s].size(); i++ ) {
                int x = graph[s][i];
                if( x == p ) continue;
                compo[x].push_back( n - sub[x] );
                compo[s].push_back( sub[x] );
                process( x , s );
        }
}
void solve( ) {
        dfs( 1 , 0 );
        process( 1 , 0 );
        int mn = inf , ans = inf;
        for( int i = 1; i <= n; i++ ) {
                int mx = 0;
                for( int j = 0; j < compo[i].size(); j++ ) {
                        mx = max( mx , (int)compo[i][j] );
                }
                if( mx < mn ) mn = mx , ans = i;
        }
        cout << ans << " " << mn <<endl;
}
void reset( ) {
        for( int i = 1; i < N; i++ ) {
                graph[i].clear() , compo[i].clear() , sub[i] = 0;
        }
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( NULL );
        int t;
        cin >> t;
        while( t-- ) {
                reset( );
                cin >> n;
                for( int i = 1; i <= n - 1; i++ ) {
                        int u , v;
                        cin >> u >> v;
                        graph[u].push_back( v );
                        graph[v].push_back( u );
                }
                solve( );
        }
        return 0;
}











