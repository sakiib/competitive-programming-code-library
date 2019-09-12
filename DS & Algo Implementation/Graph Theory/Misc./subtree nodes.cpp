#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(V) V.begin(), V.end()
#define Unique(V) sort(all(V)), V.erase(unique(all(V)), V.end())
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long int LL;
const int N = 5e5 + 5;

int n , q;
int a[ N ];
vector <int> graph[ N ];
vector <int> V[ N ];

void dfs( int s , int p ) {
        V[s].push_back( a[s] );
        for( auto x : graph[s] ) {
                if( x == p ) continue;
                dfs( x , s );
                for( auto it : V[x] ) V[s].push_back( it );
        }
}
int main( ) {
        FIO;
        #ifdef OFFLINE
            freopen( "input.txt" , "r" , stdin );
        #endif // OFFLINE
        cin >> n >> q;
        for( int i = 2; i <= n; i++ ) {
                int x;
                cin >> x;
                graph[i].push_back( x );
                graph[x].push_back( i );
        }
        for( int i = 1; i <= n; i++ ) cin >> a[i];
        dfs( 1 , 0 );
        for( int i = 1; i <= n; i++ ) sort( V[i].begin() , V[i].end() );
        while( q-- ) {
                int v , x;
                cin >> v >> x;
                cout << V[v].size( ) -
                    ( lower_bound( all(V[v]), x ) - V[v].begin() ) << endl;
        }
        return 0;
}






