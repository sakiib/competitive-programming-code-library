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

char s[ 100 ];
int len;
LL dp[ 100 ][100 ];

LL solve( int i , int j ) {
        if( i > j ) return 1;
        if( dp[i][j] != -1 ) return dp[i][j];
        LL ret = 0;
        if( s[i] == s[j] ) ret = solve( i + 1 , j ) + solve( i , j - 1 );
        else ret = solve( i + 1 , j ) + solve( i , j - 1 ) - solve( i + 1 , j - 1 );
        return dp[i][j] = ret;
}
int main( int argc , char const *argv[] ) {
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
                scanf("%s",s);
                len = strlen( s );
                memset( dp , -1 , sizeof( dp ) );
                LL ans = solve( 0 , len - 1 ) - 1;
                printf("Case %d: %lld\n",tc,ans);
        }
        return 0;
}











