#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#define endl "\n"
#define all(V) V.begin( ), V.end( )
#define Unique(V) sort( all( V ) ), V.erase( unique( all( V ) ), V.end() )
#define Check( N , p ) ( !( ( N & ( 1LL << p ) ) == 0 ) )
#define ON( N , p ) ( N = N | ( 1LL << p ) )
#define OFF( N , p ) ( N = N & ~( 1LL << p ) )
std::mt19937 rng( chrono::steady_clock::now().time_since_epoch().count() );
#define rnd(a, b) ((((rand() << 15) ^ rand()) % ((b) - (a) + 1)) + (a))
#define ran(a, b) rng() % ( (b) - (a) + 1 ) + (a)
#define trace(...) __f( #__VA_ARGS__ , __VA_ARGS__ )
template < typename Arg1 >
void __f( const char* name , Arg1&& arg1 ) { cerr << name << " : " << arg1 << "\n"; }
template < typename Arg1 , typename... Args >
void __f( const char* names , Arg1&& arg1 , Args&&... args ) {
const char* comma = strchr( names + 1 , ',' );
cerr.write( names , comma - names ) << " : " << arg1 << " , " ; __f( comma + 1 , args... ); }
typedef long long int LL;
typedef pair <int,int> pii;
typedef pair <long long,long long> pll;
const int MOD = 1e9 + 7;
const double EPS = 1e-8;
const int inf = 1e9;
const long long INF = 1e18;


//////////////////////// Centroid Decomposition /////////////////////////

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
vector <int> centroids;

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
            centroids.push_back( curCentroid );
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
inline int Dist( int u , int v ) {
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

int n , k;
bool mark[ N ] , vis[ N ];
int d[ N ];
LL ans;

void dfs_add( int u , int dep , int val ) {
        d[dep] += val;
        vis[u] = true;
        for( auto v : Tree[u] ) {
                if( !vis[v] && !mark[v] ) {
                        dfs_add( v , dep + 1 ,  val );
                }
        }
        vis[u] = false;
}
void dfs_inc( int u , int dep , int limit ) {
        vis[u] = true;
        if( dep <= k ) ans += d[ k - dep ];
        for( auto v : Tree[u] ) {
                if( !vis[v] && !mark[v] ) {
                        dfs_inc( v , dep + 1 , limit );
                }
        }
        vis[u] = false;
}
void solve( ) {
        for( auto u : centroids ) {
                mark[u] = true;
                dfs_add( u , 0 , +1 );
                ans += d[k];
                int limit = n;
                for( auto v : Tree[u] ) {
                        if( mark[v] ) continue;
                        dfs_add( v , 1 , -1 );
                        dfs_inc( v , 1 , limit );
                        dfs_add( v , 1 , +1 );
                }
                dfs_add( u , 0 , -1 );
        }
        cout << ans/2 << endl;
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( nullptr );
        cin >> n >> k;
        Initialize( n );
        for( int i = 1; i <= n - 1; i++ ) {
                int u , v;
                cin >> u >> v;
                AddEdge( u , v );
        }
        CentroidDecomposition();
        solve( );
        return 0;
}












