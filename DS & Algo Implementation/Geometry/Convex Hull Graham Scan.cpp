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
 Convex Hull ( graham scan )
 returns the points.
 change data type accordingly
 comp is also inside the point struct(same)
 points are Clock Wise Sorted
 for counter clock wise sorting chage last 2 lins -> up down vice versa & return down
 */

struct point {
        int x, y;
        point( ) {}
        point( int x , int y ) : x( x ), y( y ) {}
        void operator = ( const point &p ) { x = p.x, y = p.y; }
        bool operator < ( const point &p ) { return x == p.x ? y < p.y : x < p.x; }
        point operator + ( point p ) { return point ( x + p.x, y + p.y ); }
        point operator - ( point p ) { return point ( x - p.x, y - p.y ); }
        point operator * ( int k ) { return point( x * k , y * k ); }
        point operator / ( int k ) { return point( x / k , y / k ); }
        int cross( const point &p ) const { return x * p.y - y * p.x; }
        int dot( const point &p ) const { return x * p.x + y * p.y; }
        int dist( point q ){ return ( ( x - q.x ) * ( x - q.x ) + ( y - q.y ) * ( y - q.y ) ); }
};

bool comp( point &p1, point &p2 ) { return p1.x != p2.x ? p1.x < p2.x : p1.y < p2.y; }

bool cw( point &a, point &b, point &c ) {
        return ( a.x * ( b.y - c.y ) + b.x * ( c.y - a.y ) + c.x * ( a.y - b.y ) ) < 0;
}
bool ccw( point &a, point &b, point &c ) {
        return ( a.x * ( b.y - c.y ) + b.x * ( c.y - a.y ) + c.x * ( a.y - b.y ) ) > 0;
}
vector <point> convex_hull( vector<point> &v ) {
        if( v.size() == 1 ) return v;
        sort( v.begin(), v.end() );
        point p1 = v[0], p2 = v.back();
        vector <point> up , down;
        up.push_back( p1 ) , down.push_back( p1 );
        for( int i = 1; i < v.size(); i++ ) {
                if( i == v.size() - 1 || cw( p1, v[i], p2 ) ) {
                        while( up.size() >= 2 && !cw( up[up.size()-2], up[up.size()-1], v[i] ) )
                                up.pop_back();
                                up.push_back( v[i] );
                }
                if( i == v.size() - 1 || ccw( p1, v[i], p2 ) ) {
                        while( down.size() >= 2 && !ccw( down[down.size()-2], down[down.size()-1], v[i] ) )
                                down.pop_back();
                                down.push_back( v[i] );
                }
        }
        for( int i = down.size()-2; i > 0; i-- ) up.push_back( down[i] );
        return up;
}
int main( int argc , char const *argv[] ) {

        return 0;
}






