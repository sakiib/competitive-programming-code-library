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

/**
    given a bipartite graph , Kuhn finds the maximum matching
    running time : O( V * E )
    Following code solves lightoj - 1148
    use this if N <= 1000 , or use Hopcrop- craft.
    Max flow also works , but donno that.
*/

const int sz = 55;

struct data {
        int height;
        int age;
        int status;
} M[ sz ] , W[ sz ];

int man , woman;

/// conditions for connectivity.
bool can( int i , int j ) {
        if( abs( M[i].height - W[j].height ) > 12 ) return false;
        if( abs( M[i].age - W[j].age) > 5 ) return false;
        if( M[i].status != W[j].status ) return false;
        return true;
}



vector <int> graph[ sz ];
int matched[ sz ];
bool visited[ sz ];

bool FindMatch( int s ) {
        visited[ s ] = true;
        for( int i = 0; i < graph[ s ].size(); i++ ) {
                int node = graph[ s ][ i ];
                int next = matched[ node ];
                if( visited[ next ] ) continue;
                if( next == -1 || FindMatch( next ) ) {
                        matched[ node ] = s;
                        return true;
                }
        }
        return false;
}
int Kuhn( ) {
        int mx_matching = 0;
        memset( matched , -1 , sizeof(matched) );
        for( int i = 1; i <= man; i++ ) {
                memset( visited , false , sizeof(visited) );
                if( FindMatch( i ) ) mx_matching++;
        }
        return mx_matching;
}


void Reset( ) {
        for( int i = 1; i < sz; i++ ) graph[i].clear();
}
int main( int argc , char const *argv[] ) {
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {

               Reset( );

               scanf("%d %d",&man,&woman);
               for( int i = 1; i <= man; i++ ) {
                        scanf("%d %d %d",&M[i].height,&M[i].age,&M[i].status);
               }
               for( int i = 1; i <= woman; i++ ) {
                        scanf("%d %d %d",&W[i].height,&W[i].age,&W[i].status);
               }
               /// Build the Bipartite graph according to statement of connectivity.
               for( int i = 1; i <= man; i++ ) {
                        for( int j = 1; j <= woman; j++ ) {
                                if( can( i , j ) ) {
                                    graph[ i ].push_back( j );
                                }
                        }
                }
                int mx_matching = Kuhn( );
                printf("Case %d: %d\n",tc,mx_matching);
        }
        return 0;
}






