#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long uLL;
typedef long long int LL;
typedef pair <int,int> pii;
typedef pair <int,pii> piii;
typedef pair <long long,long long> pll;
typedef pair <long long,pll> plll;
const int N = 1e5 + 5;
const int inf = 1e9;
const long long INF = 1e18;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int MOD = 1000000007;

LL nCr[ 1005 ][ 1005 ];

void BinomCoeff( ) {
        for( int i = 0; i < 1005; i++ ) nCr[i][0] = 1;
        for( int i = 1; i < 1005; i++ ) {
                for( int j = 1; j <= i; j++ ) {
                        nCr[i][j] = ( nCr[i-1][j] + nCr[i-1][j-1] );
                }
        }
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( NULL );
        BinomCoeff( );
        return 0;
}











