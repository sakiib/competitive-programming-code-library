#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
typedef pair < int , int > ii;
const int inf = 1e9;
const LL INF = 1e18;
const int N = 1e5 + 5;
const int mod = 1000000007;
const double eps = 1e-8;
const double pi = acos( -1.0 );

LL Power ( LL b , LL p ) {
        LL res = 1, x = b;
        while ( p ) {
                if ( p & 1 ) res = ( res * x );
                x = ( x * x ); p >>= 1;
        }
        return ( res );
}
int main( int argc , char const *argv[] ) {
        ios_base :: sync_with_stdio(false); cin.tie(NULL);

        return 0;
}






