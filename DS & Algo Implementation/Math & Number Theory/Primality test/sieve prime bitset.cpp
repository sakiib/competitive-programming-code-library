#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(V) V.begin(), V.end()
#define Unique(V) sort(all(V)), V.erase(unique(all(V)), V.end())
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long int LL;
const int N = 1e5 + 5;

bitset <N> isprime;
vector <int> prime;

inline void sieve( ) {
        isprime.set( );
        prime.push_back( 2 );
        isprime[0] = 0 , isprime[1] = 0;
        for( int i = 4; i <= N; i += 2 ) isprime[i] = 0;
        int sq = sqrt( N );
        for( int i = 3; i <= sq; i += 2 ) {
                if( isprime[i] ) {
                        for( int j = i*i; j <= N; j += 2*i ) {
                                isprime[j] = 0;
                        }
                }
        }
        for( int i = 3; i <= N; i += 2 ) {
                if( isprime[i] ) prime.push_back( i );
        }
}
int main( ) {
        FIO;
        #ifdef OFFLINE
            freopen( "input.txt" , "r" , stdin );
        #endif // OFFLINE
        sieve();
        return 0;
}






