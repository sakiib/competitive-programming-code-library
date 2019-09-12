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
const double EPS = 1e-8;
const int MOD = 1000000007;

int n;
int a[ 805 ][ 805 ];
int val[ 805*805 ];

int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( nullptr );
        int q;
        cin >> n >> q;
        for( int i = 1; i <= n; i++ ) {
                for( int j = 1; j <= n; j++ ) {
                        cin >> a[i][j];
                }
        }
        while( q-- ) {
                int x1 , y1 , x2 , y2;
                cin >> x1 >> y1 >> x2 >> y2;
                int cnt = 0;
                for( int i = x1; i <= x2; i++ ) {
                        for( int j = y1; j <= y2; j++ ) {
                                val[++cnt] = a[i][j];
                        }
                }
                int med = ( cnt + 1 )/2;
                nth_element( val + 1 , val + med , val + cnt + 1 );
                cout << val[med] << endl;
        }
        return 0;
}












