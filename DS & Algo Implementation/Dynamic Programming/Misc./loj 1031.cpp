#include <bits/stdc++.h>
using namespace std;

/**
 Each player can take one or more numbers from the left or right end of the array
but cannot take from both ends at a time. He can take as many consecutive numbers
as he wants during his time. The game ends when all numbers are taken from the array
by the players. The point of each player is calculated by the summation of the numbers,
which he has taken. Each player tries to achieve more points from other. If both players
play optimally and player A starts the game then how much more point can player A get than
player B
*/
const int inf = 1e9;
int n;
int a[ 105 ];
int dp[ 105 ][ 105 ] , sum[ 105 ];

int getsum( int l , int r ) {
        if( l > r ) return 0;
        return sum[r] - sum[l-1];
}
int solve( int l , int r ) {
        if( l > r ) return 0;
        if( l == r ) return a[l];
        int ret = -inf;
        if( dp[l][r] != -inf ) return dp[l][r];
        for( int i = l; i <= r; i++ ) {
                ret = max( ret , getsum( l , i ) - solve( i+1 , r ) );
                ret = max( ret , getsum( i , r ) - solve( l , i -1 ) );
        }
        return dp[l][r] = ret;
}
int main( int argc , char const *argv[] ) {
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
                scanf("%d",&n);
                memset( sum , 0 , sizeof( sum ) );
                for( int i = 1; i <= n; i++ ) scanf("%d",&a[i]);
                for( int i = 1; i <= n; i++ ) sum[i] += ( sum[i-1] + a[i] );
                for( int i = 1; i <= n; i++ ) for( int j = 1; j <= n; j++ ) dp[i][j] = -inf;
                printf("Case %d: %d\n",tc,solve(1,n));
        }
        return 0;
}










