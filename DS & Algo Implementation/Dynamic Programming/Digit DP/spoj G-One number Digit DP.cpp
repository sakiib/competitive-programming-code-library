#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
vector <int> V;
LL dp[ 10 ][ 2 ][ 105 ];
int len;

/**
Number of integers from A to B whose sum fo digts is a prime number
*/
const int N = 200;
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
}
LL go( int idx , int smaller , int sum ) {
        if( idx >= len ) return isprime[sum];
        if( dp[idx][smaller][sum] != -1 ) return dp[idx][smaller][sum];
        LL ret = 0;
        if( smaller ) {
                for( int i = 0; i <= 9; i++ ) {
                        ret += go( idx + 1 , 1 , sum + i );
                }
        }
        else {
                for( int i = 0; i < V[idx]; i++ ) {
                        ret += go( idx + 1 , 1 , sum + i );
                }
                ret += go( idx + 1 , 0 , sum + V[idx] );
        }
        return dp[idx][smaller][sum] = ret;
}
LL solve( int val ) {
        V.clear();
        while( val ) V.push_back( val%10 ) , val /= 10;
        reverse( V.begin() , V.end() );
        len = V.size();
        memset( dp , -1 , sizeof( dp ) );
        return go( 0 , 0 , 0 );
}
int main( int argc , char const *argv[] ) {
        int t;
        scanf("%d",&t);
        sieve( );
        while( t-- ) {
                int a , b;
                scanf("%d %d",&a,&b);
                printf("%lld\n",solve( b ) - solve( a - 1 ) );
        }
        return 0;
}










