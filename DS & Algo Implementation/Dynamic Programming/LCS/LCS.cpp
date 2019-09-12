#include <bits/stdc++.h>
using namespace std;

/**
LCS
for lexico min max , change conditions accordingly
space N^2 , runtime N^2
*/

typedef pair <int,int> pii;
string a , b;
int dp[ 105 ][ 105 ];
bool vis[ 105 ][ 105 ];
int la , lb;
map <pii,string> M;

int solve( int i , int j ) {
        if( i >= la || j >= lb ) return 0;
        if( dp[i][j] != -1 ) return dp[i][j];
        if( a[i] == b[j] ) return 1 + solve( i + 1 , j + 1 );
        return dp[i][j] = max( solve( i + 1 , j ) , solve( i , j + 1 ) );
}
string lexminprint( int i , int j ) {
        if( i >= la || j >= lb ) return "";
        if( a[i] == b[j] ) return a[i] + lexminprint( i + 1 , j + 1 );
        if( vis[i][j] ) return M[pii(i,j)];
        vis[i][j] = true;
        string cur = "";
        if( solve( i + 1 , j ) > solve( i , j + 1 ) ) cur = lexminprint( i + 1 , j );
        else if( solve( i + 1 , j ) < solve( i , j + 1 ) ) cur = lexminprint( i , j + 1 );
        else cur = min( lexminprint( i + 1 , j ) , lexminprint( i , j + 1 ) );
        return M[pii(i,j)]= cur;
}
void print( int i, int j ) {
        if( i >= la ||j >= lb ) return;
        if( a[i] == b[j] ) {
                cout << a[i];
                print( i + 1 , j + 1 );
        }
        else {
                if( solve( i + 1 , j ) >= solve( i , j + 1 ) ) print( i + 1 , j );
                else print( i , j + 1 );
        }
}

int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( NULL );
        cin >> a >> b;
        la = a.size();
        lb = b.size();
        memset( dp , -1 , sizeof( dp ) );
        cout << solve( 0 , 0 ) << endl;
        print( 0 , 0 );
        cout << endl;
        memset( vis , false , sizeof( vis ) );
        lexminprint( 0 , 0 );
        return 0;
}










