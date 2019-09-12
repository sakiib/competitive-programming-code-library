#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
template <typename T> using
Treap = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
#define endl "\n"
#define all(V) V.begin( ), V.end( )
#define Unique(V) sort( all( V ) ), V.erase( unique( all( V ) ), V.end() )
std::mt19937 rng( chrono::steady_clock::now().time_since_epoch().count() );
#define ran(a, b) rng() % ( (b) - (a) + 1 ) + (a)
#define trace(...) __f( #__VA_ARGS__ , __VA_ARGS__ )
template < typename Arg1 >
void __f( const char* name , Arg1&& arg1 ) { cerr <<name<<" : "<<arg1<< "\n"; }
template < typename Arg1 , typename... Args >
void __f( const char* names , Arg1&& arg1 , Args&&... args ) {
const char* comma = strchr( names + 1 , ',' );
cerr.write( names , comma - names ) <<" : "<<arg1<<" , "; __f( comma+1 , args...);}

typedef long long int LL;
typedef pair <int,int> pii;
typedef pair <long long,long long> pll;
const int MOD = 1e9 + 7;
const double EPS = 1e-8;
const int N = 1e5 + 5;
const int inf = 1e9;
const long long INF = 1e18;

/**
determine how many subsets of S (including the empty one) have a sum
between A and B (-500,000,000 ≤ A ≤ B ≤ 500,000,000), inclusive.
*/
int n;
LL L , R;
LL a[ 100 ];

int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( nullptr );
        #ifdef forthright48
            //freopen( "input.txt" , "r" , stdin );
        #endif // forthright48
        cin >> n >> L >> R;
        for( int i = 1; i <= n; i++ ) cin >> a[i];
        if( n == 1 ) {
                LL ans = 0;
                if( a[1] >= L && a[1] <= R ) ans++;
                if( 0 >= L && 0 <= R ) ans++;
                return cout << 0 << endl,0;
        }
        vector <LL> X , Y;
        for( int i = 1; i <= n; i++ ) {
                if( i <= n/2 ) X.push_back( a[i] );
                else Y.push_back( a[i] );
        }
        int sz = X.size();
        vector <LL> A , B;
        for( int i = 0; i < ( 1<<sz ); i++ ) {
                LL sum = 0;
                for( int j = 0; j < sz; j++ ) {
                        if( i&( 1 << j ) ) {
                                sum += X[j];
                        }
                }
                A.push_back( sum );
        }
        sz = Y.size();
        for( int i = 0; i < ( 1<<sz ); i++ ) {
                LL sum = 0;
                for( int j = 0; j < sz; j++ ) {
                        if( i&( 1 << j ) ) {
                                sum += Y[j];
                        }
                }
                B.push_back( sum );
        }
        sort( A.begin() , A.end() );
        sort( B.begin() , B.end() );
        LL ans = 0;
        for( auto x : A ) {
                ans += upper_bound( B.begin() , B.end() , R - x ) -
                       lower_bound( B.begin() , B.end() , L - x );
        }
        cout << ans << endl;
        return 0;
}









