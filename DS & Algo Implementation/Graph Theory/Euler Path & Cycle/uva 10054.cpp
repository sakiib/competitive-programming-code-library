#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

int n;
int curEdge[ N ];
bool visited[ N ];
vector < pair <int,int> > graph[ N ];

vector <int> EulerCycleUndirected( int u , int Edges ) {
        vector <int> res;
        stack <int> S;
        S.push( u );
        while( !S.empty() ) {
                u = S.top(); S.pop();
                while( curEdge[u] < (int)( graph[u].size() ) ) {
                        pair <int,int> node = graph[u][curEdge[u]++];
                        int v = node.first , id = node.second;
                        if( !visited[id] ) {
                                S.push( u ) , u = v , visited[id] = true;
                        }
                }
                res.push_back( u );
        }
        if( (int)res.size() != Edges + 1 ) return {};
        reverse( res.begin() , res.end() );
        return res;
}
vector <int> EulerCycleUndirected( ) {
        int startingNode = -1 , totalEdges = 0;
        for( int i = 1; i <= 50; i++ ) {
                if( (int)graph[i].size() > 0 && (int)graph[i].size()%2 == 0 ) {
                        startingNode = i;
                }
                if( (int)graph[i].size()%2 == 1 ) return {};
                totalEdges += (int)graph[i].size();
        }
        if( startingNode == -1 ) return {};
        return EulerCycleUndirected( startingNode , totalEdges/2 );
}
void Reset( ) {
        for( int i = 0; i < N; i++ ) graph[i].clear();
        memset( visited , false , sizeof( visited ) );
        memset( curEdge , 0 , sizeof( curEdge ) );
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( NULL );
        int t;
        cin >> t;
        for( int tc = 1; tc <= t; tc++ ) {
                Reset( );
                cin >> n;
                for( int i = 1; i <= n; i++ ){
                        int u , v;
                        cin >> u >> v;
                        graph[u].push_back( {v,i} );
                        graph[v].push_back( {u,i} );
                }

                vector <int> V = EulerCycleUndirected( );

                if( !V.size() ) {
                        cout << "Case " << "#" << tc << endl;
                        cout << "some beads may be lost" << endl;
                }
                else {
                        cout << "Case " << "#" << tc << endl;
                        for( int i = 0; i < V.size() - 1; i++ ) {
                                cout << V[i] << " " << V[i+1] << endl;
                        }
                }
                if( tc < t ) cout << endl;
        }
        return 0;
}








