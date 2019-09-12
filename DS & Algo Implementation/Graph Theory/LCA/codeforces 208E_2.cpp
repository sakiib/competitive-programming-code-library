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

const int level = 20;
int n , q , Time;
vector <int> graph[ N ] , h[ N ];
vector <int> root;
int parent[ N ][ 35 ] , st[ N ] , en[ N ] , lvl[ N ];

void dfs( int s , int p , int depth ) {
        st[s] = ++Time;
        lvl[s] = lvl[p] + 1;
        h[ lvl[s] ].push_back( Time );
        for( auto x : graph[s] ) if( x != p ) dfs( x , s , depth+1 );
        en[s] = Time;
}
void build_table( ) {
        for( int i = 1; ( 1 << i ) <= n; i++ ) {
               for( int node = 1; node <= n; node++ ) {
                    parent[ node ][ i ] = parent[ parent[node][i-1] ][ i-1 ];
               }
        }
}
int KTH_parent( int v , int diff ) {
        for( int i = level; i >= 0; i-- ) {
                if( ( diff >> i )&1 ) v = parent[v][i];
        }
        return v;
}
int main( int argc , char const *argv[] ) {
        scanf("%d",&n);
        for( int i = 1; i <= n; i++ ) {
                scanf("%d",&parent[i][0]);
                if( parent[i][0] == 0 ) root.push_back( i );
                else graph[ parent[i][0] ].push_back( i );
        }
        for( auto x : root ) dfs( x , 0 , 0 );
        build_table( );
        scanf("%d",&q);
        while( q-- ) {
                int v , p;
                scanf("%d %d",&v,&p);
                int kth = KTH_parent( v , p );
                //printf("kth : %d\n",kth);
                if( kth <= 0 ) {
                        printf("0 ");
                }
                else {
                       int d = lvl[v];
                       //for( auto x : h[d] ) cout << x << " ";
                       //cout << endl;
                       //cout << st[kth] << " " << en[kth] << endl;
                       int l = lower_bound( h[d].begin() , h[d].end() , st[kth] ) - h[d].begin();
                       int r = upper_bound( h[d].begin() , h[d].end() , en[kth] ) - h[d].begin();
                       printf("%d ",r-l-1);
                }
        }
        return 0;
}
/// number od nodes in same level of a nodes subtree.






