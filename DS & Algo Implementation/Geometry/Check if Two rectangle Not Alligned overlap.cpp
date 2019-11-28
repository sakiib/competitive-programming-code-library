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
        int x , y;
        Point( ) {}
        Point( int x , int y ) : x( x ) , y( y ) {}
        Point operator + ( Point p ) {
                return Point ( x + p.x, y + p.y );
        }
        Point operator - ( Point p ) {
                return Point ( x - p.x, y - p.y );
        }
        void in( Point &a ) {
                cin >> a.x >> a.y;
        }
        void see( Point a ) {
                cout << "( " << a.x << " " << a.y << " )" << endl;
        }
        int PolygonArea( vector <Point> poly ) {
                int area = 0;
                for ( int i = 1; i + 1 < poly.size(); i++ )
                area += ( poly[i].y - poly[0].y ) * ( poly[i+1].x - poly[i].x )
                      - ( poly[i].x - poly[0].x ) * ( poly[i+1].y - poly[i].y );
                return abs( area );
        }
} P;

vector <Point> A , B;

bool Inside( Point x , vector <Point> V ) {
        int total = P.PolygonArea( V );
        int small = 0;
        for( int i = 0; i < V.size(); i++ ) {
                vector <Point> temp = { x , V[i] , V[(i+1)%4] };
                small += P.PolygonArea( temp );
        }
        return ( small == total );
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( NULL );
        Point a;
        for( int i = 1; i <= 4; i++ ) {
                P.in( a );
                A.push_back( a );
        }
        for( int i = 1; i <= 4; i++ ) {
                P.in( a );
                B.push_back( a );
        }
        for( int i = -100; i <= 100; i++ ) {
                for( int j = -100; j <= 100; j++ ) {
                        if( Inside( Point( i , j ) , A ) && Inside( Point( i , j ) , B ) ) {
                                return cout << "YES" << endl,0;
                        }
                }
        }
        cout << "NO" << endl;
        return 0;
}












