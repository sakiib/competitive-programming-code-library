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
int l[ N ] , r[ N ];
LL MX[ 4*N ] , MN[ 4*N ];
LL lazy[ 4*N ];

void pushdown( int node ) {
        if( lazy[node] == 0 ) return;
        int l = node << 1 , r = l | 1;
        MX[l] += lazy[node] , MN[l] += lazy[node];
        MX[r] += lazy[node] , MN[r] += lazy[node];
        lazy[l] += lazy[node];
        lazy[r] += lazy[node];
        lazy[node] = 0;
}
void build( int node , int b , int e ) {
        if( b > e ) return;
        if( b == e ) {
                MX[node] = a[b];
                MN[node] = a[b];
                return;
        }
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        build( l , b , m );
        build( r , m + 1 , e );
        MX[node] = max( MX[l] , MX[r] );
        MN[node] = min( MN[l] , MN[r] );
}
void update( int node , int b , int e , int i , int j , LL add ) {
        if( i > e || j < b || b > e ) return;
        if( i <= b && j >= e ) {
                MX[node] += add;
                MN[node] += add;
                lazy[node] += add;
                return;
        }
        pushdown( node );
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        update( l , b , m , i , j , add );
        update( r , m + 1 , e , i , j , add );
        MX[node] = max( MX[l] , MX[r] );
        MN[node] = min( MN[l] , MN[r] );
}
LL queryMAX( int node , int b , int e , int i , int j ) {
        if( i > e || j < b ) return -INF;
        if( i <= b && j >= e ) return MX[node];
        pushdown( node );
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        return max( queryMAX( l , b , m , i , j ) , queryMAX( r , m + 1 , e , i , j ) );
}
LL queryMIN( int node , int b , int e , int i , int j ) {
        if( i > e || j < b ) return INF;
        if( i <= b && j >= e ) return MN[node];
        pushdown( node );
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        return min( queryMIN( l , b , m , i , j ) , queryMIN( r , m + 1 , e , i , j ) );
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( nullptr );

        return 0;
}










