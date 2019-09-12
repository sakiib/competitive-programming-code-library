#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
typedef pair< int,int > ii;
typedef pair< int,ii > iii;
const int inf = 1e9;
const LL INF = 1e18;
const int N = 100005;
const int MOD = 1e9+7;

const int block = 320;
int n , q;
int ara[ N ];
int l = 1 , r = 0;
int cnt[ N ] , ans[ N ];

struct data {
        int l , r , idx , k;
        bool operator < ( const data &q ) const {
                int block_a = l / block;
                int block_b = q.l / block;
                if( block_a == block_b ) return ( r < q.r );
                return ( block_a < block_b );
    }
} Q[ N ];

void Add( int idx ) {
        cnt[ ara[idx] ]++;
}
void Remove( int idx ) {
        cnt[ ara[idx] ]--;
}
void MO( ) {
        sort( Q+1 , Q+q+1 );
        for( int i = 1; i <= q; i++ ) {
                while( l < Q[i].l ) Remove( l++ );
                while( l > Q[i].l ) Add( --l );
                while( r < Q[i].r ) Add( ++r );
                while( r > Q[i].r ) Remove( r-- );
                int sum = 0;
                for( int j = 1; j <= 50; j++ ) {
                        if( cnt[j] >= Q[i].k ) sum++;
                }
                ans[ Q[i].idx ] = sum;
        }
}
int main( int argc, char const *argv[] ) {
        scanf("%d",&n);
        for( int i = 1; i <= n; i++ ) scanf("%d",&ara[i]);
        scanf("%d",&q);
        for( int i = 1; i <= q; i++ ) {
                scanf("%d%d%d",&Q[i].l,&Q[i].r,&Q[i].k);
                Q[i].idx = i;
        }
        MO();
        for( int i = 1; i <= q; i++ ) printf("%d\n",ans[i]);
        return 0;
}
