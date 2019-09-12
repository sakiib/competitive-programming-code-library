#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long uLL;
typedef long long int LL;
typedef pair <int,int> pii;
typedef pair <int,pii> piii;
typedef pair <long long,long long> pll;
typedef pair <long long,pll> plll;
const int N = 3e5 + 5;
const int inf = 1e9;
const long long INF = 1e18;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int MOD = 1000000007;

#define all( V ) V.begin( ),V.end( )
#define Unique( V ) sort( all( V ) ), V.erase( unique( all( V ) ), V.end() )

const int block_size = 550;

int n , m , u;
LL a[ N ];
vector <LL> V;
map <LL,LL> ID;
int id;

struct BinaryIndexedTree {

        int BIT[ block_size+10 ][ N+10 ];

        inline void Init( ) { memset( BIT , 0 , sizeof( BIT ) ); }

        inline int RQuery ( int block , int l , int r ) {
            return PQuery( block , r ) - PQuery( block , l-1 );
        }

        inline void PUpdate ( int block , int idx , int val ) {
            for( ; idx <= N; idx += ( idx & -idx ) ) BIT[ block ][ idx ] += val;
        }
        inline int PQuery ( int block , int idx ) {
            int ret = 0;
            for( ; idx > 0; idx -= ( idx & -idx ) ) ret += BIT[ block ][ idx ]; return ret;
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
                for( int i = l; i <= r; i++ ) sum += ( a[i] < k ? 1 : 0 );
                return sum;
        }
        int ret = 0;
        for( int i = l; ; i++ ) {
                int pos = Block_ID( i ); if( pos != block_a ) break;
                ret += ( a[i] < k ? 1 : 0 );
        }
        for( int i = block_a+1; i < block_b; i++ ) ret += bit.RQuery( i , 1 , k - 1 );
        int f = block_size*( block_b-1 );
        for( int i = f+1; i <= r; i++ ) ret += ( a[i] < k ? 1 : 0 );
        return ret;
}
void Update( int pos , int val ) {
        int block = Block_ID( pos );
        int prev = a[pos];
        bit.PUpdate( block , prev , -1 );
        bit.PUpdate( block , val , +1 );
        a[pos] = val;
}
void Compress( ) {
        Unique( V );
        for( auto x : V ) ID[x] = ++id;
        for( int i = 1; i <= n; i++ ) a[i] = ID[ a[i] ];
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( NULL );
        cin >> n >> m >> u;
        for( int i = 1; i <= n; i++ ) cin >> a[i] , V.push_back( a[i] );
        Compress( );
        for( int i = 1; i <= n; i++ ) set_block( i , a[i] );
        while( m-- ) {
                int l , r , v , p;
                cin >> l >> r >> v >> p;
                int small = getAns( l , r , v );
                cout << "small : "<< small << endl;
        }
        return 0;
}












