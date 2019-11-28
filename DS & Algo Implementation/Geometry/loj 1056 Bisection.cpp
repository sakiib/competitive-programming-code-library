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

int x , y;

double Bisection( ) {
        double lo = 0.0 , hi = 1e9 , ret = 0.0;
        int cnt = 200;
        while( cnt-- ) {
                double mid = ( lo + hi ) * 0.5;
                double l = x*mid , w = y*mid;
                double dia = sqrt(l*l + w*w)*0.5;
                double angle = acos( (dia*dia + dia*dia - w*w) / (2.0*dia*dia) );
                double s = dia * angle;
                double p = 2*l + 2*s;
                if( fabs( 400.0 - p ) <= EPS ) return mid;
                if( p > 400.0 ) hi = mid;
                else lo = mid;
        }
        return lo;
}
int main( int argc , char const *argv[] ) {
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
                scanf("%d : %d",&x,&y);
                double r = Bisection( );
                printf("Case %d: %.10f %.10f\n",tc,x*r,y*r);
        }
        return 0;
}











