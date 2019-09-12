#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long uLL;
typedef long long int LL;
typedef pair <int,int> pii;
typedef pair <int,pii> piii;
typedef pair <long long,long long> pll;
typedef pair <long long,pll> plll;
const int N = 1e5 + 5;
const int inf = 1e9;
const long long INF = 1e18;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int MOD = 1000000007;

int  Set( int N , int pos )    { return N |= ( 1 << pos ); }
int  Reset( int N , int pos )  { return N = N & ~( 1 << pos ); }
bool Check( int N , int pos )  { return (bool)( N & ( 1 << pos ) );}
int  Toggle( int N , int pos ) { return ( N ^= ( 1 << pos ) ); }

int x[ 20 ] , y[ 20 ];
int n;
int dp[ (1 << 17) + 1 ];
int same[ 20 ][ 20 ];

bool coLinear( int i , int j , int k ) {
        LL area = abs( x[i]*y[j] + x[j]*y[k] + x[k]*y[i] - x[j]*y[i] - x[k]*y[j] - x[i]*y[k] );
        return area == 0;
}
int solve( int mask ) {
        if( __builtin_popcount( mask ) == n ) return 0;
        if( dp[mask] != -1 ) return dp[mask];
        int ret = inf;
        for( int i = 1; i <= n; i++ ) {
                if( !( mask &( 1 << i ) ) ) {
                        for( int j = i+1; j <= n; j++ ) {
                                ret = min( ret , 1 + solve( mask|same[i][j] ) );
                        }
                        return dp[mask] = ret;
                }
        }
}
int main( int argc , char const *argv[] ) {
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
                scanf("%d",&n);
                for( int i = 1; i <= n; i++ ) scanf("%d %d",&x[i],&y[i]);
                if( n < 3 ) {
                        printf("Case %d: 1\n",tc);
                        continue;
                }
                memset( same , 0 , sizeof( same ) );
                for( int i = 1; i <= n; i++ ) {
                        for( int j = i+1; j <= n; j++ ) {
                                same[i][j] |= ( 1 << i );
                                same[i][j] |= ( 1 << j );
                                for( int k = j + 1; k <= n; k++ ) {
                                        if( coLinear( i , j , k ) ) same[i][j] |= ( 1 << k );
                                }
                        }
                }
                memset( dp , -1 , sizeof( dp ) );
                printf("Case %d: %d\n",tc,solve( 0 ) );
        }
        return 0;
}











