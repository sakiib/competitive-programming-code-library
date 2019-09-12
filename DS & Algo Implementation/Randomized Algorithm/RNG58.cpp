#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#define endl "\n"
#define trace(...) __f( #__VA_ARGS__ , __VA_ARGS__ )
template < typename Arg1 >
void __f( const char* name , Arg1&& arg1 ) { cerr << name << " : " << arg1 << "\n"; }
template < typename Arg1 , typename... Args >
void __f( const char* names , Arg1&& arg1 , Args&&... args ) {
const char* comma = strchr( names + 1 , ',' );
cerr.write( names , comma - names ) << " : " << arg1 << " , " ; __f( comma + 1 , args... ); }
typedef long long int LL;
const int N = 1e5 + 5;
const int inf = 1e9;
const long long INF = 1e18;

#define rnd( a , b) ((((rand() << 15) ^ rand()) % ((b) - (a) + 1)) + (a))
std::mt19937 rng( chrono::steady_clock::now().time_since_epoch().count() );
#define ran(a, b ) rng() % ( (b) - (a) + 1 ) + (a)

int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( nullptr );
        srand( time( 0 ) );

        return 0;
}












