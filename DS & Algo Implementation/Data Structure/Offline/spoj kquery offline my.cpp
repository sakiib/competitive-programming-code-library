#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
typedef pair < int , int > ii;
const int inf = 1e9;
const LL INF = 1e18;
const int N = 3e5 + 5;
const int mod = 1000000007;
const double eps = 1e-8;
const double pi = acos( -1.0 );

struct BinaryIndexedTree {

    int BIT[ N+10 ];

    inline void Init( ) { memset( BIT , 0 , sizeof( BIT ) ); }

    inline int RQuery ( int l , int r ) { return PQuery( r ) - PQuery( l-1 ); }

    inline void PUpdate ( int idx , int val ) {
        for( ; idx <= N; idx += ( idx & -idx ) ) BIT[ idx ] += val;
    }
    inline int PQuery ( int idx ) {
        int ret = 0;
        for( ; idx > 0; idx -= ( idx & -idx ) ) ret += BIT[ idx ]; return ret;
    }
    inline void RUpdate ( int idx , int idy , int val ) {
        for( ; idx <= N; idx += ( idx & -idx ) ) BIT[ idx ] += val;
        idy++ , val *= -1;
        for( ; idy <= N; idy += ( idy & -idy ) ) BIT[ idy ] += val;
    }
} bit;

struct event {
        int type; /// 0 add , 1 - query
        int val;
        int l;
        int r;
        int id;
        int pos;
        event( int _type, int _val, int _l, int _r, int _id, int _pos ) {
                type = _type , val = _val , l = _l , r = _r , id = _id , pos = _pos;
        }
        bool operator <( const event &other ) const {
                if( val != other.val ) return val > other.val;
                return type > other.type;
        }
};

int a[ N ] , ans[ N ];
vector <event> V;

int main( int argc , char const *argv[] ) {
        int n;
        scanf("%d",&n);
        for( int i = 1; i <= n; i++ ) {
                scanf("%d",&a[i]);
                V.push_back( { 0 , a[i] , -1 , -1 , -1 , i } );
        }
        int q;
        scanf("%d",&q);
        for( int i = 1; i <= q; i++ ) {
                int l , r , val;
                scanf("%d %d %d",&l,&r,&val);
                V.push_back( { 1 , val , l , r , i , -1 } );
        }
        sort( V.begin() , V.end() );
        for( auto x : V ) {
                if( x.type == 0 ) {
                        bit.PUpdate( x.pos , +1 );
                }
                else {
                        int res = bit.RQuery( x.l , x.r );
                        ans[ x.id ] = res;
                }
        }
        for( int i = 1; i <= q; i++ ) {
                printf("%d\n",ans[i]);
        }
        return 0;
}






