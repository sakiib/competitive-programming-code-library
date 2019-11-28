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
        double dist( const Point p ) { return ( sqrt( (x-p.x)*(x-p.x) + (y-p.y)*(y-p.y) ) ); }
        LL sqdist( const Point p ) { return ( ( (x-p.x)*(x-p.x) + (y-p.y)*(y-p.y) ) ); }
} P;

int n;
vector <Point> V;

int Orientation( Point st , Point mid , Point ed ) {
        LL v = ( ed - st ).cross( mid - st );
        if( !v ) return 0;
        return v < 0 ? 1 : -1;
}
bool Convex( vector <Point> V ) {
        bool hasPos = false , hasNeg = false;
        for( int i = 0; i < V.size(); i++ ) {
                int ori = Orientation( V[i] , V[(i+1)%n] , V[(i+2)%n] );
                if( ori > 0 ) hasPos = true;
                if( ori < 0 ) hasNeg = true;
        }
        return !( hasPos && hasNeg );
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( NULL );
        while( cin >> n ) {
                if( n == 0 ) break;
                V.clear();
                for(int i = 1; i <= n; i++ ) {
                        LL x , y;
                        cin >> x >> y;
                        V.push_back( Point( x , y ) );
                }
                if( Convex( V ) ) cout << "No" << endl;
                else cout << "Yes" << endl;
        }
        return 0;
}











