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

int n;
LL l , r;
LL cnt[ 5 ];
LL dp[ 2*N ][ 5 ];

LL solve( int idx , int r ) {
        if( idx > n ) return r%3 == 0;
        if( dp[idx][r] != -1 ) return dp[idx][r];
        LL ret = 0;
        for( int i = 0; i < 3; i++ ) ret += solve( idx + 1 , (r+i)%3 ) * cnt[i];
        return dp[idx][r] = ret%MOD;
}
/// This is the one...
LL calc( LL x , int rem ) {
        return ( x + 3 - rem )/3; /// # of integers from 1 to x , reminder rem div by 3
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( nullptr );
        cin >> n >> l >> r;
        cnt[0] = calc( r , 0 ) - calc( l - 1 , 0 );
        cnt[1] = calc( r , 1 ) - calc( l - 1 , 1 );
        cnt[2] = calc( r , 2 ) - calc( l - 1 , 2 );
        memset( dp , -1 , sizeof( dp ) );
        cout << solve( 1 , 0 ) << endl;
        return 0;
}











