#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

/**
 Max or Min
 Point Update & Range Query
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
        inline void Build( int node , int b , int e ) {
                if( b > e ) return;
                if( b == e ) { Tree[ node ] = a[ b ]; return; }
                int left = node << 1 , right = left | 1 , mid = ( b + e ) >> 1;
                Build( left , b , mid );
                Build( right , mid + 1 , e );
                Tree[ node ] = max( Tree[ left ] , Tree[ right ] );
        }
        inline void Update( int node , int b , int e , int pos , int val ) {
                if( pos > e || pos < b || b > e ) return;
                if( b == e && b == pos ) { Tree[ node ] = val; return; }
                int left = node << 1 , right = left | 1 , mid = ( b + e ) >> 1;
                Update( left , b , mid , pos , val );
                Update( right , mid + 1 , e , pos , val );
                Tree[ node ] = max ( Tree[ left ] , Tree[ right ] );
        }
        inline int QueryMax( int node , int b , int e , int i , int j ) {
                if( i > e || j < b || b > e ) return -inf;
                if( i <= b && j >= e ) return Tree[ node ];
                int left = node << 1 , right = left | 1 , mid = ( b + e ) >> 1;
                int Q1 = QueryMax( left , b , mid , i , j );
                int Q2 = QueryMax( right , mid + 1 , e , i , j );
                return max( Q1 , Q2 );
        }
        inline int QueryMin( int node , int b , int e , int i , int j ) {
                if( i > e || j < b || b > e ) return inf;
                if( i <= b && j >= e ) return Tree[ node ];
                int left = node << 1 , right = left | 1 , mid = ( b + e ) >> 1;
                int Q1 = QueryMin( left , b , mid , i , j );
                int Q2 = QueryMin( right , mid + 1 , e , i , j );
                return min( Q1 , Q2 );
        }
} segtree;

int main( int argc , char const *argv[] ) {


    segtree.Init( );

    return 0;
}




