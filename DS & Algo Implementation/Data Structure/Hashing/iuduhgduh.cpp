#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#define endl "\n"
#define all(V) V.begin( ), V.end( )
#define Unique(V) sort( all( V ) ), V.erase( unique( all( V ) ), V.end() )
#define Check( N , p ) ( !( ( N & ( 1LL << p ) ) == 0 ) )
#define ON( N , p ) ( N = N | ( 1LL << p ) )
#define OFF( N , p ) ( N = N & ~( 1LL << p ) )
std::mt19937 rng( chrono::steady_clock::now().time_since_epoch().count() );
#define rnd(a, b) ((((rand() << 15) ^ rand()) % ((b) - (a) + 1)) + (a))
#define ran(a, b) rng() % ( (b) - (a) + 1 ) + (a)
#define trace(...) __f( #__VA_ARGS__ , __VA_ARGS__ )
template < typename Arg1 >
void __f( const char* name , Arg1&& arg1 ) { cerr << name << " : " << arg1 << "\n"; }
template < typename Arg1 , typename... Args >
void __f( const char* names , Arg1&& arg1 , Args&&... args ) {
const char* comma = strchr( names + 1 , ',' );
cerr.write( names , comma - names ) << " : " << arg1 << " , " ; __f( comma + 1 , args... ); }
typedef long long int LL;
typedef pair <int,int> pii;
typedef pair <long long,long long> pll;
const int MOD = 1e9 + 7;
const double EPS = 1e-8;
const int N = 1e5 + 5;
const int inf = 1e9;
const long long INF = 1e18;

char s[ 35 ];
int p[ 35 ][ 2 ];
const int base[] = { 37 , 43 };
const int mod[] = { 1000000007 , 1000000009 };

void add( int &x , int y , int m ) {
        x += y;
        if( x > y ) x -= m;
}
void sub( int &x , int y , int m ) {
        x -= y;
        if( x < 0 ) x += m;
}
int mul( int x , int y , int m ) {
        return ( 1LL * x * y ) % m;
}
int main( int argc , char const *argv[] ) {
        int n;
        scanf("%d",&n);
        p[0][0] = 1 , p[0][1] = 1;
        for( int i = 1; i <= 33; i++ ) {
                p[i][0] = mul( p[i-1][0] , base[0] , mod[0] );
                p[i][1] = mul( p[i-1][1] , base[1] , mod[1] );
        }
        map <LL,int> M;
        for( int i = 1; i <= n; i++ ) {
                scanf("%s",s);
                int len = strlen( s );
                int hash1 = 0 , hash2 = 0;
                for( int j = 0; j < len; j++ ) {
                        add( hash1 , mul( p[j][0] , s[j] , mod[0] ) , mod[0] );
                        add( hash2 , mul( p[j][1] , s[j] , mod[1] ) , mod[1] );
                }
                LL cur = ( 1LL * hash1 << 31 ) | hash2;
                if( M[cur] == 0 ) printf("OK\n");
                else printf("%s%d\n",s,M[cur]);
                M[cur]++;
        }
        return 0;
}












