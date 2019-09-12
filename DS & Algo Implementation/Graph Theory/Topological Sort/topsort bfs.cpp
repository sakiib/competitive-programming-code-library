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

const int n = 5;
vector <int> graph[ 10 ];
int indegree[ 10 ];

int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( nullptr );
        #ifdef forthright48
            //freopen( "input.txt" , "r" , stdin );
        #endif // forthright48
        for( int i = 1; i <= n; i++ ) {
                string s;
                cin >> s;
                if( s[1] == '<' ) {
                        graph[ s[0]-'A'+1 ].push_back( s[2]-'A'+1 );
                        indegree[ s[2]-'A'+1 ]++;
                }
                else {
                        graph[ s[2]-'A'+1 ].push_back( s[0]-'A'+1 );
                        indegree[ s[0]-'A'+1 ]++;
                }
        }
        queue <int> Q;
        for( int i = 1; i <= n; i++ ) {
                if( indegree[i] == 0 ) Q.push( i );
        }
        vector <int> ans;
        while( !Q.empty() ) {
                int to = Q.front();
                Q.pop();
                ans.push_back( to );
                for( auto x : graph[to] ) {
                        indegree[x]--;
                        if( indegree[x] == 0 ) Q.push( x );
                }
        }
        if( ans.size() != n ) return cout << "impossible" << endl,0;
        for( auto x : ans ) cout << (char)(x+'A'-1);
        return 0;
}












