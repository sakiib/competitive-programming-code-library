#include <bits/stdc++.h>
using namespace std;

const int N = 35;
const int inf = 1e9;
typedef pair <int,int> pii;

int curEdge[ N ];
bool visited[ N ];
vector < pair <int,int> > graph[ N ];
vector < pair <int,int> > dgraph[ N ];
int cost[ N ];
int id , tot;

int getID( char ch ) {
        return ch - 'a' + 1;
}
void Reset( ) {
        id = 0;
        tot = 0;
        for(int i = 1; i < N; i++ ) graph[i].clear() , dgraph[i].clear();
        memset( curEdge , 0 , sizeof( curEdge ) );
        memset( visited , false , sizeof( visited ) );
        for( int i = 1; i < N; i++ ) cost[i] = inf;
}
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
        for( int i = 1; i <= 26; i++ ) {
                if( (int)graph[i].size() > 0 && (int)graph[i].size()%2 == 0 ) {
                        startingNode = i;
                }
                if( (int)graph[i].size()%2 == 1 ) return {};
                totalEdges += (int)graph[i].size();
        }
        if( startingNode == -1 ) return {};
        return EulerCycleUndirected( startingNode , totalEdges/2 );
}
void dijkstra( int s ) {
        cost[s] = 0;
        priority_queue < pii, vector <pii>, greater <pii> > Q;
        Q.push( {0,s} );
        while( !Q.empty() ) {
                pii t = Q.top(); Q.pop();
                for( auto x : dgraph[t.second] ) {
                        if( cost[x.first] == inf || cost[x.first] > cost[t.second] + x.second ) {
                                cost[x.first] = cost[t.second] + x.second;
                                Q.push( { cost[x.first],x.first } );
                        }
                }
        }
}
int solve( ) {
        //vector <int> V = EulerCycleUndirected( );
        //if( V.size( ) ) return tot;
        vector <int > s;
        for( int i = 1; i <= 26; i++ ) {
                if( graph[i].size()%2 == 1 ) s.push_back( i );
        }
        if( !s.size() ) return tot;
        dijkstra( s[0] );
        return tot + cost[ s[1] ];
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( NULL );
        string s;
        Reset( );
        while( cin >> s ) {
                if( s == "deadend" ) {
                        cout << solve( ) << endl;
                        Reset( );
                }
                else {
                        int cost = s.size();
                        tot += cost;
                        int u = getID( s[0] ) , v = getID( s[s.size()-1] );
                        graph[u].push_back( {v,++id} );
                        graph[v].push_back( {u,id} );
                        dgraph[u].push_back( {v,cost} );
                        dgraph[v].push_back( {u,cost} );
                }
        }
        return 0;
}







