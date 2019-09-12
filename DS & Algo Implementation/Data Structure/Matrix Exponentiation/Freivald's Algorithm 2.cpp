#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long uLL;
typedef long long int LL;
typedef pair <int,int> pii;
typedef pair <int,pii> piii;
typedef pair <long long,long long> pll;
typedef pair <long long,pll> plll;
const int N = 1e3 + 5;
const int inf = 1e9;
const long long INF = 1e18;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int MOD = 1000000007;

int n;

struct matrix {
        LL m[ N ][ N ];
};

matrix A , B , C;

LL r[ N ];

bool Freivald( ) {
        for( int i = 1; i <= n; i++ ) r[i] = rand()%MOD;
        LL br[ N ] = {0};
        for( int i = 1; i <= n; i++ ) {
                for( int j = 1; j <= n; j++ ) {
                        br[i] += ( B.m[i][j]%MOD * r[j]%MOD )%MOD , br[i] %= MOD;
                }
        }
        LL cr[ N ] = {0};
        for( int i = 1; i <= n; i++ ) {
                for( int j = 1; j <= n; j++ ) {
                        cr[i] += ( C.m[i][j]%MOD * r[j]%MOD )%MOD , cr[i] %= MOD;
                }
        }
        LL axbr[ N ] = {0};
        for( int i = 1; i <= n; i++ ) {
                for( int j = 1; j <= n; j++ ) {
                        axbr[i] += ( A.m[i][j]%MOD * br[j]%MOD )%MOD , axbr[i] %= MOD;
                }
        }
        for( int i = 1; i <= n; i++ ) if( axbr[i] != cr[i] ) return false;
        return true;
}
bool Solve( ) {
        for( int i = 1; i <= 5; i++ ) if( !Freivald( ) ) return false;
        return true;
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( NULL );
        cin >> n;
        for( int i = 1; i <= n; i++ ) {
                for( int j = 1; j <= n; j++ ) {
                        cin >> A.m[i][j];
                }
        }
        for( int i = 1; i <= n; i++ ) {
                for( int j = 1; j <= n; j++ ) {
                        cin >> B.m[i][j];
                }
        }
        for( int i = 1; i <= n; i++ ) {
                for( int j = 1; j <= n; j++ ) {
                        cin >> C.m[i][j];
                }
        }
        if( Solve( ) ) cout << "YES" << endl;
        else cout << "NO" << endl;
        return 0;
}












