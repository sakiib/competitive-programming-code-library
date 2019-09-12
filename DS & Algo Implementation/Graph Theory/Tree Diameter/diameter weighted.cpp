#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long uLL;
typedef long long int LL;
typedef pair <int,int> pii;
typedef pair <int,pii> piii;
typedef pair <long long,long long> pll;
typedef pair <long long,pll> plll;
const int N = 3e4 + 5;
const int inf = 1e9;
const long long INF = 1e18;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int MOD = 1000000007;

vector <pii> graph[ N ];
int dist[ N ];
int n;

pair <int,int> dia( int s ) {
        memset( dist , -1 , sizeof(dist) );
        queue <int> q;
        dist[s] = 0;
        q.push( s );
        int mx_dist = 0 , last = 0;
        while( !q.empty() ) {
                int f = q.front();
                q.pop();
                for( int i = 0; i < graph[f].size(); i++ ) {
                        pii x = graph[f][i];
                        if( dist[x.first] == -1 ) {
                                dist[x.first] = dist[f] + x.second;
                                if( dist[x.first] > mx_dist ) {
                                        mx_dist = dist[x.first];
                                        last = x.first;
                                }
                                q.push( x.first );
                        }
                }
        }
        return make_pair( last , mx_dist );
}
void reset( ) {
        for( int i = 1; i < N; i++ ) graph[i].clear();
}
int main( int argc , char const *argv[] ) {
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
                reset( );
                scanf("%d",&n);
                for( int i = 1; i <= n - 1; i++ ) {
                        int u , v , w;
                        scanf("%d %d %d",&u,&v,&w);
                        ++u , ++v;
                        graph[u].push_back( make_pair( v , w ) );
                        graph[v].push_back( make_pair( u , w ) );
                }
                pair <int,int> p = dia( 1 );
                int x = p.first;
                pair <int,int> q = dia( p.first );
                int y = q.first;
                printf("Case %d: %d\n",tc,q.second);
                //cout << "Dia : " << q.second << endl;
                //cout << "Between nodes : " << x << " & " << y << endl;
        }
        return 0;
}







