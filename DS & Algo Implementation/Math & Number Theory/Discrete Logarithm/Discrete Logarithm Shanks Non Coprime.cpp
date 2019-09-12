#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

/**
incase of gp hash table:
gp_hash_table <LL,LL> Hash;
auto it = hash.find(now);
if(it != hash.end())
return i * mid - it->second + cnt;
*/

/**
 Consider Eqn : a^x = b % m.
 Find any solution for x.
 works even if a & m are not coprime.
 runtime : sqrt(m) log(m)
 */
typedef long long int LL;

struct discrete_logarithm_shanks {
        inline LL bigmod( LL b , LL p , LL mod ) {
                LL res = 1%mod , x = b%mod;
                while( p ) {
                        if( p & 1 ) res = ( res * x )%mod;
                        x = ( x * x )%mod; p >>= 1;
                }
                return res%mod;
        }
        inline LL gcd( LL a , LL b ) { return b? gcd( b , a % b ) : a; }
        inline LL bsgs( LL a , LL b , LL p ) {
                a %= p , b %= p;
                if( b == 1 ) return 0;
                LL cnt = 0 , t = 1;
                for( LL g = gcd( a , p ); g != 1; g = gcd( a , p ) ) {
                        if( b % g ) return -1;
                        p /= g , b /= g , t = t * a / g % p;
                        ++cnt;
                        if( b == t ) return cnt;
                }
                map <LL,LL> Hash;
                LL m = LL( sqrt(1.0 * p) + 1 ) , base = b;
                for( LL i = 0; i != m; ++i ) {
                        Hash[ base ] = i; base = base * a % p;
                }
                base = bigmod( a , m , p ); LL now = t;
                for( LL i = 1; i <= m + 1; ++i ) {
                        now = now * base % p;
                        if( Hash.count(now) ) return (i*m - Hash[now] + cnt);
                }
                return -1;
        }
} ds;

int main( int argc , char const *argv[] ) {
        LL a , b , m;
        int t;
        scanf("%d",&t);
        while( t-- ) {
                scanf("%lld %lld %lld",&a,&b,&m);
                LL ans = ds.bsgs( a , b , m );
                if( ans == -1 ) printf("No Solution\n");
                else printf("%lld\n",ans);
        }
        return 0;
}






