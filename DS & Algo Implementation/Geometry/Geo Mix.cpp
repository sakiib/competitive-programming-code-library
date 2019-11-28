#include <bits/stdc++.h>
using namespace std;

/// change data type accordingly..

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
        double dist( const Point p ) { return ( sqrt( (x-p.x)*(x-p.x) + (y-p.y)*(y-p.y) ) ); }
        LL sqdist( const Point p ) { return ( ( (x-p.x)*(x-p.x) + (y-p.y)*(y-p.y) ) ); }
} P;


struct lineSegment {
        Point A , B; /// two endpoints of the line
        lineSegment( ) {}
        lineSegment( Point A , Point B ) : A( A ) , B( B ) {}
        lineSegment( LL ax , LL ay , LL bx , LL by ) {
                Point A = Point( ax , ay );
                Point B = Point( bx , by );
        }
} L;

/// Line of form : ax + by + c = 0; ( Ray actually )
struct Line {
        LL a , b , c;
        Line( ) {}
        Line( LL a , LL b , LL c ) : a(a) , b(b) , c(c) {}
        int Orientation( Point p ) {
                LL val = a * p.x + b * p.y + c;
                if( val == 0 ) return 0; /// point p is coLinear
                if( val > 0 ) return 1; /// above the Line
                else return -1; ///below the line
        }
};
const int N = 1e5 + 5;
const int inf = 1e7;
const double PI = acos( -1.0 );
const double EPS = 1e-8;

double toDegree( double r ) {
        return r * 180.0 / PI;
}
/// value of the vector a
double norm( Point a ) {
        return a.x * a.x + a.y * a.y;
}
/// angle between two vector
double AngleAOB( Point A , Point O , Point B ) { /// find angle AOB
        Point oa = A - O , ob = B - O;
        return toDegree( acos( oa.dot( ob ) / sqrt( norm(oa) * norm(ob) ) ) );
}

/// angle between two vectors in radian
double Angle( Point A , Point B ) {
        double ans = fabs( ( atan2( A.y , A.x ) - atan2( B.y , B.x ) ) );
        return ans > PI+EPS ? 2*PI-ans : ans;
}

/// angle from +ve X axis in radian
double AngleFromAxis( Point P ) {
        double ang = atan2( P.y , P.x ); if( ang+EPS < 0.0 ) ang += 2.0*PI;
        return ang;
}

/// dot product of AB & BC ( AB vector , BC vector )
double dotABC( Point A , Point B , Point C ) {
        Point AB = Point( B.x - A.x , B.y - A.y ); Point BC = Point( C.x - B.x , C.y - B.y );
        return AB.dot( BC );
}

/// cross product of AB & BC ( AB vector , BC vector )
double crossABC( Point A , Point B , Point C ) {
        Point AB = Point( B.x - A.x , B.y - A.y ); Point AC = Point( C.x - A.x , C.y - A.y );
        return AB.cross( AC );
}

/// given the vertices of a convex/concave polygon , returns ir's area
double PolygonArea( vector <Point> poly ) {
        double area = 0.0;
        for ( int i = 1; i + 1 < poly.size(); i++ )
        area += ( poly[i].y - poly[0].y ) * ( poly[i+1].x - poly[i].x )
              - ( poly[i].x - poly[0].x ) * ( poly[i+1].y - poly[i].y );
        return fabs( area / 2.0 );
}

LL Orientation( Point st , Point mid , Point ed ) {
        LL v = ( ed - st ).cross( mid - st ); ///cross prod axb != bxa , so be careful
        if( !v ) return 0; /// co-linear
        return v > 0 ? 1 : -1; /// acw , cw /// check here carefully
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

int main( int argc , char const *argv[] ) {
        ios_base :: sync_with_stdio( false ); cin.tie( NULL );

        return 0;
}












