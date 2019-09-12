#include <bits/stdc++.h>
using namespace std;

#define Fast_IO ios_base::sync_with_stdio(0); cin.tie(0);

typedef unsigned long long uLL;
typedef long long int LL;
const int N = 1e5 + 5;
const int inf = 1e9;
const LL INF = 1e18;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int MOD = 1000000007;

vector <int> prime;

const int MX = 100000;

bool Check( int N , int pos ) { return (bool)( N &( 1<<pos ) ); }
int Set( int N , int pos ) { return N = N|( 1<<pos ); }
int status[ (MX/32) + 2 ];

void sieve( ) {
     int sqrtN = sqrt( MX );
     for( int i = 3; i <= sqrtN; i += 2 ) {
            if( Check( status[i>>5] , (i&31) ) == 0 ) {
                    for( int j = i*i; j <= MX; j += ( i << 1 ) ) {
                        status[j>>5] = Set( status[j>>5] , (j&31) );
                    }
            }
	 }
	 prime.push_back( 2 );
	 for( int i = 3; i <= MX; i += 2 ) {
            if( Check( status[i>>5] , (i&31) ) == 0 ) prime.push_back( i );
	 }
}
int main( int argc , char const *argv[] ) {
        sieve();
        for( auto x : prime ) cout << x << " ";
        return 0;
}







