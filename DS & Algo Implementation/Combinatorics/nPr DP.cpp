#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
typedef long long LL;

LL nPr[ 105 ][ 105 ];

void Permutation( int SZ ) {
        for( int i = 1; i <= SZ; i++ ) nPr[i][0] = 1;
        for( int i = 1; i <= SZ; i++ ) {
                for( int j = 1; j <= i; j++ ) {
                        nPr[i][j] = ( nPr[i][j - 1]%MOD * (i - j + 1)%MOD )%MOD;
                }
        }
}
int main( ) {

        Permutation( 100 );

        return 0;
}

