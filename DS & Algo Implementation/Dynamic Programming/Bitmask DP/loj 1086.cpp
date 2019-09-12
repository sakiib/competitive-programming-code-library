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

int  Set( int N , int pos )    { return N |= ( 1 << pos ); }
int  Reset( int N , int pos )  { return N = N & ~( 1 << pos ); }
bool Check( int N , int pos )  { return (bool)( N & ( 1 << pos ) );}
int  Toggle( int N , int pos ) { return ( N ^= ( 1 << pos ) ); }

int n , m , mask;
int cost[ 15 ][ 15 ];
int degree[ 15 ];
LL dp[ 1 << 15 ];

void Reset( ) {
        mask = 0;
        for( int i = 0;i < n; i++ ) {
                for( int j = 0; j < n; j++ ) {
                        if( i == j ) cost[i][j] = cost[j][i] = 0;
                        else cost[i][j] = cost[j][i] = inf;
                }
        }
        memset( degree , 0 , sizeof(degree) );
}
void Floyd_Warshall( ) {
        for( int k = 0; k < n; k++ ) {
                for( int j = 0; j < n; j++ ) {
                        for( int i = 0; i < n; i++ ) {
                                cost[i][j] = min( cost[i][j] , cost[i][k] + cost[k][j] );
                        }
                }
        }
}
LL solve( int mask ) {
        if( mask == 0 ) return 0;
        if( dp[mask] != -1 ) return dp[mask];
        LL ret = inf;
        for( int i = 0; i < n; i++ ) {
                for( int j = i+1; j < n; j++ ) {
                        if( Check( mask , i ) && Check( mask , j ) ) {
                                int tmask = Reset( mask , i );
                                tmask = Reset( tmask , j );
                                ret = min( ret , solve( tmask )+cost[i][j] );
                        }
                }
        }
        return dp[mask] = ret;
}
int main( int argc , char const *argv[] ) {
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
                scanf("%d %d",&n,&m);
                Reset( );
                LL ans = 0;
                for( int i = 1; i <= m; i++ ) {
                        int u , v , w;
                        scanf("%d %d %d",&u,&v,&w);
                        ans += w;
                        --u , --v;
                        degree[u]++ , degree[v]++;
                        cost[u][v] = min( cost[u][v] , w );
                        cost[v][u] = min( cost[v][u] , w );
                }
                Floyd_Warshall( );
                for( int i = 0; i < n; i++ ) {
                        if( degree[i]&1 ) mask = Set( mask , i );
                }
                memset( dp , -1 , sizeof(dp) );
                ans += solve( mask );
                printf("Case %d: %lld\n",tc,ans);
        }
        return 0;
}






