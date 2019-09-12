#include <bits/stdc++.h>
using namespace std;

#define Fast_IO ios_base::sync_with_stdio(0); cin.tie(0);

typedef unsigned long long uLL;
typedef long long int LL;
const int N = 1e5 + 5;
const int inf = 1e9;
const LL INF = 1e18;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int MOD = 1000000007;

int  Set( int N , int pos )    { return N |= ( 1 << pos ); }
int  Reset( int N , int pos )  { return N = N & ~( 1 << pos ); }
bool Check( int N , int pos )  { return (bool)( N & ( 1 << pos ) );}
int  Toggle( int N , int pos ) { return ( N ^= ( 1 << pos ) ); }

int b , g;
int mask[ 500 ];

int main( int argc , char const *argv[] ) {
        int t;
        scanf("%d",&t);
        while( t-- ) {
                scanf("%d %d",&b,&g);
                memset( mask , 0 , sizeof(mask) );
                for( int i = 0; i < g; i++ ) {
                        int x , y;
                        scanf("%d %d",&x,&y);
                        --x , --y;
                        mask[x] = Set( mask[x] , y );
                }
                int ans = 0;
                for( int i = 0; i < ( 1 << b ); i++ ) {
                        int curmask = ( 1 << b )-1;
                        for( int j = 0; j < b; j++ ) {
                               /// depends on problem
                               if( ( i&( 1 << j ) ) ) curmask = ( curmask&mask[j] );
                        }
                        /// builtin(i) = koyta nisi
                        ans = max( ans , __builtin_popcount( i ) + __builtin_popcount( curmask ) );
                }
                printf("%d\n",ans);
        }
        return 0;
}







