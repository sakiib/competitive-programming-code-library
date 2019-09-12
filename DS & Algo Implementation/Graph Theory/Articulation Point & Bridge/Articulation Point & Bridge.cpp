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
int st[ N ] , low[ N ];
bool visited[ N ] , br[ N ];

void Tarjan( int s , int p = -1 ) {
        st[s] = low[s] = ++Time;
        visited[s] = true;
        int child = 0;
        for( auto x : graph[s] ) {
                if( x == p ) continue;
                if( visited[x] ) {
                        low[s] = min( low[s] , st[x] );
                }
                else {
                        Tarjan( x , s );
                        low[s] = min( low[s] , low[x] );
                        if( low[x] >= st[s] && p != -1 ) point.insert( s );
                        if( low[x] > st[s] ) {
                                bridge.push_back( {s,x} );
                                br[x] = true;
                                br[s] = true;
                                /// In case of adding edge & cheking for no. of cutedge
                                /// just mark : ( br[x] = true; )
                        }
                        child++;
                }
        }
        if( p == -1 && child > 1 ) point.insert( s );
}
int main( int argc , char const *argv[] ) {
        ios_base :: sync_with_stdio(false); cin.tie(NULL);
        int n;
        cin >> n;
        for( int i = 1; i <= n; i++ ) {
                int u , v;
                cin >> u >> v;
                graph[u].push_back( v );
                graph[v].push_back( u );
        }
        point.clear() , bridge.clear();
        memset( visited , false , sizeof(visited) );
        memset( br , false , sizeof(br) );
        Time = 0;
        for( int i = 1; i <= n; i++ ) if( !visited[i] ) Tarjan( i );
        cout << "Articulation points are : " << endl;
        for( auto x : point ) cout << x << " ";
        cout << endl;
        cout << "Bridges are : " << endl;
        for( auto x : bridge ) cout << x.first << " " << x.second << endl;
        return 0;
}







