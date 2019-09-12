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

LL a , b;
vector <int> lo , hi;
LL dp[ 65 ][ 2 ][ 2 ][ 2 ][ 2 ];

void convert( LL a , LL b ) {
        while( a ) lo.push_back( a%2 ) , a /= 2;
        while( b ) hi.push_back( b%2 ) , b /= 2;
        while( lo.size() < hi.size() ) lo.push_back( 0 );
        reverse( lo.begin() , lo.end() );
        reverse( hi.begin() , hi.end() );
}
LL solve( int idx , bool l1 , bool r1 , bool l2 , bool r2 ) {
        if( idx == hi.size() ) return 0;
        if( dp[idx][l1][r1][l2][r2] != -1 ) return dp[idx][l1][r1][l2][r2];
        LL ret = 0;
        int lo1 , hi1 , lo2 , hi2;
        lo1 = l1 ? lo[idx] : 0;
        hi1 = r1 ? hi[idx] : 1;
        lo2 = l2 ? lo[idx] : 0;
        hi2 = r2 ? hi[idx] : 1;
        for( int i = lo1; i <= hi1; i++ ) {
                for( int j = lo2; j <= hi2; j++ ) {
                        int f = (i^j);
                        LL add = 0;
                        if( f ) add = ( 1LL << ( (hi.size()-1) - idx ) );
                        ret = max( ret , add + solve( idx+1, l1&&(i==lo[idx]), r1&&(i==hi[idx]),
                                                        l2&&(j==lo[idx]), r2&&(j==hi[idx] ) ) );
                }
        }
        return dp[idx][l1][r1][l2][r2] = ret;
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( nullptr );
        cin >> a >> b;
        convert( a , b );
        memset( dp , -1 , sizeof( dp ) );
        cout << solve( 0 , 1 , 1 , 1 , 1 ) << endl;
        return 0;
}











