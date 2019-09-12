#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
const int N = 1e5 + 5;

int n , q , a[ N ];
int tree[ 4*N ] , lazy[ 4*N ];

vector <int> prime;
vector <bool> isprime( 10*N , true );

inline void sieve( ) {
        isprime[0] = isprime[1] = false;
        prime.push_back( 2 );
        for( int i = 4; i <= 10*N; i +=2 ) isprime[i] = false;
        int sq = sqrt( 10*N );
        for( int i = 3; i <= sq; i += 2 ) {
                if( isprime[i] ) {
                        for( int j = i*i; j <= 10*N; j += 2*i ) {
                                isprime[j] = false;
                        }
                }
        }
}
inline void build( int node , int b , int e ) {
        if( b > e ) return;
        if( b == e ) {
                tree[node] = isprime[ a[b] ];
                return;
        }
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        build( l , b , m );
        build( r , m + 1 , e );
        tree[node] = tree[l] + tree[r];
}
inline void pushdown( int node , int b , int e ) {
        if( lazy[node] == 0 ) return;
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        tree[l] = isprime[ lazy[node] ] ? ( m - b + 1 ) : 0;
        tree[r] = isprime[ lazy[node] ] ? ( e - m ) : 0;
        lazy[l] = lazy[node];
        lazy[r] = lazy[node];
        lazy[node] = 0;
}
inline void update( int node , int b , int e , int i , int j , int v ) {
        if( i > e || j < b || b > e ) return;
        if( i <= b && j >= e ) {
                tree[node] = isprime[v] ? ( e - b + 1 ) : 0;
                lazy[node] = v;
                return;
        }
        pushdown( node , b , e );
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        update( l , b , m , i , j , v );
        update( r , m + 1 , e , i , j , v );
        tree[node] = tree[l] + tree[r];
}
inline int query( int node , int b , int e , int i , int j ) {
        if( i > e || j < b || b > e ) return 0;
        if( i <= b && j >= e ) return tree[node];
        pushdown( node , b , e );
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        return query( l , b , m , i , j ) + query( r , m + 1 , e , i , j );
}
int main( int argc , char const *argv[] ) {
        int t;
        scanf("%d",&t);
        sieve( );
        for( int tc = 1; tc <= t; tc++ ) {
                scanf("%d %d",&n,&q);
                for( int i = 1; i <= n; i++ ) scanf("%d",&a[i]);
                memset( tree , 0 , sizeof( tree ) );
                memset( lazy , 0 , sizeof( lazy ) );
                build( 1 , 1 , n );
                printf("Case %d:\n",tc);
                while( q-- ) {
                        int op;
                        scanf("%d",&op);
                        if( op == 0 ) {
                               int l , r , v;
                               scanf("%d %d %d",&l,&r,&v);
                               update( 1 , 1 , n , l , r , v );
                        }
                        else {
                                int l , r;
                                scanf("%d %d",&l,&r);
                                printf("%d\n",query( 1 , 1 , n , l , r ) );
                        }
                }
        }
        return 0;
}













