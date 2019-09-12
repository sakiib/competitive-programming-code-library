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
int SOD[ sz ];

void GenerateSumofDivLoop( int sz ) {
    for( int i = 1; i <= sz; i++ ) {
        for( int j = i; j <= sz; j += i ) {
            SOD[j] += i;
        }
    }
}
LL SODSieve( LL n ) {
    LL res = 1;
    LL sqrtn = sqrt ( n );
    for ( int i = 0; i < prime.size() && prime[i] <= sqrtn; i++ ) {
        if ( n % prime[i] == 0 ) {
            LL tempSum = 1;
            LL p = 1;
            while ( n % prime[i] == 0 ) {
                n /= prime[i];
                p *= prime[i];
                tempSum += p;
            }
            sqrtn = sqrt ( n );
            res *= tempSum;
        }
    }
    if ( n != 1 ) res *= ( n + 1 );
    return res;
}
int main(int argc,char const *argv[]) {

    sieve( );

    return 0;
}

