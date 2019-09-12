#include <bits/stdc++.h>
using namespace std;

//////////////////////// Centroid Decomposition on tree /////////////////////////

typedef long long LL;
const int LOG = 25;
const int N = 1e5 + 5;

int nodes , root;
bool cMarked[ N ];
int childCount[ N ] , cParent[ N ];
int subTree[ N ] , Level[ N ] , Parent[ N ][ LOG+5 ];
int dist[ N ];
vector <int> Tree[ N ];
vector <int> cTree[ N ];

inline void Initialize( int n ) {
            nodes = n;
            root = 0;
            memset( childCount , 0 , sizeof(childCount) );
            memset( cMarked , false , sizeof(cMarked) );
            memset( cParent , -1 , sizeof(cParent) );
            for( int i = 0; i < N; i++ ) Tree[i].clear() , cTree[i].clear();
}
inline void AddEdge( int u , int v ) {
            Tree[ u ].push_back( v );
            Tree[ v ].push_back( u );
}
inline int DFS( int u , int par ) {
            childCount[ u ] = 1;
            for( int i = 0; i < Tree[ u ].size(); i++ ) {
                    int v = Tree[ u ][ i ];
                    if( v == par || cMarked[ v ] ) continue;
                    childCount[ u ] += DFS( v , u );
            }
            return childCount[ u ];
}
inline int FindCentroid( int u , int par , int TotalNodes ) {
            bool IsCentroid = true;
            int HeavyChild = 0;
            int HeavyCount = 0;
            for( int i = 0; i < Tree[ u ].size(); i++ ) {
                    int v = Tree[ u ][ i ];
                    if( v == par || cMarked[ v ] ) continue;
                    if( childCount[ v ] > ( TotalNodes / 2 ) ) IsCentroid = false;
                    if( childCount[ v ] > HeavyCount ) {
                            HeavyCount = childCount[ v ];
                            HeavyChild = v;
                    }
            }
            if( IsCentroid && (TotalNodes - childCount[ u ]) <= ( TotalNodes/2 ) ) return u;
            FindCentroid( HeavyChild , u , TotalNodes );
}
inline int GetCentroid( int u ) {
            int Total = DFS( u , u );
            int Centroid = FindCentroid( u , u , Total );
            cMarked[ Centroid ] = true;
            return Centroid;
}
inline int DecomposeTree( int u ) {
            int curCentroid = GetCentroid( u );
            for( int i = 0; i < Tree[ curCentroid ].size(); i++ ) {
                    int v = Tree[ curCentroid ][ i ];
                    if( cMarked[ v ] ) continue;
                    int subCentroid = DecomposeTree( v );
                    cTree[ curCentroid ].push_back( subCentroid );
                    cTree[ subCentroid ].push_back( curCentroid );
                    cParent[ subCentroid ] = curCentroid;
            }
            return curCentroid;
}
inline void dfs( int s , int par , int lvl ) {
            Parent[ s ][ 0 ] = par;
            Level[ s ] = lvl;
            subTree[ s ] = 1;
            for( int i = 0; i < Tree[ s ].size(); i++ ) {
                    int v = Tree[ s ][ i ];
                    if( v != par ) {
                            dist[v] = dist[s] + 1;
                            dfs( v , s , lvl + 1 );
                            subTree[ s ] += subTree[ v ];
                    }
            }
}
inline void CalcLCA( ) {
            for( int i = 1; i <= LOG; i++ ) {
                    for( int j = 1; j <= nodes; j++ ) {
                            if( Parent[ j ][ i-1 ] != -1 ) {
                                    Parent[ j ][ i ] = Parent[ Parent[ j ][ i-1 ] ][ i-1 ];
                            }
                    }
            }
}
inline int LCA( int u , int v ) {
            if( Level[ u ] < Level[ v ] ) swap( u , v );
            int diff = Level[ u ] - Level[ v ];
            for( int i = LOG; i >= 0; i-- ) {
                    if( ( diff >> i )&1 ) u = Parent[ u ][ i ];
            }
            if( u == v ) return u;
            for( int i = LOG; i >= 0; i-- ) {
                    if( Parent[ u ][ i ] != Parent[ v ][ i ] && Parent[ u ][ i ] != -1 ) {
                            u = Parent[ u ][ i ];
                            v = Parent[ v ][ i ];
                    }
            }
            return Parent[ u ][ 0 ];
}
int Dist( int u , int v ) {
        int lca = LCA( u , v );
        return dist[u] + dist[v] - 2 * dist[lca];
}
inline void Preprocess( ) {
            memset( Parent , -1 , sizeof(Parent) );
            dfs( 1 , -1 , 0 );
            CalcLCA( );
}
inline void CentroidDecomposition( ) {
            Preprocess( );
            root = DecomposeTree( 1 );
            cParent[ root ] = -1;
}
/////////////////////////////////////////////////////////////////////////////////////

int n , dep[ N ];

void calc( int s , int p , int d ) {
        assert( dep[s] < 26 );
        dep[s] = d;
        for( auto x : cTree[s] ) {
                if( x != p ) {
                        calc( x , s , d + 1 );
                }
        }
}
void solve( ) {
        calc( root , 0 , 0 );
        for( int i = 1; i <= n; i++ ) cout << (char)( dep[i]+'A' ) << " ";
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( nullptr );
        cin >> n;
        Initialize( n );
        for( int i = 1; i <= n - 1; i++ ) {
                int u , v;
                cin >> u >> v;
                AddEdge( u , v );
        }
        CentroidDecomposition( );
        solve( );
        return 0;
}












