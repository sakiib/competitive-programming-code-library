#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define All(V) V.begin(),V.end()
#define Unique(V) sort( All(V)),V.erase( unique( All(V) ),V.end() )
#define Fast_IO ios_base::sync_with_stdio(0); cin.tie(0);

#define Fix( x ) setprecision( x ) << fixed

typedef long long int LL;
const int N = 1e5 + 5;
const int inf = 1e9;
const LL INF = 1e18;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int MOD = 1000000007;

struct point {
    double x , y;
    point( ) { }
    point( double _x , double _y ) { x = _x , y = _y; }
    point operator + ( const point p ) { return point( x + p.x , y + p.y ); }
    point operator - ( const point p ) { return point( x - p.x , y - p.y ); }
    point operator * ( double k ) { return point( x * k , y * k ); }
    point operator / ( double k ) { return point( x / k , y / k ); }

    void in( point &p ) { cin >> p.x >> p.y; }
    void print( point p )  { cerr << Fix(5) << fixed <<"( "<< p.x << " , " << p.y <<" )"<< endl; }
    double dist( const point p ) { return ( sqrt( (x-p.x)*(x-p.x) + (y-p.y)*(y-p.y) ) ); }
    double sqdist( const point p ) { return ( ( (x-p.x)*(x-p.x) + (y-p.y)*(y-p.y) ) ); }
} P;

struct MAX_BIPARTITE_MATCHING_KUHN {

        static const int MAXN = 2e2 + 5;

        int n , m , match[ MAXN ];
        bool visited[ MAXN ];
        vector <int> graph[ MAXN ];

        void Initialize( int _n , int _m ) {
                n = _n , m = _m;
                for( int i = 0; i < MAXN; i++ ) graph[i].clear();
        }
        void AddEdge( int u , int v ) {
                graph[ u ].push_back( v );
        }
        bool FindMatch( int s ) {
                visited[ s ] = true;
                for( int i = 0; i < graph[ s ].size(); i++ ) {
                        int node = graph[ s ][ i ];
                        int next = match[ node ];
                        if( visited[ next ] ) continue;
                        if( next == 0 || FindMatch( next ) ) {
                                match[ node ] = s;
                                return true;
                        }
                }
                return false;
        }
        int MaximumMatch( ) {
                int mx_matching = 0;
                memset( match , 0 , sizeof(match) );
                for( int i = 1; i <= n; i++ ) {
                        memset( visited , false , sizeof(visited) );
                        if( FindMatch( i ) ) mx_matching++;
                }
                return mx_matching;
        }
} kuhn;

int n , k;
vector <point> cat , rat;

void Build( double mx_dist ) {
        kuhn.Initialize( n , n );
        for( int i = 0; i < cat.size(); i++ ) {
                for( int j = 0; j < rat.size(); j++ ) {
                        double d = cat[i].dist( rat[j] );
                        if( d > mx_dist ) kuhn.AddEdge( i+1 , j+1 );
                }
        }
}
double BinarySearch( ) {
        double lo = 1.0 , hi = 1e9 , ret = -1.0;
        int it = 100;
        while( it-- ) {
                double mid = 0.5 * ( lo + hi );
                Build( mid );
                int match = kuhn.MaximumMatch();
                int unmatch = 2*n - match;
                if( unmatch >= k ) {
                        ret = mid;
                        hi = mid;
                }
                else lo = mid;
        }
        return ret;
}
int main( int argc , char const *argv[] ) {
        Fast_IO;
        cin >> n >> k;
        for( int i = 1; i <= n; i++ ) {
                point p;
                P.in( p );
                cat.push_back( p );
        }
        for( int i = 1; i <= n; i++ ) {
                point p;
                P.in( p );
                rat.push_back( p );
        }
        double ans = BinarySearch( );
        cout << Fix(10) << ans << endl;
        return 0;
}






