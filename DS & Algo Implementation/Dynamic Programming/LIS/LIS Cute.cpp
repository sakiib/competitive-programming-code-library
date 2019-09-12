#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef pair <int,int> pii;
typedef pair <long long,long long> pll;
const int MOD = 1e9 + 7;
const double EPS = 1e-8;
const int N = 1e5 + 5;
const int inf = 1e9;
const long long INF = 1e18;

int n , a[ 1005 ];
/// cute LIS in NlgN

int LIS1( ) { /// strictly Increasing
        multiset <int> S;
        for( int i = 1; i <= n; i++ ) {
                S.insert( a[i] );
                auto it = S.lower_bound( a[i] );
                it++;
                if( it != S.end() ) S.erase( it );
        }
        return (int)S.size();
}
int LIS2( ) { /// non-decreasing
        multiset <int> S;
        for( int i = 1; i <= n; i++ ) {
                S.insert( a[i] );
                auto it = S.upper_bound( a[i] );
                if( it != S.end() ) S.erase( it );
        }
        return (int)S.size();
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( nullptr );

        return 0;
}









