#include <bits/stdc++.h>
using namespace std;

#define Fast_IO ios_base::sync_with_stdio(0); cin.tie(0);

typedef unsigned long long uLL;
typedef long long int LL;
const int N = 1e5 + 5;
const int inf = 1e9;
const LL INF = 1e18;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int MOD = 1000000007;

LL fact[ 3*N ];

LL BigMod ( LL b , LL p , LL mod ) {
        LL res = 1 % mod , x = b % mod;
        while ( p ) {
                if ( p & 1 ) res = ( res * x ) % mod;
                x = ( x * x ) % mod; p >>= 1;
        }
        return ( res%mod );
}
LL ModInv( LL val , LL mod ) {
        return BigMod( val , mod - 2 , mod );
}
void gen_fact( ) {
        fact[0] = 1LL;
        for( int i = 1; i < 3*N; i++ ) fact[i] = ( fact[i-1]%MOD * i%MOD )%MOD;
}
LL nCr( LL n , LL r ) {
        //cout << "calc : " << n << " " << r << endl;
        LL up = fact[n];
        LL down = ( fact[r]%MOD * fact[n-r]%MOD )%MOD;
        LL inv = ModInv( down , MOD );
        LL ret = (up%MOD * inv%MOD)%MOD;
        return ret;
}
int main( int argc , char const *argv[] ) {
        Fast_IO;
        gen_fact();
        int t;
        cin >> t;
        while( t-- ) {
                int r , c;
                cin >> r >> c;
                int obs_r , obs_c;
                cin >> obs_r >> obs_c;
                LL right = c - 1 , down = r - 1;
                LL tot = nCr( right + down , right ); // total ways from (1,1) to (r,c)
                //cout <<"tot : "<< tot << endl;
                right = obs_c - 1 , down = obs_r - 1;
                LL bad_a = nCr( right + down , right ); // ways from (1,1) to obstacle (obs_r,obs_c)
                //cout << bad_a << endl;
                right = c - obs_c , down = r - obs_r;
                //cout << right << " " << down << endl;
                LL bad_b = nCr( right + down , right ); // ways from (obs_r,obs_c) to (r,c)
                //cout << bad_b << endl;
                LL bad = (bad_a%MOD * bad_b%MOD)%MOD; // total bad ways due to obstackle
                cout << (tot - bad + MOD)%MOD << endl;
        }
        return 0;
}







