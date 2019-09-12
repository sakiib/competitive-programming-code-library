#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template <typename T> using
Treap = tree <T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef unsigned long long uLL;
typedef long long int LL;
typedef pair <int,int> pii;
typedef pair <long long,long long> pll;
const int N = 1e5 + 5;
const int inf = 1e9;
const long long INF = 1e18;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int MOD = 1000000007;

/**
  k = x^y%z
  given , x , z , k find smallest y
 */

struct DISCRETE_LOGARITHM_SHANKS {
        inline LL BigMod ( LL b , LL p , LL mod ) {
                LL res = 1 % mod , x = b % mod;
                while ( p ) {
                        if ( p & 1 ) res = ( res * x ) % mod;
                        x = ( x * x ) % mod; p >>= 1;
                }
                return ( res % mod );
        }
        inline LL GCD( LL a , LL b ) { return b? GCD( b , a % b ) : a; }
        inline LL Baby_Step_Giant_Step( LL a , int b , int p ) {
                a %= p , b %= p;
                if( b == 1 ) return 0;
                LL cnt = 0 , t = 1;
                for( LL g = GCD( a , p ); g != 1; g = GCD( a , p ) ) {
                        if( b % g ) return -1;
                        p /= g , b /= g , t = t * a / g % p;
                        ++cnt;
                        if( b == t ) return cnt;
                }
                map <LL,LL> Hash;
                LL m = LL( sqrt(1.0 * p) + 1 ) , base = b;
                for( int i = 0; i != m; ++i ) {
                        Hash[ base ] = i; base = base * a % p;
                }
                base = BigMod( a , m , p ); LL now = t;
                for(int i = 1; i <= m + 1; ++i) {
                        now = now * base % p;
                        if( Hash.count(now) ) return ( i * m - Hash[now] + cnt );
                }
                return -1;
        }
} ds;

int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( NULL );
        LL x, z , k;
        while( cin >> x >> z >> k ) {
                if( x == 0 && z == 0 && k == 0 ) break;
                LL ans = ds.Baby_Step_Giant_Step( x , k , z );
                if( ans == -1 ) cout << "No Solution" << endl;
                else cout << ans << endl;
        }
        return 0;
}










