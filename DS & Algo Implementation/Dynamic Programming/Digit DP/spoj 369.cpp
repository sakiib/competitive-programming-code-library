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
int dig[ 100 ];
LL dp[ 75 ][ 2 ][ 2 ][ 20 ][ 20 ][ 20 ];

LL go( int idx , bool tight , bool lead , int t , int s , int n ) {
        if( idx == -1 ) return t == s && s == n && t > 0;
        if( !tight && !lead && dp[idx][tight][lead][t][s][n] != -1 ) return dp[idx][tight][lead][t][s][n];
        LL ret = 0;
        if( t > 17 || s > 17 || n > 17 ) return 0;
        int up = tight ? dig[idx] : 9;
        for( int i = 0; i <= up; i++ ) {
                ret += go( idx - 1 , tight&&(dig[idx]==i) , lead&&(i==0) , t+(i==3) , s+(i==6) , n+(i==9) );
                ret %= MOD;
        }
        if( !tight ) dp[idx][tight][lead][t][s][n] = ret;
        return ret;
}
LL solve( string &s ) {
        int len = 0;
        for( int i = s.size()-1; i >= 0; i-- ) dig[len++] = (s[i]-'0');
        return go( len - 1 , 1 , 1 , 0 , 0 , 0 );
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( nullptr );
        int t;
        cin >> t;
        memset( dp , -1 , sizeof( dp ) );
        while( t-- ) {
                cin >> a >> b;
                LL ans = solve( b ) - solve( a );
                int th = 0 , si = 0 , ni = 0;
                for( int i = 0; i < a.size(); i++ ) {
                        if( a[i] == '3' ) th++;
                        if( a[i] == '6' ) si++;
                        if( a[i] == '9' ) ni++;
                }
                if( th == si && si == ni && th > 0 ) ans++;
                if( ans < 0 ) ans += MOD;
                cout << ans%MOD << endl;
        }
        return 0;
}











