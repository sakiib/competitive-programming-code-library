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

int n , q;
LL a[ N ];
LL tree[ 4*N ];
LL lazy[ 4*N ];

LL pushup( LL a , LL b ) {
        return min( a , b );
}
void pushdown( int node ) {
        if( lazy[node] == 0 ) return;
        int l = node << 1 , r = l | 1;
        tree[l] += lazy[node];
        tree[r] += lazy[node];
        lazy[l] += lazy[node];
        lazy[r] += lazy[node];
        lazy[node] = 0;
}
void build( int node , int b , int e ) {
        if( b > e ) return;
        if( b == e ) {
                tree[node] = a[b];
                return;
        }
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        build( l , b , m );
        build( r , m + 1 , e );
        tree[node] = pushup( tree[l] , tree[r] );
}
void update( int node , int b , int e , int i , int j , int add ) {
        if( i > e || j < b || b > e ) return;
        if( i <= b && j >= e ) {
                tree[node] += add;
                lazy[node] += add;
                return;
        }
        pushdown( node );
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        update( l , b , m , i , j , add );
        update( r , m + 1 , e , i , j , add );
        tree[node] = pushup( tree[l] , tree[r] );
}
LL query( int node , int b , int e , int i , int j ) {
        if( i > e || j < b ) return INF;
        if( i <= b && j >= e ) return tree[node];
        pushdown( node );
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        return pushup( query( l , b , m , i , j ) , query( r , m + 1 , e , i , j ) );
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( nullptr );
        cin >> n >> q;
        for( int i = 1; i <= n; i++ ) cin >> a[i];
        build( 1 , 1 , n );
        while( q-- ) {
                string s;
                cin >> s;
                if( s == "u" ) {
                        int l , r , val;
                        cin >> l >> r >> val;
                        update( 1 , 1 , n , l , r , val );
                }
                else {
                        int l , r;
                        cin >> l >> r;
                        cout << query( 1 , 1 , n , l , r ) << endl;
                }
        }
        return 0;
}












