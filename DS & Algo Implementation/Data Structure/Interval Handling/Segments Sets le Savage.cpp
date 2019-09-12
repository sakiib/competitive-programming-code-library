#include <bits/stdc++.h>
using namespace std;

#define Fast_IO ios_base::sync_with_stdio(0); cin.tie(0);

typedef unsigned long long uLL;
typedef long long int LL;
const int N = 1e5 + 5;
const int inf = 1e9;
const LL INF = 1e18;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int MOD = 1000000007;

set < pair <int,int> > S;

int main( int argc , char const *argv[] ) {
        int n , q;
        scanf("%d %d",&n,&q);
        int ans = n;
        while( q-- ) {
                int l , r , k;
                scanf("%d %d %d",&l,&r,&k);
                auto it = S.lower_bound( make_pair( l , -1 ) );
                while( it != S.end() ) {
                        int range_r = (*it).first , range_l = (*it).second;
                        int common = min( range_r , r ) - max( range_l , l ) + 1;
                        if( common <= 0 ) break;
                        ans += common;
                        S.erase( it++ );
                        if( range_l < l ) S.insert( make_pair( l - 1 , range_l ) );
                        if( range_r > r ) S.insert( make_pair( range_r , r + 1 ) );
                }
                if( k == 1 ) S.insert( make_pair( r , l ) ) , ans -= ( r - l + 1 );
                printf("%d\n",ans);
        }
        return 0;
}







