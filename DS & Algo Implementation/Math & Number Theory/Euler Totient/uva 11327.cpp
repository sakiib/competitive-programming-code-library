#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(V) V.begin(), V.end()
#define Unique(V) sort(all(V)), V.erase(unique(all(V)), V.end())
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long int LL;
const int N = 5e5 + 5;

int PHI[ N ];
LL sum[ N ];

inline void sievePHI( int SZ ) {
        for( int i = 1; i <= SZ; i++ ) PHI[i] = i;
        for( int i = 1; i <= SZ; i++ ) {
                for( int j = 2*i; j <= SZ; j += i ) {
                        PHI[j] -= PHI[i];
                }
        }
        PHI[1] = 2;
        for( int i = 1; i <= SZ; i++ ) sum[i] += sum[i-1] + PHI[i];
}
int main( ) {
        FIO;
        #ifdef OFFLINE
            freopen( "input.txt" , "r" , stdin );
        #endif // OFFLINE
        LL n;
        sievePHI( 500000 );
        while( cin >> n ) {
                if( n == 0 ) break;
                int pos = lower_bound( sum + 1, sum + 500000 + 1, n ) - sum;
                n -= sum[pos-1];
                LL k = n;
                //cout << "pos , k : " << pos << " " << k << endl;
                for( int i = 0; i <= 500000; i++ ) {
                        if( __gcd( i , pos ) == 1 ) k--;
                        if( k == 0 ) {
                                cout << i << "/" << pos << endl;
                                break;
                        }
                }
        }
        return 0;
}






