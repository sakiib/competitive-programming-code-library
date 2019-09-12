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

const int sz = 2*N;

struct SegmentTree {
    int MX[ 4*sz ] , MN[ 4*sz ];
    int ara[ sz ];

    inline void Init( ) {
        memset( MX , 0 , sizeof( MX ) );
        memset( MN , 0 , sizeof( MN ) );
    }
    inline void Build( int node , int b , int e ) {
        if( b > e ) return;
        if( b == e ) { MX[ node ] = MN[ node ] = b; return; }
        int left = node << 1 , right = left | 1 , mid = ( b+e ) >> 1;
        Build( left , b , mid );
        Build( right , mid+1 , e );
        if( ara[ MX[left] ] > ara[ MX[right] ] ) MX[node] = MX[left];
        else MX[node] = MX[right];
        if( ara[ MN[left] ] < ara[ MN[right] ] ) MN[node] = MN[left];
        else MN[node] = MN[right];
    }
    inline void Update( int node , int b , int e , int pos , int val ) {
        if( pos > e || pos < b || b > e ) return;
        if( b == e && b == pos ) { MX[ node ] = MN[ node ] = val; return; }
        int left = node << 1 , right = left | 1 , mid = ( b+e ) >> 1;
        Update( left , b , mid , pos , val );
        Update( right , mid+1 , e , pos , val );
        if( ara[ MX[left] ] > ara[ MX[right] ] ) MX[node] = MX[left];
        else MX[node] = MX[right];
        if( ara[ MN[left] ] < ara[ MN[right] ] ) MN[node] = MN[left];
        else MN[node] = MN[right];
    }
    inline int QueryMax( int node , int b , int e , int i , int j ) {
        if( i > e || j < b || b > e ) return -inf;
        if( i <= b && j >= e ) return MX[ node ];
        int left = node << 1 , right = left | 1 , mid = ( b+e ) >> 1;
        int Q1 = QueryMax( left , b , mid , i , j );
        int Q2 = QueryMax( right , mid+1 , e , i , j );
        if( Q1 == -inf ) return Q2;
        if( Q2 == -inf ) return Q1;
        if( ara[Q1] > ara[Q2] ) return Q1;
        return Q2;
    }
    inline int QueryMin( int node , int b , int e , int i , int j ) {
        if( i > e || j < b || b > e ) return inf;
        if( i <= b && j >= e ) return MN[ node ];
        int left = node << 1 , right = left | 1 , mid = ( b+e ) >> 1;
        int Q1 = QueryMin( left , b , mid , i , j );
        int Q2 = QueryMin( right , mid+1 , e , i , j );
        if( Q1 == inf ) return Q2;
        if( Q2 == inf ) return Q1;
        if( ara[Q1] < ara[Q2] ) return Q1;
        return Q2;
    }

} segtree;

int main( int argc , char const *argv[] ) {

    segtree.Init( );

    int n , q;
    scanf("%d %d",&n,&q);
    for( int i = 1; i <= n; i++ ) scanf("%d",&segtree.ara[i]);

    segtree.Build( 1 , 1 , n );

    while( q-- ) {
        int l , r , val;
        scanf("%d %d %d",&l,&r,&val);
        int mx = segtree.QueryMax( 1 , 1 , n , l , r );
        int mn = segtree.QueryMin( 1 , 1 , n , l , r );

        //cout << segtree.ara[mx] << " " << segtree.ara[mn] << endl;
        if( segtree.ara[mx] != val ) printf("%d\n",mx);
        else if( segtree.ara[mn] != val ) printf("%d\n",mn);
        else printf("-1\n");
    }
    return 0;
}





