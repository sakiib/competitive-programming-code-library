#include <bits/stdc++.h>
using namespace std;
/// for multiple testcases clear reach only.
typedef long long int LL;
const int N = 2e5 + 5;
const int MOD = 1000000007;

#define x first
#define y second

int r , c , k;
pair <int,int> a[ N ];
LL Fact[ N ];
LL reach[ N ];
LL modInv[ N ];

bool cmp( pair <int,int> x , pair <int,int> y ) {
        if( x.first == y.first ) return x.second < y.second;
        return x.first < y.first;
}
LL BigMod( LL b , LL p , LL mod ) {
        LL res = 1 % mod , x = b % mod;
        while ( p ) {
                if ( p&1 ) res = ( res * x ) % mod;
                x = ( x * x ) % mod;
                p >>= 1;
        }
        return ( res % mod );
}
LL ModInv( LL val , LL mod ) {
        return BigMod( val , mod - 2 , mod );
}
void preCalc( ) {
        Fact[0] = 1LL;
        for( int i = 1; i < 2*N; i++ ){
                Fact[i] = ( Fact[i-1] % MOD * i %MOD ) % MOD;
        }
        modInv[N-1] = ModInv( Fact[N-1] , MOD );
        for( int i = N-2; i >= 0; i-- ) {
                modInv[i] = ( modInv[i+1] % MOD * (i+1) % MOD ) % MOD;
        }
}
LL nCr( LL n , LL r ) {
        if( r > n ) return 0;
        LL val = Fact[n];
        val = ( val % MOD * modInv[r] % MOD ) % MOD;
        val = ( val % MOD * modInv[n-r] % MOD ) % MOD;
        return val;
}
LL Ways( int x1 , int y1 , int x2 , int y2 ) {
        if( x1 > x2 || y1 > y2 ) return 0;
        LL step = ( x2 - x1 + y2 - y1 );
        LL r = ( y2 - y1 );
        return nCr( step , r );
}
void computeDP( ) {
        reach[1] = Ways( 1 , 1 , a[1].x , a[1].y );
        for( int i = 2; i <= k; i++ ) {
                reach[i] = Ways( 1 , 1 , a[i].x , a[i].y );
                LL subtract = 0;
                for( int j = 1; j < i; j++ ) {
                        subtract += reach[j] * Ways( a[j].x , a[j].y , a[i].x , a[i].y );
                        subtract = subtract % MOD;
                }
                reach[i] -= subtract , reach[i] += MOD , reach[i] %= MOD;
        }
}
int main( int argc , char const *argv[] ) {
        preCalc( );
        scanf("%d %d %d",&r,&c,&k);
        for( int i = 1; i <= k; i++ ) scanf("%d %d",&a[i].x,&a[i].y);
        sort( a+1 , a+k+1 , cmp );
        computeDP( );
        LL ans = Ways( 1 , 1 , r , c );
        LL subtract = 0;
        for( int i = 1; i <= k; i++ ) {
                subtract += reach[i] * Ways( a[i].x , a[i].y , r , c );
                subtract %= MOD;
        }
        ans -= subtract , ans += MOD , ans %= MOD;
        printf("%lld\n",ans);
        return 0;
}







