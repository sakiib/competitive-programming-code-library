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
        Point( ) : x(0) , y(0) {}
        Point( LL x , LL y ) : x(x) , y(y) {}
        void show( Point a ) {
                cerr << "( " << a.x << " , " << a.y << " )" << endl;
        }
} P;

struct Rectangle {
        Point BLeft , BRight , TLeft , TRight;
        Rectangle( ) {}
        Rectangle( Point _BLeft , Point _TRight , Point _BRight , Point _TLeft ) {
                 BLeft = _BLeft , TRight = _TRight , BRight = _BRight , TLeft = _TLeft;
        }
        Rectangle( Point a , Point b , int type ) {
                if( type == 1 ) { /// Given Bottom Left & Top Right corners
                        BLeft = a , TRight = b;
                        BRight = Point( TRight.x , BLeft.y );
                        TLeft = Point( BLeft.x , TRight.y );
                } else { /// Given Bottom Right & Top Left corners
                        BRight = a , TLeft = b;
                        BLeft = Point( TLeft.x , BRight.y );
                        TRight = Point( BRight.x , TLeft.y );
                }
        }
        void show( ) {
                P.show( BLeft ) , P.show( BRight ) , P.show( TLeft ) , P.show( TRight );
        }
        LL Area( ) {
                LL Length = abs( BRight.x - BLeft.x ) , Width = abs( TLeft.y - BLeft.y );
                return Length * Width;
        }
        /// on edge is considered overlapping here..
        bool overlap( Rectangle a ) { ///given Top Left & Bottom Right corners
                if( TLeft.x > a.BRight.x || a.TLeft.x > BRight.x ) return false;
                if( TLeft.y < a.BRight.y || a.TLeft.y < BRight.y ) return false;
                return true;
        }
        LL Intersection( Rectangle a ) { /// given Bottom Left & TopRight Corners
                if( !overlap( a ) ) return 0;
                LL ret = ( min( TRight.x , a.TRight.x ) - max( BLeft.x , a.BLeft.x ) ) *
                         ( min( TRight.y , a.TRight.y ) - max( BLeft.y , a.BLeft.y ) );
                return ret;
        }
        LL Union( Rectangle a ) {
                return Area( ) + a.Area( ) - Intersection( a ) ;
        }
};

LL x1 , x2 , x3 , x4 , h;

int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( NULL );
        cin >> x1 >> x2 >> x3 >> x4 >> h;
        Rectangle A = Rectangle( Point( x1 , 0 ) , Point( x2 , h ) , Point( x2 , 0 ) , Point( x1 , h ) );
        Rectangle B = Rectangle( Point( x3 , 0 ) , Point( x4 , h ) , Point( x4 , 0 ) , Point( x3 , h ) );
        cout << A.Intersection( B ) << endl;
        return 0;
}










