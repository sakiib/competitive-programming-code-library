#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;
typedef long long LL;

/**
Find the total number of sextuples  that satisfy:
(ab+c)/d - e = f
same number can be a,b,c,d,e,f but d != 0
we calculate (ab+c) first , then (e+f)*d
*/

int n;
int a[ N ];
unordered_map <LL,LL> cnt;

int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( NULL );
        cin >> n;
        for( int i = 1; i <= n; i++ ) cin >> a[i];
        for( int i = 1; i <= n; i++ ) {
                for( int j = 1; j <= n; j++ ) {
                        for( int k = 1; k <= n; k++ ) {
                               cnt[ a[i]*a[j] + a[k] ]++; /// ( a * b ) + c
                        }
                }
        }
        LL ans = 0;
        for( int i = 1; i <= n; i++ ) {
                for( int j = 1; j <= n; j++ ) {
                        for( int k = 1; k <= n; k++ ) {
                                if( a[k] != 0 ) {
                                        ans += ( cnt[ (a[i] + a[j] ) * a[k] ] ); /// ( e + f ) * d
                                }
                        }
                }
        }
        cout << ans << endl;
        return 0;
}










