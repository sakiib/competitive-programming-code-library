#include <bits/stdc++.h>
using namespace std;

#define trace(...) __f( #__VA_ARGS__ , __VA_ARGS__ )
template <typename Arg1>
void __f( const char* name , Arg1&& arg1 ) {
        cerr << name << " : " << arg1 << "\n";
}
template <typename Arg1, typename... Args>
void __f( const char* na , Arg1&& arg1 , Args&&... args ) {
        const char* c = strchr( na + 1 , ',' );
        cerr.write( na , c - na ) << " : " << arg1 << " , ";
        __f( c + 1 , args... );
}
#define endl "\n"
#define all(V) V.begin(),V.end()
#define Unique(V) sort(all(V)),V.erase(unique(all(V)),V.end())
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int LL;
const int N = 1e6 + 5;

#define ran(a, b) rand() % ( (b) - (a) + 1 ) + (a)
int l;
string s[ N ];
int p[ N ][ 2 ];
int base[] = { 43 , 37 };
int invbase[] = { 395348840 , 297297300 };
int MOD[] = { 1000000007 , 1000000009 };
const int mod1[] = {1000000007, 1000000009, 1000000021, 1000000033, 1000000087};
const int mod2[] = {1000000093, 1000000097, 1000000103, 1000000123, 1000000181};
const int base1[] = { 23 , 29 , 31 , 37 , 41 };
const int base2[] = { 43 , 47 , 53 , 59 , 61 };
int invmod[ N ][ 2 ];
int h[ N ][ 2 ];

inline LL bigmod( LL b , LL p , LL mod ) {
        LL res = 1%mod , x = b%mod;
        while( p ) {
            if( p&1 ) res = (res * x)%mod; x = (x * x)%mod; p >>= 1;
        } return (res%mod);
}
inline int add( int x , int y , int MOD ) {
        return x + y >= MOD ? x + y - MOD : x + y;
}
inline int sub( int x , int y , int MOD ) {
        return x - y < 0 ? x - y + MOD : x - y;
}
inline int mul( int x , int y , int MOD ) {
        return ( 1LL * x * y ) % MOD;
}
inline void update( char ch ) {
        for( int i = 0; i <= 1; i++ ) {
                h[l][i] = mul( p[l][i] , ch , MOD[i] );
                if( l ) h[l][i] = add( h[l][i] , h[l-1][i] , MOD[i] );
        }l++;
}
inline LL make_big( LL x , LL y ) {
        return ( x << 31 ) | y;
}
inline LL get_hash( int l , int r ) {
        if( l == 0 ) return make_big( h[r][0] , h[r][1] );
        int x = sub( h[r][0] , h[l-1][0] , MOD[0] );
        x = mul( x , invmod[l][0], MOD[0] );
        int y = sub( h[r][1] , h[l-1][1] , MOD[1] );
        y = mul( y , invmod[l][1] , MOD[1] ); return make_big( x , y );
}
int main( ) {
        IO;
        #ifdef LOCAL
            freopen( "input.txt" , "r" , stdin );
        #endif // LOCAL
        srand( time( NULL ) );
        MOD[0] = mod1[ ran( 0 , 4 ) ] , base[0] = base1[ ran( 0 , 4 ) ];
        invbase[0] = bigmod( base[0] , MOD[0] - 2 , MOD[0] );
        MOD[1] = mod2[ ran( 0 , 4 ) ] , base[1] = base2[ ran( 0 , 4 ) ];
        invbase[1] = bigmod( base[1] , MOD[1] - 2 , MOD[1] );
        p[0][0] = p[0][1] = invmod[0][0] = invmod[0][1] = 1;
        for( int i = 1; i < N; i++ ) {
                for( int j = 0; j <= 1; j++ ) {
                        p[i][j] = mul( p[i-1][j] , base[j] , MOD[j] );
                        invmod[i][j] = mul( invmod[i-1][j] , invbase[j] , MOD[j] );
                }
        }
        int n;
        cin >> n;
        for( int i = 1; i <= n; i++ ) cin >> s[i];
        string ans = s[1];
        for( int i = 0; i < ans.size(); i++ ) update( ans[i] );
        for( int i = 2; i <= n; i++ ) {
                string cur = s[i];
                int lb = cur.size() , la = ans.size();
                int x = 0 , y = 0;
                int start = 0;
                for( int i = la - 1 , j = 0; j < lb && i >= 0; j++ , i-- ) {
                        x = add( x , mul( p[j][0] , cur[j] , MOD[0] ) , MOD[0] );
                        y = add( y , mul( p[j][1] , cur[j] , MOD[1] ) , MOD[1] );
                        LL cur_hash = make_big( x , y );
                        if( get_hash( i , la - 1 ) ==  cur_hash ) start = j + 1;
                }
                for( int j = start; j < lb; j++ ) update( cur[j] ) , ans += cur[j];
        }
        cout << ans << endl;
        return 0;
}









