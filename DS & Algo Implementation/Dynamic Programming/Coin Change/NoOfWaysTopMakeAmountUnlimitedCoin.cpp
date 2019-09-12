#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
typedef pair < int , int > ii;
const int inf = 1e9;
const LL INF = 1e18;
const int N = 1e5 + 5;
const int mod = 1000000007;
const double eps = 1e-8;
const double pi = acos( -1.0 );

int coin[] = { 1 , 5 , 10 , 25 , 50 };
LL dp[ 5 ][ 30001 ];
LL ways[ 30001 ];

/**
 1 coin can be used many times.
 number of ways to make an amount.
 */

LL go( int id , int taka ) {
        if( taka < 0 ) return 0;
        if( taka == 0 ) return 1LL;
        if( id >= 5 ) return ( taka == 0 );
        if( dp[id][taka] != -1 ) return dp[id][taka];
        LL x = 0 , y = 0;
        x += go( id , taka - coin[id] );
        y += go( id + 1 , taka );
        return dp[id][taka] = x + y;
}
int main( int argc , char const *argv[] ) {
        memset( dp , -1 , sizeof(dp) );
        for( int i = 30000; i >= 0; i-- ) ways[i] = go( 0 , i );
        int n;
        while( scanf("%d",&n) != EOF ) {
                if( ways[n] > 1 )
                printf("There are %lld ways to produce %d cents change.\n",ways[n],n);
                else
                printf("There is only 1 way to produce %d cents change.\n",n);
        }
        return 0;
}



