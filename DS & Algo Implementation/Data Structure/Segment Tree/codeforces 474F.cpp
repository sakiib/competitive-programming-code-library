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

/**
gcd in L to R
& cnt of gcd occurence in L to R
*/
int n;
int a[ N ];

struct data {
        int gcd , cnt;
} tree[ 4*N ];

void build( int node , int b , int e ) {
        if( b > e ) return;
        if( b == e ) {
                tree[node] = {a[b],1};
                return;
        }
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        build( l , b , m );
        build( r , m + 1 , e );
        tree[node].gcd = __gcd( tree[l].gcd , tree[r].gcd );
        tree[node].cnt = ( tree[l].gcd == tree[node].gcd ? tree[l].cnt : 0 ) +
                          ( tree[r].gcd == tree[node].gcd ? tree[r].cnt : 0 );
}
data query( int node , int b , int e , int i , int j ) {
        if( i > e || j < b || b > e ) return {0,0};
        if( i <= b && j >= e ) return tree[node];
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        data q1 = query( l , b , m , i , j );
        data q2 = query( r , m + 1 , e , i , j );
        int g = __gcd( q1.gcd , q2.gcd );
        int cnt = ( g == q1.gcd ? q1.cnt : 0 ) + ( g == q2.gcd ? q2.cnt : 0 );
        return {g,cnt};
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( nullptr );
        cin >> n;
        for( int i = 1; i <= n; i++ ) cin >> a[i];
        build( 1 , 1 , n );
        int q;
        cin >> q;
        while( q-- ) {
                int l , r;
                cin >> l >> r;
                cout << ( r - l + 1  - query( 1 , 1 , n , l , r ).cnt ) << endl;
        }
        return 0;
}










