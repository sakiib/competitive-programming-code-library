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
        for( int i = 4; i <= N; i +=2 ) isprime[i] = 0;
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
inline LL NOD( LL x ) {
        LL sq = sqrt( x );
        LL ret = 1;
        for( int i = 0; i < prime.size() && prime[i] <= sq; i++ ) {
                if( x%prime[i] == 0 ) {
                    LL p = 0;
                    while( x%prime[i] == 0 ) x /= prime[i] , p++;
                    sq = sqrt( x ); p++; ret *= p;
                }
        }
        if( x != 1 ) ret *= 2;
        return ret;
}
inline LL PHI( LL x ) { /// generate sieve prime first.
        vector <LL> val;
        LL temp = x , vag = 1;
        for( int i = 0; i < prime.size(); i++ ) {
                if( x%prime[i] == 0 ) {
                        vag *= prime[i];
                        val.push_back( prime[i] );
                        x /= prime[i];
                        while( x%prime[i] == 0 ) x /= prime[i];
                }
        }
        if( x > 1 ) val.push_back( x ) , vag *= x;
        for( int i = 0; i < val.size(); i++ ) temp *= ( val[i] - 1 );
        temp /= vag;
        return temp;
}

int main( ) {
        FIO;
        #ifdef OFFLINE
            freopen( "input.txt" , "r" , stdin );
        #endif // OFFLINE
        LL n;
        sieve( );
        while( cin >> n ) {
                LL nod = NOD( n );
                LL phi = PHI( n );
                cout << n - nod - phi + 1 << endl; /// 1 , 2 bar baad porse.
        }
        return 0;
}






