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

mt19937 rng( chrono::steady_clock::now().time_since_epoch().count() );
#define rnd(a, b) ((((rand() << 15) ^ rand()) % ((b) - (a) + 1)) + (a))
#define ran(a, b ) rng() % ( (b) - (a) + 1 ) + (a)

/**
Express a number as sum of atmost 3 primes
*/

bool prime( int x ) {
        if( x < 2 ) return false;
        if( x == 2 ) return true;
        for( int i = 2; i * i <= x; i++ ) if( x%i == 0 ) return false;
        return true;
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( nullptr );
        int n;
        cin >> n;
        if( prime( n ) ) return cout << 1 << "\n" << n << endl,0;
        for( int i = 1; i <= 200; i++ ) {
                int x = ran( 1 , n );
                if( prime( x ) && ( n - x ) > 0 && prime( n - x ) ) {
                        cout << 2 << endl;
                        cout << x << " " << n - x << endl;
                        return 0;
                }
        }
        for( int i = 1; i <= 200; i++ ) {
                int x = ran( 1 , n );
                int cur = n - x;
                if( cur < 5 || !prime( x ) ) continue;
                for( int j = 1; j <= 200; j++ ) {
                        int y = ran( 2 , cur );
                        if( prime( y ) && ( cur - y ) > 0 && prime( cur - y ) ) {
                                cout << 3 << endl;
                                cout << x << " " << y << " " << cur-y << endl;
                                return 0;
                        }
                }
        }
        return 0;
}












