#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
typedef unsigned long long uLL;
typedef long long int LL;
typedef pair <int,int> pii;
typedef pair <int,pii> piii;
typedef pair <long long,long long> pll;
typedef pair <long long,pll> plll;
const int N = 1e5 + 5;
const int inf = 1e9;
const long long INF = 1e18;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int MOD = 1000000007;

bool isprime[ N ];
int prime[ N ];
int mobius[ N ] = { 0 , 1 };

void mobiusCalc( ) {
        memset( isprime , true , sizeof( isprime ) );
        int primecnt = 0;
        for( int i = 2; i < N; i++ ) {
                if( isprime[i] ) {
                        prime[ ++primecnt ] = i;
                        mobius[i] = -1;
                }
                for( int j = 1; i * prime[j] < N; j++ ) {
                        isprime[ i*prime[j] ] = false;
                        if( i%prime[j] == 0 ) {
                                mobius[ i*prime[j] ] = 0;
                                break;
                        }
                        else mobius[ i*prime[j] ] -= mobius[i];
                }
        }
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( nullptr );
        mobiusCalc( );
        for( int i = 1; i <= 5; i++ ) cout << mobius[i] << " ";
        return 0;
}











