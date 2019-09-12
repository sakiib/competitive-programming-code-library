#include <bits/stdc++.h>
using namespace std;

/**
A Sequence G is called PERFECT if elements of G are distinct and one of the two following properties hold :
1. If product of elements of G is a perfect-square then number of elements of G should be even .
2. If product of elements of is not a perfect-square then number of elements of G should be odd .
*/
typedef long long int LL;
const int MOD = 993344777;
const int N = 1e6 + 1;

int n;
int a[ N ];
int cnt[ 62 ];
int mask[ 62 ];
vector <int> prime;
int id[ 62 ];
LL dp[ 62 ][ ( 1 << 17 ) + 1 ][ 2 ][ 2 ];

bool isprime( int x ) {
        for( int i = 2; i*i <= x; i++ ) if( x%i == 0 ) return false;
        return true;
}
LL solve( int cur , int msk , int sz , int taken ) {
        if( cur == 61 ) {
                if( !taken ) return 0;
                if( sz&1 ) return msk != 0;
                else return msk == 0;
        }
        if( dp[cur][msk][sz][taken] != -1 ) return dp[cur][msk][sz][taken] ;
        LL ret = 0;
        if( cnt[cur] == 0 ) {
                ret = ( ret%MOD + solve( cur + 1 , msk , sz%2 , taken )%MOD )%MOD;
        }
        else {
                ret = ( ret%MOD + cnt[cur]%MOD * solve( cur + 1 , msk^mask[cur] , (sz%2+1%2)%2 , 1 )%MOD )%MOD;
                ret = ( ret%MOD + solve( cur + 1 , msk , sz%2 , taken )%MOD )%MOD;
        }
        return dp[cur][msk][sz][taken]  = ret%MOD;
}
int main( int argc , char const *argv[] ) {
        scanf("%d",&n);
        for( int i = 1; i <= n; i++ ) scanf("%d",&a[i]) , cnt[ a[i] ]++;
        prime.push_back( 2 );
        int t = 0;
        id[2] = ++t;
        for( int i = 3; i <= 60; i += 2 ) {
                if( isprime( i ) ) prime.push_back( i ) , id[i] = ++t;
        }
        for( int i = 1; i <= 60; i++ ) {
                int num = i;
                for( auto x : prime ) {
                        if( num%x == 0 ) {
                                mask[i] ^= ( 1 << id[x] );
                                num /= x;
                                while( num%x == 0 ) num /= x ,  mask[i] ^= ( 1 << id[x] );
                        }
                }
                if( num != 1 ) mask[i] ^= ( 1 << id[num] );
        }
        memset( dp , -1 , sizeof( dp ) );
        printf("%lld\n",solve( 1 , 0 , 0 , 0 )%MOD);
        return 0;
}








