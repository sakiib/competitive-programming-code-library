#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
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
const double EPS = 1e-9;
const int MOD = 1000000007;

double a , b , c , x;

double calc1( double p ) {
        double ret = sqrt( c*c+p*p ) + sqrt( (a-p)*(a-p) + (b+c)*(b+c) );
        return ret;
}
double calc2( double p , double base , double up ) {
        double ret = sqrt( (up-p)*(up-p) + base*base ) + sqrt( c*c + p*p );
        return ret;
}
double TernarySearch1( double l , double r ) {
        double lo = l , hi = r , ret = 1e18;
        int iter = 100;
        while( iter-- && hi - lo > EPS ) {
                double midL = ( 2.0 * lo + hi )/3.0;
                double midR = ( lo + 2.0 * hi )/3.0;
                double distA = calc1( midL );
                double distB = calc1( midR );
                if( distA < distB ) hi = midR;
                else lo = midL;
        }
        return min( calc1( lo ) , calc1( hi ) );
}
double TernarySearch2( double l , double r , double base , double up ) {
        double lo = l , hi = r , ret = 1e18;
        int iter = 100;
        while( iter-- && hi - lo > EPS ) {
                double midL = ( 2.0 * lo + hi )/3.0;
                double midR = ( lo + 2.0 * hi )/3.0;
                double distA = calc2( midL , base , up );
                double distB = calc2( midR , base, up );
                if( distA < distB ) hi = midR;
                else lo = midL;
        }
        return min( calc2( lo , base, up ) , calc2( hi , base , up ) );
}
int main( int argc , char const *argv[] ) {
        int t;
        scanf("%d",&t);
        while( t-- ) {
                scanf("%lf %lf %lf %lf",&a,&b,&c,&x);
                double ans = 0.0;
                double A = TernarySearch1( 0.0 , a ); /// home to riv + riv to grandma
                ans += A;
                double tot = sqrt( a*a + b*b );
                double percent = tot * x * 0.01;
                ans += percent; /// walk x% towards home
                double theta = atan( b/a );
                double H = percent * cos( theta );
                double B = percent * sin( theta );
                double rem = b + c - B;
                double up = a - H;
                double now = TernarySearch2( 0.0 , up , rem , up ); ///x to riv + riv to home
                ans += now;
                printf("%0.9f\n",ans);
        }
        return 0;
}











