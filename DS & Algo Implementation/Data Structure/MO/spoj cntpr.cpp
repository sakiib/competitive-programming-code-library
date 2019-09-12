#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
typedef pair < int , int > ii;
const int inf = 1e9;
const LL INF = 1e18;
const int N = 1e5 + 5;
const int mod = 1000000007;
const double eps = 1e-8;
const double pi = acos( -1.0 );

/**
You are given sequence A of N integers. You are also given integer K and M queries.
Each query consists of two integers l, r.
For each query output number of pairs i, j such that l <= i < j <= r
and abs(A[i] - A[j]) >= K.
*/
const int MX = 100000;
const int block = 350;
int l = 1 , r = 0;
int ans[ N ] , a[ N ];
int n , q , k , res;

struct data {
        int l , r , k , idx;
        data(){}
        data( int l , int r , int k , int idx ):l(l), r(r), k(k), idx(idx){}
        bool operator <( const data &q ) const {
                int block_a = l / block;
                int block_b = q.l / block;
                if( block_a == block_b ) return ( r < q.r );
                return ( block_a < block_b );
        }
} Q[ N ];
struct BinaryIndexedTree {

    int BIT[ N+10 ];

    inline void Init( ) { memset( BIT , 0 , sizeof( BIT ) ); }

    inline int RQuery ( int l , int r ) {
        return PQuery( r ) - PQuery( l-1 );
    }
    inline void PUpdate ( int idx , int val ) {
        if( idx <= 0 ) return;
        for( ; idx <= N; idx += ( idx & -idx ) ) BIT[ idx ] += val;
    }
    inline int PQuery ( int idx ) {
        int ret = 0;
        for( ; idx > 0; idx -= ( idx & -idx ) ) ret += BIT[ idx ];
        return ret;
    }
    inline void RUpdate ( int idx , int idy , int val ) {
        for( ; idx <= N; idx += ( idx & -idx ) ) BIT[ idx ] += val;
        idy++ , val *= -1;
        for( ; idy <= N; idy += ( idy & -idy ) ) BIT[ idy ] += val;
    }
} bit;

void Add( int id ) {
        int val = a[id];
        bit.PUpdate( val , +1 );
        int x = 0 , y = 0;
        if( val - k >= 1 ) x = bit.RQuery( 1 , val - k );
        int tot = bit.RQuery( 1 , MX );
        if( val + k -1 <= MX ) y = tot - bit.RQuery( 1 , val + k - 1 );
        res += ( x + y );
}
void Remove( int id ) {
        int val = a[id];
        bit.PUpdate( val , -1 );
        int x = 0 , y = 0;
        if( val - k >= 1 ) x = bit.RQuery( 1 , val - k );
        int tot = bit.RQuery( 1 , MX );
        if( val + k -1 <= MX ) y = tot - bit.RQuery( 1 , val + k - 1 );
        res -= ( x + y );
}
void MO( ) {
        sort( Q+1 , Q+q+1 );
        for( int i = 1; i <= q; i++ ) {
                while( l < Q[i].l ) Remove( l++ );
                while( l > Q[i].l ) Add( --l );
                while( r < Q[i].r ) Add( ++r );
                while( r > Q[i].r ) Remove( r-- );
                ans[ Q[i].idx ] = res;
        }
}
int main( int argc , char const *argv[] ) {
        scanf("%d %d %d",&n,&q,&k);
        for( int i = 1; i <= n; i++ ) scanf("%d",&a[i]);
        for( int i = 1; i <= q; i++ ) {
                scanf("%d %d",&Q[i].l,&Q[i].r);
                Q[i].idx = i;
        }
        MO( );
        for( int i = 1; i <= q; i++ ) printf("%d\n",ans[i]);
        return 0;
}






