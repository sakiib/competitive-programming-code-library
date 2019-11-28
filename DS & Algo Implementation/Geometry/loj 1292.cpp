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

int n;

/**
Maximmum points coLinear
*/
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
        LL sqdist( const Point p ) { return ( ( (x-p.x)*(x-p.x) + (y-p.y)*(y-p.y) ) ); }
} P;
vector <Point> V;

LL Orientation( Point st , Point mid , Point ed ) {
        LL v = ( ed - st ).cross( mid - st );
        if( !v ) return 0;
        return v > 0 ? 1 : -1;
}
bool coLinear( Point a , Point b , Point c ) {
        LL ori = Orientation( a , b , c );
        return ori == 0;
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
                        V.push_back( Point( x , y ) );
                }
                int mx = 0;
                if( n <= 2 ) {
                        printf("Case %d: %d\n",tc,n);
                        continue;
                }
                for( int i = 0; i < V.size(); i++ ) {
                        for( int j = i+1; j < V.size(); j++ ) {
                                int cnt = 0;
                                for( int k = j+1; k < V.size(); k++ ) {
                                        if( coLinear( V[i] , V[j] , V[k] ) ) cnt++;
                                }
                                cnt += 2;
                                mx = max( mx , cnt );
                        }
                }
                printf("Case %d: %d\n",tc,mx);
        }
        return 0;
}











