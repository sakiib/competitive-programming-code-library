#include <bits/stdc++.h>
using namespace std;

struct KUHN {
        static const int MAXN = 1e3 + 5;

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

int main( int argc , char const *argv[] ) {
        map <string,int> M;
        M[ "XXL" ] = 1;
        M[ "XL" ] = 2;
        M[ "L" ] = 3;
        M[ "M" ] = 4;
        M[ "S" ] = 5;
        M[ "XS" ] = 6;
        char s[ 10 ];

        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
                int n , m;
                scanf("%d %d",&n,&m);

                kuhn.initialize( m , n );

                for( int i = 1; i <= m; i++ ) {
                        scanf("%s",s);
                        for( int j = 1; j <= n; j++ ) {
                                kuhn.AddEdge( i , ( 6 * ( j ) ) + M[s] + m );
                        }
                        scanf("%s",s);
                        for( int j = 1; j <= n; j++ ) {
                                kuhn.AddEdge( i , ( 6 * ( j ) ) + M[s] + m );
                        }
                }
                int match = kuhn.MaximumMatch( );
                if( match == m ) printf("Case %d: YES\n",tc);
                else printf("Case %d: NO\n",tc);
        }
        return 0;
}







