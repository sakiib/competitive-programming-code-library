#include <bits/stdc++.h>
using namespace std;

/**
struct DISJOINT_SET_UNION {
        static const int MAXN = 1e5 + 5;
        vector <int> V[ MAXN ];
        int Par[ MAXN ] , SZ[ MAXN ], idx[ MAXN ];
        inline void makeset( int k ) {
                for( int i = 0; i <= k; i++ ) {
                        Par[ i ] = i , SZ[ i ] = 1 , idx[i] = i , V[i].push_back( i );
                }
        }
        inline int root( int x ) {
                return Par[x] == x ? x : Par[x] = root( Par[x] );
        }
        inline void unite( int x , int y ) {
                int u = root( x ) , v = root( y );
                if( u == v ) return;
                if( SZ[v] <= SZ[u] ) {
                        Par[v] = u , SZ[u] += SZ[v];
                        while( !V[ idx[v] ].empty() ) {
                                V[idx[u]].push_back( V[idx[v]].back() ) , V[idx[v]].pop_back();
                        }
                }
                else if( SZ[v] > SZ[u] ) {
                        Par[u] = v , SZ[v] += SZ[u];
                        while( !V[ idx[u] ].empty() ) {
                                V[idx[v]].push_back( V[idx[u]].back() ) , V[idx[u]].pop_back();
                        }
                }
        }
        inline bool same_set( int x , int y ) {
                return root( x ) == root( y );
        }
} dsu;
*/

/**
struct DISJOINT_SET_UNION {
        static const int MAXN = 1e5 + 5;
        int par[ MAXN ] , sz[ MAXN ] , compo;
        inline void makeset( int k ) {
                compo = k;
                for( int i = 0; i <= k; i++ ) par[i] = i , sz[i] = 1;
        }
        inline int root( int x ) {
                return par[x] == x ? x : par[x] = root( par[x] );
        }
        inline bool same_set( int x , int y ) {
                return root( x ) == root( y );
        }
        inline void unite( int x , int y ) {
                int u = root( x ) , v = root( y );
                if( u == v ) return;
                compo--;
                if( sz[v] <= sz[u] ) par[v] = u , sz[u] += sz[v];
                else if( sz[v] > sz[u] ) par[u] = v , sz[v] += sz[u];
        }
} dsu;
*/

/**
const int N = 1e5 + 5;
int p[ N ];

inline void makeset( int k ) {
        for( int i = 0; i <= k; i++ ) p[i] = i;
}
inline int root( int x ) {
        return p[x] == x ? x : p[x] = root( p[x] );
}
inline void unite( int x , int y ) {
        int u = root( x ) , v = root( y );
        if( u == v ) return;
        if( rand()%2 ) swap( u , v );
        p[u] = v;
}
*/


int main( int argc , char const *argv[] ) {

        return 0;
}



