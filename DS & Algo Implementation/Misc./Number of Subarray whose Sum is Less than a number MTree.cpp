#include <bits/stdc++.h>
using namespace std;

#define Fast_IO ios_base::sync_with_stdio(0); cin.tie(0);

typedef unsigned long long uLL;
typedef long long int LL;
const int N = 1e5 + 5;
const int inf = 1e9;
const LL INF = 1e18;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int MOD = 1000000007;

int n;
LL t;
LL a[ 2*N ] , sum[ 2*N ];
vector <LL> tree[ 4*2*N ];

vector <LL> Merge( vector <LL> a , vector <LL> b ) {
        vector <LL> ret;
        merge( a.begin() , a.end() , b.begin() , b.end() , back_inserter(ret) );
        return ret;
}
void build( int node , int b , int e ) {
        if( b > e ) return;
        if( b == e ) {
                tree[node].push_back( sum[b] );
                return;
        }
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        build( l , b , m );
        build( r , m + 1 , e );
        tree[node] = Merge( tree[l] , tree[r] );
}
LL query( int node , int b , int e , int i , int j , LL val ) {
        if( i > e || j < b || b > e ) return 0;
        if( i <= b && j >= e ) {
                return lower_bound( tree[node].begin(), tree[node].end(), val ) - tree[node].begin();
        }
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        LL x = query( l , b , m , i , j , val );
        LL y = query( r , m + 1 , e , i , j , val );
        return x + y;
}
int main( int argc , char const *argv[] ) {
        Fast_IO;
        cin >> n >> t;
        for( int i = 1; i <= n; i++ ) cin >> a[i];
        for( int i = 1; i <= n; i++ ) sum[i] += sum[i-1] + a[i];
        build( 1 , 1 , n );
        LL ans = 0;
        for( int i = 1; i <= n; i++ ) {
                ans += query( 1 , 1 , n , i , n , sum[i-1] + t );
        }
        cout << ans << endl;
        return 0;
}








