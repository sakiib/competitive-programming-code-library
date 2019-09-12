#include <bits/stdc++.h>
using namespace std;

#define Fast_IO ios_base::sync_with_stdio(0); cin.tie(0);

typedef unsigned long long uLL;
typedef long long int LL;
const int N = 1e5 + 5;
const int inf = 1e9;
const LL INF = 1e18;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int MOD = 1000000007;

int coin[ N ];
int dp[ N ];
int taka = 100;

int main( int argc , char const *argv[] ) {
        int n;
        scanf("%d",&n);
        for( int i = 1; i <= n; i++ ) scanf("%d",&coin[i]);
        for( int i = 1; i <= taka; i++ ) dp[i] = inf;
        dp[0] = 0;
        for( int i = 1; i <= n; i++ ) {
                for( int j = coin[i]; j <= taka; j++ ) {
                        dp[j] = min( dp[j] , dp[ j - coin[i] ] + 1 );
                }
        }
        cout << dp[10] << endl;
        return 0;
}







