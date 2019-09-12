#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

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

map <string,int> ID;
map <int,string> rID;
int id = 0;

int GetID( char a , char b ) {
        string s = "";
        s += a , s += b;
        if( ID[s] == 0 ) ID[s] = ++id;
        rID[ ID[s] ] = s;
        return ID[s];
}
int main( int argc , char const *argv[] ) {
        ios_base :: sync_with_stdio( false ); cin.tie( NULL );
        int k;
        cin >> k;
        for( int i = 1; i <= k; i++ ) {
                string s;
                cin >> s;
                int u = GetID( s[0] , s[1] ) , v = GetID( s[1] , s[2] );
                graph[u].push_back( v );
        }
        n = id;
        vector <int> V = EulerPathDirected( );
        if( !V.size() ) return cout << "NO" << endl,0;
        cout << "YES" << endl;
        bool f = true;
        for( auto x : V ) {
               if( f ) {
                        cout << rID[x];
                        f = false;
               }
               else {
                        string s = rID[x];
                        cout << s[1];
               }
        }
        return 0;
}










