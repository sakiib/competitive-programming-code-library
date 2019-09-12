#include <bits/stdc++.h>
using namespace std ;
typedef long long LL;

const int N = 100005;
const LL inf = 10000000000000;
typedef pair <LL , LL> ii;
LL n , m;
vector < ii > graph[ N ];
LL cost[ N ];
LL path[ N ];
bool relaxed[ N ];

void dijkstra() {
    priority_queue< ii, vector< ii >, greater < ii > > Q;
    cost[ 1 ] = 0;
    Q.push( {cost[ 1 ] , 1});
    while ( !Q.empty() ) {
        ii t = Q.top();
        Q.pop();
        LL c = t.first;
        LL s = t.second;
        if( relaxed[s] ) continue;
        relaxed[s] = true;
        for ( int i = 0; i < graph[ s ].size(); i++ ) {
            ii next = graph[ s ][ i ];
            LL cx = next.second;
            LL sx = next.first;
            if ( cost[ sx ] == inf || ( cost[ sx ] > cost[ s ] + cx)) {
                cost[ sx ] = cost[ s ] + cx;
                path[ sx ] = s;
                Q.push( {cost[ sx ] , sx});
            }
        }
    }
}
void reset() {
    for ( LL i = 1; i<= n; i++ ) {
        cost[ i ] = inf;
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
    reset();
    dijkstra();
    if( cost[ n ] == inf ) {
        printf("-1\n");
        return 0;
    }
    print_path( n );
    return 0;
}
