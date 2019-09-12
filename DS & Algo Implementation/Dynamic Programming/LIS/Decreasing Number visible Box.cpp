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
int a[ N ] , b[ N ];
bool hidden[ N ];

int BS( int l , int r , int val ) {
        int ret = -1;
        while( l <= r ) {
                int m = ( l + r ) >> 1;
                if( b[m] >= 2*val ) ret = m , r = m - 1;
                else l = m + 1;
        }
        return ret;
}
int solve( ) {
        sort( a + 1 , a + n + 1 );
        for( int i = 1; i <= n; i++ ) b[i] = a[i];
        memset( hidden , false , sizeof( hidden ) );
        for( int i = 1; i < n; i++ ) {
                int pos = BS( i + 1 , n , a[i] );
                if( pos != -1 ) hidden[i] = true , b[pos] = b[pos-1];
        }
        int cnt = 0;
        for( int i = 1; i <= n; i++ ) cnt += ( !hidden[i] );
        return cnt;
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( nullptr );
        int t;
        cin >> t;
        for( int tc = 1; tc <= t; tc++ ) {
                cin >> n;
                for( int i = 1; i <= n; i++ ) cin >> a[i];
                cout << "Case "<< tc << ": "<< solve( ) << endl;
        }
        return 0;
}





