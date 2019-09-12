#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
const int MOD = 1000000007;

#define   Check( N , p ) ( !( ( N & ( 1 << p ) ) == 0 ) )
#define   ON( N , p )    ( N = N | ( 1 << p ) )
#define   OFF( N , p )   ( N = N & ~( 1 << p ) )

/**
An N-based number is beautiful if all of the digits from 0 to N − 1 are used in that number and the
difference between any two adjacent digits is exactly 1 (one). For example, 9876543210 is a 10-based
beautiful number. You have to calculate the number beautiful numbers that has got atmost M digits
*/

int n , m;
LL dp[ 105 ][ 1 << 10 ][ 11 ];

LL go( int idx , int mask , int last ) {
        if( idx > m ) return ( mask == ( 1 << n ) - 1 );
        if( dp[idx][mask][last] != -1 ) return  dp[idx][mask][last];
        LL ret = 0;
        if( mask == ( 1 << n ) - 1 ) ret++;
        if( last + 1 <= n - 1 ) ret += go( idx + 1 , mask|( 1 << (last+1) ) , last + 1 );
        if( last - 1 >= 0 ) ret += go( idx + 1 , mask|( 1 << (last-1) ) , last - 1 );
        return dp[idx][mask][last] = ret%MOD;
}
LL solve( ) {
        memset( dp , -1 , sizeof( dp ) );
        LL ans = 0;
        int mask = 0;
        for( int i = 1; i <= n - 1; i++ ) ans += go( 2 , 1 << i , i ) , ans %= MOD;
        return ans%MOD;
}
int main( int argc , char const *argv[] ) {
        int t;
        scanf("%d",&t);
        while( t-- ) {
                scanf("%d %d",&n,&m);
                printf("%lld\n",solve( ));
        }
        return 0;
}










