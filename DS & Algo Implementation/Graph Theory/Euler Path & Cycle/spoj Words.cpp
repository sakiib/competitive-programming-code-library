#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template <typename T> using
Treap = tree <T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
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
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( NULL );
        int t;
        cin >> t;
        while( t-- ) {
                Reset( );
                int k;
                cin >> k;
                for( int i = 1; i <= k; i++ ) {
                        string s;
                        cin >> s;
                        int u = GetID( s[0] ) , v = GetID( s[s.size()-1] );
                        graph[u].push_back( v );
                }
                vector <int> V = EulerPathDirected( );
                if( !V.size() ) cout << "The door cannot be opened." << endl;
                else cout << "Ordering is possible." << endl;
        }
        return 0;
}




