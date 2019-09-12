/**
 * Created by Sakib on 5/30/2018.
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
#define sz( V ) (int)V.size( )
#define all( V ) V.begin( ),V.end( )
#define Found( S , val ) S.find( val ) != S.end( )
#define Unique( V ) sort( all( V ) ), V.erase( unique( all( V ) ), V.end() )
#define FOR( i , a , b ) for( int i = a; i <= b; i++ )
#define ROF( i , a , b ) for( int i = a; i >= b; i-- )
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

int ara[ N ];
int Table[ N ][ 30 ];
int lg[ N ];
int n;

void Build_Table( ) {
    for( int i = 1; i <= N; i++ ) Table[i][0] = ara[i];
    for( int i = 2; i <= N; i++ ) lg[i] = lg[i/2] + 1;
    for( int j = 1; ( 1 << j ) <= N; j++ ) {
        for( int i = 1; i+( 1 << j )-1 <= N; i++ ) {
            Table[i][j] = __gcd( Table[i][j-1] , Table[i+(1<<(j-1))][j-1] );
        }
    }
}
int Query( int l , int r ) {
    if( l > r ) swap( l , r );
    int k = lg[r-l+1];
    return __gcd( Table[l][k] , Table[r-(1<<k)+1][k] );
}
int main( int argc, char const *argv[] ) {
    fast_io;
    cin >> n;
    for( int i = 1; i <= n; i++ ) cin >> ara[i];
    Build_Table( );
    int q;
    cin >> q;
    while( q-- ) {
        int l , r;
        cin >> l >> r;
        cout << Query( l , r )<< endl;
    }
    return 0;
}



