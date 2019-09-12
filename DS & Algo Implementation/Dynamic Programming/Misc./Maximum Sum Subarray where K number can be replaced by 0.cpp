#include <bits/stdc++.h>
using namespace std;

const int N = 5005;
const int inf = 1e9;

int n , k;
int a[ N ];
int dp[ N ][ N ];

int solve( int idx , int rem ) {
        if( idx > n ) return 0;
        if( dp[idx][rem] != -1 ) return dp[idx][rem];
        int ret = -inf;
        if( rem > 0 ) {
                ret = solve( idx + 1 , rem - 1 );
                ret = max( ret , solve( idx + 1 , rem ) + a[idx] );
        }
        else {
                ret = max( ret , solve( idx + 1 , rem ) + a[idx] );
        }
        return dp[idx][rem] = max( ret , a[idx] ); /// coz ekta nitei hobe
}
int solve( int idx , int rem ) {
        if( idx > n ) return 0;
        if( dp[idx][rem] != -1 ) return dp[idx][rem];
        int ret = -inf;
        if( a[idx] < 0 && rem > 0 ) ret = solve( idx + 1 , rem - 1 );
        ret = max( ret , solve( idx + 1 , rem ) + a[idx] );
        return dp[idx][rem] = max( ret , a[idx] );
}
int main( int argc , char const *argv[] ) {
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
                scanf("%d %d",&n,&k);
                for( int i = 1; i <= n; i++ ) scanf("%d",&a[i]);
                memset( dp , -1 , sizeof( dp ) );
                int ans = -inf;
                for(int i = 1; i <= n; i++ ) ans = max( ans, solve( i , k ) );
                printf("Case %d: %d\n",tc,ans);
        }
        return 0;
}











