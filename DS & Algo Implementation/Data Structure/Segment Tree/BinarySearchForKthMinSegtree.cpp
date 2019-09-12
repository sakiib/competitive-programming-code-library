#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
typedef pair < int , int > ii;
const int inf = 1e9;
const LL INF = 1e18;
const int N = 1e5 + 5;
const int mod = 1000000007;
const double eps = 1e-8;
const double pi = acos( -1.0 );

int n , a[ N ] , tree[ 4*N ];

void build( int node , int b , int e , int val ) {
        if( b > e ) return;
        if( b == e ) {
                tree[node] += 1;
                return;
        }
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        if( val <= m ) build( l , b , m , val );
        else build( r , m+1 , e , val );
        tree[node] = tree[l] + tree[r];
}
int query( int node , int b , int e , int k ) {
        if( b > e ) return 0;
        if( b == e ) return b;
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        if( k <= tree[l] ) return query( l , b , m , k );
        else return query( r , m+1 , e , k - tree[l] );
}
int main( int argc , char const *argv[] ) {
        ios_base :: sync_with_stdio(false); cin.tie(NULL);
        cin >> n;
        for( int i = 1; i <= n; i++ ) cin >> a[i];
        for( int i = 1; i <= n; i++ ) build( 1 , 1 , 10 , a[i] );
        cout << query( 1 , 1 , 10 , 2 ) << endl;
        return 0;
}







