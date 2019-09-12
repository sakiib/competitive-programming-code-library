#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

const int N = 1e3 + 5;
const int inf = 0x3f3f3f3f;
const int dx[] = { 1 , -1 , 0 , 0 };
const int dy[] = { 0 , 0 , 1 , -1 };

int r , c;
string s[ N ];
int sx , sy , ex , ey;
int cost[ N ][ N ][ 5 ];

struct node {
        int turn , dir , x , y;
        node( ) :
                turn(0) , dir(0) , x(0) , y(0) {}
        node( int turn , int dir , int x , int y ) :
                turn( turn ) , dir(dir) , x( x ) , y( y ) {}
        bool operator <( const node &q ) const {
                return turn > q.turn;
        }
};
bool valid( int nx , int ny ) {
        return ( nx >= 0 && ny >= 0 && nx < r && ny < c && s[nx][ny] != '*' );
}
int dijkstra( ) {
        priority_queue <node> Q;
        memset( cost , inf , sizeof( cost ) );
        for( int i = 0; i < 4; i++ ) cost[sx][sy][i] = 0;
        if( valid( sx + 1 , sy ) ) Q.push( node( 0 , 0 , sx + 1 , sy ) ) , cost[sx+1][sy][0] = 0;
        if( valid( sx - 1 , sy ) ) Q.push( node( 0 , 1 , sx - 1 , sy ) ) , cost[sx-1][sy][1] = 0;
        if( valid( sx , sy + 1 ) ) Q.push( node( 0 , 2 , sx , sy + 1 ) ) , cost[sx][sy+1][2] = 0;
        if( valid( sx , sy - 1 ) ) Q.push( node( 0 , 3 , sx , sy - 1 ) ) , cost[sx][sy-1][3] = 0;
        int ans = inf;
        while( !Q.empty() ) {
                node t = Q.top(); Q.pop( );
                if( t.x == ex && t.y == ey ) return t.turn;
                for( int i = 0; i < 4; i++ ) {
                        int nx = t.x + dx[i] , ny = t.y + dy[i];
                        if( !valid( nx , ny ) ) continue;
                        int nc = ( i != t.dir );
                        if( cost[nx][ny][i] > cost[t.x][t.y][t.dir] + nc ) {
                                cost[nx][ny][i] = cost[t.x][t.y][t.dir] + (i != t.dir);
                                Q.push( node( t.turn + nc , i , nx , ny ) );
                        }
                }
        }
        return ans;
        int mn = inf;
        for( int i = 0; i < 4; i++ ) mn = min( mn , cost[ex][ey][i] );
        return mn;
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( nullptr );
        //freopen( "input.txt" , "r" , stdin );
        cin >> r >> c;
        for( int i = 0; i < r; i++ ) cin >> s[i];
        for( int i = 0; i < r; i++ ) {
                for( int j = 0; j < c; j++ ) {
                        if( s[i][j] == 'S' ) sx = i , sy = j;
                        if( s[i][j] == 'T' ) ex = i , ey = j;
                }
        }
        cout << ( dijkstra( ) <= 2 ? "YES" : "NO" ) << endl;
        return 0;
}









