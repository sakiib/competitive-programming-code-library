#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long uLL;
typedef long long int LL;
typedef pair <int,int> pii;
typedef pair <int,pii> piii;
typedef pair <long long,long long> pll;
typedef pair <long long,pll> plll;
const int N = 505;
const int inf = 1e9;
const long long INF = 1e18;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int MOD = 1000000007;

/**
oth directions. Greg loves playing with the graph and now he has invented a new game:

The game consists of n steps.
On the i-th step Greg removes vertex number xi from the graph. As Greg removes a vertex,
he also removes all the edges that go in and out of this vertex.

Before executing each step, Greg wants to know the sum of lengths of the shortest paths
between all pairs of the remaining vertices. The shortest path can go through any remaining
vertex. In other words, if we assume that d(i, v, u) is the shortest path between vertices
v and u in the graph that formed before deleting vertex xi, then Greg wants to know the
value of the following sum:
*/

int n;
int a[ N ];
int cost[ N ][ N ];
LL ans[ N ];
bool added[ N ];

int dp[ N ][ N ];

LL addNode( int k ) {
        added[k] = true;
        LL sum = 0;
        for( int i = 1; i <= n; i++ ) {
                for( int j = 1; j <= n; j++ ) {
                        cost[i][j] = min( cost[i][j] , cost[i][k] + cost[k][j] );
                        if( added[i] && added[j] ) sum += cost[i][j];
                }
        }
        return sum;
}
void fw( ) {
        for( int k = 1; i <= n; k++ ) {
                for( int i = 1; i <= n; i++ ) {
                        for( int j = 1; j <= n; j++ ) {
                                dp[i][j] = min( dp[i][j] , dp[i][k] + dp[k][j] );
                        }
                }
        }
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( NULL );
        cin >> n;
        for( int i = 1; i <= n; i++ ) {
                for( int j = 1; j <= n; j++ ) {
                        cin >> cost[i][j];
                }
        }
        for( int i = 1; i <= n; i++ ) cin >> a[i];
        for( int i = n; i >= 1; i-- ) ans[i] = addNode( a[i] );
        for( int i = 1; i <= n; i++ ) cout << ans[i]<< " ";
        return 0;
}










