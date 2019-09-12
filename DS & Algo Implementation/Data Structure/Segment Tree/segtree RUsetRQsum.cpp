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
 sum Query
 Range update set value & Range query sum
 */


const int sz = N;

struct SegmentTree {
    int Tree[ 4*sz ] , Lazy[ 4*sz ];
    int ara[ sz ];

    inline void Init( ) {
        memset( Tree , 0 , sizeof( Tree ) );
        memset( Lazy , -1 , sizeof( Lazy ) );
    }
    inline void LazyPropagate( int node , int b , int e ) {
        if( Lazy[ node ] != -1 ) {
            Tree[node] += ( Lazy[ node ]*( e-b+1 ) );
            if( b != e ) {
                Lazy[ 2*node ] = Lazy[ node ];
                Lazy[ 2*node+1 ] = Lazy[ node ];
            }
            Lazy[ node ] = -1;
        }
    }
    inline void Build( int node , int b , int e ) {
        if( b > e ) return;
        if( b == e ) { Tree[ node ] = ara[ b ]; return; }
        int left = node << 1 , right = left | 1 , mid = ( b+e ) >> 1;
        Build( left , b , mid );
        Build( right , mid+1 , e );
        Tree[ node ] = Tree[ left ] + Tree[ right ];
    }
    inline void Update( int node , int b , int e , int i , int j , int val ) {
        LazyPropagate( node , b , e );
        if( i > e || j < b || b > e ) return;
        if( i <= b && j >= e ) {
            Tree[ node ] = ( val * ( e-b+1 ) );
            if( b != e ) {
                Lazy[ 2*node ] = val;
                Lazy[ 2*node+1 ] = val;
            } return;
        }
        int left = node << 1 , right = left | 1 , mid = ( b+e ) >> 1;
        Update( left , b , mid , i , j , val );
        Update( right , mid+1 , e , i , j , val );
        Tree[ node ] = Tree[ left ] + Tree[ right ];
    }
    inline int Query( int node , int b , int e , int i , int j ) {
        LazyPropagate( node , b , e );
        if( i > e || j < b || b > e ) return 0;
        if( i <= b && j >= e ) return Tree[ node ];
        int left = node << 1 , right = left | 1 , mid = ( b+e ) >> 1;
        int Q1 = Query( left , b , mid , i , j );
        int Q2 = Query( right , mid+1 , e , i , j );
        return ( Q1 + Q2 );
    }

} segtree;

int main( int argc , char const *argv[] ) {

    return 0;
}


