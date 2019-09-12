#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
const int inf = (int)1e9;
const LL INF = (LL)2e18;
const int N = 100005;
const int mod = 1000000007;
const double eps = 1e-8;
const double pi = acos( -1.0 );

LL SQRT( LL n ) {
    LL lo = 1 , hi = 1e9, ret = 0;
    while( lo <= hi ) {
        LL mid = ( lo+hi ) >> 1;
        if( mid*mid <= n ) {
            ret = mid;
            lo = mid+1;
        }
        else hi = mid-1;
    }
    return ret;
}
int main( int argc, char const *argv[] ) {
    LL n;
    while( cin >> n ) {
        cout << SQRT( n ) << endl;
    }
    return 0;
}






