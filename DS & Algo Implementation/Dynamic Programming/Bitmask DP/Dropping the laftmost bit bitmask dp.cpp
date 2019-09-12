#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
template <typename T> using
Treap = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
#define endl "\n"
#define all(V) V.begin( ), V.end( )
#define Unique(V) sort( all( V ) ), V.erase( unique( all( V ) ), V.end() )
std::mt19937 rng( chrono::steady_clock::now().time_since_epoch().count() );
#define ran(a, b) rng() % ( (b) - (a) + 1 ) + (a)
#define trace(...) __f( #__VA_ARGS__ , __VA_ARGS__ )
template < typename Arg1 >
void __f( const char* name , Arg1&& arg1 ) { cerr <<name<<" : "<<arg1<< "\n"; }
template < typename Arg1 , typename... Args >
void __f( const char* names , Arg1&& arg1 , Args&&... args ) {
const char* comma = strchr( names + 1 , ',' );
cerr.write( names , comma - names ) <<" : "<<arg1<<" , "; __f( comma+1 , args...);}
typedef long long int LL;
typedef pair <int,int> pii;
typedef pair <long long,long long> pll;
const int MOD = 1e9 + 7;
const double EPS = 1e-8;
const int N = 2005;
const int inf = 1e9;
const long long INF = 1e18;

int  Set( int N , int pos )    { return N |= ( 1 << pos ); }
bool Check( int N , int pos )  { return (bool)( N & ( 1 << pos ) );}

int n , e , k;
bool bad[ N ][ N ];
vector <int> graph[ N ];
int dp[ N ][ (1 << 9) ];

int add( int x , int y , int MOD ) {
        x += y;
        if( x >= MOD ) x -= MOD;
        return x;
}
int solve( int idx , int mask ) {
        if( idx == n ) return 1;
        mask = mask >> 1;
        if( dp[idx][mask] != -1 ) return dp[idx][mask];
        int ret = 0;
        for( int i = idx - e; i <= idx + e; i++ ) {
                if( i < 0 || i >= n ) continue;
                int v = ( i - idx + e );
                if( !Check( mask , v ) && !bad[idx][i] ) {
                        ret = add( ret , solve( idx + 1 , Set( mask , v ) ), MOD );
                }
        }
        return dp[idx][mask] = ret;
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( nullptr );
        #ifdef forthright48
            //freopen( "input.txt" , "r" , stdin );
        #endif // forthright48
        cin >> n >> e >> k;
        for( int i = 1; i <= k; i++ ) {
                int u , v;
                cin >> u >> v;
                --u , --v;
                bad[u][v] = true;
        }
        memset( dp , -1 , sizeof( dp ) );
        cout << solve( 0 , 0 ) << endl;
        return 0;
}









