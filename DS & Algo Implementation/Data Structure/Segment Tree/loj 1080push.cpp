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

char s[ N ] , c[ 5 ];
int len, q;
int tree[ 4*N ] , lazy[ 4*N ];

void pushdown( int node , int b , int e ) {
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        if( lazy[node] == 0 ) return;
        tree[l] += lazy[node];
        tree[r] += lazy[node];
        lazy[l] += lazy[node];
        lazy[r] += lazy[node];
        lazy[node] = 0;
}
void update( int node , int b , int e , int i , int j ) {
        if( i > e || j < b || b > e ) return;
        if( i <= b && j >= e ) {
                tree[node] += 1;
                lazy[node] += 1;
                return;
        }
        pushdown( node , b , e );
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        update( l , b , m , i , j );
        update( r , m + 1 , e , i , j );
        tree[node] = tree[l] + tree[r];
}
int query( int node , int b , int e , int pos ) {
        if( pos > e || pos < b || b > e ) return 0;
        if( pos == b && b == e ) return tree[node];
        pushdown( node , b , e );
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        return query( l , b , m , pos ) + query( r , m + 1 , e , pos );
}
int main( int argc , char const *argv[] ) {
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
                printf("Case %d:\n",tc);
                scanf("%s",s);
                len = strlen( s );
                scanf("%d",&q);
                while( q-- ) {
                       scanf("%s",c);
                       if( c[0] == 'I' ) {
                                int l , r;
                                scanf("%d %d",&l,&r);
                                update( 1 , 0 , len - 1 , --l , --r );
                       }
                       else {
                                int pos;
                                scanf("%d",&pos);
                                int add = query( 1 , 0 , len - 1 , --pos );
                                int val = s[pos]-'0';
                                if( add%2 == 0 ) printf("%d\n",val);
                                else printf("%d\n",val^1);
                       }
                }
                memset( tree , 0 , sizeof( tree ) );
                memset( lazy , 0 , sizeof( lazy ) );
        }
        return 0;
}











