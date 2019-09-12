#include <bits/stdc++.h>
using namespace std;

/**
Undirected & 1 based index
*/
const int N = 1e5 + 5;
int color[ N ];
vector <int> graph[ N ];

bool biColorable( int s , int c ) {
        color[s] = c;
        bool ret = true;
        for( auto x : graph[s] ) {
                if( color[x] == c ) return false;
                if( color[x] == -1 ) ret &= biColorable( x ,  c^1 );
        }
        return ret;
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( NULL );
        int n;
        while( cin >> n ) {
                if( n == 0 ) break;
                int k;
                cin >> k;
                for( int i = 1; i < N; i++ ) color[i] = -1 , graph[i].clear();
                for( int i = 1; i <= k; i++ ) {
                        int u , v;
                        cin >> u >> v;
                        ++u , ++v;
                        graph[u].push_back( v );
                        graph[v].push_back( u );
                }
                if( biColorable( 1 , 1 ) ) cout << "BICOLORABLE." << endl;
                else cout << "NOT BICOLORABLE." << endl;
        }
        return 0;
}










