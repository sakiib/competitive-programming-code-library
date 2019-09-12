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
 problem:
 query : how many nodes with value equal to x are in the subtree of v ??
 update : change the value of a particular node to another value.
 */

vector <int> graph[ N ];
int st[ N ] , en[ N ] , disc[ N ];
int val[ N ];
int Time;
int n , q , k;
const int block_size = 350;

struct BinaryIndexedTree {

        int BIT[ block_size+10 ][ N+10 ];

        inline void Init( ) { memset( BIT , 0 , sizeof( BIT ) ); }

        inline int RQuery ( int block , int l , int r ) {
            return PQuery( block , r )-PQuery( block , l-1 );
        }

        inline void PUpdate ( int block , int idx , int val ) {
            for( ; idx <= N; idx += ( idx & -idx ) ) BIT[ block ][ idx ] += val;
        }
        inline int PQuery ( int block , int idx ) {
            int ret = 0;
            for( ; idx > 0; idx -= ( idx & -idx ) ) ret += BIT[ block ][ idx ];
            return ret;
        }
        inline void RUpdate ( int block , int idx , int idy , int val ) {
            for( ; idx <= N; idx += ( idx & -idx ) ) BIT[ block ][ idx ] += val;
            idy++ , val *= -1;
            for( ; idy <= N; idy += ( idy & -idy ) ) BIT[ block ][ idy ] += val;
        }
} bit;

int Block_ID( int id ) {
        int pos = ( (id+block_size-1)/block_size );
        return pos;
}
void set_block( int id , int num ) {
        int block = Block_ID( id );
        bit.PUpdate( block , num , +1 );
}
int getAns( int l , int r , int k ) {
        int block_a = Block_ID( l ) , block_b = Block_ID( r );
        if( block_a == block_b ) {
                int sum = 0;
                for( int i = l; i <= r; i++ ) sum += ( disc[i] == k ? 1 : 0 );
                return sum;
        }
        int ret = 0;
        for( int i = l; ; i++ ) {
                int pos = Block_ID( i );
                if( pos != block_a ) break;
                ret += ( disc[i] == k ? 1 : 0 );
        }
        for( int i = block_a+1; i < block_b; i++ ) ret += bit.RQuery( i , k-1 , k );
        int f = block_size*( block_b-1 );
        for( int i = f+1; i <= r; i++ ) ret += ( disc[i] == k ? 1 : 0 );
        return ret;
}
void Update( int pos , int val ) {
        int block = Block_ID( pos );
        int prev = disc[pos];
        bit.PUpdate( block , prev , -1 );
        bit.PUpdate( block , val , +1 );
        disc[pos] = val;
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

        //for( int i = 1; i <= Time; i++ ) cout <<disc[i]<<" ";
        //cout << endl;
        //for( int i = 1; i <= Time; i++ ) cout <<st[i]<<" "<<en[i]<< endl;

        for( int i = 1; i <= Time; i++ ) set_block( i , st[i] );

        //Update( st[5] , 6 );

        int q;
        cin >> q;
        while( q-- ) {
                int op;
                cin >> op;
                if( op == 1 ) {
                        int node , nval;
                        cin >> node >> nval;
                        Update( st[node] , nval );
                }
                else {
                       int p;
                       cin >> p >> k;
                       int l = st[p] , r = en[p];
                       //cout << p << " " << l << " " << r << endl;
                       cout << "ans : " << getAns( l , r , k ) << endl;
                }
        }
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
*/






