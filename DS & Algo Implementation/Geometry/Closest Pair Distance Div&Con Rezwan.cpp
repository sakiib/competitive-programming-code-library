#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
const int N = 1e5 + 5;
const LL INF = 1e18;
#define SQ(x) ((x)*(x))

/**
 Divide & Conquer.
 Return the Distance of the Closest Pair of points.
 */

struct point {
        LL x , y;
        point(){}
        point( LL x , LL y ) : x( x ) , y( y ) {}
        bool operator <( const point &q ) const {
                return ( x == q.x ) ? ( y < q.y ) : ( x < q.x );
        }
        LL Dist( const point &q ) {return SQ( x-q.x ) + SQ( y-q.y );}
};

int n;
LL a[ N ];

vector <point> V;

LL BruteForce( int l , int r ) {
        LL ret = INF;
        for( int i = l; i <= r; i++ ) {
                for( int j = i+1; j <= r; j++ ) {
                        ret = min( ret , V[i].Dist( V[j] ) );
                }
        }
        return ret;
}
LL Solve( int l , int r ) {
        if( ( r - l ) <= 3 ) return BruteForce( l , r );
        int mid = ( l + r ) >> 1;
        LL d = min( Solve( l , mid ) , Solve( mid + 1 , r ) );
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
LL ClosestPairDistance( ) {
        sort( V.begin() , V.end() );
        return Solve( 0 , V.size() - 1 );
}
int main( int argc , char const *argv[] ) {
        scanf("%d",&n);
        for( int i = 1; i <= n; i++ ) {
                scanf("%lld",&a[i]);
                a[i] += a[i-1];
                V.push_back( point( i , a[i] ) );
        }
        LL ans = ClosestPairDistance( );
        printf("%lld\n",ans);
        return 0;
}







