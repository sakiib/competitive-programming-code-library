#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef unsigned long long uLL;
typedef long long int LL;
typedef pair <int,int> pii;
typedef pair <long long,long long> pll;
const int N = 1e5 + 5;
const int inf = (int)1e9;
const long long INF = 1LL * 1e18;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int MOD = 1000000009;

template <typename T> using Treap = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

template <class T> ostream& operator << ( ostream& out, const vector < T >& v ) {
out<<'[';for(int i=0;i<v.size();++i){out<<v[i];if(i+1<v.size())out<<", ";}out <<']';return out;}

template <class S, class T> ostream& operator << ( ostream& out, const pair < S,T >& P ) {
out << '{' << P.first << ", " << P.second << '}'; return out; }

template <class S, class T> ostream& operator << ( ostream& out, const map < S,T >& mp ) {
out<<"[\n";for(const auto& x : mp){out <<'{'<<x.first<<", "<<x.second<< "}\n";}out <<"]\n";return out;}

template <class T> ostream& operator << ( ostream& out, const multiset <T>& cs ){ out<<'{';
for(auto it=cs.begin();it!=cs.end();){out<<*it;it++;if(it!=cs.end())out<<", ";else out<<'}';}return out;}

template <class T> ostream& operator << ( ostream& out, const set <T>& cs ){ out<<'{';
for(auto it=cs.begin();it!=cs.end();){out<<*it;it++;if(it!=cs.end())out<<", ";else out<<'}';}return out;}

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define fix( x ) setprecision( x ) << fixed
#define mem( a , x ) memset( a , x , sizeof( a ) )
#define sz( V ) (int)V.size( )
#define Found( S , x ) S.find( x ) != S.end()
#define all( V ) V.begin( ),V.end( )
#define Unique( V ) sort( all( V ) ), V.erase( unique( all( V ) ), V.end() )
#define One( x ) __builtin_popcountll( x )
#define leftmostOne( x )  ( 63 - __builtin_clzll( x ) )
#define rightmostOne( x ) __builtin_ctzll( x )
#define Set( N , pos ) ( N |= ( 1LL << pos ) )
#define Check( N , pos ) ( !(( N&( 1LL << pos )) == 0 ) )
#define Reset( N , pos ) ( N = ( N&(~( 1LL << pos )) ) )
#define Toggle( N , pos ) ( N ^= ( 1LL << pos ) )
#define FOR( i , a , b ) for( int i = (a); i <= (b); i++ )
#define ROF( i , a , b ) for( int i = (a); i >= (b); i-- )
const int dx[] = {+1, -1, 0, 0}, dy[] = {0, 0, +1, -1};
const int fx[] = {-1, +0, +1, +0, +1, +1, -1, -1}, fy[] = {+0, -1, +0, +1, +1, -1, +1, -1};
const int hx[] = {-2, -2, -1, -1, +1, +1, +2, +2}, hy[] = {+1, -1, +2, -2, +2, -2, +1, -1};
#define trace(...) __f( #__VA_ARGS__ , __VA_ARGS__ )
template < typename Arg1 >
void __f( const char* name , Arg1&& arg1 ) { cerr << name << " : " << arg1 << std::endl; }
template < typename Arg1 , typename... Args >
void __f( const char* names , Arg1&& arg1 , Args&&... args ) {
const char* comma = strchr( names + 1 , ',' );
cerr.write( names , comma - names ) << " : " << arg1 << " , " ; __f( comma + 1 , args... ); }

int k , b;
vector <int> V;
int p[ 150 ];
int dp[ 129 ][ 2 ][ 1001 ][ 129 ];

int solve( int idx , int chk , int rem , int one ) {
        if( idx >= b ) return rem%k == 0 ? one%MOD: 0;
        if( dp[idx][chk][rem][one] != -1 ) return dp[idx][chk][rem][one]%MOD;
        int ret = 0;
        if( chk ) {
                for(int i = 0; i <= 1; i++ ) {
                        ret += solve( idx + 1 , 1 , ( rem%k + i%k*p[b-1-idx]%k)%k , one + i );
                        ret %= MOD;
                }
        }
        else {
                for(int i = 0; i < V[idx]; i++ ) {
                        ret += solve( idx + 1 , 1 , ( rem%k + i%k*p[b-1-idx]%k)%k , one + i );
                        ret %= MOD;
                }
                ret += solve( idx + 1 , 0 , ( rem%k + V[idx]%k*p[b-1-idx]%k)%k , one + V[idx] );
        }
        return dp[idx][chk][rem][one] = ret%MOD;
}
int main( int argc , char const *argv[] ) {
        FastIO;
        // freopen( "input.txt" , "r" , stdin );
        cin >> k >> b;
        for( int i = 1; i <= b; i++ ) V.push_back( 1 );
        p[0] = 1%k;
        for( int i = 1; i <= 130; i++ ) p[i] = ( p[i-1]%k * 2%k )%k;
        memset( dp , -1 , sizeof( dp ) );
        cout << solve( 0 , 0 , 0 , 0 ) << endl;
        return 0;
}















