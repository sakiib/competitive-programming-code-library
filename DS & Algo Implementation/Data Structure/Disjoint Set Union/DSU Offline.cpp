#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
typedef pair < int , int > ii;
const int inf = 1e9;
const LL INF = 1e18;
const int N = 1e5 + 5;
const int mod = 1000000007;
const double eps = 1e-8;
const double pi = acos( -1.0 );

/// given a weighted graph & q query
/// how many nodes can be visited from the given node & a weight such that
/// we cant pass a node weughing higher than the given weight.
/// Offline Solution.
/// SPOJ ADABRANC

int n , m , q;

struct event {
        int type; /// 0 - Add Edge , 1 - Query
        int id;
        int u;
        int v;
        int w;
        event( int _type, int _id, int _u, int _v, int _w ) {
                type = _type , id = _id , u = _u , v = _v , w = _w;
        }
        bool operator <( const event &other ) const {
                if( w != other.w ) return w > other.w;
                return type < other.type;
        }
};

int Parent[ 3*N ] , Compo[ 3*N ] , ans[ 3*N ];
vector <event> V;

void Makeset( int n ) {
        for( int i = 1; i <= n; i++ ) {
                Parent[i] = i;
                Compo[i] = 1;
        }
}
int Find( int x ) {
        return ( Parent[x] == x ? x : Parent[x] = Find( Parent[x] ) );
}
void Union( int a , int b ) {
        int x = Find( a );
        int y = Find( b );
        if( x != y ) {
                Parent[y] = x;
                Compo[x] += Compo[y];
                Compo[y] = 0;
        }
}
int main( int argc , char const *argv[] ) {
        scanf("%d %d %d",&n,&m,&q);
        Makeset( n );
        for( int i = 1; i <= m; i++ ) {
                int u , v , w;
                scanf("%d %d %d",&u,&v,&w);
                ++u , ++v;
                V.push_back( { 0 , -1 , u , v , w } );
        }
        for( int i = 1; i <= q; i++ ) {
                int s , w;
                scanf("%d %d",&s,&w);
                ++s;
                V.push_back( { 1 , i , s , -1 , w } );
        }
        sort( V.begin() , V.end() );
        for( auto x : V ) {
                if( x.type == 0 ) {
                        Union( x.u , x.v );
                }
                else {
                        ans[ x.id ] = Compo[ Find(x.u) ];
                }
        }
        for( int i = 1; i <= q; i++ ) {
                printf("%d\n",ans[i]);
        }
        return 0;
}






