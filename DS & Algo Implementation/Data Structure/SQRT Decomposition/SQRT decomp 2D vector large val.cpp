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

int block_size = 800;
vector <LL> BLOCK[ 505 ];

LL a[ N ];
int n , m;
LL u;

void Calc( ) {
        for( int i = 1; i <= 500; i++ ) BLOCK[i].clear();
}
int Block_ID( int id ) {
        int pos = ( ( id + block_size - 1 ) / block_size );
        return pos;
}
void SetBlock( int id , LL v ) {
        int pos = Block_ID( id );
        BLOCK[pos].push_back( v );
}
pair <int,int> StartEndofBlock( int id ) {
        int st = ( id - 1 ) * block_size + 1;
        int en = min( n , ( st + block_size - 1 ) );
        return {st,en};
}
LL Query( int l , int r , LL val ) {
        int block_a = Block_ID( l ) , block_b = Block_ID( r );
        if( block_a == block_b ) {
                LL sum = 0;
                for( int i = l; i <= r; i++ ) sum += ( a[i] < val );
                return sum;
        }
        LL ret = 0;
        for( int i = l; ; i++ ) {
                int pos = Block_ID( i );
                if( pos != block_a ) break;
                ret += ( a[i] < val );
        }
        for( int i = block_a + 1; i < block_b; i++ ) {
                ret += lower_bound( BLOCK[i].begin() , BLOCK[i].end() , val ) - BLOCK[i].begin();
        }
        int f = block_size * ( block_b - 1 );
        for( int i = f + 1; i <= r; i++ ) {
                ret += ( a[i] < val );
        }
        return ret;
}
/**
void Update( int pos , LL val ) {
        int id = Block_ID( pos );
        vector <LL> temp;
        int idx = 0;
        for( int i = 0; i < BLOCK[id].size(); i++ ) {
                if( BLOCK[id][i] == a[pos] ) {
                        idx = i;
                        break;
                }
        }
        a[pos] = val;
        bool f = false;
        for(int i = 0; i < BLOCK[id].size(); i++ ) {
                if( i == idx ) continue;
                if( BLOCK[id][i] >= val && !f ) {
                        f = true;
                        temp.push_back( val );
                        temp.push_back( BLOCK[id][i] );
                }
                else temp.push_back( BLOCK[id][i] );
        }
        if( !f ) temp.push_back( val );
        BLOCK[id].clear();
        BLOCK[id] = temp;
}
*/
void Update( int pos , LL val ) {
        int id = Block_ID( pos );
        pair <int,int> f = StartEndofBlock( id );
        a[pos] = val;
        BLOCK[id].clear();
        for( int i = f.first; i <= f.second; i++ ) BLOCK[id].push_back( a[i] );
        sort( BLOCK[id].begin() , BLOCK[id].end() );
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( NULL );

        //freopen( "input.txt" , "r" , stdin );
        //freopen( "output.txt" , "w" , stdout );

        Calc( );
        cin >> n >> m >> u;
        for( int i = 1; i <= n; i++ ) {
                cin >> a[i];
                SetBlock( i , a[i] );
        }
        for( int i = 1; i <= 500; i++ ) sort( BLOCK[i].begin() , BLOCK[i].end() );
        while( m-- ) {
                int l , r;
                LL v , p;
                cin >> l >> r >> v >> p;
                LL small = Query( l , r , v );
                LL val = u * small / ( r - l + 1 );
                Update( p , val );
        }
        for( int i = 1; i <= n; i++ ) cout << a[i] << endl;
        return 0;
}
/**

Number of elements less than a number in L to R
with update operations , can't be compressed

Binary Search + SQRT decomp
*/










