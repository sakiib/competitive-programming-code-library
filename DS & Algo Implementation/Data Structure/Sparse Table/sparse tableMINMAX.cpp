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
int n;
int a[ N ];
int MX[ N ][ k ], MN[ N ][ k ];
int lg[ N ];

void Build_Table( ) {
        for( int i = 1; i <= n; i++ ) MN[i][0] = MX[i][0] = a[i];
        for( int i = 2; i <= n; i++ ) lg[i] = lg[i/2] + 1;
        for( int j = 1; ( 1 << j ) <= n; j++ ) {
                for( int i = 1; i + ( 1 << j ) - 1 <= n; i++ ) {
                        MN[i][j] = min( MN[i][j-1] , MN[ i + ( 1 << (j-1) ) ][j-1] );
                        MX[i][j] = max( MX[i][j-1] , MX[ i + ( 1 << (j-1) ) ][j-1] );
                }
        }
}
pair <int,int> Query( int l , int r ) {
        if( l > r ) swap( l , r );
        int k = lg[r-l+1];
        int mn = min( MN[l][k] , MN[ r - ( 1 << k ) + 1 ][k] );
        int mx = max( MX[l][k] , MX[ r - ( 1 << k ) + 1 ][k] );
        return { mn , mx };
}
int main( int argc, char const *argv[] ) {
    cin >> n;
    for( int i = 1; i <= n; i++ ) cin >> a[i];

    Build_Table( );

    int q;
    cin >> q;
    while( q-- ) {
        int l , r;
        cin >> l >> r;
        pair <int,int> p = Query( l , r );
        cout << p.first << " " << p.second << endl;
    }
    return 0;
}

