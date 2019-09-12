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
# of Integers in L to R such that : is divisible by each of its nonzero digits
*/

LL dp[ 20 ][ 2 ][ 2525 ][ 55 ];
int LC[ 2525 ][ 10 ];
int ID[ 2525 ];
int dig[ 20 ];
int len;

LL go( int idx , bool tight , int rem , int lcm ) {
        if( idx == -1 ) {
                if( lcm == 0 ) return 0;
                return rem%lcm == 0;
        }
        if( !tight && dp[idx][tight][rem][ID[lcm]] != -1 ) return dp[idx][tight][rem][ID[lcm]];
        LL ret = 0;
        int limit = tight ? dig[idx] : 9;
        for( int i = 0; i <= limit; i++ ) {
                ret += go( idx - 1 , tight&&( i == dig[idx] ) , (rem*10+i)%2520 , LC[lcm][i] );
        }
        if( !tight ) dp[idx][tight][rem][ID[lcm]] = ret;
        return ret;
}
LL solve( LL x ) {
        len = 0;
        while( x ) dig[len++] = x%10 , x /= 10;
        return go( len - 1 , 1 , 0 , 0  );
}
int LCM( int x , int y ) {
        return x / __gcd( x , y ) * y;
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( nullptr );
        set <int> S;
        for( int i = 0; i < ( 1 << 10 ); i++ ) {
                int lcm = 0;
                for( int j = 1; j <= 9; j++ ) {
                       if( i&( 1 << j ) ) {
                                if( lcm == 0 ) lcm = j;
                                else lcm = LCM( lcm , j );
                       }
                }
                for( int j = 0; j <= 9; j++ ) {
                        if( lcm == 0 ) LC[lcm][j] = j;
                        else if( j == 0 ) LC[lcm][j] = lcm;
                        else LC[lcm][j] = LCM( lcm , j );
                        S.insert( LC[lcm][j] );
                }
        }
        int id = 0;
        for( auto x : S ) ID[x] = ++id;
        memset( dp , -1 , sizeof( dp ) );
        int t;
        cin >> t;
        while( t-- ) {
                LL l , r;
                cin >> l >> r;
                cout << solve( r ) - solve( l - 1 ) << endl;
        }
        return 0;
}












