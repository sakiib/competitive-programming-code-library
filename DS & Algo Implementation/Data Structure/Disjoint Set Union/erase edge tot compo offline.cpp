#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n , m , q;
int p[ N ];
int query[ N ];
bool alive[ N ];
int compo;

vector < pair <int,int> > edge[ N ];

void makeset( int k ) {
        for( int i = 1; i <= k; i++ ) p[i] = i;
}
int _find( int x ) {
        return p[x] == x ? x : p[x] = _find( p[x] );
}
void unite( int id ) {
        int a = edge[id][0].first , b = edge[id][0].second;
        int u = _find( a ) , v = _find( b );
        if( u == v ) return;
        if( rand()%2 ) swap( u , v );
        p[u] = v;
        compo--;
}
int main( int argc , char const *argv[] ) {
        scanf("%d %d",&n,&m);
        compo = n;
        for( int i = 1; i <= m; i++ ) {
                int u , v;
                scanf("%d %d",&u,&v);
                edge[i].push_back( {u,v} );
        }
        scanf("%d",&q);
        memset( alive , true , sizeof( alive ) );
        for( int i = 1; i <= q; i++ ) scanf("%d",&query[i]) , alive[ query[i] ] = false;
        reverse( query + 1 , query + q + 1 );
        makeset( n );
        for( int i = 1; i <= m; i++ ) if( alive[i] ) unite( i );
        vector <int> ans;
        for( int i = 1; i <= q; i++ ) ans.push_back( compo ) , unite( query[i] );
        for( int i = ans.size() - 1; i >= 0; i-- ) printf("%d ",ans[i]);
        return 0;
}












