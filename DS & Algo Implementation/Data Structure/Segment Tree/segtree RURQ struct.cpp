#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;

/**
 Sum Query
 Range add value Update & Range sum Query
 */

struct SEGMENT_TREE {
        typedef long long LL;
        static const int inf = 2e9 + 5;
        static const int MAXN = 1e5 + 5;

        int a[ MAXN ] , Tree[ 4*MAXN ] , Lazy[ 4*MAXN ];

        inline void Init( ) {
                memset( Tree , 0 , sizeof( Tree ) );
                memset( Lazy , 0 , sizeof( Lazy ) );
        }
        inline void LazyPropagate( int node , int b , int e ) {
                if( Lazy[ node ] != 0 ) {
                Tree[node] += ( Lazy[ node ] * ( e - b + 1 ) );
                        if( b != e ) {
                                Lazy[ 2 * node ] += Lazy[ node ];
                                Lazy[ 2 * node + 1 ] += Lazy[ node ];
                        }
                        Lazy[ node ] = 0;
                }
        }
        inline void Build( int node , int b , int e ) {
                if( b > e ) return;
                if( b == e ) { Tree[ node ] = a[ b ]; return; }
                int left = node << 1 , right = left | 1 , mid = ( b + e ) >> 1;
                Build( left , b , mid );
                Build( right , mid + 1 , e );
                Tree[ node ] = Tree[ left ] + Tree[ right ];
        }
        inline void Update( int node , int b , int e , int i , int j , int val ) {
                LazyPropagate( node , b , e );
                if( i > e || j < b || b > e ) return;
                if( i <= b && j >= e ) {
                        Tree[ node ] += ( val * ( e - b + 1 ) );
                        if( b != e ) {
                                Lazy[ 2 * node ] += val;
                                Lazy[ 2 * node + 1 ] += val;
                        }
                        return;
                }
                int left = node << 1 , right = left | 1 , mid = ( b + e ) >> 1;
                Update( left , b , mid , i , j , val );
                Update( right , mid + 1 , e , i , j , val );
                Tree[ node ] = Tree[ left ] + Tree[ right ];
        }
        inline int Query( int node , int b , int e , int i , int j ) {
                LazyPropagate( node , b , e );
                if( i > e || j < b || b > e ) return 0;
                if( i <= b && j >= e ) return Tree[ node ];
                int left = node << 1 , right = left | 1 , mid = ( b + e ) >> 1;
                int Q1 = Query( left , b , mid , i , j );
                int Q2 = Query( right , mid + 1 , e , i , j );
                return ( Q1 + Q2 );
        }

} segtree;

int main( int argc , char const *argv[] ) {

    segtree.Init( );
    segtree.Build( 1 , 1 , 10 );

    return 0;
}



