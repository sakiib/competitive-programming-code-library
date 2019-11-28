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

struct Point {
        LL x , y;
        Point( ) {}
        Point( LL x , LL y ) : x( x ) , y( y ) {}
        Point operator + ( Point p ) { return Point ( x + p.x, y + p.y ); }
        Point operator - ( Point p ) { return Point ( x - p.x, y - p.y ); }
        Point operator * ( LL k ) { return Point( x * k , y * k ); }
        Point operator / ( LL k ) { return Point( x / k , y / k ); }
        LL dot( const Point p ) { return ( x * p.x + y * p.y ); }
        LL cross( const Point p ) { return ( x * p.y - y * p.x ); }
        LL PolygonArea( vector <Point> poly ) {
                LL area = 0;
                for ( int i = 1; i + 1 < poly.size(); i++ )
                        area += ( poly[i].y - poly[0].y ) * ( poly[i+1].x - poly[i].x )
                              - ( poly[i].x - poly[0].x ) * ( poly[i+1].y - poly[i].y );
                return abs(area);
        }
} P;

vector <Point> V;
int n;

LL LatticePoint( Point a , Point b ) {
        if( a.x == b.x ) return abs( b.y - a.y );
        if( a.y == b.y ) return abs( b.x - a.x );
        return __gcd( abs( a.x - b.x ) , abs( a.y - b.y ) );
}
/// Border line e # of lattice points
LL Border_Point( vector <Point> V ) {
        LL cnt = 0;
        for( int i = 0; i < V.size(); i++ ) cnt += LatticePoint( V[i] , V[(i+1)%n] );
        return ( cnt - 1 ); /// start point ta 2 bar count kore felsi
}
int main( int argc , char const *argv[] ) {
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
                scanf("%d",&n);
                V.clear();
                for( int i = 1; i <= n; i++ ) {
                        LL x , y;
                        scanf("%lld %lld",&x,&y);
                        V.push_back( Point( x , y ) );
                }
                LL area = P.PolygonArea( V ); /// actually area * 2
                LL border_point = Border_Point( V );
                LL ans = ( area - border_point + 2 )/2; /// multiplied both side by 2 actually
                printf("Case %d: %lld\n",tc,ans);
        }
        return 0;
}











