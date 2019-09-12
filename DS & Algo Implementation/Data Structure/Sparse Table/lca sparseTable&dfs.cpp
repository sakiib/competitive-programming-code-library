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
#define pb                   push_back
#define sz( V )              (int)( V.size() )
#define all( V )             V.begin() , V.end()
#define mem( a , x )         memset( a, x, sizeof( a ) )
#define Fix( x )             setprecision( x ) << fixed
#define FOR( i , a , b )     for( int i = a; i <= b; i++ )
#define ROF( i , a , b )     for( int i = a; i >= b; i-- )
#define Unique( V )          sort(all(V)),V.erase(unique(all(V)),V.end())

const int level = 18;

vector <int> graph[ N ];
int depth[ N ];
int parent[ N ][ level ];
int n;

void dfs( int s , int p ) {
    parent[ s ][ 0 ] = p;
    depth[ s ] = depth[ p ] + 1;
    for( int i = 0; i < graph[ s ].size(); i++ ) {
        int next = graph[ s ][ i ];
        if( next == p ) continue;
        dfs( next , s );
    }
}
void precompute_LCA( ) {
    for( int i = 1; i < level; i++ ) {
        for( int node = 1; node <= n; node++ ) {
            if( parent[ node ][ i-1 ] != -1 ) {
                parent[ node ][ i ] = parent[ parent[node][i-1] ][ i-1 ];
            }
        }
    }
}
int LCA( int u , int v ) {
    if( depth[ v ] < depth[ u ] ) swap( u , v );
    int dif = depth[ v ] - depth[ u ];
    for( int i = 0; i < level; i++ ) {
        if( ( dif >> i )&1 ) v = parent[ v ][ i ];
    }
    if( u == v ) return u;
    for( int i = level-1; i >= 0; i-- ) {
        if( parent[ u ][ i ] != parent[ v ][ i ] ) {
            u = parent[ u ][ i ];
            v = parent[ v ][ i ];
        }
    }
    return parent[ u ][ 0 ];
}
int main( int argc, char const *argv[] ) {

    n = 8;
    for( int i = 1; i <= 7; i++ ) {
        int u , v;
        cin >> u >> v;
        graph[ u ].push_back( v );
        graph[ v ].push_back( u );
    }
    memset( parent , -1 , sizeof(parent) );
    dfs( 1 , 0 );
    precompute_LCA( );
    cout << "LCA of ( 4 , 7 ) : " << LCA( 4 , 7 ) << endl;
    cout << "LCA of ( 4 , 6 ) : " << LCA( 4 , 6 ) << endl;
    return 0;
}

/**

Tree :

1 2
1 3
2 4
2 5
2 6
3 7
3 8

output :

lca ( 4 , 7 ) : 1
lca ( 4 , 6 ) : 2

*/






