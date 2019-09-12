#include <bits/stdc++.h>
using namespace std;

//////////////////////////// Heavy Light Decomposition ///////////////////////

static const int MAXN = 1e4 + 5;
static const int LOG = 20;
typedef pair <int,int> ii;
static const int INF = 1e9 + 5;

int n , Node;
int cost[ MAXN ];
int A[ MAXN ] , sub[ MAXN ] , par[ MAXN ] , depth[ MAXN ];
int chainNo , chainInd[ MAXN ] , chainHead[ MAXN ] , posInTree[ MAXN ];
vector <int> graph[ MAXN ];

struct segment {
        int mx;
        int cnt;
        segment( ) : mx(0) , cnt(0) {}
        segment( int mx , int cnt ) : mx(mx) , cnt(cnt) {}
};

segment tree[ 4*MAXN ];
int lazy[ 4*MAXN ];

void Initialize( int _n ) {
                n = _n;
                memset( tree , 0 , sizeof(tree) );
                memset( lazy , 0 , sizeof(lazy) );
                chainNo = 0 , Node = 1;
                for( int i = 0; i < MAXN; i++ ) {
                        graph[i].clear();
                        A[i] = 0 , sub[i] = 0 , cost[i] = 0;
                        chainInd[i] = 0 , chainHead[i] = -1 , posInTree[i] = 0;
                }
}
void AddEdge( int u , int v ) {
                graph[ u ].push_back( v ); graph[ v ].push_back( u );
}
void dfs( int s , int p ) {
                par[s] = p , sub[s] = 1 , depth[s] = depth[p] + 1;
                for( int i = 0; i < graph[s].size(); i++ ) {
                        int v = graph[s][i];
                        if( v != p ) {
                                dfs( v , s );
                                sub[s] += sub[v];
                        }
                }
}
void HLD( int s , int p ) {
                if( chainHead[ chainNo ] == -1 ) chainHead[ chainNo ] = s;
                chainInd[ s ] = chainNo;
                posInTree[ s ] = Node;
                A[ Node++ ] = cost[ s ];
                int mxChild = -1;
                for( int i = 0; i < graph[s].size(); i++ ) {
                        int v = graph[s][i];
                        if( v != p ) {
                                if( mxChild == -1 || sub[ mxChild ] < sub[ v ] ) {
                                        mxChild = v;
                                }
                        }
                }
                if( mxChild != -1 ) HLD( mxChild , s );
                for( int i = 0; i < graph[s].size(); i++ ) {
                        int v = graph[s][i];
                        if( v != p && v != mxChild ) {
                                chainNo++;
                                HLD( v , s );
                        }
                }
}
int LCA( int u , int v ) {
                while( 1 ) {
                        int pu = chainHead[ chainInd[u] ] , pv = chainHead[ chainInd[v] ];
                        if( pu == pv ) return ( depth[ u ] < depth[ v ] ? u : v );
                        if( depth[ pu ] < depth[ pv ] ) v = par[ pv ];
                        else u = par[ pu ];
                }
}

//////////////////////////// Segment Tree part , change accordingly //////////////////////


segment combine( segment a , segment b ) {
        if( a.mx > b.mx ) return a;
        if( a.mx < b.mx ) return b;
        return segment( a.mx , a.cnt + b.cnt );
}
void pushdown( int node ) {
        if( lazy[node] == 0 ) return;
        int l = node << 1 , r = l | 1;
        tree[l].mx += lazy[node];
        tree[r].mx += lazy[node];
        lazy[l] += lazy[node];
        lazy[r] += lazy[node];
        lazy[node] = 0;
}
void build( int node , int b , int e ) {
        if( b > e ) return;
        if( b == e ) {
                tree[node] = segment( A[b] , 1 );
                return;
        }
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        build( l , b , m );
        build( r , m + 1 , e );
        tree[node] = combine( tree[l] , tree[r] );
}
segment query( int node , int b , int e , int i , int j ) {
        if( i > e || j < b || b > e ) return segment( -INF , 0 );
        if( i <= b && j >= e ) return tree[node];
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        return combine( query( l , b , m , i , j ) , query( r , m + 1 , e , i , j ) );
}
void update( int node , int b , int e , int i , int j , int add ) {
        if( i > e || j < b || b > e ) return;
        if( i <= b && j >= e ) {
                tree[node].mx += add;
                lazy[node] += add;
                return;
        }
        pushdown( node );
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        update( l , b , m , i , j , add );
        update( r , m + 1 , e , i , j , add );
        tree[node] = combine( tree[l] , tree[r] );
}

////////////////////////////////////////////////////////////////////////////////////////////

void UpdateUP( int u , int v , int w ) {
                if( u == v ) {
                        update( 1 , 1 , Node , posInTree[ u ] , posInTree[ u ] , w );
                        return;
                }
                int uchain , vchain = chainInd[ v ];
                while( true ) {
                        uchain = chainInd[ u ];
                        if( uchain == vchain ) {
                                int st = posInTree[ v ] , en = posInTree[ u ];
                                update( 1 , 1 , Node , st , en , w );
                                break;
                        }
                        int st = posInTree[ chainHead[ uchain ] ] , en = posInTree[ u ];
                        update( 1 , 1 , Node , st , en , w );
                        u = chainHead[ uchain ] , u = par[ u ];
                }
}
void UpdateHLD( int u , int v , int w ) {
                int lca = LCA( u , v );
                UpdateUP( u , lca , w );
                UpdateUP( v , lca , w );
                UpdateUP( lca , lca , -w );
}

////////////////////////////////////////////////////////////////////////////////////////////

int main( int argc , char const *argv[] ) {
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
                scanf("%d",&n);
                Initialize( n );
                for( int i = 1; i <= n - 1; i++ ) {
                        int u , v;
                        scanf("%d %d",&u,&v);
                        AddEdge( u , v );
                }
                dfs( 1 , 0 );
                HLD( 1 , 0 );
                build( 1 , 1 , Node );
                int q;
                scanf("%d",&q);
                printf("Case %d:\n",tc);
                for( int qq = 1; qq <= q; qq++ ) {
                        int k;
                        scanf("%d",&k);
                        vector < pair <int,int> > V;
                        for( int kk = 1; kk <= k; kk++ ) {
                                int u , v;
                                scanf("%d %d",&u,&v);
                                V.push_back( {u,v} );
                                UpdateHLD( u , v , +1 );
                        }
                        if( tree[1].mx == k ) printf("%d\n",tree[1].cnt);
                        else printf("0\n");
                        for( auto x : V ) UpdateHLD( x.first , x.second , -1 );
                }
        }
        return 0;
}















