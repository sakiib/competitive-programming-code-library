#include<bits/stdc++.h>
using namespace std;

const int N  = 100005;
typedef long long LL;

vector <int> prime;
vector <bool> isprime( N , true );

void sieve( ) {
    isprime[0] = isprime[1] = false;
    prime.push_back( 2 );
    for( int i = 4; i <= N; i +=2 ) isprime[i] = false;
    int sq = sqrt( N );
    for( int i = 3; i <= sq; i += 2 ) {
        if( isprime[i] ) {
            for( int j = i*i; j <= N; j += 2*i ) {
                isprime[j] = false;
            }
        }
    }
    for( int i = 3; i <= N; i += 2 ) {
        if( isprime[i] ) prime.push_back( i );
    }
}


const int sz = 100005;
int NOD[ sz ];

void GenNumofDivLoop( int sz ) {
    for( int i = 1; i <= sz; i++ ) {
        for( int j = i; j <= sz; j += i ) {
            NOD[j]++;
        }
    }
}
inline int NODSieve( LL x ) {
        LL sq = sqrt( x );
        int ret = 1;
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
int main(int argc,char const *argv[]) {
    sieve( );
    return 0;
}

