#include <bits/stdc++.h>
using namespace std;

struct CENTROID_DECOMPOSITION {
        typedef long long LL;
        static const int LOG = 25;
        static const int INF = 2e9 + 5;
        static const int MAXN = 1e5 + 5;

        int nodes , Root;
        bool CentroidMarked[ MAXN ];
        int ChildCount[ MAXN ] , CentroidParent[ MAXN ];
        int SubTree[ MAXN ] , Level[ MAXN ] , Par[ MAXN ][ LOG+5 ];
        vector <int> Tree[ MAXN ];
        vector <int> CentroidTree[ MAXN ];
        //Map stores distance from a centroid to centroid subtree nodes in original Tree.
        map <int,int> M[ MAXN ];

        void Initialize( int n ) {
                nodes = n;
                Root = 0;
                memset( ChildCount , 0 , sizeof(ChildCount) );
                memset( CentroidParent , -1 , sizeof(CentroidParent) );
                memset( CentroidMarked , false , sizeof(CentroidMarked) );
                for( int i = 0; i < MAXN; i++ ) {
                        Tree[i].clear(); CentroidTree[i].clear(); M[i].clear();
                }
        }
        // Making the Tree.
        void AddEdge( int u , int v ) {
                Tree[ u ].push_back( v ); Tree[ v ].push_back( u );
        }
        // Calculate Distance from all Centroids.
        void CalculateDistance( int u , int par , int dis , int src ) {
                M[ src ][ u ] = dis;
                for(int i = 0; i < Tree[ u ].size(); i++ ){
                        int v = Tree[ u ][ i ];
                        if( v == par || CentroidMarked[ v ] ) continue;
                        CalculateDistance( v , u , dis + 1 , src );
                }
        }
        // Calculate Subtree Size of a Node.
        int DFS( int u , int par ) {
                ChildCount[ u ] = 1;
                for( int i = 0; i < Tree[ u ].size(); i++ ) {
                        int v = Tree[ u ][ i ];
                        if( v == par || CentroidMarked[ v ] ) continue;
                        ChildCount[ u ] += DFS( v , u );
                }
                return ChildCount[ u ];
        }
        // Gets a Tree or SubTree & Finds it's Centroid.
        int FindCentroid( int u , int par , int TotalNodes ) {
                bool IsCentroid = true;
                int HeavyChild = 0;
                int HeavyCount = 0;
                for( int i = 0; i < Tree[ u ].size(); i++ ) {
                        int v = Tree[ u ][ i ];
                        if( v == par || CentroidMarked[ v ] ) continue;
                        if( ChildCount[ v ] > ( TotalNodes / 2 ) ) IsCentroid = false;
                        if( ChildCount[ v ] > HeavyCount ) {
                                HeavyCount = ChildCount[ v ];
                                HeavyChild = v;
                        }
                }
                if( IsCentroid && (TotalNodes - ChildCount[ u ]) <= (TotalNodes/2) ) return u;
                FindCentroid( HeavyChild , u , TotalNodes );
        }
        // Calculate Single centroid of u & mark it.
        int GetCentroid( int u ) {
                int Total = DFS( u , u );
                int Centroid = FindCentroid( u , u , Total );
                CalculateDistance( Centroid , Centroid , 0 , Centroid );
                CentroidMarked[ Centroid ] = true;
                return Centroid;
        }
        // Form CentroidTree from centroids.
        int DecomposeTree( int u ) {
                int CurCentroid = GetCentroid( u );
                for( int i = 0; i < Tree[ CurCentroid ].size(); i++ ) {
                        int v = Tree[ CurCentroid ][ i ];
                        if( CentroidMarked[ v ] ) continue;
                        int SubCentroid = DecomposeTree( v );
                        CentroidTree[ CurCentroid ].push_back( SubCentroid );
                        CentroidTree[ SubCentroid ].push_back( CurCentroid );
                        CentroidParent[ SubCentroid ] = CurCentroid;
                }
                return CurCentroid;
        }
        void dfs( int s , int par , int lvl ) {
                Par[ s ][ 0 ] = par;
                Level[ s ] = lvl;
                SubTree[ s ] = 1;
                for( int i = 0; i < Tree[ s ].size(); i++ ) {
                        int v = Tree[ s ][ i ];
                        if( v != par ) {
                                dfs( v , s , lvl + 1 );
                                SubTree[ s ] += SubTree[ v ];
                        }
                }
        }
        void CalcLCA( ) {
                for( int i = 1; i <= LOG; i++ ) {
                        for( int j = 1; j <= nodes; j++ ) {
                                if( Par[ j ][ i-1 ] != -1 ) {
                                        Par[ j ][ i ] = Par[ Par[ j ][ i-1 ] ][ i-1 ];
                                }
                        }
                }
        }
        int LCA( int u , int v ) {
                if( Level[ u ] < Level[ v ] ) swap( u , v );
                int diff = Level[ u ] - Level[ v ];
                for( int i = LOG; i >= 0; i-- ) {
                        if( ( diff >> i )&1 ) u = Par[ u ][ i ];
                }
                if( u == v ) return u;
                for( int i = LOG; i >= 0; i-- ) {
                        if( Par[ u ][ i ] != Par[ v ][ i ] && Par[ u ][ i ] != -1 ) {
                                u = Par[ u ][ i ];
                                v = Par[ v ][ i ];
                        }
                }
                return Par[ u ][ 0 ];
        }
        void Preprocess( ) {
                memset( Par , -1 , sizeof(Par) );
                dfs( 1 , -1 , 0 );
                CalcLCA( );
        }
        void CentroidDecomposition( ) {
                Preprocess( ); // Calculate Level of Tree Nodes & prepare LCA query.
                Root = DecomposeTree( 1 );
                CentroidParent[ Root ] = -1;
        }

} centroid;

int main( int argc , char const *argv[] ) {

        return 0;
}






