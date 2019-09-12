#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

typedef long long int LL;
typedef pair <int,int> pii;
typedef pair <long long,long long> pll;
const int MOD = 1e9 + 7;
const double EPS = 1e-8;
const int N = 1e5 + 5;
const int inf = 1e9;
const long long INF = 1e18;

/**
Update(L,R,v)	You should add v to all Ai where L ≤ i ≤ R
Query(L,R,v)	You should output the frequency of the number v in
                the range from Lth to Rth index in the array.
*/
const int block_size = 350;

int BLOCK[ 355 ][ 2*N+5 ];
int lazy[ 355 ];

int a[ N ];
int n , q;

void Init( ) {
        memset( BLOCK , 0 , sizeof( BLOCK ) );
        memset( lazy , 0 , sizeof( lazy ) );
}
int Block_ID( int id ) {
        int pos = ( ( id + block_size - 1 ) / block_size );
        return pos;
}
void SetBlock( int id , int v ) {
        int pos = Block_ID( id );
        BLOCK[pos][v]++;
}
pair <int,int> StartEndofBlock( int id ) {
        int st = ( id - 1 ) * block_size + 1;
        int en = min( n , ( st + block_size - 1 ) );
        return {st,en};
}
void update( int l , int r , int add ) {
        int block_a = Block_ID( l ) , block_b = Block_ID( r );
        if( block_a == block_b ) {
                for( int i = l; i <= r; i++ ) {
                        BLOCK[block_a][a[i]]--;
                        a[i] += add;
                        BLOCK[block_a][a[i]]++;
                }
                return;
        }
        for( int i = l; ; i++ ) {
                int pos = Block_ID( i ); if( pos != block_a ) break;
                BLOCK[block_a][a[i]]--;
                a[i] += add;
                BLOCK[block_a][a[i]]++;
        }
        for( int i = block_a + 1; i < block_b; i++ ) lazy[i] += add;
        for( int i = block_size * ( block_b - 1 ) + 1; i <= r; i++ ) {
                BLOCK[block_b][a[i]]--;
                a[i] += add;
                BLOCK[block_b][a[i]]++;
        }
}
int query( int l , int r , int k ) {
        int block_a = Block_ID( l ) , block_b = Block_ID( r );
        if( block_a == block_b ) {
                int ans = 0;
                for( int i = l; i <= r; i++ ) {
                        if( a[i] + lazy[block_a] == k ) ans++;
                }
                return ans;
        }
        int ans = 0;
        for( int i = l; ; i++ ) {
                int pos = Block_ID( i ); if( pos != block_a ) break;
                if( a[i] + lazy[block_a] == k ) ans++;
        }
        for( int i = block_a + 1; i < block_b; i++ ) ans += BLOCK[i][k-lazy[i]];
        for( int i = block_size * ( block_b - 1 ) + 1; i <= r; i++ ) {
                if( a[i] + lazy[block_b] == k ) ans++;
        }
        return ans;
}
int main( int argc , char const *argv[] ) {
        #ifdef forthright48
            freopen( "input.txt" , "r" , stdin );
        #endif // forthright48
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
                scanf("%d %d",&n,&q);
                Init();
                for( int i = 1; i <= n; i++ ) scanf("%d",&a[i]);
                for( int i = 1; i <= n; i++ ) SetBlock( i , a[i] );
                printf("Case %d:\n",tc);
                while( q-- ) {
                        int typ;
                        scanf("%d",&typ);
                        if( typ == 1 ) {
                                int l , r , v;
                                scanf("%d %d %d",&l,&r,&v);
                                update( l , r , v );
                        }
                        else {
                                int l , r , k;
                                scanf("%d %d %d",&l,&r,&k);
                                printf("%d\n",query( l , r , k ) );
                        }
                }
        }
        return 0;
}










