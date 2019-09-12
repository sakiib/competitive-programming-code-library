
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define trace(...) __f( #__VA_ARGS__ , __VA_ARGS__ )
template <typename Arg1>
void __f( const char* name , Arg1&& arg1 ) {
        cerr << name << " : " << arg1 << "\n";
}
template <typename Arg1, typename... Args>
void __f( const char* na , Arg1&& arg1 , Args&&... args ) {
        const char* c = strchr( na + 1 , ',' );
        cerr.write( na , c - na ) << " : " << arg1 << " , ";
        __f( c + 1 , args... );
}
#define endl "\n"
#define all(V) V.begin(),V.end()
#define Unique(V) sort(all(V)),V.erase(unique(all(V)),V.end())
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int LL;
typedef pair <int,int> pii;
const int MOD = 1e9 + 7;
const int inf = 1e9;
const double EPS = 1e-9;
const double PI = acos(-1.0);
const long long INF = 1e18;
const int N = 3e5 + 5;


template <typename T> using
    Treap = tree<T,null_type,
    less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;

Treap <LL> t[ 4*N ];
int n , m , k;
LL a[ N ];

void build( int node , int b , int e ) {
        if( b > e ) return;
        for( int i = b; i <= e; i++ ) t[node].insert( a[i] );
        if( b == e ) return;
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        build( l , b , m );
        build( r , m + 1 , e );
}
void update( int node , int b , int e , int pos , LL nval , LL pval ) {
        if( b > e || pos > e || pos < b ) return;
        t[node].erase( t[node].find_by_order( t[node].order_of_key( pval ) ) );
        t[node].insert( nval );
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        if( b == e ) return;
        update( l , b , m , pos , nval , pval );
        update( r , m + 1 , e , pos , nval , pval );
}
int getsmall( int node , int b , int e , int i , int j , LL x ) {
        if( i > e || j < b || b > e  ) return 0;
        if( i <= b && j >= e ) return t[node].order_of_key( x );
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        return getsmall( l , b , m , i , j , x ) + getsmall( r , m+1 , e , i , j , x );
}

int main( ) {
        IO;
        #ifdef LOCAL
            freopen( "input.txt" , "r" , stdin );
        #endif // LOCAL
        cin >> n >> m >> k;
        for( int i = 1; i <= n; i++ ) cin >> a[i];
        build( 1 , 1 , n );
        while( m-- ) {
                int l , r , u , p;
                cin >> l >> r >> u >> p;
                int small = getsmall( 1 , 1 , n , l , r , u );
                LL nval = 1LL * k * small / ( r - l + 1 );
                update( 1 , 1 , n , p , nval , a[p] );
                a[p] = nval;
        }
        for( int i = 1; i <= n; i++ ) cout << a[i] << endl;
        return 0;
}








