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
typedef pair <int,int> pii;
const int MOD = 1e9 + 7;
const int inf = 1e9;
const double EPS = 1e-9;
const double PI = acos(-1.0);
const long long INF = 1e18;
const int N = 1e5 + 5;

const LL MX = 1e12;

int n;
LL sz;
string s;
LL len[ 105 ];
int nxt[ 105 ][ 30 ];
LL dp[ 105 ][ 105 ];

LL solve( int idx , int l ) {
        if( idx >= n ) return 0;
        if( l == 1 ) return 1;
        if( dp[idx][l] != -1 ) return dp[idx][l];
        LL ret = 0;
        for( int i = 1; i <= 26; i++ ) ret += solve( nxt[idx+1][i] , l - 1 );
        return dp[idx][l] = min( MX , ret );
}
int main( ) {
        IO;
        #ifdef LOCAL
            //freopen( "input.txt" , "r" , stdin );
        #endif // LOCAL
        cin >> n >> sz >> s;
        for( int i = 1; i <= 26; i++ ) nxt[n][i] = n;
        for( int i = n - 1; i >= 0; i-- ) {
                for( int j = 1; j <= 26; j++ ) {
                        nxt[i][j] = nxt[i+1][j];
                }
                nxt[i][s[i]-'a'+1] = i;
        }
        memset( dp , -1 , sizeof( dp ) );
        len[0] = 1;
        for( int i = n; i >= 1; i-- ) {
                for( int j = 1; j <= 26; j++ ) {
                        len[i] += solve( nxt[0][j] , i );
                }
        }
        /// for( int i = 0; i <= n; i++ ) trace( i , len[i] ); i length er distinct subsequence
        LL ans = 0;
        for( int i = n; i >= 0; i-- ) {
                if( len[i] >= sz ) {
                        ans += 1LL * ( n - i ) * sz;
                        return cout << ans << endl,0;
                }
                else {
                        ans += 1LL * ( n - i ) * len[i];
                        sz -= len[i];
                }
        }
        cout << -1 << endl;
        return 0;
}








