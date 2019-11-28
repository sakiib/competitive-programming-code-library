#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long uLL;
typedef long long int LL;
const int N = 1e5 + 5;
const int inf = 1e9;
const LL INF = 1e18;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int MOD = 1000000007;

struct point {
    int x , y;
    point( ) { }
    point( int _x , int _y ) { x = _x , y = _y; }
    point operator + ( const point p ) { return point( x + p.x , y + p.y ); }
    point operator - ( const point p ) { return point( x - p.x , y - p.y ); }
    point operator * ( int k ) { return point( x * k , y * k ); }
    point operator / ( int k ) { return point( x / k , y / k ); }

    int dot( const point p ) { return ( x * p.x + y * p.y ); }
    int cross( const point p ) { return ( x * p.y - y * p.x ); }

} P;

point p[ N ];

bool cmp( point a , point b ) {
        return ( a - p[1] ).cross( b - p[1] ) < 0; /// recheck it <= or <
}
int main( int argc , char const *argv[] ) {
        int x , y;
        int n = 0;
        while( scanf("%d %d",&x,&y) != EOF ) {
                p[++n] = point( x , y );
        }
        sort( p+2 , p+n+1 , cmp );
        for( int i = 1; i <= n; i++ ) printf("(%d,%d)\n",p[i].x,p[i].y);
        return 0;
}








