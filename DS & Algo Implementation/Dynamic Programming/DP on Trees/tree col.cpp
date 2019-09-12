#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#define endl "\n"
#define all(V) V.begin( ), V.end( )
#define Unique(V) sort( all( V ) ), V.erase( unique( all( V ) ), V.end() )
#define Check( N , p ) ( !( ( N & ( 1LL << p ) ) == 0 ) )
#define ON( N , p ) ( N = N | ( 1LL << p ) )
#define OFF( N , p ) ( N = N & ~( 1LL << p ) )
std::mt19937 rng( chrono::steady_clock::now().time_since_epoch().count() );
#define rnd(a, b) ((((rand() << 15) ^ rand()) % ((b) - (a) + 1)) + (a))
#define ran(a, b) rng() % ( (b) - (a) + 1 ) + (a)
#define trace(...) __f( #__VA_ARGS__ , __VA_ARGS__ )
template < typename Arg1 >
void __f( const char* name , Arg1&& arg1 ) { cerr << name << " : " << arg1 << "\n"; }
template < typename Arg1 , typename... Args >
void __f( const char* names , Arg1&& arg1 , Args&&... args ) {
const char* comma = strchr( names + 1 , ',' );
cerr.write( names , comma - names ) << " : " << arg1 << " , " ; __f( comma + 1 , args... ); }
typedef long long int LL;
typedef pair <int,int> pii;
typedef pair <long long,long long> pll;
const int MOD = 1e9 + 7;
const double EPS = 1e-8;
const int N = 1e5 + 5;
const int inf = 1e9;
const long long INF = 1e18;

/**
Number of ways to color a tree such that , no two adjacent nodes are color
with BLACK color
*/

int black = 1 , white = 2;
int n;
vector <int> graph[ N ];
LL dp[ N ][ 5 ];

LL dfs( int s , int p , int col ) {
        if( dp[s][col] != -1 ) return dp[s][col];
        LL ret = 1;
        for( auto x : graph[s] ) {
                if( x != p ) {
                        LL sum = 0;
                        if( col == black ) {
                                sum += dfs( x , s , white ), sum %= MOD;
                        }
                        else {
                                sum += dfs( x , s , white ) , sum %= MOD;
                                sum += dfs( x , s , black ) , sum %= MOD;
                        }
                        ret = ( ret%MOD * sum%MOD )%MOD;
                }
        }
        return dp[s][col] = ret%MOD;
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( nullptr );
        cin >> n;
        for( int i = 1; i <= n - 1; i++ ) {
                int u , v;
                cin >> u >> v;
                graph[u].push_back( v );
                graph[v].push_back( u );
        }
        memset( dp , -1 , sizeof( dp ) );
        for( int i = 1; i <= 2; i++ ) dfs( 1 , 0 , i ); /// 1 - bl , 2 = wh
        cout << ( dp[1][1]%MOD + dp[1][2]%MOD )%MOD << endl;
        return 0;
}





