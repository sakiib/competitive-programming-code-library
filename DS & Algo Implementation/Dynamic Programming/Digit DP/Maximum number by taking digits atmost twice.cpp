#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef pair <int,int> pii;
typedef pair <long long,long long> pll;
const int MOD = 1e9 + 7;
const double EPS = 1e-8;
const int N = 1e5 + 5;
const int inf = 1e9;
const long long INF = 1e18;

int  on( int N , int pos )    { return N |= ( 1 << pos ); }
int  off( int N , int pos )  { return N = N & ~( 1 << pos ); }
bool check( int N , int pos )  { return (bool)( N & ( 1 << pos ) );}
int  toggle( int N , int pos ) { return ( N ^= ( 1 << pos ) ); }

LL n;
int dig[ 20 ];
int dp[ 20 ][ 1 << 20 ][ 2 ][ 2 ];

int calc( int mask , int d ) {
        int ret = mask;
        if( !check( ret , d ) ) {
                ret = on( ret , d );
                return ret;
        }
        if( !check( ret , d + 10 ) ) {
                ret = on( ret , d + 10 );
                return ret;
        }
        return -1;
}
int go( int idx , int mask , int lead , int tight ) {
        if( idx == -1 ) return 1;
        if( !tight && !lead && dp[idx][mask][lead][tight] != -1 )
                                    return dp[idx][mask][lead][tight];
        int ret = 0;
        int up = tight ? dig[idx] : 9;
        for( int i = up; i >= 0; i-- ) {
                int cur_mask = calc( mask , i );
                if( cur_mask == -1 ) continue;
                ret |= go( idx - 1 , cur_mask , lead&&(i==0) , tight&&(dig[idx]==i) );
        }
        if( !tight ) dp[idx][mask][lead][tight] = ret;
        return ret;
}

vector <int> ans;

void print( int idx , int mask , int lead , int tight ) {
        if( idx == -1 ) return;
        int ret = 0;
        int up = tight ? dig[idx] : 9;
        for( int i = up; i >= 0; i-- ) {
                int cur_mask = calc( mask , i );
                if( cur_mask == -1 ) continue;
                if( go( idx - 1 , cur_mask , lead&&(i==0) , tight&&(dig[idx]==i) ) ) {
                        if( !lead || ( lead && i != 0 ) ) ans.push_back( i );
                        print( idx - 1 , cur_mask , lead&&(i==0) , tight&&(dig[idx]==i) );
                        return;
                }
        }
}
void solve( ) {
        int len = 0;
        while( n ) dig[len++] = n%10 , n /= 10;
        ans.clear();
        go( len - 1 , 0 , 1 , 1 );
        print( len - 1 , 0 , 1 , 1 );
        for( int i = 0; i < ans.size(); i++ ) printf("%d",ans[i]);
        printf("\n");
}
int main( int argc , char const *argv[] ) {
        #ifdef forthright48
            freopen( "input.txt" , "r" , stdin );
        #endif // forthright48
        memset( dp , -1 , sizeof( dp ) );
        while( scanf("%lld",&n) != EOF ) {
                solve( );
        }
        return 0;
}













