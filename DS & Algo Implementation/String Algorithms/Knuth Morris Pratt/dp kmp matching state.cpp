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
const int MOD = 10000007;
const int inf = 1e9;
const double EPS = 1e-9;
const double PI = acos(-1.0);
const long long INF = 1e18;
const int N = 1e3 + 5;

/// uva - 12040

int d , l;
string s;
int dp[ N ][ N ];
int pi[ N ];

int add( int x , int y , int MOD ) {
        x += y;
        return x >= MOD ? x - MOD : x;
}
void prefix_function( string &s ) {
        int n = (int)s.size();
        pi[0] = 0;
        for ( int i = 1; i < n; i++ ) {
                int j = pi[i-1];
                while ( j > 0 && s[i] != s[j] ) j = pi[j-1];
                if ( s[i] == s[j] ) j++;
                pi[i] = j;
        }
}
int solve( int i , int j ) {
        if( j >= l ) return 0;
        if( i >= d ) return 1;
        if( dp[i][j] != -1 ) return dp[i][j];
        int ret = 0;
        int cur = j;
        for( int dig = 0 + ( i == 0 ); dig <= 9; dig++ ) {
                while( cur ) {
                        if( dig == (s[cur]-'0') ) break;
                        cur = pi[cur-1];
                }
                if( (s[cur]-'0') == dig ) ret = add( ret , solve( i + 1 , cur + 1 ) , MOD );
                else ret = add( ret , solve( i + 1 , cur ) , MOD );
                cur = j;
        }
        return dp[i][j] = ret;
}
int main( ) {
        IO;
        #ifdef LOCAL
            freopen( "input.txt" , "r" , stdin );
            freopen( "output.txt" , "w" , stdout );
        #endif // LOCAL
        int t;
        cin >> t;
        while( t-- ) {
                cin >> d >> s;
                l = s.size();
                prefix_function( s );
                memset( dp , -1 , sizeof( dp ) );
                cout << ( solve( 0 , 0 )%MOD + ( d == 1 )%MOD )%MOD << endl;
        }
        return 0;
}









