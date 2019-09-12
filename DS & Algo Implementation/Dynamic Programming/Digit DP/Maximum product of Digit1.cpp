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
}
LL solve( int pos , bool eqlo , bool eqhi , bool zero ) {
        if( pos == vhi.size() ) return 1LL;
        if( dp[pos][eqlo][eqhi][zero] != -1 ) return dp[pos][eqlo][eqhi][zero];
        int lo = 0 , hi = 9;
        if( eqlo ) lo = vlo[pos];
        if( eqhi ) hi = vhi[pos];
        LL ans = 0;
        for( int i = lo; i <= hi; i++ ) {
                LL gun = i;
                if( !gun && zero ) gun = 1; /// if leading zero on && dig 0 , then gun = 1;
                LL temp = gun * solve( pos + 1 , eqlo && ( i == vlo[pos] ) ,
                                     eqhi && ( i == vhi[pos] ) , zero&&(i == 0 ) );
                if( temp >= ans ) {
                        ans = temp;
                        dig[pos][eqlo][eqhi][zero] = i;
                        eqlogg[pos][eqlo][eqhi][zero] = eqlo && ( i == vlo[pos] );
                        eqhigg[pos][eqlo][eqhi][zero] = eqhi && ( i == vhi[pos] );
                        okgg[pos][eqlo][eqhi][zero] = zero&&( i == 0 );
                }
        }
        return dp[pos][eqlo][eqhi][zero] = ans;
}

LL ans;

void print( int pos , bool eqlo , bool eqhi , bool zero ) {
        if( pos == vhi.size() ) return;
        ans *= 10;
        ans += dig[pos][eqlo][eqhi][zero];
        print( pos+1 , eqlogg[pos][eqlo][eqhi][zero] , eqhigg[pos][eqlo][eqhi][zero] ,
                                                    okgg[pos][eqlo][eqhi][zero] );
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
                solve( 0 , 1 , 1 , 1 );
                print( 0 , 1 , 1 , 1 );
                cout << ans << endl;
        }
        return 0;
}












