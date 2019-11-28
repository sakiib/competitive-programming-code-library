#include <bits/stdc++.h>
using namespace std;

#define Fast_IO ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long int LL;
const int N = 5e4 + 5;
const LL INF = 1e18;
#define SQ(x) ((x)*(x))

struct RET {
        double res;
        int u , v;
        RET(){}
        RET( double res , int u , int v ):res(res) , u(u) , v(v){}
};
struct Point {
        double x , y;
        int idx;
        Point(){}
        Point( double x , double y , int idx ):x(x) , y(y) , idx(idx){}
        double Dist( const Point &q ) {return sqrt(SQ( x-q.x ) + SQ( y-q.y ));}
};
bool CompareX( const Point &a , const Point &b ) {
        return a.x < b.x;
}
bool CompareY( const Point &a , const Point &b ) {
        return a.y < b.y;
}
RET BruteForce( Point P[] , int n ) {
        double Min = INF;
        int u = 0 , v = 0;
        for( int i = 0; i < n; i++ ) {
                for( int j = i+1; j < n; j++ ) {
                        if( P[i].Dist( P[j] ) < Min ) {
                                u = P[i].idx;
                                v = P[j].idx;
                                Min = P[i].Dist( P[j] );
                        }
                }
        }
        return RET( Min , u , v );
}
RET ClosestPairInStrip( Point Strip[] , int SZ , RET d ) {
        double curMin = d.res;
        int u = d.u , v = d.v;
        for( int i = 0; i < SZ; i++ ) {
                for( int j = i+1; j < SZ && ( Strip[j].y - Strip[i].y ) < curMin; j++ ) {
                        if( Strip[i].Dist( Strip[j] ) < curMin ) {
                                curMin = Strip[i].Dist( Strip[j] );
                                u = Strip[i].idx;
                                v = Strip[j].idx;
                        }
                }
        }
        return RET( curMin , u ,  v );
}
RET FindPoint( Point Px[] , Point Py[] , int n ) {
        if( n <= 3 ) return BruteForce( Px , n );
        int mid = n/2;
        Point midPoint = Px[ mid ];
        Point leftSide[ mid ];
        Point rightSide[ n-mid ];
        int leftIdx = 0 , rightIdx = 0;
        for( int i = 0; i < n; i++ ) {
                if( Py[i].x <= midPoint.x ) leftSide[ leftIdx++ ] = Py[i];
                else rightSide[ rightIdx++ ] = Py[i];
        }
        RET disLeft = FindPoint( Px , leftSide , mid );
        RET disRight = FindPoint( Px + mid , rightSide , n - mid );
        RET curBest = disLeft;
        if( disLeft.res < disRight.res ) curBest = disLeft;
        else curBest = disRight;
        double MinDist = curBest.res;
        Point Strip[ n+1 ];
        int j = 0;
        for( int i = 0; i < n; i++ ) {
                if( abs( Py[i].x - midPoint.x ) < MinDist ) Strip[j] = Py[i] , j++;
        }
        RET nCur = ClosestPairInStrip( Strip , j , curBest );
        if( curBest.res < nCur.res ) return curBest;
        return nCur;
}

Point Px[ N ];
Point Py[ N ];

RET ClosestPairofPoint( Point P[] , int n ) {
        for( int i = 0; i < n; i++ ) Px[i] = P[i] , Py[i] = P[i];
        sort( Px , Px+n , CompareX );
        sort( Py , Py+n , CompareY );
        return FindPoint( Px , Py , n );
}

int n;
Point P[ N ];

int main( int argc , char const *argv[] ) {
        cin >> n;
        for( int i = 0; i < n; i++ ) {
                cin >> P[i].x >> P[i].y;
                P[i].idx = i;
        }
        RET res = ClosestPairofPoint( P , n );
        int u = min( res.u , res.v );
        int v = max( res.u , res.v );
        cout << u << " " << v << " ";
        cout << setprecision(6) << fixed << res.res << endl;
        return 0;
}







