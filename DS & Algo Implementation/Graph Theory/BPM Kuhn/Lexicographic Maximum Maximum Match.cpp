#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <deque>
#include <functional>
#include <string>
#include <iostream>
#include <cctype>
#include <set>
#include <climits>
#include <iomanip>
#include <cassert>
#include <sstream>

using namespace std;

struct MAX_BIPARTITE_MATCHING_KUHN {

        static const int MAXN = 1e5 + 5;

        int n , m , match[ MAXN ];
        bool visited[ MAXN ];
        vector <int> graph[ MAXN ];

        void Initialize( int _n ) {
                n = _n;
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
                for( int i = n; i >= 1; i-- ) { /// For max/min lexicographic match change here.
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
                int n;
                scanf("%d",&n);
                kuhn.Initialize( n );
                for( int i = 1; i <= n; i++ ) {
                        int l , r;
                        scanf("%d %d",&l,&r);
                        for( int j = l; j <= r; j++ ) {
                                kuhn.AddEdge( i , j );
                        }
                }
                int match = kuhn.MaximumMatch();
                //printf("mx match : %d\n",match);
                vector <int> V;
                for( int i = 1; i <= 100000; i++ ) {
                        if( kuhn.match[i] != 0 ) V.push_back( kuhn.match[i] );
                }
                printf("%d\n",match);
                sort( V.begin() , V.end() );
                for( int i = 0; i < V.size(); i++ ) {
                        if( i == 0 ) printf("%d",V[i]);
                        else printf(" %d",V[i]);
                }
                printf("\n");
        }
        return 0;
}








