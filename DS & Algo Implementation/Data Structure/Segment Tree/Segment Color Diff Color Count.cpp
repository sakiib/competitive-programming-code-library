#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long uLL;
typedef long long int LL;
typedef pair <int,int> pii;
typedef pair <int,pii> piii;
typedef pair <long long,long long> pll;
typedef pair <long long,pll> plll;
const int N = 2e5 + 5;
const int inf = 1e9;
const long long INF = 1e18;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int MOD = 1000000007;

/**
different segment is colored with diff color ( can overlap )
in the end how many color is there
for large value , take them in & compress them
*/
int n;
int tree[ 4*N ] , lazy[ 4*N ];

void pushdown( int node , int b , int e ) {
        if( lazy[node] == 0 ) return;
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        tree[l] = tree[node];
        tree[r] = tree[node];
        lazy[l] = lazy[node];
        lazy[r] = lazy[node];
        lazy[node] = 0;
}
void update( int node , int b , int e , int i , int j , int c ) {
        if( i > e || j < b || b > e ) return;
        if( i <= b && j >= e ) {
                tree[node] = c;
                lazy[node] = c;
                return;
        }
        pushdown( node , b , e );
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        update( l , b , m , i , j , c );
        update( r , m + 1 , e , i , j , c );
}
int query( int node , int b , int e , int pos ) {
        if( pos > e || pos < b || b > e ) return 0;
        if( b == e && b == pos ) return tree[node];
        pushdown( node , b , e );
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        if( pos <= m ) return query( l , b , m , pos );
        else return query( r , m + 1 , e , pos );
}
int main( int argc , char const *argv[] ) {
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
                scanf("%d",&n);
                for(int i = 1; i <= n; i++ ) {
                        int l , r;
                        scanf("%d %d",&l,&r);
                        update( 1 , 1 , N , l , r , i );
                }
                map <int,int> M;
                for( int i = 1; i < N; i++ ) {
                        int c = query( 1 , 1 , N , i );
                        if( c != 0 ) M[c];
                }
                int ans = M.size();
                printf("Case %d: %d\n",tc,ans);
                for( int i = 1; i < 4*N; i++ ) tree[i] = 0 , lazy[i] = 0;
        }
        return 0;
}











