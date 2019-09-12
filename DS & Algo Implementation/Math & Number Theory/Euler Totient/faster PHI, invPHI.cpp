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
const int N = 2e8 + 5;

int PHI[ N ];
int invPHI[ N ];

inline void sievePhi( int SZ ) {
        for( int i = 0; i <= SZ; i++ ) invPHI[i] = inf;
        PHI[1] = 1;
        for( int i = 2; i <= SZ; i++ ) {
                if( !PHI[i] ) {
                        PHI[i] = i - 1;
                        for( int j = 2 * i; j <= SZ; j += i ) {
                                if( !PHI[j] ) PHI[j] = j;
                                PHI[j] -= PHI[j] / i;
                        }
                }
        }
        for( int i = 1; i <= SZ; i++ ) {
                invPHI[ PHI[i] ] = min( invPHI[ PHI[i]] , i );
        }
}
/**
just PHI..
inline void sievePhi( int SZ ) {
        PHI[1] = 1;
        for( int i = 2; i <= SZ; i++ ) {
                if( !PHI[i] ) {
                        PHI[i] = i - 1;
                        for( int j = 2 * i; j <= SZ; j += i ) {
                                if( !PHI[j] ) PHI[j] = j;
                                PHI[j] -= PHI[j] / i;
                        }
                }
        }
}
*/
int main( ) {
        #ifdef LOCAL
            //freopen( "input.txt" , "r" , stdin );
        #endif // LOCAL
        sievePhi( 2e8 );
        int t;
        scanf("%d",&t);
        while( t-- ) {
                int n;
                scanf("%d",&n);
                if( invPHI[n] == inf ) printf("-1\n");
                else printf("%d\n",invPHI[n]);
        }
        return 0;
}

