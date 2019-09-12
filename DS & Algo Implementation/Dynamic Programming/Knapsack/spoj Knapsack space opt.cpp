#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
typedef unsigned long long uLL;
typedef long long int LL;
typedef pair <int,int> pii;
typedef pair <int,pii> piii;
typedef pair <long long,long long> pll;
typedef pair <long long,pll> plll;
const int N = 2005;
const int inf = 1e9;
const long long INF = 1e18;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int MOD = 1000000007;

int n;
int cap;
int wt[ N ] , val[ N ];
int dp[ N ][ N ];

int main( int argc , char const *argv[] ) {
        while( scanf("%d %d",&cap,&n) != EOF ) {
                for( int i = 1; i <= n; i++ ) {
                        scanf("%d %d",&wt[i],&val[i]);
                }
                for( int i = 1; i <= n; i++ ) {
                        for( int j = 0; j <= 2000; j++ ) {
                                dp[i][j] = -inf;
                        }
                }
                dp[0][0] = 0;
                for( int i = 1; i <= n; i++ ) {
                        for( int j = 0; j <= 2000; j++ ) {
                                if( wt[i] <= j ) {
                                        dp[i][j] = max( dp[i-1][j] , dp[i-1][j-wt[i]] + val[i] );
                                }
                                else {
                                        dp[i][j] = dp[i-1][j];
                                }
                        }
                }
                printf("%d\n",dp[n][cap]);
        }
        return 0;
}











