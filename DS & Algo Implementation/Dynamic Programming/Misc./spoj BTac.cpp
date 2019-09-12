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
shortest length string that contains two string as subsequence
*/

string a , b;
int la , lb;
int dp[ 105 ][ 105 ];

int LCS( int i ,int j ) {
        if( i >= la || j >= lb ) return 0;
        if( dp[i][j] != -1 ) return dp[i][j];
        if( a[i] == b[j] ) return 1 + LCS( i + 1 , j + 1 );
        return dp[i][j] = max( LCS( i + 1 , j ) , LCS( i , j + 1 ) );
}
void print( int i , int j ) {
        if( i >= la ) {
                for( int k = j; k < lb; k++ ) cout << b[k];
                return;
        }
        if( j >= lb ) {
                for( int k = i; k < la; k++ ) cout << a[k];
                return;
        }
        if( a[i] == b[j] ) {
                cout << a[i];
                print( i + 1 , j + 1 );
        }
        else {
                if( LCS( i + 1 , j ) >= LCS( i , j + 1 ) ) {
                        cout << a[i];
                        print( i + 1 , j );
                }
                else {
                        cout << b[j];
                        print( i , j + 1 );
                }
        }
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( nullptr );
        while( cin >> a >> b ) {
                la = a.size();
                lb = b.size();
                memset( dp , -1 , sizeof( dp ) );
                int lcs = LCS( 0 , 0 );
                int len = la + lb - lcs;
                print( 0 , 0 );
                cout << endl;
        }
        return 0;
}
