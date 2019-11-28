#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
struct Point {
        LL x , y;
        Point( ) {}
        Point( LL x , LL y ) : x( x ) , y( y ) {}
        Point operator + ( Point p ) { return Point ( x + p.x, y + p.y ); }
        Point operator - ( Point p ) { return Point ( x - p.x, y - p.y ); }
        Point operator * ( LL k ) { return Point( x * k , y * k ); }
        Point operator / ( LL k ) { return Point( x / k , y / k ); }
        LL dot( const Point p ) { return ( x * p.x + y * p.y ); }
        LL cross( const Point p ) { return ( 1LL * x * p.y - 1LL * y * p.x ); }
        Point in( Point &a ) { cin >> a.x >> a.y; }
} P;

struct lineSegment {
        Point A , B;
        lineSegment( ) {}
        lineSegment( Point A , Point B ) : A( A ) , B( B ) {}
        lineSegment( LL ax , LL ay , LL bx , LL by ) {
                Point A = Point( ax , ay );
                Point B = Point( bx , by );
        }
} L;

const int N = 1e5 + 5;
const int inf = 1e7;
/// if points on border is considerd outside , handle it onSegment() check
int n;
vector <lineSegment> V;
Point a[ N ];

LL Orientation( Point st , Point mid , Point ed ) {
        LL v = ( ed - st ).cross( mid - st );
        if( !v ) return 0; /// co-linear
        return v > 0 ? 1 : -1; /// acw , cw
}
/// check if point a , b , c are co-linear
bool coLinear( Point a , Point b , Point c ) {
        LL ori = Orientation( a , b , c );
        return ori == 0;
}
/// check if point p is on linesegment l or not.
bool onSegment( Point p , lineSegment l ) {
        if( coLinear( l.A , l.B , p ) ) {
                Point r = l.A , s = l.B;
                return ( 1LL * ( p.x - r.x ) * ( p.x - s.x ) <= 0 &&
                         1LL * ( p.y - r.y ) * ( p.y - s.y ) <= 0 );
        }
        else return false;
}
/// check if two line segment intersects or not.
bool lineIntersect( lineSegment p , lineSegment q ) {
        if( Orientation( p.A , p.B , q.A ) == - Orientation( p.A , p.B , q.B )
         && Orientation( q.A , q.B , p.A ) == - Orientation( q.A , q.B , p.B ) ) return true;
        else return false;
}
LL RayShoot( vector <lineSegment> V , Point A , Point B ) {
        LL cnt = 0;
        lineSegment Q = lineSegment( A , B );
        for( int i = 0; i < V.size(); i++ ) {
                lineSegment P = V[i];
                if( onSegment( A , P ) ) return 1;
                cnt += lineIntersect( P , Q ) ? 1 : 0;
        }
        return cnt;
}
int main( int argc , char const *argv[] ) {
        ios_base :: sync_with_stdio( false ); cin.tie( NULL );
        while( cin >> n ) {
                if( n == 0 ) break;
                V.clear();
                for( int i = 1; i <= n; i++ ) {
                        Point p;
                        cin >> a[i].x >> a[i].y;
                        if( i > 1 ) V.push_back( lineSegment( a[i] , a[i-1] ) );
                }
                V.push_back( lineSegment( a[n] , a[1] ) );
                Point p;
                cin >> p.x >> p.y;
                if( RayShoot( V , p , Point( p.x+inf , p.y+inf+1 ) )&1 ) {
                        cout << "T" << endl;
                }
                else {
                        cout << "F" << endl;
                }
        }
        return 0;
}











