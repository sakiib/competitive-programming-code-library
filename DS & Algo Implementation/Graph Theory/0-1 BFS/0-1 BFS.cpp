#include <bits/stdc++.h>
using namespace std;

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

const int dx[] = { 1 , -1 , 0 , 0 };
const int dy[] = { 0 , 0 , 1 , -1 };

int r , c;
string s[ 1005 ];
int cost[ 1005 ][ 1005 ];

bool valid( int nx , int ny ) {
        return ( nx >= 0 && ny >= 0 && nx < r && ny < c );
}
void BFS01( ) {
        memset( cost , -1 , sizeof( cost ) );
        cost[0][0] = 0;
        deque <pii> Q;
        Q.push_front( {0,0} );
        while( !Q.empty() ) {
                pii f = Q.front(); Q.pop_front();
                int px = f.first , py = f.second;
                for( int i = 0; i < 4; i++ ) {
                        int nx = px + dx[i];
                        int ny = py + dy[i];
                        if( !valid( nx , ny ) ) continue;
                        int c = 0;
                        if( s[nx][ny] != s[px][py] ) c = 1;
                        if( cost[nx][ny] == -1 || cost[nx][ny] > cost[px][py] + c ) {
                                cost[nx][ny] = cost[px][py] + c;
                                if( c == 0 ) Q.push_front( {nx,ny} );
                                else Q.push_back( {nx,ny} );
                        }
                }
        }
}
void solve( ) {
        cin >> r >> c;
        for( int i = 0; i < r; i++ ) cin >> s[i];
        BFS01( );
        cout << cost[r-1][c-1] << endl;
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( NULL );
        int t;
        cin >> t;
        while( t-- ) {
                solve( );
        }
        return 0;
}











