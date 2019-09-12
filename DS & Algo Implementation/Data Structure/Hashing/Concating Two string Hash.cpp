#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
const int N = 2e6 + 5;

const int MOD = 1000000007;
const int Base = 43;

LL Pow[ N ];
string s[ N ];
int Len[ N ];
LL FHash[ N ] , BHash[ N ];

void genPower( ) {
        Pow[0] = 1LL;
        for( int i = 1; i < N; i++ ) Pow[i] = ( Pow[i-1] * Base ) % MOD;
}
void calc( int id , string s , int len ) {
        LL fHash = 0;
        for( int i = 0; i < len; i++ ) {
                fHash += ( Pow[i] * s[i] ) % MOD , fHash %= MOD;
        }
        LL bHash = 0;
        for( int i = len - 1; i >= 0; i-- ) {
                bHash += ( Pow[len-1-i] * s[i] ) % MOD , bHash %= MOD;
        }
        FHash[id] = fHash;
        BHash[id] = bHash;
}
LL solve( int x , int y ) {
        LL f1 = FHash[x] , b1 = BHash[x] , f2 = FHash[y] , b2 = BHash[y];
        LL totF = ( f1 % MOD + Pow[ Len[x] ] % MOD * f2 % MOD ) % MOD;
        LL totB = ( b2 % MOD + Pow[ Len[y] ] % MOD * b1 % MOD ) % MOD;
        return ( totF == totB );
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( NULL );
        genPower( );

        int n;
        cin >> n;
        for( int i = 1; i <= n; i++ ) {
                cin >> Len[i] >> s[i];
                calc( i , s[i] , Len[i] );
        }
        LL ans = 0;
        for( int i = 1; i <= n; i++ ) {
                for( int j = 1; j <= n; j++ ) {
                        ans += solve( i , j );
                }
        }
        cout << ans << endl;
        return 0;
}











