#include <bits/stdc++.h>
using namespace std;

typedef pair <int,int> pii;
string a , b;
int dp[ 105 ][ 105 ];
bool vis[ 105 ][ 105 ];
int la , lb;
map < pii,string > M;

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
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( NULL );
        int t;
        cin >> t;
        for( int tc = 1; tc <= t; tc++ ) {
                cin >> a >> b;
                la = a.size();
                lb = b.size();
                cout << "Case "<< tc << ": ";
                memset( dp , -1 , sizeof( dp ) );
                int mx = solve( 0 , 0 );
                memset( vis , false , sizeof( vis ) );
                if( mx == 0 ) cout << ":(" << endl;
                else cout << lexminprint( 0 , 0 ) << endl;
        }
        return 0;
}










