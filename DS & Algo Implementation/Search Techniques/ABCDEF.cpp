#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(V) V.begin(), V.end()
#define Unique(V) sort(all(V)), V.erase(unique(all(V)), V.end())
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long int LL;
const int N = 1e5 + 5;

/**
d&c with bs
: d != 0 && ab+c = (e+f)*d
*/

int A[ 105 ];

int main( ) {
        FIO;
        #ifdef OFFLINE
            freopen( "input.txt" , "r" , stdin );
        #endif // OFFLINE
        int n;
        cin >> n;
        for( int i = 1; i <= n; i++ ) cin >> A[i];
        vector <int> X , Y;
        for( int a = 1; a <= n; a++ ) {
                for( int b = 1; b <= n; b++ ) {
                        for( int c = 1; c <= n; c++ ) {
                                X.push_back( A[a] * A[b] + A[c] );
                        }
                }
        }
        for( int d = 1; d <= n; d++ ) {
                for( int e = 1; e <= n; e++ ) {
                        for( int f = 1; f <= n; f++ ) {
                                if( A[d] != 0 ) Y.push_back( A[d] * ( A[e] + A[f] ) );
                        }
                }
        }
        sort( all(X) );
        sort( all(Y) );
        LL ans = 0;
        for( auto x : X ) ans += upper_bound( all(Y) , x ) - lower_bound( all(Y) , x );
        cout << ans << endl;
        return 0;
}







