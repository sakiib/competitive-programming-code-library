#include <bits/stdc++.h>
using namespace std;

typedef pair < int , int > ii;
typedef pair < int , ii > iii;
typedef long long int LL;
typedef unsigned long long uLL;
const int inf = (int)1e9;
const LL INF = (LL)2e18;
const int N = 100005;
const int mod = 1000000007;
const double eps = 1e-8;
const double pi = acos( -1.0 );

vector <int> graph[ N ];

int dfs( int s , int p ) {
        int ret = 0;
        for( auto x : graph[s] ) {
                if( x == p ) continue;
                ret = max( ret , dfs( x , s ) + 1 );
        }
        return ret;
}
int main( int argc, char const *argv[] ) {
    ios_base::sync_with_stdio(0); cin.tie(0);

    for( int i = 1; i <= 6; i++ ) {
        int u , v;
        cin >> u >> v;
        graph[u].push_back( v );
        graph[v].push_back( u );
    }
    cout << "Depth of the tree : " << dfs( 1 , 0 ) << endl;
    return 0;
}

/**
depth : 4

1 2
1 3
2 4
2 5
5 6
6 7
*/







