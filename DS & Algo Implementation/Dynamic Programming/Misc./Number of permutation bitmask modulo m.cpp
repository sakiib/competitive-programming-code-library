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

LL n;
int m;
int k;
vector <int> dig;
LL dp[ (1 << 18) + 1 ][ 101 ][ 2 ];

LL solve( int mask , int rem , int zero ) {
        if( mask == ( 1 << k ) - 1 ) return rem%m == 0 && !zero;
        if( dp[mask][rem][zero] != -1 ) return dp[mask][rem][zero];
        LL ret = 0;
        bool done[ 10 ];
        memset( done , false , sizeof( done ) );
        for( int i = 0; i < dig.size(); i++) {
                if( zero && dig[i] == 0 ) continue;
                if( done[ dig[i] ] ) continue;
                if( Check( mask , i ) ) continue;
                done[ dig[i] ] = true;
                int cmask = mask;
                ret += solve( ON( cmask , i ) , ( rem%m * 10%m + dig[i]%m )%m , zero && ( dig[i] == 0 ) );
        }
        return dp[mask][rem][zero] = ret;
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( nullptr );
        cin >> n >> m;
        while( n ) dig.push_back( n%10 ) , n /= 10;
        k = dig.size();
        memset( dp , -1 , sizeof( dp ) );
        LL tot = solve( 0 , 0 , 1 );
        cout << tot << endl;
        return 0;
}












