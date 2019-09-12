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
set <int> point;
int Time;
int st[ N ] , low[ N ] , par[ N ];
bool visited[ N ];
bool br[ N ];

void Tarjan( int s , int p = -1 ) {
        st[s] = low[s] = ++Time;
        visited[s] = true;
        int child = 0;
        par[s] = p;
        for( auto x : graph[s] ) {
                if( x == p ) continue;
                if( visited[x] ) low[s] = min( low[s] , st[x] );
                else {
                        Tarjan( x , s );
                        low[s] = min( low[s] , low[x] );
                        if( low[x] >= st[s] && p != -1 ) point.insert( s );
                        if( low[x] > st[s] ) {
                                bridge.push_back( {s,x} );
                                br[x] = true;
                                br[s] = true;
                        }
                        child++;
                }
        }
        if( p == -1 && child > 1 ) point.insert( s );
}
void Reset( ) {
        Time = 0;
        bridge.clear();
        point.clear();
        memset( br , false , sizeof(br) );
        memset( visited , false , sizeof(visited) );
        for( int i = 1; i < N; i++ ) graph[i].clear();
}
int main( int argc , char const *argv[] ) {
        ios_base :: sync_with_stdio(false); cin.tie(NULL);
        int n , m;
        while( cin >> n >> m ) {
                if( n == 0 && m == 0 ) break;
                Reset( );
                for( int i = 1; i <= m; i++ ) {
                        int u , v;
                        cin >> u >> v;
                        graph[u].push_back( v );
                        graph[v].push_back( u );
                }
                Tarjan( 1 );
                cout << point.size() << endl;
        }
        return 0;
}







