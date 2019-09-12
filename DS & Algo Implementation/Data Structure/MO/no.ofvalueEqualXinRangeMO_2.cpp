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

const int block = 4;
vector <int> V;
int l = 1 , r = 0;
int n , q , a[ N ] , cnt[ N ] , ans[ N ];
int tot;

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
        for( int i = l; i <= r; i++ ) if( a[i] == x ) ret++;
        return ret;
}
void Add( int id ) {
        cnt[ a[id] ]++;
}
void Remove( int id ) {
        cnt[ a[id] ]--;
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
int main( int argc , char const *argv[] ) {
        ios_base :: sync_with_stdio(false); cin.tie(NULL);
        cin >> n;
        for( int i = 1; i <= n; i++ ) cin >> a[i];
        cin >> q;
        for( int i = 1; i <= q; i++ ) {
                cin >> Q[i].l >> Q[i].r >> Q[i].k;
                Q[i].idx = i;
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
15
1 3 4 1 5 7 2 3 2 7 1 5 2 1 4

15
1 7 5
2 5 3
4 4 1
4 10 7
2 2 1
3 6 5
5 5 7
12 14 5
1 15 3
2 15 7
1 1 3
3 10 7
7 7 3
4 15 4
3 3 4
*/




