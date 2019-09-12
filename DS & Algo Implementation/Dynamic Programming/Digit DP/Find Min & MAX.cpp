#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
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

#define Set( N , pos ) ( N |= ( 1LL << pos ) )
#define Check( N , pos ) ( !(( N&( 1LL << pos )) == 0 ) )
#define Reset( N , pos ) ( N = ( N&(~( 1LL << pos )) ) )

/**
given numbers x,l,r find the smallest and greatest ugly number.
A non-negative integer is called ugly if and only if a ^ x >= l && <= r
find MIN & MAX ugly
*/
LL x , l , r;
LL dp[ 65 ][ 2 ][ 2 ];

LL MAX( int idx , bool eqlo , bool eqhi  ) {
        if( idx < 0 ) return 0;
        if( dp[idx][eqlo][eqhi] != -INF ) return dp[idx][eqlo][eqhi];
        int lo = 0 , hi = 1;
        if( eqlo ) lo = Check( l , idx );
        if( eqhi ) hi = Check( r , idx );
        int cur = Check( x , idx );
        LL ret = -2*INF;
        for( int i = 0; i <= 1; i++ ) {
                if( (cur^i) >= lo && (cur^i) <= hi ) {
                        ret = max( ret , (1LL<<idx)*i + MAX( idx - 1 ,
                                   eqlo&&( (cur^i) == lo ) , eqhi&&( (cur^i) == hi ) ) );
                }
        }
        return dp[idx][eqlo][eqhi] = ret;
}
LL MIN( int idx , bool eqlo , bool eqhi  ) {
        if( idx < 0 ) return 0;
        if( dp[idx][eqlo][eqhi] != -INF ) return dp[idx][eqlo][eqhi];
        int lo = 0 , hi = 1;
        if( eqlo ) lo = Check( l , idx );
        if( eqhi ) hi = Check( r , idx );
        int cur = Check( x , idx );
        LL ret = 2*INF;
        for( int i = 0; i <= 1; i++ ) {
                if( (cur^i) >= lo && (cur^i) <= hi ) {
                        ret = min( ret , (1LL<<idx)*i + MIN( idx - 1 ,
                                   eqlo&&( (cur^i) == lo ) , eqhi&&( (cur^i) == hi ) ) );
                }
        }
        return dp[idx][eqlo][eqhi] = ret;
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( nullptr );

        cin >> x >> l >> r; /// find MIN & MAX val such that val^x is in L to R

        for( int i = 0; i < 65; i++ )
            for( int j = 0; j <= 1; j++ )
                for( int k = 0; k <= 1; k++ ) dp[i][j][k] = -INF;

        cout << MIN( 59 , 1 , 1  ) << " ";

        for( int i = 0; i < 65; i++ )
            for( int j = 0; j <= 1; j++ )
                for( int k = 0; k <= 1; k++ ) dp[i][j][k] = -INF;

        cout << MAX( 59 , 1 , 1 ) << endl;
        return 0;
}












