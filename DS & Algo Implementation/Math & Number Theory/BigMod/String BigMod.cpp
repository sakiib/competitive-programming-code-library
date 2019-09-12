#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
const int MOD = 1000000007;

/**
 This works for any mod val.
 but if mod is prime then , we can use fermet's little theorem.

 theorem : A^(p-1) = 1%p
           B%(p-1) = B%(1e9+7 - 1)

 LL x = b%mod;
 LL y = p&(mod-1);
 LL ans = ( x^y )%mod
 */

LL StringMod( string s , LL m ) {
        LL ret = 0;
        for( int i = 0; i < s.size(); i++ ) {
                ret = ( ( ret%m * 10%m )%m + ( s[i]-'0' )%m )%m;
        }
        return ret%m;
}
LL BigMod ( LL a , LL p , LL m ) {
        LL res = 1 % m, x = a % m;
        while ( p ) {
                if ( p & 1 ) res = ( res * x ) % m;
                x = ( x * x ) % m; p >>= 1;
        }
        return res%m;
}
int main( int argc , char const *argv[] ) {
        string b , p;
        int t;
        cin >> t;
        while( t-- ) {
                cin >> b >> p;
                LL base = StringMod( b , MOD );
                LL ans = 1;
                int len = p.size()-1;
                for( int i = 0; i < p.size(); i++ ) {
                        LL x = BigMod( ans , 10 , MOD );
                        x = x * BigMod( base , p[i]-'0' , MOD );
                        ans = x % MOD;
                }
                cout << ans << endl;
        }
        return 0;
}

