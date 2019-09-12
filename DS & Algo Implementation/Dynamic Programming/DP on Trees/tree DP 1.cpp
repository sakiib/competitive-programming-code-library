/**
The first problem we solve is as follows:
Given a tree T of N nodes, where each node i has Ci coins
attached with it. You have to choose a subset of nodes such that
no two adjacent nodes(i.e. nodes connected directly by an edge) are
chosen and sum of coins attached with nodes in chosen subset is maximum.
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int coin[ N ];
vector <int> graph[ N ];
int dp1[ N ] , dp2[ N ];

void dfs( int s , int p ) {
        int sum1 = 0 , sum2 = 0;
        for( auto x : graph[s] ) {
                if( x == p ) continue;
                dfs( x , s );
                sum1 += dp2[x];
                sum2 += max( dp1[x] , dp2[x] );
        }
        dp1[s] = coin[s] + sum1;
        dp2[s] = sum2;
}
int main( int argc , char const *argv[] ) {
        ios_base :: sync_with_stdio(false); cin.tie(NULL);
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++ ) cin >> coin[i];
        for( int i = 1; i <= n-1; i++ ) {
                int u , v;
                cin >> u >> v;
                graph[u].push_back( v );
                graph[v].push_back( u );
        }
        dfs( 1 , 0 );
        cout <<"ans : "<< max( dp1[1] , dp2[1] ) << endl;
        return 0;
}
/**
5
1 2 3 4 5
1 2
1 3
2 4
2 5

ans : 12
*/






