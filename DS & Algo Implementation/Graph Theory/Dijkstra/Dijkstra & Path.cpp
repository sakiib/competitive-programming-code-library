#include <bits/stdc++.h>
using namespace std ;
/**
dont work for negative edges
*/
typedef long long LL;

const int N = 100005;
const LL INF = 10000000000000;
typedef pair <LL,LL> ll;

LL n , m;
vector <ll> graph[ N ];
LL cost[ N ];
LL path[ N ];
bool relaxed[ N ]; /// this is very important..

void DIJKSTRA( ) {
        priority_queue < ll, vector<ll>, greater<ll> > Q;
        for( int i = 1; i <= n; i++ ) cost[ i ] = INF;
        cost[ 1 ] = 0;
        Q.push( { cost[ 1 ] , 1 } );
        while ( !Q.empty() ) {
                ll t = Q.top(); Q.pop();
                LL c = t.first , s = t.second;
                if( relaxed[s] ) continue;
                relaxed[s] = true;
                for ( int i = 0; i < graph[ s ].size(); i++ ) {
                        ll next = graph[ s ][ i ];
                        LL cx = next.second , sx = next.first;
                        if ( cost[ sx ] == INF || ( cost[ sx ] > cost[ s ] + cx ) ) {
                                cost[ sx ] = cost[ s ] + cx;
                                path[ sx ] = s;
                                Q.push( { cost[ sx ] , sx } );
                        }
                }
        }
}
void print_path( LL en ) {
    if ( en == 0 ) return;
    print_path( path[en] );
    printf("%lld ",en );
}
int main( int argc , char const *argv[] ) {
    scanf("%lld%lld",&n,&m);
    for ( LL i = 1; i <= m; i++ ) {
        LL u , v , w;
        scanf("%lld%lld%lld",&u,&v,&w);
        graph[ u ].push_back( {v,w} );
        graph[ v ].push_back( {u,w} );
    }
    DIJKSTRA();
    cout << "Shortest Path : " << cost[ n ] << endl;
    if( cost[ n ] == INF ) {
        printf("-1\n"); /// Not reachable
        return 0;
    }
    print_path( n ); /// Path Printing.
    return 0;
}
