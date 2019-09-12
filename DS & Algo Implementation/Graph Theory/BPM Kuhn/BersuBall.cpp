#include <bits/stdc++.h>
using namespace std;

struct MAX_BIPARTITE_MATCHING_KUHN {

        static const int MAXN = 1e2 + 5;

        int n , m , match[ MAXN ];
        bool visited[ MAXN ];
        vector <int> graph[ MAXN ];

        void initialize( int _n , int _m ) {
                n = _n , m = _m;
                for( int i = 0; i < MAXN; i++ ) graph[i].clear();
        }
        void AddEdge( int u , int v ) {
                graph[ u ].push_back( v );
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

const int N = 105;

int b[ N ] , g[ N ];

int main( int argc , char const *argv[] ) {
        int n , m;
        scanf("%d",&n);
        for( int i = 1; i <= n; i++ ) scanf("%d",&b[i]);
        scanf("%d",&m);
        for( int i = 1; i <= m; i++ ) scanf("%d",&g[i]);
        kuhn.initialize( n , m );
        for( int i = 1; i <= n; i++ ) {
                for( int j = 1; j <= m; j++ ) {
                        if( abs( b[i] - g[j] ) <= 1 ) kuhn.AddEdge( i , j );
                }
        }
        printf("%d\n",kuhn.MaximumMatch( ));
        return 0;
}






