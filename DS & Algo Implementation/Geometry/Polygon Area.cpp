#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1.0);
const double EPS = 1e-8;

struct Point {
        int x , y;
        Point( ) {}
        Point( int x , int y ) : x( x ) , y( y ) {}
        Point operator + ( Point p ) {
                return Point ( x + p.x, y + p.y );
        }
        Point operator - ( Point p ) {
                return Point ( x - p.x, y - p.y );
        }
        Point operator * ( int k ) { return Point( x * k , y * k ); }
        int PolygonArea( vector <Point> &poly ) {
                int area = 0;
                if( poly.size() < 3 ) return 0;
                for ( int i = 1; i + 1 < poly.size(); i++ )
                area += ( poly[i].y - poly[0].y ) * ( poly[i+1].x - poly[i].x )
                      - ( poly[i].x - poly[0].x ) * ( poly[i+1].y - poly[i].y );
                return abs( area ); /// area is twice the actual area
        }
} P;

int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( NULL );
        vector <Point> tria = { {0,0} , {20,0} , {10,30} };
        Point A = {10,15};
        int tot_area = P.PolygonArea( tria );
        int small_areas = 0;
        for( int i = 0; i < 3; i++ ) {
                vector <Point> V = { tria[i] , tria[(i+1)%3] , A };
                small_areas += P.PolygonArea( V );
        }
        cout << ( small_areas == tot_area ? "Inside" : "Outside" ) << endl;
        return 0;
}











