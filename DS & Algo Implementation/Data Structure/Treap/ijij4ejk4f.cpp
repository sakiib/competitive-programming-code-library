#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef unsigned long long uLL;
typedef long long int LL;
typedef pair <int,int> pii;
typedef pair <long long,long long> pll;
const int N = 1e5 + 5;
const int inf = (int)1e9;
const long long INF = 1LL * 1e18;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int MOD = 1000000007;

template <typename T> using Treap =
         tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

int n , q;
LL a[ N ];

/**
type 1 : update 1 value at pos p ( 1 based )
type 2 : answer query
*/
int main( int argc , char const *argv[] ) {
        #ifdef forthright48
            freopen( "input.txt" , "r" , stdin );
        #endif // forthright48
        int t;
        scanf("%d",&t);
        while( t-- ) {
                scanf("%d",&n);
                for( int i = 1; i <= n; i++ ) scanf("%lld",&a[i]);
                Treap <LL> treap;
                for( int i = 1; i <= n; i++ ) treap.insert( -a[i] );
                scanf("%d",&q);
                while( q-- ) {
                        int type;
                        scanf("%d",&type);
                        if( type == 1 ) {
                                LL pos , val;
                                scanf("%lld %lld",&pos,&val);
                                LL now = a[pos];
                                treap.erase( treap.find_by_order( treap.order_of_key( -now ) ) );
                                treap.insert( -val );
                                a[pos] = val;
                        }
                        else {
                                LL m;
                                scanf("%lld",&m);
                                LL lo = 0 , hi = treap.size() - 1 , ret = 0;
                                while( lo <= hi ) {
                                        LL mid = ( lo + hi ) >> 1;
                                        LL now = *treap.find_by_order( mid );
                                        now *= -1;
                                        if( now >= mid * m ) ret = mid + 1 , lo = mid + 1;
                                        else hi = mid - 1;
                                }
                                printf("%lld\n",ret);
                        }
                }
        }
        return 0;
}














