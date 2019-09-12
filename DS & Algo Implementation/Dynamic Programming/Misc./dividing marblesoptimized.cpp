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

int a[ 10 ];
int state[ 7 ][ 2*N ];
int dp[ 7 ][ 2*N ];
int tot;
int tc;

int ok( int idx , int taken ) {
        if( idx > 6 ) return taken == tot/2 && tot%2 == 0;
        if( taken > tot/2 ) return 0;
        if( state[idx][taken] == tc ) return dp[idx][taken];
        state[idx][taken] = tc;
        int ret = 0;
        for( int i = 0; i <= a[idx]; i++ ) ret |= ok( idx + 1 , taken + i * idx );
        return dp[idx][taken] = ret;
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( nullptr );
        tc = 0;
        bool f = false;
        while( cin >> a[1] >> a[2] >> a[3]>> a[4] >> a[5] >> a[6] ) {
                if( a[1] + a[2] + a[3] + a[4] + a[5] + a[6] == 0 ) break;
                for( int i = 1; i <= 6; i++ ) a[i] %= 10;
                tot = a[1]*1 + a[2]*2 + a[3]*3 + a[4]*4 + a[5]*5 + a[6]*6;
                cout << "Collection #" << ++tc << ":" << endl;
                if( ok( 1 , 0 ) ) cout << "Can be divided." << endl;
                else cout << "Can't be divided." << endl;
                cout <<endl;
        }
        return 0;
}












