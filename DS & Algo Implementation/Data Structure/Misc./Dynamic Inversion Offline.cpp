#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(V) V.begin(),V.end()
#define see(x) cerr << #x << " = " << x << "\n";
#define Unique(V) sort(all(V)),V.erase(unique(all(V)),V.end())
#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long int LL;
typedef pair <int,int> pii;
const int MOD = 1e9 + 7;
const int inf = 1e9;
const double PI = acos(-1.0);
const long long INF = 1e18;
const int N = 2e5 + 5;

/**
UVA - 11990: Code okay but TLE
*/

const int block_size = 450;
int n , m;
int a[ N ] , pos[ N ] , bad[ N ];
bool f[ N ];

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
int getsmall( int l , int r , int k ) {
        if( l > r ) return 0;
        int block_a = Block_ID( l ) , block_b = Block_ID( r );
        if( block_a == block_b ) {
                int sum = 0;
                for( int i = l; i <= r; i++ ) sum += ( a[i] < k && a[i] != 0 ? 1 : 0 );
                return sum;
        }
        int ret = 0;
        for( int i = l; ; i++ ) {
                int pos = Block_ID( i );
                if( pos != block_a ) break;
                ret += ( a[i] < k && a[i] != 0 ? 1 : 0 );
        }
        for( int i = block_a+1; i < block_b; i++ ) ret += bit.RQuery( i , 1 , k - 1 );
        int f = block_size*( block_b-1 );
        for( int i = f+1; i <= r; i++ ) ret += ( a[i] < k && a[i] != 0 ? 1 : 0 );
        return ret;
}
int getbig( int l , int r , int k ) {
        if( l > r ) return 0;
        int block_a = Block_ID( l ) , block_b = Block_ID( r );
        if( block_a == block_b ) {
                int sum = 0;
                for( int i = l; i <= r; i++ ) sum += ( a[i] > k ? 1 : 0 );
                return sum;
        }
        int ret = 0;
        for( int i = l; ; i++ ) {
                int pos = Block_ID( i );
                if( pos != block_a ) break;
                ret += ( a[i] > k ? 1 : 0 );
        }
        for( int i = block_a+1; i < block_b; i++ ) ret += bit.RQuery( i , k + 1 , n );
        int f = block_size*( block_b-1 );
        for( int i = f+1; i <= r; i++ ) ret += ( a[i] > k ? 1 : 0 );
        return ret;
}
int main( ) {
        IO;
        #ifdef OFFLINE
            freopen( "input.txt" , "r" , stdin );
            freopen( "output.txt" , "w" , stdout );
        #endif // OFFLINE
        while( cin >> n >> m ) {
            bit.Init();
            memset( f , false , sizeof( f ) );
            memset( a , 0 , sizeof( a ) );
            for( int i = 1; i <= n; i++ ) {
                     int val;
                     cin >> val;
                     pos[ val ] = i;
            }
            for( int i = 1; i <= m; i++ ) {
                    int x;
                    cin >> x;
                    bad[i] = x;
                    f[x] = true;
            }
            vector <int> V;
            for( int i = 1; i <= n; i++ ) {
                    if( !f[ i ] ) V.push_back( i );
            }
            LL tot = 0;
            if( V.size() ) {
                    sort( V.begin() , V.end() );
                    for( auto x : V ) {
                            a[ pos[x] ] = x;
                            set_block( pos[x] , x );
                            tot += getsmall( pos[x] + 1 , n , x );
                    }
            }
            vector <int> ans;
            for( int i = m; i >= 1; i-- ) {
                    int cur = bad[i];
                    set_block( pos[cur] , cur );
                    a[pos[cur]] = cur;
                    tot += getsmall( pos[cur] + 1 , n , cur );
                    tot += getbig( 1 , pos[cur] - 1 , cur );
                    ans.push_back( tot );
            }
            reverse( ans.begin() , ans.end() );
            for( auto x : ans ) cout << x << endl;
        }
        return 0;
}








