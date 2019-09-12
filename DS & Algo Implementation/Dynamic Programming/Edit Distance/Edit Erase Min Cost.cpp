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
int la , lb;
LL dp[ 1005 ][ 1005 ];

LL solve( int i , int j ) {
        if( i >= la ) return ( lb - j ) * 30;
        if( j >= lb ) return ( la - i ) * 15;
        if( dp[i][j] != -1 ) return dp[i][j];
        LL mn = 2*inf;
        if( a[i] == b[j] ) return solve( i + 1 , j + 1 );
        else mn = min( 15 + solve( i + 1 , j ) , 30 + solve( i , j + 1 ) );
        return dp[i][j] = mn;
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( nullptr );
        while( cin >> a ) {
                if( a == "#" ) break;
                cin >> b;
                la = a.size();
                lb = b.size();
                memset( dp , -1 , sizeof( dp ) );
                cout << solve( 0 , 0 ) << endl;
        }
        return 0;
}










