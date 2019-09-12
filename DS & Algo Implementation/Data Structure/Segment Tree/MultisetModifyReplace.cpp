#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
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

multiset <int> tree[ 4*N ];
int a[ N ];
int n , q;

/**
Find the smallest number greater than or equal to a given number
with modification query
*/
void build( int node , int b , int e ) {
        if( b > e ) return;
        for( int i = b; i <= e; i++ ) tree[node].insert( a[i] );
        if( b == e ) return;
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        build( l , b , m );
        build( r , m + 1 , e );
}
void update( int node , int b , int e , int pos , int val ) {
        if( pos > e || pos < b || b > e ) return;
        if( b == e && b == pos ) {
                tree[node].erase( tree[node].find( a[pos] ) );
                tree[node].insert( val );
                return;
        }
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        update( l , b , m , pos , val );
        update( r , m + 1 , e , pos , val );
}
int query( int node , int b , int e , int i , int j , int val ) {
        if( i > e || j < b || b > e ) return inf;
        if( i <= b && j >= e ) return *tree[node].lower_bound( val );
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        return min( query( l , b , m , i , j , val ) , query( r , m + 1 , e , i , j , val ) );
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( nullptr );
        cin >> n;
        for( int i = 1; i <= n; i++ ) cin >> a[i];
        build( 1 , 1 , n );
        cout << query( 1 , 1 , n , 1 , n , 3 ) <<endl;
        return 0;
}












