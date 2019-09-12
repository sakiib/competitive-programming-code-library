#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
const int N = 1e6 + 5;

LL a , b;

vector <LL> prime;
vector <bool> isprime( N , true );
bool isp[ N ];

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
void segmented_sieve( ) {
        if( a > b ) swap( a , b );
        if( b < 2 ) return;
        if( a < 2 ) a = 2;
        LL cap = sqrt( b ) + 1 , start , cnt = 0;
        memset( isp , true , sizeof(isp) );
        for( int i = 0; i < prime.size(); i++ ) {
                if( prime[i] >= cap ) break;
                if( prime[i] >= a ) start = prime[i] * 2;
                else start = a + ( ( prime[i] - a % prime[i] ) % prime[i] );
                for( LL j = start; j <= b; j += prime[i] ) {
                        isp[ j - a ] = false;
                }
        }
        start = ( a % 2 ) ? a : a + 1;
        if( a == 2 ) printf("%lld\n",a) , cnt++;
        for( LL i = start; i <= b; i += 2 ) {
                if( isp[ i - a ] ) printf("%lld\n",i) , cnt++;
        }
        printf("Total Prime : %d\n",cnt);
}
int main( int argc , char const *argv[] ) {
        sieve( );
        while( scanf("%lld %lld",&a,&b) ) {
                segmented_sieve( );
        }
        return 0;
}






