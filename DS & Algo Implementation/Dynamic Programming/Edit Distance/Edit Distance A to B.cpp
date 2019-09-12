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

string a , b;
int dp[ 2005 ][ 2005 ];

/**
make A is equal to B
by replace , remove , insert ( cost 1 each )
*/
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( nullptr );
        int t;
        cin >> t;
        while( t-- ) {
                cin >> a >> b;
                a = '@' + a;
                b = '#' + b;
                int la = a.size() - 1 , lb = b.size() - 1;
                for( int i = 1; i <= la; i++ ) dp[i][0] = i;
                for( int i = 1; i <= lb; i++ ) dp[0][i] = i;
                for( int i = 1; i <= la; i++ ) {
                        for( int j = 1; j <= lb; j++ ) {
                                if( a[i] == b[j] ) dp[i][j] = dp[i-1][j-1];
                                else {
                                        dp[i][j] = min( 1 + dp[i-1][j] , min( 1 + dp[i][j-1] , 1 + dp[i-1][j-1] ) );
                                }
                        }
                }
                cout << dp[la][lb] << endl;
        }
        return 0;
}











