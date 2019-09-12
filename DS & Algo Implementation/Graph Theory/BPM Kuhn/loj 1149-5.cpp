#include <bits/stdc++.h>
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

int n , m;
LL a[ 105 ] , b[ 105 ];

struct MAX_BIPARTITE_MATCHING_KUHN {

        static const int MAXN = 2e2 + 5;

        int n , m , match[ MAXN ];
        bool visited[ MAXN ];
        vector <int> graph[ MAXN ];

        void Initialize( int _n , int _m ) {
                n = _n , m = _m;
                for( int i = 0; i < MAXN; i++ ) graph[i].clear();
        }
        void AddEdge( int u , int v ) {
                graph[ u ].push_back( v );
                graph[ v ].push_back( u );
        }
        bool FindMatch( int s ) {
                visited[ s ] = true;
                for( int i = 0; i < graph[ s ].size(); i++ ) {
                        int node = graph[ s ][ i ];
                        int next = match[ node ];
                        if( visited[ next ] ) continue;
                        if( next == 0 || FindMatch( next ) ) {
                                match[ node ] = s;
                                return true;
                        }
                }
                return false;
        }
        int MaximumMatch( ) {
                int mx_matching = 0;
                memset( match , 0 , sizeof(match) );
                for( int i = 1; i <= n; i++ ) {
                        memset( visited , false , sizeof(visited) );
                        if( FindMatch( i ) ) mx_matching++;
                }
                return mx_matching;
        }
} kuhn;

int main( int argc , char const *argv[] ) {
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
                scanf("%d",&n);
                for( int i = 1; i <= n; i++ ) scanf("%lld",&a[i]);
                scanf("%d",&m);
                for( int i = 1; i <= m; i++ ) scanf("%lld",&b[i]);
                kuhn.Initialize( n , m );
                for( int i = 1; i <= n; i++ ) {
                        for( int j = 1; j <= m; j++ ) {
                                if( b[j]%a[i] == 0 ) {
                                        kuhn.AddEdge( i , j+105 ); /// or (i,j) & make undir.
                                }
                        }
                }
                int mx = kuhn.MaximumMatch( );
                printf("Case %d: %d\n",tc,mx);
        }
        return 0;
}











