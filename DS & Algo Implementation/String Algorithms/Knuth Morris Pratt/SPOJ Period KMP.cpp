#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
typedef pair < int , int > ii;
const int inf = 1e9;
const LL INF = 1e18;
const int N = 1e5 + 5;
const int mod = 1000000007;
const double eps = 1e-8;
const double pi = acos( -1.0 );

int Failure[ 10*N ];

void Failure_Function( string pattern , int lp ) {
        Failure[0] = Failure[1] = 0;
        for( int i = 2; i <= lp; i++ ) {
                int j = Failure[i-1];
                while( true ) {
                        if( pattern[j] == pattern[i-1] ) {
                                Failure[i] = j+1;
                                break;
                        }
                        if( j == 0 ) {
                                Failure[i] = 0;
                                break;
                        }
                        j = Failure[j];
                }
        }
}
int main( int argc , char const *argv[] ) {
        ios_base :: sync_with_stdio(false); cin.tie(NULL);
        int t;
        cin >> t;
        for( int tc = 1; tc <= t; tc++ ) {
                string s;
                int len;
                cin >> len >> s;
                Failure_Function( s , len );
                cout << "Test case #" << tc << endl;
                for( int i = 2; i <= len; i++ ) {
                        if( Failure[i] != 0 && ( i%( i - Failure[i] ) == 0 ) ) {
                                cout << i << " " << i/( i - Failure[i] ) << endl;
                                int k = i/( i - Failure[i] );
                                int x = len/k;
                                ans = min( ans , x );
                        }
                }
        }
        return 0;
}







