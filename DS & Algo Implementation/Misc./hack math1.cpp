#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define sf scanf
#define pf prinf
#define All(V) V.begin(),V.end()
#define Unique(V) sort( All(V)),V.erase( unique( All(V) ),V.end() )
#define Fast_IO ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long int LL;
const int N = 1e5 + 5;
const int inf = 1e9;
const LL INF = 1e18;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int MOD = 1000000007;
/**
 Find any number from 1 to 2e18 such that ,
 it divides every number except one number in the array.
 */

int n;
LL a[ N ] , tree[ 4*N ];

void build( int node , int b , int e ) {
        if( b > e ) return;
        if( b == e ){
                tree[node] = a[b];
                return;
        }
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        build( l , b , m );
        build( r , m + 1 , e );
        tree[node] = __gcd( tree[l] , tree[r] );
}
LL query( int node , int b , int e , int i , int j ) {
        if( i > e || j < b || b > e ) return 0;
        if( i <= b && j >= e ) return tree[node];
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        LL x = query( l , b , m , i , j );
        LL y = query( r , m + 1 , e , i , j );
        return __gcd( x , y );
}
int main( int argc , char const *argv[] ) {
        Fast_IO;
        cin >> n;
        for( int i = 1; i <= n; i++ ) cin >> a[i];
        if( n == 1 ) return cout << 2*INF <<endl,0;
        build( 1 , 1 , n );
        for( int i = 1; i <= n; i++ ) {
                LL l = query( 1 , 1 , n , 1 , i-1 );
                LL r = query( 1 , 1 , n , i+1 , n );
                LL g = __gcd( l , r );
                if( a[i]%g != 0 ) return cout << g << endl,0;
        }
        return 0;
}






