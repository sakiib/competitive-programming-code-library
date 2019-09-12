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

/**
number of integers from 1 to k , that are not divisible by
any of the numbers from the given array
for l to r : solve(r) - solve(l-1)
*/
int n;
LL k;
LL a[ 105 ];

LL LCM( LL a , LL b ) {
        return a / __gcd( a , b ) * b;
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( nullptr );
        cin >> k >> n;
        for( int i = 0; i < n; i++ ) cin >> a[i];
        LL ans = 0;
        for( int i = 1; i < ( 1 << n ); i++ ) {
                int cnt = 0;
                LL lcm;
                for( int j = 0; j < n; j++ ) {
                        if( i&( 1LL << j ) ) {
                                ++cnt;
                                if( cnt == 1 ) lcm = a[j];
                                else lcm = LCM( lcm , a[j] );
                        }
                }
                if( cnt&1 ) ans += k/lcm;
                else ans -= k/lcm;
        }
        cout << ( k - ans ) << endl;
        return 0;
}











