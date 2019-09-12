#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
typedef pair < int , int > ii;
const int inf = 1e9;
const LL INF = 1e18;
const int N = 1e5 + 5;
const int mod = 1000007;
const double eps = 1e-8;
const double pi = acos( -1.0 );

/**
 Nlog(N)
 */

LL a[ N ];
LL k , c , n;

LL solveBrute( ) {
        LL ret = 0;
        for( int i = 0; i < n; i++ ) {
                for( int j = i+1; j < n; j++ ) {
                        ret += abs( a[i] - a[j] );
                }
        }
        return ret;
}
LL solve( ) {
        sort( a , a+n );
        LL ret = 0;
        for( int i = 0; i < n; i++ ) {
                ret += ( 1LL * i * a[i] - 1LL * ( n - 1 - i ) * a[i] );
        }
        return ret;
}
int main( int argc , char const *argv[] ) {
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ){
                scanf("%lld %lld %lld %lld",&k,&c,&n,&a[0]);
                a[0] % mod;
                for( int i = 1; i < n; i++ ) a[i] = ( k%mod * a[i-1]%mod + c%mod )%mod;

                //printf("Case %d: %lld\n",tc,solveBrute());
                printf("Case %d: %lld\n",tc,solve());
        }
        return 0;
}






