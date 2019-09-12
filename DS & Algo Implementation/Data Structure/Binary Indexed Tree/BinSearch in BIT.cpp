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

struct BINARY_INDEXED_TREE {

        static const int MAXN = 1e5 + 5;

        int BIT[ MAXN + 5 ];

        inline void Initialize( ) {
                memset( BIT , 0 , sizeof( BIT ) );
        }
        inline int RQuery ( int l , int r ) {
                return PQuery( r ) - PQuery( l - 1 );
        }
        inline void PUpdate ( int idx , int v ) {
                if( idx <= 0 ) return;
                for( ;idx <= MAXN; idx += ( idx & -idx ) ) BIT[ idx ] += v;
        }
        inline int PQuery ( int idx ) {
                int ret = 0;
                for( ;idx > 0; idx -= ( idx & -idx ) ) ret += BIT[ idx ];
                return ret;
        }
        inline void RUpdate ( int idx , int idy , int v ) {
                for( ;idx <= MAXN; idx += ( idx & -idx ) ) BIT[ idx ] += v;
                idy++ , v *= -1;
                for( ;idy <= MAXN; idy += ( idy & -idy ) ) BIT[ idy ] += v;
        }
} bit;


int a[ N ];
int n , s;

/// lower bound , idx sum is equal / greater equal to v in 1 to n
/// for l to r , add query( 1 , l - 1 ) to v

int bit_search( int v ) {
        int sum = 0;
        int pos = 0;
        int LOGN = log2( n );
        for( int i = LOGN; i >= 0; i-- ) {
                if( pos + (1 << i) <= n and sum + bit.BIT[ pos + (1 << i) ] < v ) {
                        sum += bit.BIT[ pos + (1 << i) ];
                        pos += (1 << i);
                }
        }
        if( pos + 1 > n ) return -1;
        return pos + 1; // +1 because 'pos' will have position of largest value less than 'v'
}

int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( nullptr );
        while( cin >> n >> s ) {
                bit.Initialize();
                for( int i = 1; i <= n; i++ ) {
                        cin >> a[i];
                        bit.PUpdate( i ,  + a[i] );
                }
                int ans = inf;
                for( int i = 1; i <= n; i++ ) {
                        int idx = bit_search( s + bit.RQuery( 1 , i - 1 ) );
                        if( idx != -1 ) {
                                ans = min( ans , idx - i + 1 );
                        }
                }
                if( ans == inf ) cout << 0 << endl;
                else cout << ans << endl;
        }
        return 0;
}












