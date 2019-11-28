#include <bits/stdc++.h>
using namespace std;

#define Fast_IO ios_base::sync_with_stdio(0); cin.tie(0);

typedef unsigned long long uLL;
typedef long long int LL;
const int N = 1e5 + 5;
const int inf = 1e9;
const LL INF = 1e18;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int MOD = 1000000007;
#define SQ(x) ((x)*(x))

/**
 Find the points & Perimeter of Convex Hull
 points are Clock Wise Sorted
 */

struct point {
        double x, y;
        point () {}
        point( double x , double y ) : x(x), y(y) {}
        void operator = ( const point &p ) { x = p.x, y = p.y; }
        bool operator < ( const point &p ) { return x == p.x ? y < p.y : x < p.x; }
        point operator + ( const point &p ) const { point pt( x + p.x, y + p.y ); return pt; }
        point operator - ( const point &p ) const { point pt( x - p.x, y - p.y ); return pt; }
        double crossProduct( const point &p ) const { return x * p.y - y * p.x; }
        double dotProduct( const point &p ) const { return x * p.x + y * p.y; }
        double dist( point q ){ return sqrt( SQ( x-q.x ) + SQ( y-q.y ) ); }
};
bool comp( point &p1, point &p2 ) { return p1.x != p2.x ? p1.x < p2.x : p1.y < p2.y; }

bool cw( point &a, point &b, point &c ) {
        double area = a.x*( b.y-c.y ) + b.x*( c.y-a.y ) + c.x*( a.y-b.y ); return area < 0;
}
bool ccw( point &a, point &b, point &c ) {
        double area = a.x*( b.y-c.y ) + b.x*( c.y-a.y ) + c.x*( a.y-b.y ); return area > 0;
}
vector <point> convex_hull( vector<point> &v ) {
        if( v.size() == 1 ) return v;
        sort( v.begin() , v.end() );
        point p1 = v[0] , p2 = v.back();
        vector <point> up , down;
        up.push_back( p1 ) , down.push_back( p1 );
        for( int i = 1; i < v.size(); i++ ) {
                if( i == v.size()-1 || cw( p1, v[i], p2 ) ) {
                        while( up.size() >= 2 && !cw( up[up.size()-2], up[up.size()-1], v[i] ) )
                                up.pop_back();
                                up.push_back( v[i] );
                }
                if( i == v.size()-1 || ccw( p1, v[i], p2 ) ) {
                        while( down.size() >= 2 && !ccw( down[down.size()-2], down[down.size()-1], v[i] ) )
                                down.pop_back();
                                down.push_back( v[i] );
                }
        }
        for( int i = down.size()-2; i > 0; i-- ) up.push_back( down[i] );
        return up;
}
int main( int argc , char const *argv[] ) {
        int n;
        int tc = 0;
        while( cin >> n ) {
                if( n == 0 ) break;
                vector <point> V;
                point p;
                for( int i = 1; i <= n; i++ ) {
                        cin >> p.x >> p.y;
                        V.push_back( p );
                }
                vector <point> c = convex_hull( V );
                int sz = c.size();
                double d = 0.0;
                cout << "Region #" << ++tc << ":" << endl;
                for( int i = 0; i < c.size(); i++ ) {
                        d += ( c[ (i+1)%sz ].dist( c[i] ) );
                        cout << setprecision(1) << fixed << "(" << c[i].x << "," << c[i].y << ")-";
                }
                cout << setprecision(1) << "(" << c[0].x << "," << c[0].y << ")" << endl;
                cout << "Perimeter length = " << setprecision(2) << fixed << d << endl;
        }
        return 0;
}







