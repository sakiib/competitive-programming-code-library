#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define All(V) V.begin(),V.end()
#define Unique(V) sort( All(V)),V.erase( unique( All(V) ),V.end() )
#define Fast_IO ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long int LL;
const int N = 1e5 + 5;
const int inf = 1e9;
const LL INF = 1e18;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int MOD = 1000000007;

/**
 sum of -> 1%mod + 2%mod + 3%mod + 4%mod + ... + n%mod;
 */

int main( int argc , char const *argv[] ) {
        Fast_IO;
        int t;
        cin >> t;
        while( t-- ) {
                LL n , m;
                cin >> n >> m;
                if( m > n ) {
                        LL ans = n*(n+1)/2;
                        cout << ans << endl;
                }
                else {
                        LL full = n/m;
                        LL ans = full * m*(m-1)/2;
                        LL baki = n%m;
                        ans += ( baki*(baki+1)/2 );
                        cout << ans << endl;
                }
        }
        return 0;
}






