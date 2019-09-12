#include <bits/stdc++.h>
using namespace std;

string a , b;
int la , lb;
int dp1[ 100 ][ 100 ];

/// bottom up approach.
/// this takes O(N^2) memory & O(N^2) time..

int LCS1( ) {
        la = a.size();
        lb = b.size();
        for( int i = 0; i <= la; i++ ) {
                for( int j = 0; j <= lb; j++ ) {
                        if( i == 0 || j == 0 ) dp1[i][j] = 0;
                        else if( a[i-1] == b[j-1] ) dp1[i][j] = 1 + dp1[i-1][j-1];
                        else dp1[i][j] = max( dp1[i-1][j] , dp1[i][j-1] );
                }
        }
        return dp1[la][lb];
}

/// this takes O( N) memory & O(N^2) time..

/**
observation:
One important observation in above simple implementation is, in each iteration of outer loop
we only, need values from all columns of previous row.
*/

int dp2[ 2 ][ 100 ];

int LCS2( ) {
        la = a.size();
        lb = b.size();
        int id = 0;
        for( int i = 0; i <= la; i++ ) {
                id =  (id^1);
                for( int j = 0; j <= lb; j++ ) {
                        if( i == 0 || j == 0 ) dp2[id][j] = 0;
                        else if( a[i-1] == b[j-1] ) dp2[id][j] = 1 + dp2[1^id][j-1];
                        else dp2[id][j] = max( dp2[1^id][j] , dp2[id][j-1] );
                }
        }
        return dp2[id][lb];
}
int main( int argc , char const *argv[] ) {
        cin >> a >> b;
        cout << LCS1( ) << endl;
        cout << LCS2( ) << endl;
        return 0;
}










