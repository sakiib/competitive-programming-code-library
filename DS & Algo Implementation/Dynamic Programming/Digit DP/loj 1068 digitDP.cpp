/**
 * Created by Sakib on 06/05/2018.
 */
#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(args...) { dbg,args; cerr<<"\n"; }
struct debugger{
template<typename T>debugger& operator,(const T& v){cerr<<v<<" ";return *this;}}dbg;
/**
Each case contains three positive integers A, B and K (1 ≤ A ≤ B < 231 and 0 < K < 10000).
Find how many numbers from A to B are divisible by6 k
*/
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

int L , R , K;
vector <int> Num;
int len;
int dp[ 15 ][ 5 ][ 85 ][ 85 ];

void Convert( int n ) {
    Num.clear();
    len = 0;
    while( n ) {
        Num.push_back( n%10 ) , n /= 10;
    }
    len = Num.size();
    reverse( Num.begin() , Num.end() );
}
int go( int pos , int chk , int rem1 , int rem2 ) {
    if( pos >= len ) return ( rem1%K == 0 && rem2%K == 0 );
    if( dp[pos][chk][rem1][rem2] != -1 ) return dp[pos][chk][rem1][rem2];
    int ret = 0;
    if( chk ) {
        for( int dgt = 0; dgt <= 9; dgt++ ) {
           ret += go( pos+1 , 1 , (rem1*10+dgt)%K , (rem2+dgt)%K );
        }
    }
    else {
        for( int dgt = 0; dgt < Num[pos]; dgt++ ) {
            ret += go( pos+1 , 1 , (rem1*10+dgt)%K , (rem2+dgt)%K );
        }
        ret += go( pos+1 , 0 , (rem1*10+Num[pos])%K , (rem2+Num[pos])%K );
    }
    return dp[pos][chk][rem1][rem2] = ret;
}
int main( int argc, char const *argv[] ) {
    //fast_io;
    int t;
    scanf("%d",&t);
    for( int tc = 1; tc <= t; tc++ ) {
        scanf("%d %d %d",&L,&R,&K);
        if( K > 81 ) {
            printf("Case %d: 0\n",tc);
            continue;
        }
        Convert( R );
        memset( dp , -1 , sizeof(dp) );
        int Ans = go( 0 , 0 , 0 , 0 );
        memset( dp , -1 , sizeof(dp) );
        Convert( L-1 );
        Ans -= go( 0 , 0 , 0 , 0 );
        printf("Case %d: %d\n",tc,Ans);
    }
    return 0;
}









