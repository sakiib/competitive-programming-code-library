#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef pair <int,int> pii;
typedef pair <long long,long long> pll;
const double EPS = 1e-8;
const int N = 1e5 + 5;
const int inf = 1e9;
const long long INF = 1e18;

const int base = 257;
const int invbase = 70038911;
const int MOD = 1e9 + 7;

int n , q , a[ N ];
int p[ N ] , invmod[ N ];
int ana[ N ];

inline int add( int x , int y , int MOD ) {
        x += y;
        return x >= MOD ? x - MOD : x;
}
inline int sub( int x , int y , int MOD ) {
        x -= y;
        return x < 0 ? x + MOD : x;
}
inline int mul( int x , int y , int MOD ) {
        return ( 1LL * x * y ) % MOD;
}
inline void gen_pow( ) {
        p[0] = 1 , invmod[0] = 1;
        for( int i = 1; i < N; i++ ) {
                p[i] = mul( p[i-1] , base , MOD );
                invmod[i] = mul( invmod[i-1] , invbase , MOD );
        }
}
inline void build_hash( ) {
        for( int i = 1; i <= n; i++ ) {
                ana[i] = add( ana[i] , add( ana[i-1] , p[a[i]] , MOD ) , MOD );
        }
}
inline int get_ana_hash( int l , int r ) {
        return sub( ana[r] , ana[l-1] , MOD );
}
int main( int argc , char const *argv[] ) {
        scanf("%d %d",&n,&q);
        gen_pow();
        for( int i = 1; i <= n; i++ ) scanf("%d",&a[i]);
        build_hash();
        while( q-- ) {
                int a , b , c , d;
                scanf("%d %d %d %d",&a,&b,&c,&d);
                if( get_ana_hash( a , b ) == get_ana_hash( c , d ) ) puts("Yes");
                else puts("No");
        }
        return 0;
}










