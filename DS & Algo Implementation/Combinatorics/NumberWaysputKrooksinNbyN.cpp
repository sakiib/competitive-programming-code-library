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

/**

One way to arrive at the correct answer is to view the placement of the rooks in two steps:
First choose the k rows that the rooks will go in, and then, going row by row,
decide which column to place that row's rook in. The first rook has 100 columns to choose from,
the second will have 99, the third 98, and so on. The total is thus

nCk * n!/(n-k)! = (nCk)^2 * k!

*/
int n , k;

long long dp[ 105 ][ 105 ];

long long nCr( int n , int r ) {
        if( r > n ) return 0;
        if( r == 1 ) return dp[n][r] = n;
        if( r == 0 ) return dp[n][r] = 1;
        if( n == r ) return dp[n][r] = 1;
        if( dp[n][r] != -1 ) return dp[n][r];
        return dp[n][r] = nCr( n-1 , r ) + nCr( n-1 , r-1 );
}
int main( int argc , char const *argv[] ) {
        int t;
        scanf("%d",&t);
        memset( dp , -1 , sizeof( dp ) );
        for(int tc = 1; tc <= t; tc++ ) {
                scanf("%d %d",&n,&k);
                LL ans = nCr( n , k );
                LL d = ( n - k );
                for( int i = n; i > d; i-- ) ans *= i;
                printf("Case %d: %lld\n",tc,ans);
        }
        return 0;
}











