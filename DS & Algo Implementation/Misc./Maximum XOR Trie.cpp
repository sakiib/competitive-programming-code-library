#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template <typename T> using
Treap = tree <T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef unsigned long long uLL;
typedef long long int LL;
typedef pair <int,int> pii;
typedef pair <long long,long long> pll;
const int N = 1e5 + 5;
const int inf = 1e9;
const long long INF = 1e18;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int MOD = 1000000007;

#define Check( N , p ) ( !( ( N & ( 1LL << p ) ) == 0 ) )
#define ON( N , p ) ( N = N | ( 1LL << p ) )
#define OFF( N , p ) ( N = N & ~( 1 << p ) )

struct Node {
        int cnt;
        bool endMark;
        Node *Next[ 2 ];
        Node( ) {
                cnt = 0 , endMark = false , Next[0] = Next[1] = NULL;
        }
} *Root;

void Add( int val ) {
        Node *cur = Root;
        for( int i = 30; i >= 0; i-- ) {
                int id = Check( val , i );
                if( cur -> Next[id] == NULL ) cur -> Next[id] = new Node( );
                cur = cur -> Next[id];
                cur -> cnt++;
        }
}
void Remove( int val ) {
        Node *cur = Root;
        for( int i = 30; i >= 0; i-- ) {
                int id = Check( val , i );
                cur = cur -> Next[id];
                cur -> cnt--;
        }
}
LL Query( int val ) {
        Node *cur = Root;
        LL ans = 0;
        for( int i = 30; i >= 0; i-- ) {
                int id = Check( val , i );
                if( cur -> Next[id^1] != NULL && cur -> Next[id^1] -> cnt > 0 ) {
                        cur = cur -> Next[id^1];
                        ON( ans , i );
                }
                else if( cur -> Next[id] != NULL && cur -> Next[id] -> cnt > 0 ) {
                        cur = cur -> Next[id];
                }
        }
        return ans;
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( NULL );

        //cout << ( 1 << 30 ) << endl;
        Root = new Node( );
        Add( 0 );
        int q;
        cin >> q;
        while( q-- ) {
                string s;
                int val;
                cin >> s >> val;
                if( s == "+" ) Add( val );
                if( s == "-" ) Remove( val );
                if( s == "?" ) cout << Query( val ) << endl;
        }
        return 0;
}















