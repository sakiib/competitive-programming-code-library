#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(V) V.begin(), V.end()
#define Unique(V) sort(all(V)), V.erase(unique(all(V)), V.end())
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long int LL;
const int N = 1e5 + 5;

const int MOD = 1000000007;
int n;
LL a[ N ];

template <typename T> class binary_indexed_tree {
    public:
        static const int N = 1e5 + 5;
        T BIT[ N + 10 ];
        inline void init( ) {
                memset( BIT , 0 , sizeof( BIT ) );
        }
        inline T r_query ( int l , int r ) {
                if( l > r ) return 0;
                return p_query( r ) - p_query( l - 1 );
        }
        inline void p_update ( int idx , T v ) {
                if( idx <= 0 ) return;
                for( ;idx <= N; idx += ( idx & -idx ) ) BIT[ idx ] += v;
        }
        inline T p_query ( int idx ) {
                T ret = 0;
                for( ;idx > 0; idx -= ( idx & -idx ) ) ret += BIT[ idx ];
                return ret;
        }
        inline void r_update ( int idx , int idy , T v ) {
                for( ;idx <= N; idx += ( idx & -idx ) ) BIT[ idx ] += v;
                idy++ , v *= -1;
                for( ;idy <= N; idy += ( idy & -idy ) ) BIT[ idy ] += v;
        }
};

int main( ) {
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
                scanf("%d",&n);
                vector <LL> V;
                for( int i = 1; i <= n; i++ ) {
                        scanf("%lld",&a[i]) , V.push_back( a[i] );
                }
                Unique( V );
                map <LL,LL> M;
                int id = 0;
                for( int i = 0; i < V.size(); i++ ) M[V[i]] = ++id;
                for( int i = 1; i <= n; i++ ) a[i] = M[ a[i] ];
                binary_indexed_tree <LL> bit;
                LL ans = 0;
                bit.init();
                for( int i = 1; i <= n; i++ ) {
                        LL cur = bit.r_query( 1 , a[i] - 1 ) + 1;
                        ans = ( ans%MOD + cur%MOD )%MOD;
                        bit.p_update( a[i] , cur%MOD );
                }
                printf("Case %d: %lld\n",tc,ans);
        }
        return 0;
}






