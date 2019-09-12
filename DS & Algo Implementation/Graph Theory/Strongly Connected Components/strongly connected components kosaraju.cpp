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

int n , m;
vector <int> graph[ N ] , rev_graph[ N ];
vector <int> component[ N ];
bool vis[ N ];
stack <int> St;
int compo_size;

void TopoSort( int s ) {
        vis[ s ] = true;
        for( auto x : graph[s] ) if( !vis[x] ) TopoSort( x );
        St.push( s );
}
void Kosaraju( int s ) {
        vis[ s ] = true;
        component[ compo_size ].push_back( s );
        for( auto x : rev_graph[s] ) if( !vis[x] ) Kosaraju( x );
}
void SCC( ) {
        memset( vis , false , sizeof(vis) );
        for( int i = 1; i <= n; i++ ) {
                if( !vis[i] ) TopoSort( i );
        }
        memset( vis , false , sizeof(vis) );
        while( !St.empty() ) {
                int tp = St.top();
                St.pop();
                if( !vis[tp] ) compo_size++ , Kosaraju( tp );
        }
}

int main( int argc , char const *argv[] ) {
        ios_base :: sync_with_stdio(false); cin.tie(NULL);
        //freopen( "input.txt" , "r" , stdin );
        cin >> n >> m;
        for( int i = 1; i <= m; i++ ) {
                int u , v;
                cin >> u >> v;
                graph[u].push_back( v );
                rev_graph[v].push_back( u );
        }

        SCC( );

        cout << "total SCC " << compo_size <<endl;
        for( int i = 1; i <= compo_size; i++ ) {
                for( auto x : component[i] ) {
                        cout << x << " ";
                }
                cout << endl;
        }
        return 0;
}






