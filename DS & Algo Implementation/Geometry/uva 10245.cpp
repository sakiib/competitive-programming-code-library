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

#define SQ(x) ((x)*(x))
struct point {
        long double x , y;
        point( ) {}
        point( double x , double y ) : x( x ) , y( y ) {}
        bool operator <( const point &q ) const {
                return ( x == q.x ) ? ( y < q.y ) : ( x < q.x );
        }
        long double Dist( const point &q ) { return SQ( x-q.x ) + SQ(y-q.y); }
};

int n;
vector <point> V;

long double BruteForce( int l , int r ) {
        long double ret = INF;
        for( int i = l; i <= r; i++ ) {
                for( int j = i+1; j <= r; j++ ) {
                        ret = min( ret , V[i].Dist( V[j] ) );
                }
        }
        return ret;
}
long double Solve( int l , int r ) {
        if( ( r - l ) <= 3 ) return BruteForce( l , r );
        int mid = ( l + r ) >> 1;
        long double d = min( Solve( l , mid ) , Solve( mid + 1 , r ) );
        vector <point> t;
        for( int i = l; i <= r; i++ ) {
                if( SQ( V[mid].x - V[i].x ) <= d ) {
                        t.push_back( point( V[i].y , V[i].x ) );
                }
        }
        sort( t.begin() , t.end() );
        for( int i = 0; i < t.size(); i++ ) {
                for( int j = i+1; j < t.size() && j <= i + 6; j++ ) {
                        d = min( d , t[i].Dist( t[j] ) );
                }
        }
        return d;
}
long double ClosestPairDistance( ) {
        sort( V.begin() , V.end() );
        return Solve( 0 , V.size() - 1 );
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( NULL );
        while( cin >> n ) {
                if( n == 0 ) break;
                V.clear();
                cout << setprecision(4) << fixed;
                long double x , y;
                for( int i = 1; i <= n; i++ ) {
                        cin >> x >> y;
                        V.push_back( point( x , y ) );
                }
                long double d = ClosestPairDistance( );
                long double ans = sqrt(d*1.0);
                if( ans + EPS < 10000.0 ) cout << ans << endl;
                else cout << "INFINITY" << endl;
        }
        return 0;
}











