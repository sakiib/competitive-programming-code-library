#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 1e5 + 5;

#define Check( N , p ) ( !( ( N & ( 1 << p ) ) == 0 ) )
#define ON( N , p ) ( N = N | ( 1 << p ) )
#define OFF( N , p ) ( N = N & ~( 1 << p ) )

int n , k;
int a[ N ];

struct Node {
        int cnt , endMark;
        Node *Child[ 2 ];
        Node( ) {
                cnt = 0 , endMark = 0 , Child[0] = Child[1] = NULL;
        }
} *root;

void Delete( Node* cur ) {
        for( int i = 0; i < 2; i++ ) {
                if( cur -> Child[i] ) Delete( cur -> Child[i] );
        }
        delete( cur );
}
void Insert( int val ) {
        Node *cur = root;
        for( int i = 20; i >= 0; i-- ) {
                int id = Check( val , i );
                if( cur -> Child[id] == NULL ) cur -> Child[id] = new Node();
                cur = cur -> Child[id];
                cur -> cnt++;
        }
        cur -> endMark ++;
}
LL GetAns( Node *cur , int xo , int pos , bool smaller ) {
        if( pos < 0 ) return smaller ? cur -> cnt : 0;
        int idx = Check( xo , pos ); // have
        int idk = Check( k , pos ); // need
        LL ret = 0;
        if( smaller )  return cur -> cnt; // already small , take everything
        else {
                if( idk == 0 ) {
                        if( cur -> Child[idx] != NULL ) {
                                ret += GetAns( cur -> Child[idx] , xo , pos - 1 , false );
                        }
                }
                else {
                        if( cur -> Child[idx^1] != NULL ) {
                                ret += GetAns( cur -> Child[idx^1] , xo , pos - 1 , false );
                        }
                        if( cur -> Child[idx] != NULL ) {
                               ret += GetAns( cur -> Child[idx] , xo , pos - 1 , true );
                        }
                }
        }
        return ret;
}
int main( int argc , char const *argv[] ) {
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
                scanf("%d %d",&n,&k);
                for( int i = 1; i <= n; i++ ) scanf("%d",&a[i]);
                int pref = 0;
                LL ans = 0;
                root = new Node( );
                Insert( 0 );
                for( int i = 1; i <= n; i++ ) {
                        pref ^= a[i];
                        ans += GetAns( root , pref , 20 , false );
                        Insert( pref );
                }
                printf("%lld\n",ans);
                Delete( root );
        }
        return 0;
}










