#include <bits/stdc++.h>
using namespace std;

#define Set( N , p )           N=((N)((1LL)<<(p)))
#define Reset( N , p )         N=((N)&(~((1LL)<<(p))))
#define Check( N , p )         (!(((N)&((1LL)<<(p)))==(0)))

const int N = 15*( 2e5 + 5 );

struct node {
        int cnt;
        int next[ 2 ];
        node( ) {
                cnt = 0;
                memset( next , -1 , sizeof( next ) );
        }
} tree[ N ];

int root , sz;
bool ed[ N ];

inline void init( ) {
        root = 0;
        sz = 0;
        tree[root] = node();
}
inline void add( int num ) {
        int cur = root;
        for( int i = 30; i >= 0; i-- ) {
                int id = Check( num , i );
                if( tree[cur].next[id] == -1 ) {
                        tree[cur].next[id] = ++sz;
                        tree[sz] = node();
                }
                cur = tree[cur].next[id];
                tree[cur].cnt++;
        }
        ed[cur] = true;
}
inline bool has( int num ) {
        int cur = root;
        for( int i = 30; i >= 0; i-- ) {
                int id = Check( num , i );
                if( tree[cur].next[id] == -1 ) return false;
                cur = tree[cur].next[id];
        }
        return ed[cur];
}
inline void rem( int num ) {
        int cur = root;
        for( int i = 30; i >= 0; i-- ) {
                int id = Check( num , i );
                cur = tree[cur].next[id];
                tree[cur].cnt--;
        }
        if( tree[cur].cnt == 0 ) ed[cur] = false;
}
int getans( int num ) {
        int mx = 0;
        int cur = root;
        for( int i = 30; i >= 0; i-- ) {
                int id = Check( num , i );
                if( tree[cur].next[1^id] != -1 && tree[ tree[cur].next[1^id] ].cnt > 0 ) {
                        mx |= ( 1 << i );
                        cur = tree[cur].next[1^id];
                }
                else if( tree[cur].next[id] != -1 ) {
                        cur = tree[cur].next[id];
                }
        }
        return mx;
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie(0);
        //freopen( "input.txt" , "r" , stdin );
        init();
        add( 0 );
        int q;
        cin >> q;
        while( q-- ) {
                string s;
                int num;
                cin >> s >> num;
                if( s[0] == '+' ) add( num );
                else if( s[0] == '-' ) rem( num );
                else cout << getans( num ) << endl;
        }
        return 0;
}









