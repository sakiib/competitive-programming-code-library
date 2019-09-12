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

LL lo , hi;
vector <int> vlo , vhi;
LL dp[ 20 ][ 2 ][ 2 ][ 2 ];
int dig[ 20 ][ 2 ][ 2 ][ 2 ];
bool eqlogg[ 20 ][ 2 ][ 2 ][ 2 ] , eqhigg[ 20 ][ 2 ][ 2 ][ 2 ] , okgg[ 20 ][ 2 ][ 2 ][ 2 ];

void convert( LL lo , LL hi ) {
        vlo.clear();
        vhi.clear();
        while( hi ) vhi.push_back( hi%10 ) , hi /= 10;
        reverse( vhi.begin(), vhi.end() );
        while( lo ) vlo.push_back( lo%10 ) , lo /= 10;
        while( vlo.size() < vhi.size() ) vlo.push_back( 0 );
        reverse( vlo.begin() , vlo.end() );

        //for( auto x : vlo ) cout << x << " "; cout <<endl;
        //for( auto x : vhi ) cout << x << " "; cout <<endl;
}
LL solve( int pos , bool eqlo , bool eqhi , bool ok ) {
        if( pos == vhi.size() ) return 1LL;
        if( dp[pos][eqlo][eqhi][ok] != -1 ) return dp[pos][eqlo][eqhi][ok];
        int lo = 0 , hi = 9;
        if( eqlo ) lo = vlo[pos];
        if( eqhi ) hi = vhi[pos];
        LL ans = 0;
        for( int i = lo; i <= hi; i++ ) {
                LL gun = i;
                if( !gun && !ok ) gun = 1; /// if leading zero on && dig 0 , then gun = 1;
                LL temp = gun * solve( pos + 1 , eqlo && ( i == vlo[pos] ) ,
                                     eqhi && ( i == vhi[pos] ) , ok || i );
                if( temp >= ans ) {
                        ans = temp;
                        dig[pos][eqlo][eqhi][ok] = i;
                        eqlogg[pos][eqlo][eqhi][ok] = eqlo && ( i == vlo[pos] );
                        eqhigg[pos][eqlo][eqhi][ok] = eqhi && ( i == vhi[pos] );
                        okgg[pos][eqlo][eqhi][ok] = ok || i;
                }
        }
        return dp[pos][eqlo][eqhi][ok] = ans;
}

LL ans;

void print( int pos , bool eqlo , bool eqhi , bool ok ) {
        if( pos == vhi.size() ) return;
        ans *= 10;
        ans += dig[pos][eqlo][eqhi][ok];
        print( pos+1 , eqlogg[pos][eqlo][eqhi][ok] , eqhigg[pos][eqlo][eqhi][ok] ,
                                                    okgg[pos][eqlo][eqhi][ok] );
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( nullptr );
        while( cin >> lo >> hi ) {
                convert( lo , hi );
                memset( dp , -1 , sizeof( dp ) );
                memset( dig , 0 , sizeof( dig ) );
                memset( eqlogg , false , sizeof( eqlogg ) );
                memset( eqhigg , false , sizeof( eqhigg ) );
                memset( okgg , false , sizeof( okgg ) );
                ans = 0;
                solve( 0 , 1 , 1 , 0 );
                print( 0 , 1 , 1 , 0 );
                cout << ans << endl;
        }
        return 0;
}











