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
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

/**
MIN of all sub-rect of a x b , given the matrix of n x m
runtime : N * N
matrix is 0,0 based
*/

typedef long long LL;
const int N = 3005;
int mn[ N ][ N ];
int g[ N * N ];

vector <int> reduce( vector <int> &a , int b ) {
        int n = a.size( );
        deque <int> dq;
        vector <int> ans;
        int cr = -1;
        for( int l = 0; l + b - 1 < n; l++ ) {
                int r = l + b - 1;
                while( cr < r ) {
                    cr++;
                    while( dq.size() && a[dq.back()] >= a[cr] ) dq.pop_back();
                    dq.push_back( cr );
                }
                while( dq.front() < l ) dq.pop_front();
                ans.push_back( a[ dq.front() ] );
        }
        return ans;
}
int main( ) {
        IO;
        int n , m , a , b;
        cin >> n >> m >> a >> b;
        int x , y , z;
        cin >> g[0] >> x >> y >> z;
        for( int i = 1; i < n * m; i++ ) {
                g[i] = ( 1LL * g[i-1] * x + y )%z;
        }
        for( int i = 0; i < n; i++ ) {
                for( int j = 0; j < m; j++ ) {
                        mn[i][j] = g[ i * m + j ];
                }
        }
        int nn = n - a + 1 , mm = m - b + 1;
        for( int i = 0; i < n; i++ ) {
                vector <int> v;
                for( int j = 0; j < m; j++ ) v.push_back( mn[i][j] );
                v = reduce( v , b );
                for( int j = 0; j < mm; j++ ) mn[i][j] = v[j];
        }
        m = mm;
        for( int j = 0; j < m; j++ ) {
                vector <int> v;
                for( int i = 0; i < n; i++ ) v.push_back( mn[i][j] );
                v = reduce( v , a );
                for( int i = 0; i < nn; i++ ) mn[i][j] = v[i];
        }
        n = nn;
        LL ans = 0;
        for( int i = 0; i < n; i++ ) {
                for( int j = 0; j < m; j++ ) {
                        ans += mn[i][j];
                }
        }
        cout << ans << endl;
        return 0;
}








