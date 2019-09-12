#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 1e5 + 5;
const int mx = 32;
#define   Check( N , p )   ( !( ( N & ( 1LL << p ) ) == 0 ) )
#define   ON( N , p )      ( N = N | ( 1LL << p ) )
#define   OFF( N , p )     ( N = N & ~( 1LL << p ) )
LL a[ N ];

/**
 xor( L - R ) = xor( ( 1 - R ) , ( 1 - (L-1) ) )
 */
struct Node {
        bool endMark;
        int cnt;
        Node *Child[ 2 ];
        Node( ) {
                endMark = false , cnt = 0;
                Child[0] = Child[1] = NULL;
        }
} *root;

void Delete( Node* cur ) {
        for( int i = 0; i < 2; i++ ) {
                if( cur -> Child[i] ) Delete( cur -> Child[i] );
        }
        delete( cur );
}
void Insert( LL num ) {
        Node *cur = root;
        for( int i = mx; i >= 0; i-- ) {
                int id = Check( num , i );
                if( cur -> Child[id] == NULL ) cur -> Child[id] = new Node();
                cur = cur -> Child[id];
                cur -> cnt++;
        }
}
LL GetAns( LL num ) {
        Node *cur = root;
        LL ans = 0;
        for( int i = mx; i >= 0; i-- ) {
                int id = Check( num , i );
                if( cur -> Child[id^1] != NULL && cur -> Child[id^1] -> cnt > 0 ) {
                        cur = cur -> Child[id^1];
                        ON( ans , i );
                }
                else if( cur -> Child[id] != NULL && cur -> Child[id] -> cnt > 0 ) {
                        cur = cur -> Child[id];
                }
        }
        return ans;
}
int main( int argc , char const *argv[] ) {
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
                root = new Node( );
                int n;
                scanf("%d",&n);
                for( int i = 1; i <= n; i++ ) scanf("%lld",&a[i]);
                LL pref = 0 , ans = 0;
                Insert( 0 );
                for( int i = 1; i <= n; i++ ) {
                        pref ^= a[i];
                        Insert( pref );
                        ans = max( ans , GetAns( pref ) );
                }
                printf("%lld\n",ans);
                Delete( root );
        }
        return 0;
}















