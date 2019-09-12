#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 1e5 + 5;
const int mod[] = { 1000000007 , 1000000009 };
const int base[] = { 37 , 43 };

int n , q;
char s[ N ];
int p[ N ][ 2 ];
vector <LL> Hash[ N ];

int mul( int x , int y , int m ) { return 1LL * x * y % m; }
void add( int &x , int y , int m ) { x += y; if( x > m ) x -= m; }

void gen_power( ) {
        p[0][0] = p[0][1] = 1;
        for( int i = 1; i < N; i++ ) {
                p[i][0] = mul( p[i-1][0] , base[0] , mod[0] );
                p[i][1] = mul( p[i-1][1] , base[1] , mod[1] );
        }
}
void add_hash( ) {
        int len = strlen( s );
        int Hash1 = 0 , Hash2 = 0 , l = 0;
        for( int i = len - 1; i >= 0; i-- ) {
                int x = mul( p[len-1-i][0] , s[i] , mod[0] );
                add( Hash1 , x , mod[0] );
                int y = mul( p[len-1-i][1] , s[i] , mod[1] );
                add( Hash2 , y , mod[1] );
                Hash[++l].push_back( ( 1LL*Hash1 << 31 ) | Hash2 );
        }
}
int solve( int len ) {
        if( Hash[len].size() == 0 ) return 0;
        int lo = 0 , hi = Hash[len].size() - 1 , mx = 0;
        while( 1 ) {
                int l = lo , r = hi , ret = -1;
                if( l >= Hash[len].size() ) break;
                LL cur_hash = Hash[len][l];
                while( l <= r ) {
                        int m = ( l + r ) >> 1;
                        if( Hash[len][m] <= cur_hash ) ret = m , l = m + 1;
                        else r = m - 1;
                }
                if( ret != -1 ) mx = max( mx , ret - lo + 1 );
                lo = ret + 1;
        }
        return mx;
}
int main( int argc , char const *argv[] ) {
        gen_power();
        int t;
        scanf("%d",&t);
        while( t-- ) {
                for( int i = 1; i < N; i++ ) Hash[i].clear();
                scanf("%d %d",&n,&q);
                for( int i = 1; i <= n; i++ ) {
                        scanf("%s",s);
                        add_hash( );
                }
                for( int i = 1; i < N; i++ ) {
                        sort( Hash[i].begin() , Hash[i].end() );
                }
                while( q-- ) {
                        int l;
                        scanf("%d",&l);
                        printf("%d\n",solve( l ) );
                }
        }
        return 0;
}












