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

int n , mypos;
vector <int> graph[ N ];
int dist[ N ];

pair <int,int> dia( int s ) {
        memset( dist , -1 , sizeof(dist) );
        queue <int> Q;
        dist[s] = 0;
        Q.push( s );
        int mx_dist = 0 , last = 0;
        while( !Q.empty() ) {
                int f = Q.front(); Q.pop();
                for( auto x : graph[f] ) {
                        if( dist[x] == -1 ) {
                                dist[x] = dist[f] + 1;
                                if( dist[x] > mx_dist ) {
                                        mx_dist = dist[x];
                                        last = x;
                                }
                                Q.push( x );
                        }
                }
        }
        return make_pair( last , mx_dist );
}
int main( int argc , char const *argv[] ) {
        ios_base :: sync_with_stdio(false); cin.tie(NULL);
        cin >> n;
        for( int i = 1; i <= n-1; i++ ) {
                int u , v;
                cin >> u >> v;
                graph[u].push_back( v );
                graph[v].push_back( u );
        }

        pair <int,int> p = dia( 1 );
        int x = p.first;
        pair <int,int> q = dia( p.first );
        int y = q.first;
        cout << "Dia : " << q.second << endl;
        cout << "Between nodes : " << x << " & " << y << endl;
        return 0;
}







