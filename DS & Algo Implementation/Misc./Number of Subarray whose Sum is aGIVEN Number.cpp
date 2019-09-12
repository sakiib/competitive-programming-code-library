#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
const int N = 1e6 + 5;

int k , l;
string s;
LL sum[ N ];
unordered_map <LL,LL> dp;
LL ans;

int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio(false); cin.tie(NULL);
        cin >> k >> s;
        l = s.size();
        dp.reserve( N );
        dp.max_load_factor( 0.25 );
        for( int i = 0; i < l; i++ ) {
                sum[i] += sum[i-1] + ( s[i] - '0' );
                dp[ sum[i] ]++;
        }
        for( int i = 0; i < l; i++ ) {
                ans += dp[ k + sum[i-1] ];
                dp[ sum[i] ]--;
        }
        cout << ans << endl;
        return 0;
}








