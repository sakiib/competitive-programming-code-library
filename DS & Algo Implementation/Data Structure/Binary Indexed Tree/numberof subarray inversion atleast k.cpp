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

int n;
LL k;
int a[ N ];
map <int,int> M;

template <typename T> class binary_indexed_tree {
    public:
        static const int N = 1e5 + 5;
        T BIT[ N + 5 ];
        void init( ) { memset( BIT , 0 , sizeof(BIT) ); }
        T r_query ( int l , int r ) {
                return p_query( r ) - p_query( l - 1 );
        }
        void p_update ( int idx , int v ) {
                if( idx <= 0 ) return;
                for(;idx <= N; idx += ( idx & -idx )) BIT[idx] += v;
        }
        T p_query ( int idx ) {
                T ret = 0;
                for(;idx > 0; idx -= ( idx & -idx )) ret += BIT[idx];
                return ret;
        }
        void r_update ( int idx , int idy , T v ) {
                for(;idx <= N; idx += ( idx & -idx )) BIT[idx] += v;
                idy++ , v *= -1;
                for(;idy <= N; idy += ( idy & -idy )) BIT[idy] += v;
        }
};

LL solve( ) {
        int l = 1 , r = 0;
        LL tot = 0;
        LL ans = 0;
        LL inv = 0;
        binary_indexed_tree <int> bit;
        bit.init();
        while( l <= n && r <= n ) {
                while( r + 1 <= n && ( inv < k || l > r ) ) {
                        r++;
                        inv += bit.r_query( a[r] + 1 , 1e5 );
                        bit.p_update( a[r] , +1 );
                }
                if( inv >= k ) ans += ( n - r + 1 );
                bit.p_update( a[l] , -1 );
                inv -= bit.r_query( 1 , a[l] - 1 );
                l++;
        }
        return ans;
}
int main( ) {
        IO;
        #ifdef LOCAL
            freopen( "input.txt" , "r" , stdin );
        #endif // LOCAL
        cin >> n >> k;
        vector <int> V;
        for( int i = 1; i <= n; i++ ) {
                cin >> a[i] , V.push_back( a[i] );
        }
        Unique( V );
        int id = 0;
        for( auto x : V ) M[x] = ++id;
        for( int i = 1; i <= n; i++ ) a[i] = M[a[i]];
        cout << solve() << endl;
        return 0;
}








