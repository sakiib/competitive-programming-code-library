#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

/**
 For Directed Graph Only
 no reset has been done , so
 Reset graph & everything carefully for multiple test cases.
 check what is n
 see the path & cycle carefully
 for definition see wiki
 */

int n;
int inDegree[ N ] , curEdge[ N ];
vector <int> graph[ N ];

vector <int> EulerPathDirected( int startingNode , int totalEdges ) {
        vector <int> res;
        stack <int> S;
        S.push( startingNode );
        while( !S.empty() ) {
                int st = S.top(); S.pop();
                while( curEdge[st] < graph[st].size() ) {
                        S.push( st );
                        st = graph[st][ curEdge[st]++ ];
                }
                res.push_back( st );
        }
        if( (int)res.size() != totalEdges + 1 ) return {};
        reverse( res.begin() , res.end() );
        return res;
}
vector <int> EulerPathDirected( ) {
        int startingNode = -1 , totalEdges = 0;
        for( int i = 1; i <= n; i++ ) {
                for( auto x : graph[i] ) {
                        inDegree[x]++;
                }
                if( (int)graph[i].size() > 0 ) startingNode = i;
                totalEdges += (int)( graph[i].size() );
        }
        int deficit = 0;
        for( int i = 1; i <= n; i++ ) {
                if( (int)graph[i].size() > inDegree[i] ) {
                        deficit += ( (int)graph[i].size() - inDegree[i] );
                        startingNode = i;
                }
        }
        if( deficit > 1 || startingNode == -1 ) return {};
        return EulerPathDirected( startingNode , totalEdges );
}
vector <int> EulerCycleDirected( int startingNode , int totalEdges ) {
        memset( curEdge , 0 , sizeof( curEdge ) );
        vector <int> res;
        stack <int> S;
        S.push( startingNode );
        while( !S.empty() ) {
                int st = S.top(); S.pop();
                while( curEdge[st] < graph[st].size() ) {
                        S.push( st );
                        st = graph[st][ curEdge[st]++ ];
                }
                res.push_back( st );
        }
        if( (int)res.size() != totalEdges + 1 ) return {};
        reverse( res.begin() , res.end() );
        return res;
}
vector <int> EulerCycleDirected( ) {
        int startingNode = -1 , totalEdges = 0;
        for( int i = 1; i <= n; i++ ) {
                for( auto x : graph[i] ) {
                        inDegree[x]++;
                }
                if( (int)graph[i].size() > 0 ) startingNode = i;
                totalEdges += (int)( graph[i].size() );
        }
        for( int i = 1; i <= n; i++ ) {
                if( inDegree[i] != (int)graph[i].size() ) return {};
        }
        if( startingNode == -1 ) return {};
        return EulerCycleDirected( startingNode , totalEdges );
}
void Reset( ) {
        for( int i = 1; i < N; i++ ) graph[i].clear();
        memset( curEdge , 0 , sizeof( curEdge ) );
        memset( inDegree , 0 , sizeof( inDegree ) );
}
int main( int argc , char const *argv[] ) {
        n = 3;
        graph[1].push_back( 2 );
        graph[2].push_back( 3 );
        graph[3].push_back( 1 );
        vector <int> V = EulerCycleDirected( );
        if( V.size() ) cout << "Euler Cycle Exist" <<endl;
        else cout << "Euler Cycle Doesn't Exist"<< endl;
        cout << V.size() << endl;
        for( auto x : V ) cout << x << " ";
        return 0;
}









