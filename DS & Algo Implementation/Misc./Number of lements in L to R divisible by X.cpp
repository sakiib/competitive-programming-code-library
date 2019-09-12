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

#define all( V ) V.begin( ),V.end( )

int n , q;
int a[ N ];
vector <int> pos[ N ];
vector <int> V[ N ];

int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( NULL );
        cin >> n >> q;
        for( int i = 1; i <= n; i++ ) {
                cin >> a[i];
                pos[ a[i] ].push_back( i );
        }
        for( int i = 1; i <= 1e5; i++ ) {
                for( int j = i; j <= 1e5; j += i ) {
                        for( auto x : pos[j] ) {
                               V[i].push_back( x );
                        }
                }
        }
        for( int i = 1; i <= 1e5; i++ ) sort( V[i].begin() , V[i].end() );
        while( q-- ) {
                int l , r , g;
                cin >> l >> r >> g;
                int di = upper_bound( all( V[g] ) , r ) - lower_bound( all( V[g] ) , l );
                int gi = upper_bound( all( pos[g] ) , r ) - lower_bound( all( pos[g] ) , l );

                if( di == ( r - l + 1 ) ) {
                        if( gi == 0 ) cout << 1 << endl;
                        else cout << 0 << endl;
                }
                else {
                        cout << ( r - l + 1 - di ) << endl;
                }
        }
        return 0;
}












