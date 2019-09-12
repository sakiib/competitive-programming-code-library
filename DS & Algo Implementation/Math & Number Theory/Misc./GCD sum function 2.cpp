#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 1e6 + 5;

/**
 this gets AC for spoj gcd extreme
 */

int PHI[ N ];
LL sum[ N ];
bool mark[ N ];

void SievePHI( int sz ) {
        for( int i = 1; i < N; i++ ) PHI[i] = i;
        for( int i = 1; i <= sz; i++ ) {
                for( int j = 2*i; j <= sz; j += i ) {
                        PHI[j] -= PHI[i];
                }
        }
}
inline void SievePhi( int sz ) {
        for( int i = 1; i <= sz; i++ ) PHI[i] = i;
        PHI[1] = 1 , mark[1] = true;
        for( int i = 2; i <= sz; i++ ) {
                if( !mark[i] ) {
                        for( int j = i; j <= sz; j +=i ) {
                                mark[j] = true , PHI[j] = PHI[j]/i*(i-1);
                        }
                }
        }
}
void calc( ) {
        for( int i = 1; i < N; i++ ) {
                for( int j = 2 * i; j < N; j += i ) {
                        sum[j] += 1LL * PHI[j/i] * i;
                }
        }
        for( int i = 1; i < N; i++ ) sum[i] += sum[i-1];
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( NULL );
        SievePhi( 1000000 );
        calc( );
        int n;
        while( cin >> n ) {
                if( n == 0 ) break;
                cout << sum[n] << endl;
        }
        return 0;
}











