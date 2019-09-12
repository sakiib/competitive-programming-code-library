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

#define   Check( N , p )   ( !( ( N & ( 1LL << p ) ) == 0 ) )
#define   ON( N , p )      ( N = N | ( 1LL << p ) )
#define   OFF( N , p )     ( N = N & ~( 1LL << p ) )

int n , a[ N ];

struct node {
        LL sz , sum;
        node *nxt[2];
        node( ) {
                sz = 0 , sum = 0;
                nxt[0]= nxt[1] = NULL;
        }
} *root;

LL ans;

void solve( int idx , int x ) {
        node *cur = root;
        for( int i = 20; i >= 0; i-- ) {
                int id = Check( x , i );
                if( cur -> nxt[id] == NULL ) return;
                cur = cur -> nxt[id];
        }
        ans += ( cur -> sz * idx - cur -> sum );
}
void add( int idx , int x ) {
        node *cur = root;
        for( int i = 20; i >= 0; i-- ) {
                int id = Check( x , i );
                if( cur -> nxt[id] == NULL ) {
                        cur -> nxt[id] = new node();
                }
                cur = cur -> nxt[id];
        }
        cur -> sz++;
        cur -> sum += idx;
}
void del( node* cur ) {
        for( int i = 0; i < 2; i++ ) {
                if( cur -> nxt[i] ) del( cur -> nxt[i] );
        }
        delete( cur );
}
int main( ) {
        IO;
        #ifdef LOCAL
            //freopen( "input.txt" , "r" , stdin );
        #endif // LOCAL
        int t;
        cin >> t;
        while( t-- ) {
                cin >> n;
                for( int i = 1; i <= n; i++ ) {
                         cin >> a[i];
                }
                root = new node( );
                int pref = 0;
                ans = 0;
                for( int i = 1; i <= n; i++ ) {
                        solve( i , pref^a[i] );
                        add( i , pref );
                        pref ^= a[i];
                }
                cout << ans << endl;
        }
        return 0;
}







