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

/**
if a point is dropped from above & there are some sloppy lines
underneath , then what will be the drop point ( x )
of the point eventually
*/

struct point {
        int x , y;
        point( ){}
        point( int x , int y ) : x(x) , y(y) {}
        point operator - ( point p ) { return point ( x - p.x, y - p.y ); }
        int cross( const point p ) { return ( x * p.y - y * p.x ); }
};
struct segment {
        point l , r;
        segment( ) {}
        segment( point l , point r ) : l(l) , r(r) {}
};

int Orientation( point st , point mid , point ed ) {
        int v = ( ed - st ).cross( mid - st );
        if( !v ) return 0; /// co-linear
        return v > 0 ? 1 : -1; /// acw , cw
}
int n;
segment s[ N ];

int solve( point a ) {
        while( 1 ) {
                int idx = -1 , mx = -1;
                for( int i = 1; i <= n; i++ ) {
                        int ori = Orientation( s[i].l , s[i].r , a ); /// serial is very important
                        if( ori == 1 ) continue; /// point is under the line
                        if( a.x >= s[i].l.x && a.x <= s[i].r.x  ) {
                                int h = max( s[i].l.y , s[i].r.y );
                                if( h > mx ) mx = h , idx = i;
                        }
                }
                if( idx == -1 ) return a.x;
                if( s[idx].l.y < s[idx].r.y ) a.x = s[idx].l.x , a.y = s[idx].l.y - 1;
                else a.x = s[idx].r.x , a.y = s[idx].r.y - 1;
        }
        return a.x;
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( NULL );
        int t;
        cin >> t;
        bool f = false;
        while( t-- ) {
                if( f ) cout << endl;
                f = true;
                cin >> n;
                for( int i = 1; i <= n; i++ ) {
                        point a , b;
                        cin >> a.x >> a.y >> b.x >> b.y;
                        if( a.x > b.x ) swap( a , b );
                        s[i] = segment( a , b );
                }
                int q;
                cin >> q;
                while( q-- ) {
                        point a;
                        cin >> a.x >> a.y;
                        cout << solve( a ) << endl;
                }
        }
        return 0;
}











