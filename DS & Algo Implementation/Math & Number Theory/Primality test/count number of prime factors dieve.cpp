#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(V) V.begin(), V.end()
#define Unique(V) sort(all(V)), V.erase(unique(all(V)), V.end())
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long int LL;
const int N = 1e5 + 5;

/// dp[i] = number of prime factors i has in its primefactorization
int dp[ N ];

int main( ) {
        FIO;
        #ifdef OFFLINE
            freopen( "input.txt" , "r" , stdin );
        #endif // OFFLINE
        for( int i = 2; i <= 1e5; i++ ) {
                if( !dp[i] ) {
                        for( int j = i; j <= 1e5; j += i ) {
                                dp[j] = dp[j/i] + 1;
                        }
                }
        }
        for( int i = 1; i <= 20; i++ ) cout << i << " " << dp[i] << endl;
        return 0;
}






