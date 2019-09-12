#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long uLL;
typedef long long int LL;
typedef pair <int,int> pii;
typedef pair <int,pii> piii;
typedef pair <long long,long long> pll;
typedef pair <long long,pll> plll;
const int N = 1e5 + 5;
const int inf = 1e9;
const long long INF = 1e18;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int MOD = 1000000007;

int n , q;
LL tree[ 4*N ] , lazy[ 4*N ];

void pushdown( int node , int b , int e ) {
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        if( lazy[node] == -1 ) return;
        tree[l] = lazy[node] * ( m - b + 1 );
        tree[r] = lazy[node] * ( e - m );
        lazy[l] = lazy[node];
        lazy[r] = lazy[node];
        lazy[node] = -1;
}
void update( int node , int b , int e , int i , int j , int val ) {
        if( i > e || j < b || b > e ) return;
        if( i <= b && j >= e ) {
                tree[node] = val * ( e - b + 1 );
                lazy[node] = val;
                return;
        }
        pushdown( node , b , e );
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        update( l , b , m , i , j , val );
        update( r , m + 1 , e , i , j , val );
        tree[node] = tree[l] + tree[r];
}
LL query( int node , int b , int e , int i , int j ) {
        if( i > e || j < b || b > e ) return 0;
        if( i <= b && j >= e ) return tree[node];
        pushdown( node , b , e );
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        return query( l , b , m , i , j ) + query( r , m + 1 , e , i , j );
}
LL gcd( LL a , LL b ) {
        if( !b ) return a;
        return gcd( b , a%b );
}
int main( int argc , char const *argv[] ) {
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
                memset( tree , 0 , sizeof( tree ) );
                memset( lazy , -1 , sizeof( lazy ) );
                scanf("%d %d",&n,&q);
                printf("Case %d:\n",tc);
                for( int i = 1; i <= q; i++ ) {
                        int type;
                        scanf("%d",&type);
                        if( type == 1 ) {
                                int l , r , val;
                                scanf("%d %d %d",&l,&r,&val);
                                update( 1 , 1 , n , ++l , ++r , val );
                        }
                        else {
                                int l , r;
                                scanf("%d %d",&l,&r);
                                LL tot = query( 1 , 1 , n , ++l , ++r );
                                LL len = ( r - l + 1 );
                                LL g = gcd( tot , len );
                                tot /= g , len /= g;
                                if( len == 1 ) printf("%lld\n",tot);
                                else printf("%lld/%lld\n",tot,len);
                        }
                }
        }
        return 0;
}












