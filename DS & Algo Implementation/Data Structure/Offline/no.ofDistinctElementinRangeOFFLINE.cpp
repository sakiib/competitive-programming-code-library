#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
typedef pair < int , int > ii;
const int inf = 1e9;
const LL INF = 1e18;
const int N = 1e6 + 5;
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

struct data {
        int l;
        int r;
        int val;
        int idx;
        int type; /// 0 add val , 1 query
        data(){}
        data( int _l , int _r , int _val , int _idx , int _type ) {
                l = _l , r = _r , val = _val , idx = _idx , type = _type;
        }
        bool operator <( const data &q ) const {
              if( r == q.r ) return val > q.val;
              return r < q.r;
        }
};

vector <data> V;
int n , q , vis[ 10*N ] , ans[ 2*N ];

int main( int argc , char const *argv[] ) {
        scanf("%d",&n);
        for( int i = 1; i <= n; i++ ) {
                int num;
                scanf("%d",&num);
                V.push_back( data( i , i , num , -1 , 0 ) );
        }
        scanf("%d",&q);
        for( int i = 1; i <= q; i++ ) {
                int l , r;
                scanf("%d %d",&l,&r);
                V.push_back( data( l , r , 0 , i , 1 ) );
        }
        sort( V.begin() , V.end() );
        //for( auto x : V ) cout << x.l <<" "<<x.r<<" "<<x.val<<" "<<x.idx<<" "<<x.type<<endl;
        memset( vis , 0 , sizeof(vis) );
        for( auto x : V ) {
                if( x.type == 1 ) {
                        ans[ x.idx ] = bit.RQuery( x.l , x.r );
                }
                else {
                        if( vis[ x.val ] != 0 ) bit.PUpdate( vis[ x.val ] , -1 );
                        bit.PUpdate( x.l , +1 );
                        vis[ x.val ] = x.l;
                }
        }
        for( int i = 1; i <= q; i++ ) printf("%d\n",ans[i]);
        return 0;
}
