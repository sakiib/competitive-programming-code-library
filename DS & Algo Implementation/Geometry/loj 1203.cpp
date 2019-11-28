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

struct point {
        LL x, y;
        point( ) {}
        point( LL x , LL y ) : x(x), y(y) {}
        void operator = ( const point &p ) { x = p.x, y = p.y; }
        bool operator < ( const point &p ) { return x == p.x ? y < p.y : x < p.x; }
        point operator + ( const point &p ) const { point pt( x + p.x, y + p.y ); return pt; }
        point operator - ( const point &p ) const { point pt( x - p.x, y - p.y ); return pt; }
        double cross( const point &p ) const { return x * p.y - y * p.x; }
        double dot( const point &p ) const { return x * p.x + y * p.y; }
};

int n;
vector <point> V;

bool comp( point &p1, point &p2 ) { return p1.x != p2.x ? p1.x < p2.x : p1.y < p2.y; }

bool cw( point &a, point &b, point &c ) {
        LL area = a.x*( b.y-c.y ) + b.x*( c.y-a.y ) + c.x*( a.y-b.y ); return area < 0;
}
bool ccw( point &a, point &b, point &c ) {
        LL area = a.x*( b.y-c.y ) + b.x*( c.y-a.y ) + c.x*( a.y-b.y ); return area > 0;
}
vector <point> convex_hull( vector<point> &v ) {
        if( v.size() == 1 ) return v;
        sort( v.begin(), v.end() );
        point p1 = v[0], p2 = v.back();
        vector <point> up , down;
        up.push_back( p1 );
        down.push_back( p1 );
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


int mod( int i , int n ) {
        if( i < 0 ) i += n;
        return i%n;
}
double toDegree( double r ) {
        return r * 180.0 / PI;
}
double norm( point a ) {
        return a.x * a.x + a.y * a.y;
}
double Angle( point a , point o , point b ) {
        point oa = a - o , ob = b - o;
        return toDegree( acos( oa.dot( ob ) / sqrt( norm(oa) * norm(ob) ) ) );
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
                        V.push_back( point( x , y ) );
                }
                vector <point> c = convex_hull( V );
                if( c.size() < 3 ) {
                        printf("Case %d: %.0f\n",tc,0.0);
                        continue;
                }
                int sz = c.size();
                double ans = inf;
                for( int i = 0; i < c.size(); i++ ) {
                        int j = mod( i - 1 , sz ) , k = mod( i+1 , sz );
                        double angle = Angle( c[k] , c[i] , c[j] );
                        ans = min( ans , fabs( angle ) );
                }
                printf("Case %d: %.6f\n",tc,ans);
        }
        return 0;
}











