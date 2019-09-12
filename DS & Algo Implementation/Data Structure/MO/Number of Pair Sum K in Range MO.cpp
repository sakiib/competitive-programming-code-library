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
int l = 1 , r = 0;
int n , q , k;
map <int,int> cnt;
int a[ N ] , ans[ N ];
int res;
vector <int> V;

struct data {
        int l , r , idx;
        data(){}
        data( int l , int r , int idx ):l(l), r(r), idx(idx){}
        bool operator <( const data &q ) const {
                int block_a = l / block;
                int block_b = q.l / block;
                if( block_a == block_b ) return ( r < q.r );
                return ( block_a < block_b );
        }
} Q[ N ];

void Add( int id ) {
        res += cnt[ k - a[id] ];
        cnt[ a[id] ]++;
}
void Remove( int id ) {
        cnt[ a[id] ]--;
        res -= cnt[ k - a[id] ];
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
int Brute( int l , int r , int k ) {
        int ret = 0;
        for( int i = l; i <= r; i++ ) {
                for( int j = i; j <= r; j++ ) {
                        if( a[i] + a[j] == k ) ret++;
                }
        }
        return ret;
}
int main( int argc , char const *argv[] ) {
        scanf("%d %d %d",&n,&q,&k);
        for( int i = 1; i <= n; i++ ) scanf("%d",&a[i]);
        for( int i = 1; i <= q; i++ ) {
                scanf("%d %d",&Q[i].l,&Q[i].r);
                Q[i].idx = i;
                V.push_back( Brute( Q[i].l , Q[i].r , k ) );
        }
        MO( );
        printf("Bruteforce ans\n");
        for( auto x : V ) printf("%d\n",x);
        printf("MO ans\n");
        for( int i = 1; i <= q; i++ ) printf("%d\n",ans[i]);
        return 0;
}

/// Number of Pairs in ( l - r ) ( l <= i <= j <= r ) such that ,
/// ( a[i] + a[j] = k )

/**
10 5 5
1 2 4 3 1 5 3 10 6 3
1 5
1 10
3 8
2 7
5 9
*/
/// out : 3 5 1 3 0






