#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
/**
 for cycle all degree must be even & graph must be conncetd */
int n;
int curEdge[ N ];
bool visited[ N ];
vector < pair <int,int> > graph[ N ]; /// val , idx

vector <int> EulerPathUndirected( int u , int Edges ) {
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
vector <int> EulerPathUndirected( ) {
        int u = -1 , Edges = 0;
        for( int i = 1; i <= n; i++ ) {
                if( graph[i].size() > 0 && graph[i].size()%2 == 0 && u == -1 ) {
                        u = i;
                }
                if( graph[i].size()%2 == 1 ) return {};
                Edges += (int)( graph[i].size() );
        }
        return EulerPathUndirected( u , Edges/2 );
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
        for( int i = 1; i <= n; i++ ) {
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
        for( int i = 1; i < N; i++ ) graph[i].clear();
        memset( visited , false , sizeof( visited ) );
        memset( curEdge , 0 , sizeof( curEdge ) );
}
int main( int argc , char const *argv[] ) {

        return 0;
}










