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

vector <int> graph[ N ];
int sub[ N ];
int n , k;
int sz;
int tot;

void dfs( int s , int p ) {
        sub[s] = 1;
        for( auto x : graph[s] ) {
                if( x != p ) {
                        dfs( x , s );
                        sub[s] += sub[x];
                }
        }
        if( sub[s]%sz == 0 ) tot++;
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( nullptr );
        #ifdef forthright48
            freopen( "input.txt" , "r" , stdin );
        #endif // forthright48
        cin >> n >> k;
        for( int i = 1; i <= n - 1; i++ ) {
                int u , v;
                cin >> u >> v;
                graph[u].push_back( v );
                graph[v].push_back( u );
        }
        if( n%k != 0 ) return cout << "No" << endl,0;
        tot = 0;
        sz = n/k;
        dfs( 1 , 0 );
        if( tot == k ) cout << "Yes" << endl;
        else cout << "No" << endl;
        return 0;
}













