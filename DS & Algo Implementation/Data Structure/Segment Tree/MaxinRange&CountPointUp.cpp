#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
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

struct segment {
        int mx;
        int cnt;
        segment( ) : mx(0) , cnt(0) {}
        segment( int mx , int cnt ) : mx(mx) , cnt(cnt) {}
};

segment tree[ 4*N ];
int n;
int a[ N ];

segment combine( segment a , segment b ) {
        if( a.mx > b.mx ) return a;
        if( a.mx < b.mx ) return b;
        return segment( a.mx , a.cnt + b.cnt );
}
void build( int node , int b , int e ) {
        if( b > e ) return;
        if( b == e ) {
                tree[node] = segment( a[b] , 1 );
                return;
        }
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        build( l , b , m );
        build( r , m + 1 , e );
        tree[node] = combine( tree[l] , tree[r] );
}
segment query( int node , int b , int e , int i , int j ) {
        if( i > e || j < b || b > e ) return segment( -inf , 0 );
        if( i <= b && j >= e ) return tree[node];
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        return combine( query( l , b , m , i , j ) , query( r , m + 1 , e , i , j ) );
}
void update( int node , int b , int e , int pos , int val ) {
        if( pos > e || pos < b || b > e ) return;
        if( b == e && b == pos ) {
                tree[node] = segment( val , 1 );
                return;
        }
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        update( l , b , m , pos , val );
        update( r , m + 1 , e , pos , val );
        tree[node] = combine( tree[l] , tree[r] );
}
/**

 same thing just with range update

struct segment {
        int mx;
        int cnt;
        segment( ) : mx(0) , cnt(0) {}
        segment( int mx , int cnt ) : mx(mx) , cnt(cnt) {}
};

segment tree[ 4*N ];
int lazy[ 4*N ];
int n;
int a[ N ];

segment combine( segment a , segment b ) {
        if( a.mx > b.mx ) return a;
        if( a.mx < b.mx ) return b;
        return segment( a.mx , a.cnt + b.cnt );
}
void pushdown( int node ) {
        if( lazy[node] == 0 ) return;
        int l = node << 1 , r = l | 1;
        tree[l].mx += lazy[node];
        tree[r].mx += lazy[node];
        lazy[l] += lazy[node];
        lazy[r] += lazy[node];
        lazy[node] = 0;
}
void build( int node , int b , int e ) {
        if( b > e ) return;
        if( b == e ) {
                tree[node] = segment( a[b] , 1 );
                return;
        }
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        build( l , b , m );
        build( r , m + 1 , e );
        tree[node] = combine( tree[l] , tree[r] );
}
segment query( int node , int b , int e , int i , int j ) {
        if( i > e || j < b || b > e ) return segment( -inf , 0 );
        if( i <= b && j >= e ) return tree[node];
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        return combine( query( l , b , m , i , j ) , query( r , m + 1 , e , i , j ) );
}
void update( int node , int b , int e , int i , int j , int add ) {
        if( i > e || j < b || b > e ) return;
        if( i <= b && j >= e ) {
                tree[node].mx += add;
                lazy[node] += add;
                return;
        }
        pushdown( node );
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        update( l , b , m , i , j , add );
        update( r , m + 1 , e , i , j , add );
        tree[node] = combine( tree[l] , tree[r] );
}
*/
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( nullptr );
        cin >> n;
        for( int i = 1; i <= n; i++ ) cin >> a[i];
        build( 1 , 1 , n );
        segment ans = query( 1 , 1 , n , 1 , n );
        cout << ans.mx << " " << ans.cnt << endl;
        return 0;
}











