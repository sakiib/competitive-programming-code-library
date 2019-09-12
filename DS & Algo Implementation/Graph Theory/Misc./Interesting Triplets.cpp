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
int sub[ N ];
int n;
vector <int> compo[ N ];
bool vis[ N ];

/**

 A, B, C from a tree, sometimes it may occur that sum of the shortest distance
  from A to B and from B to C is equal to the shortest distance from A to C
*/


int bfs( int s , int t ) {
        queue <int> Q;
        Q.push( s );
        int d[ 30 ];
        memset( d , -1 , sizeof(d) );
        d[s] = 0;
        while( !Q.empty( ) ) {
                int f = Q.front();
                Q.pop();
                for( auto x : graph[f] ) {
                        if( d[x] == -1 || d[x] > d[f]+1 ) {
                                d[x] = d[f] + 1;
                                Q.push( x );
                        }
                }
        }
        return d[t];
}
bool ok( int a , int b , int c ) {
        int x = bfs( a , b ) , y = bfs( b , c ) , z = bfs( a , c );
        return ( x+y == z );
}
void dfs( int s , int p ) {
        sub[s] = 1;
        for( auto x : graph[s] ) {
                if( x == p ) continue;
                dfs( x , s );
                sub[s] += sub[x];
        }
}
void process( int s , int p ) {
        for( auto x : graph[s] ) {
                if( x == p ) continue;
                compo[x].push_back( n-sub[x] );
                compo[s].push_back( sub[x] );
                process( x , s );
        }
}
LL Hard( ) {
        dfs( 1 , 0 );
        process( 1 , 0 );
        LL ans = 0;
        for( int i = 1; i <= n; i++ ) {
                for( auto x : compo[i] ) {
                        ans += ( 1LL * x * ( n - 1 - x ) );
                }
        }
        return ans;
}
LL Easy( ) {
        LL ans = 0;
        for( int i = 1; i <= n; i++ ) {
                for( int j = 1; j <= n; j++ ) {
                        for( int k = 1; k <= n; k++ ) {
                                if( i == j || j == k ) continue;
                                if( ok( i , j , k ) ) ans++;
                        }
                }
        }
        return ans;
}
int main( int argc , char const *argv[] ) {
        ios_base :: sync_with_stdio(false); cin.tie(NULL);
        int t;
        cin >> t;
        for( int tc = 1; tc <= t; tc++ ) {
                cin >> n;
                for( int i = 1; i <= n-1; i++ ) {
                        int u , v;
                        cin >> u >> v;
                        graph[u].push_back( v );
                        graph[v].push_back( u );
                }
                memset( vis , false , sizeof(vis) );
                cout << "Case " << tc << ": " << Hard( ) << endl;
                for( int i = 1; i < N; i++ ) graph[i].clear() , compo[i].clear();
        }
        return 0;
}
/**

Input :

1

15

1 2
1 3
1 4
3 5
3 6
6 7
6 8
6 9
7 10
7 11
11 12
8 15
9 13
9 14

Output : 450

*/



