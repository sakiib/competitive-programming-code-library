#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long LL;
const double eps = 1e-8;
const double pi = acos( -1.0 );

#define ii pair < int , int >
#define iii pair < ii , int >
#define ff first
#define ss second
#define SQ(x) (x*x)
#define Fix( x ) setprecision( x ) << fixed

bool EqualTo( double a , double b ) { return ( fabs ( a - b ) <= eps ); }
bool NotEqual( double a , double b ) { return ( fabs ( a - b ) > eps ); }
bool LessThan( double a , double b ) { return ( a + eps < b ); }
bool LessThanEqual( double a , double b ) { return ( a < b + eps ); }
bool GreaterThan( double a , double b ) { return ( a > b + eps ); }
bool GreaterThanEqual( double a , double b ) { return ( a + eps > b ); }


struct point {
    double x , y;
    point( ) { }
    point( double _x , double _y ) { x = _x , y = _y; }
    point operator + ( const point p ) { return point( x + p.x , y + p.y ); }
    point operator - ( const point p ) { return point( x - p.x , y - p.y ); }
    point operator * ( double k ) { return point( x * k , y * k ); }
    point operator / ( double k ) { return point( x / k , y / k ); }

    void in( point &p ) { cin >> p.x >> p.y; }
    void print( point p )  { cerr << setprecision(5) << fixed <<"( "<< p.x << " , " << p.y <<" )"<< endl; }

    double dot( const point p ) { return ( x * p.x + y * p.y ); }
    double cross( const point p ) { return ( x * p.y - y * p.x ); }

    double dist( const point p ) { return ( sqrt( (x-p.x)*(x-p.x) + (y-p.y)*(y-p.y) ) ); }
    double sqdist( const point p ) { return ( ( (x-p.x)*(x-p.x) + (y-p.y)*(y-p.y) ) ); }

    /// angle between two vectors
    double Angle( point A , point B ) {
        double ans = fabs( ( atan2( A.y , A.x ) - atan2( B.y , B.x ) ) );
        return ans > pi+eps ? 2*pi-ans : ans;
    }
    /// angle from +ve X axis
    double AngleFromAxis( point P ) {
        double ang = atan2( P.y , P.x ); if( ang+eps < 0.0 ) ang += 2.0*pi; return ang;
    }
    /// dot product of AB & BC ( AB vector , BC vector )
    double dotABC( point A , point B , point C ) {
        point AB = point( B.x - A.x , B.y - A.y ); point BC = point( C.x - B.x , C.y - B.y );
        return AB.dot( BC );
    }
    /// cross product of AB & BC ( AB vector , BC vector )
    double crossABC( point A , point B , point C ) {
        point AB = point( B.x - A.x , B.y - A.y ); point AC = point( C.x - A.x , C.y - A.y );
        return AB.cross( AC );
    }
    /// 0 = Collinear, 1 = Clockwise, 2 = Counterclockwise.
    int Orientation( point P , point Q , point R ) {
        LL ret = ( Q.y - P.y ) * ( R.x - Q.x ) - ( Q.x - P.x ) * ( R.y - Q.y );
        if ( ret > 0 ) return 1; ///Polar angle of (Q - R) is smaller than (P - Q) with respect to x axis.
        if ( ret < 0 ) return 2; ///Polar angle of (Q - R) is greater than (P - Q) with respect to x axis.
        return 0;
    }
    bool CoLinear( point a , point b , point c ) { return ( Orientation( a , b , c ) == 0 ); }
    double PolygonArea( vector < point > poly ) {
        double area = 0;
        int l = poly.size( );
        for ( int i = 1; i + 1 < l; i++ )
        area += ( poly[i].y-poly[0].y)*(poly[i+1].x-poly[i].x)-(poly[i].x-poly[0].x)*(poly[i+1].y-poly[i].y );
        return fabs( area / 2.0 );
    }
} P;

/// must include point template..

struct Line {

    /// Returns A,B,C of the Line equation Ax + By = C joining points p & q
    iii LineEqn( point p , point q ) {
        int a = q.y - p.y , b = p.x - q.x , c = a * p.x + b * p.y;
        return make_pair( make_pair( a,b ) , c );
    }
    /// Find minimum distance between point C and line or segment ( A - B ) given end point
    double PointToLineDist( point a , point b , point c , bool seg ) {
        double d = P.crossABC( a , b , c ) / a.dist( b );
        if( seg ) {
            if( P.dotABC( a , b , c ) > 0.0 ) return ( b.dist( c ) );
            if( P.dotABC( b , a , c ) > 0.0 ) return ( a.dist( c ) );
        }
        return fabs( d );
    }
    /// Point to Line distance given a point ( p ) & ( A , B , C ) of Line Ax+By+C = 0
    double PointLineDist( point p , double a , double b , double c ) {
        double u = fabs( a*p.x + b*p.y + c ) / ( sqrt( a*a + b*b ) );
        return u;
    }
    /// Check if point R lies on line segment ( P - Q )
    bool OnSegment( point P , point Q , point R ) {
        if ( R.x >= min( P.x , Q.x ) && R.x <= max( P.x , Q.x ) && R.y >= min( P.y , Q.y ) && R.y <= max( P.y , Q.y ) ) {
            return true;
        }
        else return false;
    }
    /// Check if line segment ( P1-P2 ) and line segment ( P3-P4 ) intersect or not
    bool SegmentIntersect( point P1 , point P2 , point P3 , point P4 ) {
        int o1 = P.Orientation( P1 , P2 , P3 ); int o2 = P.Orientation( P1 , P2 , P4 );
        int o3 = P.Orientation( P3 , P4 , P1 ); int o4 = P.Orientation( P3 , P4 , P2 );
        if ( o1 != o2 && o3 != o4 && o1 != 0 && o2 != 0 && o3 != 0 && o4 != 0 ) return true;
        if ( o1 == 0 && OnSegment( P1 , P2 , P3 ) ) return true; if ( o2 == 0 && OnSegment( P1 , P2 , P4 ) ) return true;
        if ( o3 == 0 && OnSegment( P3 , P4 , P1 ) ) return true; if ( o4 == 0 && OnSegment( P3 , P4 , P2 ) ) return true;
        return false;
    }
    /// Find Intersection point of line ( P1-P2 ) and (P3-P4)
    void IntersectionPoint( point P1 , point P2 , point P3 , point P4 ) {
        iii L1 = LineEqn( P1 , P2 );
        int A1 = L1.ff.ff , B1 = L1.ff.ss , C1 = L1.ss;
        iii L2 = LineEqn( P3 , P4 );
        int A2 = L2.ff.ff , B2 = L2.ff.ss , C2 = L2.ss;
        int dif = A1 * B2 - A2 * B1; /// Slope difference of the two lines
        if( dif == 0 ) {
            /// /// Lines are either collinear or parallel.
            vector < point > List;
            List.push_back( P1 ); List.push_back( P3 ); List.push_back( P4 ); List.push_back( P2 );
            if ( P.PolygonArea( List ) == 0 ) printf("Collinear\n");
            else printf("Parallel\n");
        }
        else {
            double x = ( B2 * C1 - B1 * C2 ) / dif; double y = ( A1 * C2 - A2 * C1 ) / dif;
            cerr << setprecision(10) << fixed << x << " " << y << endl; /// Return if needed.
        }
    }
    /// Find a point C on line AB such that distance from A to C is D.
    point pointAtDistanceD( point A , point B , double D ){
        point vecAB , C;
        vecAB.x = B.x - A.x;  vecAB.y = B.y - A.y;
        double norm = sqrt( SQ( vecAB.x ) + SQ( vecAB.y ) );
        vecAB.x /= norm;  vecAB.y /= norm;
        /// To find a point D distance away but outside the line then minus here.
        C.x = A.x + D*vecAB.x;  C.y = A.y + D*vecAB.y;
        return C;
    }
} L;

struct Circle {

    /// Find the intersection points of a line and a circle
    /// Parameters: Circle center, radius, line end points P1 and P2
    pair <point,point> LineCircleIntersectionPoints( point center , double r , point P1 , point P2 ) {
        double a1 = P2.x - P1.x; double a2 = P2.y - P1.y;
        double b1 = P1.x - center.x; double b2 = P1.y - center.y;
        // At^2 + Bt + C = 0
        double A = SQ(a1) + SQ(a2); double B = (a1*b1 + a2*b2)*2; double C = SQ(b1) + SQ(b2) - SQ(r);

        if( ( B*B - 4.0*A*C ) < 0 ) { /** Does not intersect */ }
        else if( ( B*B - 4.0*A*C ) == 0 ) { /** The line is tangent with the circle at a single point */ }
        else{
            /// The line intersect the circle at two points
            double t1 = (-B - sqrt(B*B - 4.0*A*C))/2.0/A; double t2 = (-B + sqrt(B*B - 4.0*A*C))/2.0/A;
            point E1 = { P1.x + a1*t1 , P1.y + a2*t1 };  point E2 = { P1.x + a1*t2 , P1.y + a2*t2 };
            return make_pair( E1 , E2 );
        }
    }
    /// Find intersected area of two circles
    /// Parameters: 1st circle center, radius, 2nd circle center, radius
    double CircleCircleIntersectionArea( point P0 , double R0 , point P1 , double R1 ) {
        double d = P0.dist( P1 );
        if( R0 + R1 <= d ) return 0;
        if( R0 >= R1 && ( R0 - R1 ) >= d ) return pi * SQ(R1);
        if( R0 <= R1 && ( R1 - R0 ) >= d ) return pi * SQ(R0);
        double CAD = 2.0 * acos( (SQ(R0) + SQ(d) - SQ(R1) ) / ( 2.0 * R0 * d ) );
        double CBD = 2.0 * acos( (SQ(R1) + SQ(d) - SQ(R0) ) / ( 2.0 * R1 * d ) );
        //double A1 = (0.5 * SQ(R0) * CAD) - (0.5 * SQ(R0) * sin(CAD));
        double A1 = 0.5 * SQ(R0) * ( CAD - sin(CAD) );
        //double A2 = (0.5 * SQ(R1) * CBD) - (0.5 * SQ(R1) * sin(CBD));
        double A2 = 0.5 * SQ(R1) * ( CBD - sin(CBD) );
        return ( A1 + A2 );
    }
    /// Find intersection points of two circles
    /// Parameters: 1st circle center, radius, 2nd circle center, radius
    void CircleCircleIntersectionPoints( point P0 , double R0 , point P1 , double R1 ) {
        double d = P0.dist( P1 );
        if( d > R0 + R1 ){ /** They don't intersect.*/ }
        else if( d < fabs(R0 - R1) ) { /** One fully contains the other one.*/ }
        else if( fabs(d - 0) < eps && R0 == R1 ) { /** Both are same circle.*/ }
        else{
            /// The circles intersect with each other
            double a = ( SQ(R0) - SQ(R1) + SQ(d) ) / (2.0 * d); double b = d - a;
            double h = sqrt(SQ(R0) - SQ(a));
            double rx = -(P1.y - P0.y) * (h/d); double ry = (P1.x - P0.x) * (h/d);
            point P2;
            P2.x = P0.x + ( a * ( P1.x - P0.x ) ) / d; P2.y = P0.y + ( a * ( P1.y - P0.y ) ) / d;
            point E1 = { P2.x + rx , P2.y + ry }; point E2 = { P2.x - rx , P2.y - ry };
            P.print( E1 ); P.print( E2 );
            /// E1, E2 are the intersection points. Return if needed.
        }
    }
    /// Find the center of the circle which pass through point a & b having radius R.
    void FindCenterGivenTwoPointsOnIt( point a , point b , double R ) {
        point g1,g2;
        double x1 = a.x, x2 = b.x; double y1 = a.y, y2 = b.y; double d = a.dist( b );
        if ( d * d > 4.0 * R * R ) { /** Not Possible to Find any Center;*/ return; }
        double x_part = sqrt( R * R - 0.25 * d * d ) * ( y1 - y2 ) / d;
        double y_part = sqrt( R * R - 0.25 * d * d ) * ( x2 - x1 ) / d;
        double x3 = 0.5 * ( x1 + x2 ), y3 = 0.5 * ( y1 + y2 );
        g1 = point( x3 + x_part, y3 + y_part ); /// One possible center
        g2 = point( x3 - x_part, y3 - y_part ); /// Another possible center
        P.print( g1 ); P.print( g2 );
    }
    /// Given 3 points A, B, C on the circumference of a circle
    /// Find the center of that circle
    point CircleCenter( point A , point B , point C ) {
        double yDelta_a = B.y - A.y; double xDelta_a = B.x - A.x;
        double yDelta_b = C.y - B.y; double xDelta_b = C.x - B.x;
        point center = point( 0.0 , 0.0 );
        double aSlope = yDelta_a/xDelta_a; double bSlope = yDelta_b/xDelta_b;
        center.x = (aSlope*bSlope*(A.y - C.y) + bSlope*(A.x + B.x)- aSlope*(B.x + C.x) )/(2* (bSlope - aSlope));
        center.y = -1*( center.x - (A.x + B.x) / 2 ) / aSlope +  ( A.y + B.y ) / 2;
        return center;
    }
} C;

int main( int argc, char const *argv[] ) {

    return 0;
}












