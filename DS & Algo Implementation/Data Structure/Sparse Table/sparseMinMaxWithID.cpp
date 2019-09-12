#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
typedef pair< int,int > ii;
typedef pair< int,ii > iii;
const int inf = 1e9;
const LL INF = 1e18;
const int N = 100005;
const int MOD = 1e9+7;
const double EPS = 1e-6;
const double PI = acos(-1.0);

const int k = 30;
int n , q;
int a[ N ] , lg[ N ];
int MX[ N ][ k ] , MN[ N ][ k ];
int MXID[ N ][ k ] , MNID[ N ][ k ];

void Build_STable( ) {
        for( int i = 1; i <= n; i++ ) {
                MX[ i ][ 0 ] = MN[ i ][ 0 ] = a[ i ] , MXID[ i ][ 0 ] = MNID[ i ][ 0 ] = i;
        }
        for( int i = 2; i <= n; i++ ) lg[i] = lg[ i/2 ] + 1;
        for( int j = 1; ( 1 << j ) <= n; j++ ) {
                for( int i = 1; i + ( 1 << j ) - 1 <= n; i++ ) {
                        if( MN[ i ][ j-1 ] <= MN[ i + ( 1 << (j-1) ) ][ j-1 ] ) {
                                MN[ i ][ j ] = MN[ i ][ j-1 ];
                                MNID[ i ][ j ] = MNID[ i ][ j-1 ];
                        }
                        else {
                                MN[ i ][ j ] = MN[ i + ( 1 << (j-1) ) ][ j-1 ];
                                MNID[ i ][ j ] = MNID[ i + ( 1 << (j-1) ) ][ j-1 ];
                        }
                        if( MX[ i ][ j-1 ] >= MX[ i + ( 1 << (j-1) ) ][ j-1 ] ) {
                                MX[ i ][ j ] = MX[ i ][ j-1 ];
                                MXID[ i ][ j ] = MXID[ i ][ j-1 ];
                        }
                        else {
                                MX[ i ][ j ] = MX[ i + ( 1 << (j-1) ) ][ j-1 ];
                                MXID[ i ][ j ] = MXID[ i + ( 1 << (j-1) ) ][ j-1 ];
                        }
                }
        }
}
pair <int,int> Query( int l , int r ) {
        if( l > r ) swap( l , r );
        int k = lg[ r-l+1 ];
        int mn = min( MN[ l ][ k ] , MN[ r - ( 1 << k ) + 1 ][ k ] );
        int mx = max( MX[ l ][ k ] , MX[ r - ( 1 << k ) + 1 ][ k ] );
        return { mn , mx };
}
pair <int,int> QueryID( int l , int r ) {
        if( l > r ) swap( l , r );
        int k = lg[ r-l+1 ];
        int mnid , mxid;
        if( MN[ l ][ k ] <= MN[ r - ( 1 << k ) + 1 ][ k ] ) mnid = MNID[ l ][ k ];
        else mnid = MNID[ r - ( 1 << k ) + 1 ][ k ];
        if( MX[ l ][ k ] >= MX[ r - ( 1 << k ) + 1 ][ k ] ) mxid = MXID[ l ][ k ];
        else mxid = MXID[ r - ( 1 << k ) + 1 ][ k ];
        return { mnid , mxid };
}
int main( int argc, char const *argv[] ) {
        cin >> n;
        for( int i = 1; i <= n; i++ ) cin >> a[i];
        Build_STable( );
        cin >> q;
        while( q-- ) {
                int l , r;
                cin >> l >> r;
                pair <int,int> p = Query( l+1 , r+1 );
                cout << p.first  << endl;
    }
    return 0;
}


