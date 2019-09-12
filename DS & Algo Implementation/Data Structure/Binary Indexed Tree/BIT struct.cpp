#include <bits/stdc++.h>
using namespace std;

struct BINARY_INDEXED_TREE {
        static const int MAXN = 1e6 + 5;
        int BIT[ MAXN + 5 ];

        inline void initialize( ) {
                memset( BIT , 0 , sizeof( BIT ) );
        }
        inline int r_query ( int l , int r ) {
                return p_query( r ) - p_query( l - 1 );
        }
        inline void p_update ( int idx , int v ) {
                if( idx <= 0 ) return;
                for( ;idx <= MAXN; idx += ( idx & -idx ) ) BIT[ idx ] += v;
        }
        inline int p_query ( int idx ) {
                int ret = 0;
                for( ;idx > 0; idx -= ( idx & -idx ) ) ret += BIT[ idx ];
                return ret;
        }
        inline void r_update ( int idx , int idy , int v ) {
                for( ;idx <= MAXN; idx += ( idx & -idx ) ) BIT[ idx ] += v;
                idy++ , v *= -1;
                for( ;idy <= MAXN; idy += ( idy & -idy ) ) BIT[ idy ] += v;
        }
} bit;

struct binary_indexed_tree {
        static const int N = 1e5 + 5;
        int BIT[ N + 5 ];
        void init( ) { memset( BIT , 0 , sizeof(BIT) ); }
        int r_query ( int l , int r ) {
                return p_query( r ) - p_query( l - 1 );
        }
        void p_update ( int idx , int v ) {
                if( idx <= 0 ) return;
                for(;idx <= N; idx += ( idx & -idx )) BIT[idx] += v;
        }
        int p_query ( int idx ) {
                int ret = 0;
                for(;idx > 0; idx -= ( idx & -idx )) ret += BIT[idx];
                return ret;
        }
        void r_update ( int idx , int idy , int v ) {
                for(;idx <= N; idx += ( idx & -idx )) BIT[idx] += v;
                idy++ , v *= -1;
                for(;idy <= N; idy += ( idy & -idy )) BIT[idy] += v;
        }
};
int main( int argc , char const *argv[] ) {

    bit.initialize( );

    return 0;
}










