#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
const int inf = (int)1e9;
const LL INF = (LL)1e18;
const int N = 100005;
const LL MOD = 1000000007;
const double EPS = 1e-7;
const double PI = acos( -1.0 );

/**
 Sum Query
 Point Update & Range Query
 */

const int sz = N;

struct SegmentTree {

    int Tree[ 4*sz ];
    int ara[ sz ];

    inline void Init( ) {
        memset( Tree , 0 , sizeof( Tree ) );
    }
    inline void Build( int node , int b , int e ) {
        if( b > e ) return;
        if( b == e ) { Tree[ node ] = ara[ b ]; return; }
        int left = node << 1 , right = left | 1 , mid = ( b+e ) >> 1;
        Build( left , b , mid );
        Build( right , mid+1 , e );
        Tree[ node ] = Tree[ left ] + Tree[ right ];
    }
    inline void Update( int node , int b , int e , int pos , int val ) {
        if( pos > e || pos < b || b > e ) return;
        if( b == e && b == pos ) { Tree[ node ] = val; return; }
        int left = node << 1 , right = left | 1 , mid = ( b+e ) >> 1;
        Update( left , b , mid , pos , val );
        Update( right , mid+1 , e , pos , val );
        Tree[ node ] = Tree[ left ] + Tree[ right ];
    }
    inline int Query( int node , int b , int e , int i , int j ) {
        if( i > e || j < b || b > e ) return 0;
        if( i <= b && j >= e ) return Tree[ node ];
        int left = node << 1 , right = left | 1 , mid = ( b+e ) >> 1;
        int Q1 = Query( left , b , mid , i , j );
        int Q2 = Query( right , mid+1 , e , i , j );
        return ( Q1 + Q2 );
    }
} segtree;

int main( int argc , char const *argv[] ) {


    segtree.Init( );

    return 0;
}



