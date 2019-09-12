#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long uLL;
typedef long long int LL;
typedef pair <int,int> pii;
typedef pair <long long,long long> pll;
const int N = 1e5 + 5;
const int inf = 1e9;
const long long INF = 1e18;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int MOD = 1000000007;

int n = 26;
vector <int> graph[ 30 ];
int inDegree[ N ] , curEdge[ N ];
vector <string> val[ 30 ][ 30 ];

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
int GetID( char ch ) {
        return ch - 'a' + 1;
}
void Reset( ) {
        for( int i = 1; i < 30; i++ ) graph[i].clear();
        memset( curEdge , 0 , sizeof( curEdge ) );
        memset( inDegree , 0 , sizeof( inDegree ) );
        for( int i = 1; i < 30; i++ ) {
                for( int j = 1; j < 30; j++ ) {
                        val[i][j].clear();
                }
        }
}
int main( int argc , char const *argv[] ) {
        int t;
        cin >> t;
        for( int tc = 1; tc <= t; tc++ ) {
                Reset( );
                int k;
                cin >> k;
                for( int i = 1; i <= k; i++ ) {
                        string s;
                        cin >> s;
                        int u = GetID( s[0] ) , v = GetID( s[s.size()-1] );
                        graph[u].push_back( v );
                        val[u][v].push_back( s );
                }
                vector <int> V = EulerPathDirected( );
                if( !V.size() ) {
                        cout << "Case "<< tc << ": "<< "No" << endl;
                        continue;
                }
                cout << "Case "<< tc << ": " << "Yes" << endl;
                for( int i = 0; i < V.size() - 1; i++ ) {
                        int u = V[i] , v = V[i+1] , pos = val[u][v].size() - 1;
                        if( i == 0 ) cout << val[u][v][pos];
                        else cout << " " << val[u][v][pos];
                        val[u][v].pop_back( );
                }
                cout <<endl;
        }
        return 0;
}
