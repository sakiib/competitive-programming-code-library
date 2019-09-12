/**
 * Created by Sakib on 06/16/2018.
 */
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(args...) { dbg,args; cerr<<"\n"; }
template <typename T>
using orderset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
struct debugger{
template<typename T>debugger& operator,(const T& v){cerr<<v<<" ";return *this;}}dbg;

#define Fix( x ) setprecision( x ) << fixed
#define mem( a , x ) memset( a , x , sizeof( a ) )
#define bug( a , b ) cerr<< #a <<" = "<<a<<" , "<< #b <<" = "<<b<<"\n";
#define pb push_back
#define mp make_pair
#define ub upper_bound
#define lb lower_bound
#define FOR( i , a , b ) for( int i = a; i <= b; i++ )
#define ROF( i , a , b ) for( int i = a; i >= b; i-- )
#define sz( V ) (int)V.size( )
#define all( V ) V.begin( ),V.end( )
#define Found( S , val ) S.find( val ) != S.end( )
#define Unique( V ) sort( all( V ) ), V.erase( unique( all( V ) ), V.end() )
typedef pair < int , int > ii;
typedef pair < int , ii > iii;
typedef long long int LL;
typedef unsigned long long uLL;
const int inf = (int)1e9;
const LL INF = (LL)1e18;
const int N = 100005;
const int mod = 1000000007;
const double eps = 1e-8;
const double pi = acos( -1.0 );

int T , w;
int n;
pair < int , int > a[ 35 ];
int dp[ 35 ][ 1005 ];
bool dir[ 35 ][ 1005 ];

int go( int pos , int rem ) {
    if( rem < 0 ) return -inf;
    if( pos > n ) return 0;
    if( rem == 0 ) return 0;
    if( pos > n ) return 0;
    if( dp[pos][rem] != -1 ) return dp[pos][rem];
    int op1 = 0 , op2 = 0;
    op1 = go( pos+1 , rem-w*a[pos].first-2*w*a[pos].first )+a[pos].second;
    op2 = go( pos+1 , rem );
    dir[pos][rem] = ( op1 > op2 );
    return dp[pos][rem] = max( op1 , op2 );
}
void path( int pos , int rem ) {
    vector < int > mark;
    int j = T;
    FOR( i , 1 , n ) {
        if( dir[i][j] ) {
            j -= ( w*a[i].first+2*w*a[i].first );
            mark.pb( i );
        }
    }
    cout << sz( mark ) << endl;
    for( auto x : mark ) cout << a[x].first << " " << a[x].second << endl;
}
int main( int argc, char const *argv[] ) {

    bool f = false;
    while( cin >> T >> w ) {
        if( f ) cout << endl;
        f = true;
        cin >> n;
        FOR( i , 1 , n ) cin >> a[i].first >> a[i].second;
        mem( dp , -1 );
        mem( dir , false );
        cout << go( 1 , T ) << endl;
        path( 1 , T );
    }
    return 0;
}







