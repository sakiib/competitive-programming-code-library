#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
const int inf = 1e9;

int n;
int a[ N ];
int sum[ N ];
int dp[ N ][ N ];

/**
spoj MIXTURES
*/

int getsum( int l , int r ) {
        return ( sum[r] - sum[l-1] )%100;
}
int MCM( int l , int r ) {
        if( l >= r ) return 0;
        if( dp[l][r] != -1 ) return dp[l][r];
        int ret = inf;
        for( int i = l; i < r; i++ ) {
                int temp = getsum( l , i ) * getsum( i + 1 , r );
                ret = min( ret , MCM( l , i ) + MCM( i + 1 , r ) + temp );
        }
        return dp[l][r] = ret;
}
int main( int argc , char const *argv[] ) {
        while( scanf("%d",&n) != EOF ) {
                for( int i = 1; i <= n; i++ ) scanf("%d",&a[i]);
                memset( sum , 0 , sizeof( sum ) );
                for( int i = 1; i <= n; i++ ) sum[i] += sum[i-1] + a[i];
                memset( dp , -1 , sizeof( dp ) );
                printf("%d\n",MCM( 1 , n ));
        }
        return 0;
}








