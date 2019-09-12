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
const int MOD = 1000000007;

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

LL l , r;
pll dp[ 65 ][ 2 ][ 2 ];
bool vis[ 65 ][ 2 ][ 2 ];

pll go( int pos , bool bigger , bool smaller , int what ) {
        // trace( pos , bigger , smaller , what );
        if( pos < 0 ) return { 0 , 0 };
        pll &ret = dp[pos][bigger][smaller];
        if( vis[pos][bigger][smaller] ) return ret;
        vis[pos][bigger][smaller] = true;
        int bitL = Check( l , pos );
        int bitR = Check( r , pos );
        int from = bigger ? 0 : bitL;
        int to = smaller ? 1 : bitR;
        ret = { -1 , INF };
        FOR( i , from , to ) {
                pll temp = go( pos - 1 , bigger | ( i > bitL ) , smaller | ( i < bitR ) , i );
                temp.first += i;
                if( i ) Set( temp.second , pos );
                if( temp.first > ret.first ) ret = temp;
                else if( temp.first == ret.first && temp.second < ret.second ) ret.second = temp.second;
        }
        return ret;
}
void solve( ) {
        cin >> l >> r;
        mem( vis , false );
        pll ans = go( 62 , 0 , 0 , -1 );
        cout << ans.second << endl;
}
int main( int argc , char const *argv[] ) {
        FastIO;
        //freopen( "input.txt" , "r" , stdin );
        int q;
        cin >> q;
        while( q-- ) {
                solve( );
        }
        return 0;
}
