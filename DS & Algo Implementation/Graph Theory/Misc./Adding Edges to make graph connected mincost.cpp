#include <bits/stdc++.h>
using namespace std;

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

int n , m;
LL a[ N ];

struct data {
        int u , v;
        LL w;
        data( int u , int v , LL w ) : u( u ) , v( v ) , w( w ) {}
        bool operator <( const data &q ) const {
                return w < q.w;
        }
};

vector <data> edge;
int par[ N ];

int Find( int u ) {
        return par[u] == u ? u : par[u] = Find( par[u] );
}
void unite( int u , int v ) {
        int x = Find( u ) , y = Find( v );
        if( x != y ) par[x] = y;
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( NULL );
        cin >> n >> m;
        LL mn = INF;
        int idx = 0;
        for( int i = 1; i <= n; i++ ) {
                cin >> a[i];
                if( a[i] < mn ) {
                        mn = a[i] , idx = i;
                }
        }
        for( int i = 1; i <= n; i++ ) {
                if( idx == i ) continue;
                edge.push_back( data( i , idx , a[i] + mn ) );
        }
        for( int i = 1; i <= m; i++ ) {
                int u , v;
                LL w;
                cin >> u >> v >> w;
                edge.push_back( data( u , v , w ) );
        }
        for( int i = 1; i < N; i++ ) par[i] = i;
        sort( edge.begin() , edge.end() );
        LL ans = 0;
        for( auto x : edge ) {
                if( Find( x.u ) != Find( x.v ) ) unite( x.u , x.v ) , ans += x.w;
        }
        cout << ans << endl;
        return 0;
}











