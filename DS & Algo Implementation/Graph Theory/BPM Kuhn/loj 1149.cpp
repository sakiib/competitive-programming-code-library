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

const int sz = 105;

int n , m ,a[ sz ] , b[ sz ];
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
        for( int i = 1; i <= n; i++ ) {
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
               scanf("%d",&n);
               for( int i = 1; i <= n; i++ ) scanf("%d",&a[i]);
               scanf("%d",&m);
               for( int i = 1; i <= m; i++ ) scanf("%d",&b[i]);
               for( int i = 1; i <= n; i++ ) {
                    for( int j = 1; j <= m; j++ ) {
                            if( b[j]%a[i] == 0 ) graph[i].push_back( j );
                    }
               }
               int mx_matching = Kuhn( );
               printf("Case %d: %d\n",tc,mx_matching);
        }
        return 0;
}







