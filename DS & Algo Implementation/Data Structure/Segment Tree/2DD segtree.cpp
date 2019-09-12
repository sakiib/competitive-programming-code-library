#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#define endl "\n"
#define trace(...) __f( #__VA_ARGS__ , __VA_ARGS__ )
template < typename Arg1 >
void __f( const char* name , Arg1&& arg1 ) { cerr << name << " : " << arg1 << "\n"; }
template < typename Arg1 , typename... Args >
void __f( const char* names , Arg1&& arg1 , Args&&... args ) {
const char* comma = strchr( names + 1 , ',' );
cerr.write( names , comma - names ) << " : " << arg1 << " , " ; __f( comma + 1 , args... ); }
typedef unsigned long long uLL;
typedef long long int LL;
typedef pair <int,int> pii;
typedef pair <int,pii> piii;
typedef pair <long long,long long> pll;
typedef pair <long long,pll> plll;
const int N = 1e3 + 5;
const int inf = 1e9;
const long long INF = 1e18;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int MOD = 1000000007;

struct _2DSegmentTreeRURQ {
        int a[ N ] , sum[ 4*N ] , lazy[ 4*N ];

        inline void init( ) {
                memset( sum , 0 , sizeof( sum ) );
                memset( lazy , 0 , sizeof( lazy ) );
        }
        inline void pushdown( int node , int b , int e ) {
                if( lazy[node] == 0 ) return;
                int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
                sum[l] += ( lazy[node] * ( m - b + 1 ) );
                sum[r] += ( lazy[node] * ( e - m ) );
                lazy[l] += lazy[node];
                lazy[r] += lazy[node];
                lazy[node] = 0;
        }
        inline void update( int node , int b , int e , int i , int j , int v ) {
                if( i > e || j < b || b > e ) return;
                if( i <= b && j >= e ) {
                        sum[node] += v * ( e - b + 1 );
                        lazy[node] += v;
                        return;
                }
                pushdown( node , b , e );
                int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
                update( l , b , m , i , j , v );
                update( r , m + 1 , e , i , j , v );
                sum[node] = ( sum[l] + sum[r] );
        }
        inline int query( int node , int b , int e , int i , int j ) {
                if( i > e || j < b || b > e ) return 0;
                if( i <= b && j >= e ) return sum[node];
                pushdown( node , b , e );
                int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
                return query( l , b , m , i , j ) + query( r , m + 1 , e , i , j );
        }
} tree[ N ];

int r , c;
string s[ N ];
int a[ N ][ N ];
map <char,int> M;
map <int,char> X;

int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( nullptr );
        cin >> r >> c;
        M['N'] = 0 , M['E'] = 1 , M['S'] = 2 , M['W'] = 3;
        X[0] = 'N' , X[1] = 'E' , X[2] = 'S' , X[3] = 'W';
        for( int i = 0; i < r; i++ ) cin >> s[i];
        int id = 0;
        for( int i = 0; i < r; i++ ) {
                for( int j = 0; j < c; j++ ) {
                        a[i+1][j+1] = M[ s[i][j] ];
                }
        }
        int q;
        cin >> q;
        while( q-- ) {
                string typ;
                cin >> typ;
                if( typ == "D" ) {
                        int x , y;
                        cin >> x >> y;
                        int prev = a[x][y];
                        int tot = tree[x].query( 1 , 1 , c , y , y );
                        //cout << "tot" << endl;
                        while( tot <= 0 ) tot += 4;
                        if( tot >= 4 ) tot %= 4;
                        tot%= 4;
                        prev += tot;
                        if( prev >= 4 ) prev %= 4;
                        //cout << prev << endl;
                        cout << X[prev] << endl;
                }
                else {
                        int x1 , y1 , x2 , y2 , d;
                        cin >> x1 >> y1 >> x2 >> y2 >> d;
                        int add = ( d == 0 ? +1 : -1 );
                        for( int i = x1; i <= x2; i++ ) tree[i].update( 1 , 1 , c , y1 , y2 , add );
                }
        }
        return 0;
}











