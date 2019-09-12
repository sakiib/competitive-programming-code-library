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
const long long INF = 1e15 + 5;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int MOD = 1000000007;

/**
codeforces 474E
The i-th pillar has the height of hi meters. Starting from one pillar i1,
Marmot wants to jump on the pillars i2, ..., ik. (1 ≤ i1 < i2 < ... < ik ≤ n).
From a pillar i Marmot can jump on a pillar j only if i < j and |hi - hj| ≥ d,
where |x| is the absolute value of the number x.
*/

int n;
LL a[ N ];
LL d;
LL dp[ N ];
int par[ N ];

struct node {
        node *l , *r;
        int mx , idx;
        node( ) : l( nullptr ) , r( nullptr ) , mx( 0 ) , idx( 0 ) {}
        node( node *l , node *r , int mx , int idx ) :
                           l( l ) , r( r ) , mx( mx ) , idx( idx ) {}
        void combine( LL b , LL e ) {
                LL m = ( b + e ) >> 1;
                mx = 0 , idx = 0;
                if( l && r ) {
                        mx = max( mx , max( l -> mx , r -> mx ) );
                        if( l -> mx >= mx ) idx = l -> idx;
                        if( r -> mx >= mx ) idx = r -> idx;
                }
                else if( l && !r ) {
                        mx = max( mx , l -> mx );
                        if( l -> mx >= mx ) idx = l -> idx;
                }
                else if( !l && r ) {
                        mx = max( mx , r -> mx );
                        if( r -> mx >= mx ) idx = r -> idx;
                }
        }
} *root;

typedef node* pnode;

void update( pnode &cur , LL b , LL e , LL pos , int val , int id ) {
        if( !cur ) cur = new node();
        if( pos > e || pos < b || b > e ) return;
        if( b == e && b == pos ) {
                cur -> mx = val;
                cur -> idx = id;
                return;
        }
        LL m = ( b + e ) >> 1;
        if( pos <= m ) update( cur -> l , b , m , pos , val , id );
        else update( cur -> r , m + 1 , e , pos , val , id );
        cur -> combine( b , e );
}
pair <int,int> query( pnode &cur , LL b , LL e , LL i , LL j ) {
        if( !cur ) return {0,0};
        if( i > e || j < b || b > e ) return {0,0};
        if( i <= b && j >= e ) return {cur->mx,cur->idx};
        LL m = ( b + e ) >> 1;
        pair <int,int> x = query( cur -> l , b , m , i , j );
        pair <int,int> y = query( cur -> r , m + 1 , e , i , j );
        pair <int,int> ret = {0,0};
        if( x.first >= y.first ) ret.first = max( ret.first , x.first ) , ret.second = x.second;
        else ret.first = max( ret.first , y.first ) , ret.second = y.second;
        return ret;
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( nullptr );
        cin >> n >> d;
        for( int i = 1; i <= n; i++ ) cin >> a[i];
        root = NULL;
        for( int i = 1; i <= n; i++ ) {
                pair <int,int> x = query( root , 1 , INF , 1 , a[i] - d );
                pair <int,int> y = query( root , 1 , INF , a[i] + d , INF );
                pair <int,int> m = max( x , y );
                dp[i] = m.first + 1;
                par[i] = m.second;
                update( root , 1 , INF , a[i] , dp[i] , i );
        }
        int mx = 0;
        for( int i = 1; i <= n; i++ ) if( dp[i] > dp[mx] ) mx = i;
        cout << dp[mx] << endl;
        vector <int> path;
        while( mx > 0 ) path.push_back( mx ) , mx = par[mx];
        for( int i = path.size() - 1; i >= 0; i-- ) cout << path[i] << " ";
        return 0;
}












