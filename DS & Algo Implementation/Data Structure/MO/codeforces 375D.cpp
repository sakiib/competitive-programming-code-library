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

const int block = 350;

vector <int> graph[ N ];
int n , q , Time;
int col[ N ] , st[ N ] , en[ N ] , disc[ N ] , ans[ N ];
int l = 1 , r = 0;
int cnt[ N ];

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

void dfs( int s , int p ) {
        st[s] = ++Time;
        disc[ st[s] ] = s;
        for( auto x : graph[s] ) if( x != p ) dfs( x , s );
        en[s] = Time;
}
void Add( int id ) {
        bit.PUpdate( cnt[ col[ disc[id] ] ] , -1 );
        cnt[ col[ disc[id] ] ]++;
        bit.PUpdate( cnt[ col[ disc[id] ] ] , +1 );
}
void Remove( int id ) {
        bit.PUpdate( cnt[ col[ disc[id] ] ] , -1 );
        cnt[ col[ disc[id] ] ]--;
        bit.PUpdate( cnt[ col[ disc[id] ] ] , +1 );
}
void MO( ) {
        sort( Q+1 , Q+q+1 );
        for( int i = 1; i <= q; i++ ) {
                while( l < Q[i].l ) Remove( l++ );
                while( l > Q[i].l ) Add( --l );
                while( r < Q[i].r ) Add( ++r );
                while( r > Q[i].r ) Remove( r-- );
                ans[ Q[i].idx ] = bit.RQuery( Q[i].k , n );
        }
}
int main( int argc , char const *argv[] ) {
        scanf("%d %d",&n,&q);
        for( int i = 1; i <= n; i++ ) scanf("%d",&col[i]);
        for( int i = 1; i <= n-1; i++ ) {
                int u , v;
                scanf("%d %d",&u,&v);
                graph[u].push_back( v ) , graph[v].push_back( u );
        }
        dfs( 1 , 0 );
        for( int i = 1; i <= q; i++ ) {
                int v , k;
                scanf("%d %d",&v,&k);
                Q[i].l = st[v], Q[i].r = en[v], Q[i].k = k, Q[i].idx = i;
        }
        MO( );
        for( int i = 1; i <= q; i++ ) printf("%d\n",ans[i]);
        return 0;
}






