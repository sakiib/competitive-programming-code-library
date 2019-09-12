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

const int MX = 64;
int n , k;
LL a[ N ];

void gauss( int n , int m , vector < bitset<MX> > &V ) {
        for( int row = 0 , col = m - 1; col >= 0 && row < n; col-- ) {
                for( int i = row; i < n; i++ ) {
                        if( V[i][col] ) {
                                swap( V[i] , V[row] );
                                break;
                        }
                }
                if( !V[row][col] ) continue;
                for( int i = 0; i < n; i++ ) {
                        if( i == row ) continue;
                        if( V[i][col] ) V[i] ^= V[row];
                }
                row++;
         }
         //for( auto x : V ) cout << x << endl;
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( nullptr );
        cin >> n;
        vector < bitset<MX> > V;
        for( int i = 1; i <= n; i++ ) cin >> a[i] , V.push_back( bitset<MX>( a[i] ) );
        gauss( n , MX , V );
        LL ans = 0;
        for( int i = 0; i < n; i++ ) {
                LL temp = 0;
                for( int j = 0; j < MX; j++ ) {
                        temp |= ( 1LL << j ) * V[i][j];
                }
                //cout << "temp: " << temp << endl;
                if( ( ans^temp ) > ans ) ans ^= temp;
        }
        cout << ans << endl;
        return 0;
}












