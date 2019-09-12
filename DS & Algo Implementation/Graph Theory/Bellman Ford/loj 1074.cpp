#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
const int INF = 2e9 + 9;

struct Edge {
        int u , v , w;
        Edge(){}
        Edge( int u , int v , int w ): u(u) , v(v) , w(w){}
};

int a[ N ] , cost[ N ];
int Neg[ N ];
vector <Edge> V;
int n , m;

void BellmanFord( int s ) {
        for( int i = 0; i < N; i++ ) cost[ i ] = INF;
        cost[ 1 ] = 0;
        for( int i = 1; i < n; i++ ) {
                for( int j = 0; j < V.size(); j++ ) {
                        if( cost[ V[j].u ] + V[j].w < cost[ V[j].v ] && cost[ V[j].u ] < INF  ) {
                               cost[ V[j].v ] = cost[ V[j].u ] + V[j].w;
                        }
                }
        }

        for( int i = 0; i < V.size(); i++ ) {
                if( cost[ V[i].u ] + V[i].w < cost[ V[i].v ] ) {
                        /// Negative Cycle Found.
                }
        }
        for( int i = 1; i < n; i++ ) {
                for( int j = 0; j < V.size(); j++ ) {
                        if( cost[ V[j].u ] + V[j].w < cost[ V[j].v ] && cost[ V[j].u ] < INF  ) {
                               cost[ V[j].v ] = cost[ V[j].u ] + V[j].w;
                               Neg[ V[j].v ] = 1; /// is in negative cycle
                        }
                }
        }
}
int main( int argc , char const *argv[] ) {
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {

                V.clear();
                memset( Neg , 0 , sizeof(Neg) );

                scanf("%d",&n);
                for( int i = 1; i <= n; i++ ) scanf("%d",&a[i]);
                scanf("%d",&m);
                for( int i = 1; i <= m; i++ ) {
                        int u , v;
                        scanf("%d %d",&u,&v);
                        int w = ( a[v] - a[u] ) * ( a[v] - a[u] ) * ( a[v] - a[u] );
                        V.push_back( Edge( u , v , w ) );
                }
                BellmanFord( 1 );
                //for( int i = 1; i <= n; i++ ) cout << i << " Neg[i] : " << Neg[i] << endl;

                printf("Case %d:\n",tc);
                int q;
                scanf("%d",&q);
                while( q-- ) {
                        int p;
                        scanf("%d",&p);
                        int ans = cost[p];
                        if( Neg[p] != 1 && ans < INF && ans >= 3 ) printf("%d\n",ans);
                        else printf("?\n");
                }
        }
        return 0;
}
/**
1
5
2 5 9 15 25
6
1 2
4 5
3 4
5 4
2 5
5 3
5
1
2
3
4
5
*/




