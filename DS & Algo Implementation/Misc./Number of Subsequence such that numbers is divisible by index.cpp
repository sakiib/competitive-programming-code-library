#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
const int N = 1e5 + 5;
const int MOD = 1000000007;
/**
saw the Editorial & the Code , just trying to upsolve
*/

int n , a[ N ];
vector <int> d[ 10*N ];
LL dp[ 10*N ];

void add( LL &x , LL y ) {
        x = ( x%MOD + y%MOD )%MOD;
}
vector <int> Factorize( int val ) {
        vector <int> ret;
        for( int i = 1; i * i <= val; i++ ) {
                if( val%i == 0 ) {
                        ret.push_back( i );
                        if( val/i != i ) ret.push_back( val/i );
                }
        }
        return ret;
}
int main( int argc , char const *argv[] ) {
        ios_base :: sync_with_stdio( false ); cin.tie( NULL );
        cin >> n;
        for(int i = 1; i <= n; i++ ) cin >> a[i];
        dp[0] = 1LL;
        for( int i = 1; i <= n; i++ ) {
                vector <int> V = Factorize( a[i] );
                sort( V.begin() , V.end() );
                reverse( V.begin() , V.end() );
                for( auto x : V ) {
                        add( dp[x] , dp[x-1] );
                }
        }
        LL ans = 0;
        for( int i = 1; i <= n; i++ ) add( ans , dp[i] );
        cout << ans << endl;
        return 0;
}
















