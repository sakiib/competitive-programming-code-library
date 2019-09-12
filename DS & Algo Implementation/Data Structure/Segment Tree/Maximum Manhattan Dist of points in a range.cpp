#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL INF = 1e18;
const int N = 1e5 + 5;

struct point {
        LL x , y;
};

point a[ N ];
int n , q;
string s;
LL tree[ 4*N ][ 5 ][ 2 ]; // 0 - min , 1 - max

void build( int node , int b , int e ) {
        if( b > e ) return;
        if( b == e ) {
                tree[node][1][0] = tree[node][1][1] = a[b].x + a[b].y;
                tree[node][2][0] = tree[node][2][1] =  - a[b].x + a[b].y;
                tree[node][3][0] = tree[node][3][1] = a[b].x - a[b].y;
                tree[node][4][0] = tree[node][4][1] = - a[b].x - a[b].y;
                return;
        }
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        build( l , b , m );
        build( r , m + 1 , e );
        tree[node][1][0] = min( tree[l][1][0] , tree[r][1][0] );
        tree[node][1][1] = max( tree[l][1][1] , tree[r][1][1] );
        tree[node][2][0] = min( tree[l][2][0] , tree[r][2][0] );
        tree[node][2][1] = max( tree[l][2][1] , tree[r][2][1] );
        tree[node][3][0] = min( tree[l][3][0] , tree[r][3][0] );
        tree[node][3][1] = max( tree[l][3][1] , tree[r][3][1] );
        tree[node][4][0] = min( tree[l][4][0] , tree[r][4][0] );
        tree[node][4][1] = max( tree[l][4][1] , tree[r][4][1] );
}
void update( int node , int b , int e, int pos , LL nx , LL ny ) {
        if( b > e || pos > e || pos < b ) return;
        if( b == e && b == pos ) {
                tree[node][1][0] = tree[node][1][1] = nx + ny;
                tree[node][2][0] = tree[node][2][1] =  - nx + ny;
                tree[node][3][0] = tree[node][3][1] = nx - ny;
                tree[node][4][0] = tree[node][4][1] = - nx - ny;
                return;
        }
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        update( l , b , m , pos , nx , ny );
        update( r , m + 1 , e , pos , nx , ny );
        tree[node][1][0] = min( tree[l][1][0] , tree[r][1][0] );
        tree[node][1][1] = max( tree[l][1][1] , tree[r][1][1] );
        tree[node][2][0] = min( tree[l][2][0] , tree[r][2][0] );
        tree[node][2][1] = max( tree[l][2][1] , tree[r][2][1] );
        tree[node][3][0] = min( tree[l][3][0] , tree[r][3][0] );
        tree[node][3][1] = max( tree[l][3][1] , tree[r][3][1] );
        tree[node][4][0] = min( tree[l][4][0] , tree[r][4][0] );
        tree[node][4][1] = max( tree[l][4][1] , tree[r][4][1] );
}
LL querymx( int node , int b , int e , int i , int j , int id ) {
        if( i > e || j < b || b > e ) return -INF;
        if( i <= b && j >= e ) return tree[node][id][1];
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        return max( querymx( l , b , m , i , j , id ) , querymx( r , m + 1 , e , i , j , id ) );
}
LL querymn( int node , int b , int e , int i , int j , int id ) {
        if( i > e || j < b || b > e ) return INF;
        if( i <= b && j >= e ) return tree[node][id][0];
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        return min( querymn( l , b , m , i , j , id ) , querymn( r , m + 1 , e , i , j , id ) );
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( NULL );
        cin >> n;
        for( int i = 1; i <= n; i++ ) cin >> a[i].x >> a[i].y;
        build( 1 , 1 , n );
        cin >> q;
        while( q-- ) {
                cin >> s;
                if( s == "U" ) {
                        int pos;
                        LL nx , ny;
                        cin >> pos >> nx >> ny;
                        ++pos;
                        update( 1 , 1 , n , pos , nx , ny );
                }
                else {
                        int l , r;
                        cin >> l >> r;
                        ++l , ++r;

                        LL mx1 = querymx( 1 , 1 , n , l , r , 1 );
                        LL mn1 = querymn( 1 , 1 , n , l , r , 1 );

                        LL mx2 = querymx( 1 , 1 , n , l , r , 2 );
                        LL mn2 = querymn( 1 , 1 , n , l , r , 2 );

                        LL mx3 = querymx( 1 , 1 , n , l , r , 3 );
                        LL mn3 = querymn( 1 , 1 , n , l , r , 3 );

                        LL mx4 = querymx( 1 , 1 , n , l , r , 4 );
                        LL mn4 = querymn( 1 , 1 , n , l , r , 4 );
                        cout<< max( mx1 - mn1 , max( mx2 - mn2 , max( mx3 - mn3 , mx4 - mn4 ) ) ) << endl;
                }
        }
        return 0;
}
/**

https://discuss.codechef.com/questions/70645/mdist-editorial
Maximum Manhattan distance between a pair of points in a given range , with point update

Logic :
Manhattan dist(P1, P2) = |x1 - x2| + |y1 - y2|
             = max(  x1 - x2 +  y1 - y2,
                    -x1 + x2 +  y1 - y2,
                     x1 - x2 + -y1 + y2,
                    -x1 + x2 + -y1 + y2) )

             = max(  ( x1 + y1) - ( x2 + y2),
                     (-x1 + y1) - (-x2 + y2),
                     ( x1 - y1) - ( x2 - y2),
                     (-x1 - y1) - (-x2 - y2) )

             = max( f1(P1) - f1(P2),
                    f2(P1) - f2(P2),
                    f3(P1) - f3(P2),
                    f4(P1) - f4(P2) )

where f1(P) = +x+y, f2(P) = -x+y, f3(P) = +x-y, f4(P) = -x-y

tree build :
1 -> x + y
2 -> - x + y
3 -> x - y
4 -> - x - y

*/








