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

const int block = 5;

int n ;
int val[ N ] , disc[ N ] , st[ N ] , en[ N ] , cnt[ N ] , ans[ N ];
vector <int> graph[ N ];
int Time;
int q , l = 1 , r = 0;
vector <int> V;

struct data {
        int l , r , idx , k;
        bool operator < ( const data &q ) const {
                int block_a = l / block;
                int block_b = q.l / block;
                if( block_a == block_b ) return ( r < q.r );
                return ( block_a < block_b );
    }
} Q[ N ];

int brute( int l , int r , int x ) {
        int ret = 0;
        for( int i = l; i <= r; i++ ) if( disc[i] == x ) ret++;
        return ret;
}
void Add( int id ) {
        cnt[ disc[id] ]++;
}
void Remove( int id ) {
        cnt[ disc[id] ]--;
}
void MO( ) {
        sort( Q+1 , Q+q+1 );
        for( int i = 1; i <= q; i++ ) {
                while( l < Q[i].l ) Remove( l++ );
                while( l > Q[i].l ) Add( --l );
                while( r < Q[i].r ) Add( ++r );
                while( r > Q[i].r ) Remove( r-- );
                ans[ Q[i].idx ] = cnt[ Q[i].k ];
        }
}
void dfs( int s , int p ) {
        st[s] = ++Time;
        disc[ st[s] ] = val[ s ];
        for( auto x : graph[s] ) {
                if( x != p ) dfs( x , s );
        }
        en[s] = Time;
}
int main( int argc , char const *argv[] ) {
        cin >> n;
        for( int i = 1; i <= n; i++ ) cin >> val[i];
        for( int i = 1; i <= n-1; i++ ) {
                int u , v;
                cin >> u >> v;
                graph[u].push_back( v );
                graph[v].push_back( u );
        }
        dfs( 1 , 0 );
        cin >> q;
        for( int i = 1; i <= q; i++ ) {
                int node , val;
                cin >> node >> val;
                Q[i].l = st[node], Q[i].r = en[node], Q[i].k = val, Q[i].idx = i;
                V.push_back( brute( Q[i].l , Q[i].r , Q[i].k ) );
        }
        MO( );
        cout << "Bruteforce ans : " << endl;
        for( auto x : V ) cout << x << " ";
        cout << endl;
        cout << "MO's ans : " << endl;
        for( int i = 1; i <= q; i++ ) cout << ans[i] <<" ";
        cout << endl;
        return 0;
}

/**
8
1 2 2 3 3 6 3 3

1 2
1 5
2 3
2 4
5 6
5 8
5 7

5
5 3
5 6
1 3
2 3
2 2
*/





