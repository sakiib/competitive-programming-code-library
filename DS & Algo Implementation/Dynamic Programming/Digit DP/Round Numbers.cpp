#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
#include<stack>
#include<vector>
#include<deque>
#include<functional>
#include<string>
#include<iostream>
#include<cctype>
#include<set>
#include<climits>
#include<iomanip>
#include<cassert>
#include<sstream>

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
/**
Numbers from L to R , that has zero >= one in binary rep.
*/
vector <int> V;
LL dp[ 35 ][ 2 ][ 35 ][ 35 ][ 2 ];
int vis[ 35 ][ 2 ][ 35 ][ 35 ][ 2 ];
int len , TC;

LL go( int idx , int smaller , int one , int zero , int st ) {
        if( idx >= len ) return ( zero >= one );
        if( vis[idx][smaller][one][zero][st] == TC ) return dp[idx][smaller][one][zero][st];
        vis[idx][smaller][one][zero][st] = TC;
        LL ret = 0;
        if( smaller ) {
                for( int i = 0; i <= 1; i++ ) {
                        ret += go( idx + 1 , 1 , one + ( i == 1 ) , zero + ( !st && ( i == 0 )) , ( st && ( i == 0 ) ) );
                }
        }
        else {
                for( int i = 0; i < V[idx]; i++ ) {
                        ret += go( idx + 1 , 1 , one + ( i == 1 ) , zero + ( !st && ( i == 0 )) , ( st && ( i == 0 ) ) );
                }
                ret += go( idx + 1 , 0 , one + ( V[idx] == 1 ) , zero + ( !st && ( V[idx] == 0 )) , ( st && ( V[idx] == 0 ) ) );
        }
        return dp[idx][smaller][one][zero][st] = ret;
}
LL solve( LL x ) {
        V.clear();
        while( x ) V.push_back( x%2 ) , x /= 2;
        reverse( V.begin() , V.end() );
        len = V.size();
        ++TC;
        return go( 0 , 0 , 0 , 0 , 1 );
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( NULL );
        LL l , r;
        TC = 0;
        while( cin >> l >> r ) {
                if( l > r ) swap( l , r );
                cout << solve( r ) - solve( l - 1 ) << endl;
        }
        return 0;
}











