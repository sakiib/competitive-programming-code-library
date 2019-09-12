#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
typedef unsigned long long uLL;
typedef long long int LL;
typedef pair <int,int> pii;
typedef pair <int,pii> piii;
typedef pair <long long,long long> pll;
typedef pair <long long,pll> plll;
const int N = 2e5 + 5;
const int inf = 1e9;
const long long INF = 1e18;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int MOD = 1000000007;

int n;
int a[ N ];

struct segment {
        int l , r , id , len;
        segment( ) : l( 0 ) , r( 0 ) , id( 0 ) , len( 0 ) {}
        segment( int l , int r , int id , int len ) :
                  l( l ) , r( r ) , id( id ) , len( len ) {}
        bool operator <( const segment &q ) const {
                if( len == q.len ) return id < q.id;
                return len >q.len;
        }
};
vector <segment> V;

int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( nullptr );
        cin >> n;
        for( int i = 1; i <= n; i++ ) cin >> a[i];
        for( int i = 1; i <= n; ) {
                if( i + 1 <= n && a[i+1] == a[i] ) {
                        int j = i + 1;
                        while( j <= n && a[j] == a[i] ) j++;
                        V.push_back( segment( i , j - 1 , i , j - i ) );
                        i = j;
                }
                else V.push_back( segment( i , i , i , 1 ) ) , i++;
        }
        for( auto x : V ) cout << x.l << " " << x.r << " " << x.id << " " << x.len <<endl;
        return 0;
}












