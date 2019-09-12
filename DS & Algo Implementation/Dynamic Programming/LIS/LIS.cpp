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

/**
for longest decreasing , multiply values by -1
for non-decreasing change the 2nd (else if) condition >=
*/
int n;
int a[ N ];
vector <int> lis;

int LowerBound( vector <int> &tail , int l , int r , int key ) {
        while( r - l > 1 ) {
                int m = ( l + r ) >> 1;
                if( a[ tail[m] ] >= key ) r = m;
                else l = m;
        }
        return r;
}
int LIS( ) {
        vector <int> tail( N + 1 , 0 );
        vector <int> prev( N + 1 , -1 );
        lis.clear( );
        int len = 1;
        for( int i = 1; i < n; i++ ) {
                if( a[i] < a[ tail[0] ] ) tail[0] = i;
                else if( a[i] > a[ tail[ len-1 ] ] ) {
                        prev[i] = tail[ len-1 ] , tail[ len++ ] = i;
                }
                else {
                        int pos = LowerBound( tail , -1 , len - 1 , a[i] );
                        prev[i] = tail[ pos-1 ];
                        tail[pos] = i;
                }
        }
        for( int i = tail[ len-1 ]; i >= 0 && i < N; i = prev[i] ) lis.push_back( a[i] );
        reverse( lis.begin( ) , lis.end( ) );
        return len;
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( nullptr );
        cin >> n;
        for( int i = 0; i < n; i++ ) cin >> a[i];
        cout << "Length : " << LIS( ) << endl;
        for( auto x : lis ) cout << x << " ";
        return 0;
}











