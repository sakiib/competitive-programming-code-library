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

struct data {
        int x , y , z;
        data(){}
        data( int x , int y , int z ) : x(x) , y(y) , z(z) {}
        bool operator <( const data &q ) const {
                return z < q.z;
        }
};

int n , m , k , q;
vector <data> V;
int grid[ 505 ][ 505 ];
int sum[ 505 ][ 505 ];

bool ok( int t ) {
        memset( grid , 0 , sizeof( grid ) );
        memset( sum , 0 , sizeof( sum ) );
        for( auto it : V ) {
                if( it.z > t ) break;
                grid[it.x][it.y] = 1;
        }
        for( int i = 1; i <= n; i++ ) {
                for( int j = 1; j <= m; j++ ) {
                        sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + grid[i][j];
                }
        }
        for( int i = 1; i + k - 1 <= n; i++ ) {
                for( int j = 1; j + k - 1 <= m; j++ ) {
                        int kk = i + k - 1 , ll = j + k - 1;
                        int tot = sum[kk][ll] - sum[i-1][ll] - sum[kk][j-1] + sum[i-1][j-1];
                        if( tot == k * k ) return true;
                }
        }
        return false;
}
int main( ) {
        IO;
        #ifdef LOCAL
            //freopen( "input.txt" , "r" , stdin );
        #endif // LOCAL
        cin >> n >> m >> k >> q;
        for( int i = 1; i <= q; i++ ) {
                int x , y , z;
                cin >> x >> y >> z;
                V.push_back( data( x , y , z ) );
        }
        sort( V.begin() , V.end() );
        int lo = 0 , hi = inf , ret = -1;
        while( lo <= hi ) {
                int mid = ( lo + hi ) >> 1;
                if( ok( mid ) ) ret = mid , hi = mid - 1;
                else lo = mid + 1;
        }
        cout << ret << endl;
        return 0;
}








