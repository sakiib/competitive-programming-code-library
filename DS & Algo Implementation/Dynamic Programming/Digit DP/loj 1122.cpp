/**
 * Created by Sakib on 06/09/2018.
 */
#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(args...) { dbg,args; cerr<<"\n"; }
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

int n , m;
bool has[ 15 ];
int dp[ 15 ][ 15 ];

int go( int prev , int taken ) {
    if( taken >= n ) return 1;
    if( dp[prev][taken] != -1 ) return dp[prev][taken];
    int ret = 0;
    FOR( i , 1 , 9 ) if( has[i] && abs(prev-i) <= 2 ) ret += go( i , taken+1 );
    return dp[prev][taken] = ret;
}
int main( int argc, char const *argv[] ) {
    int t;
    scanf("%d",&t);
    FOR( tc , 1 , t ) {
        scanf("%d %d",&m,&n);
        int d;
        mem( has , false );
        FOR( i , 1 , m ) scanf("%d",&d) , has[d] = true;
        mem( dp , -1 );
        int ans = 0;
        FOR( i , 1 , 9 ) if( has[i] ) ans += go( i , 1 );

        printf("Case %d: %d\n",tc,ans);
    }
    return 0;
}









