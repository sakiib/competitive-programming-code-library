#include <bits/stdc++.h>
using namespace std;

struct Node {
        bool endMark;
        int cnt;
        Node *Next[ 4 ];
        Node( ) {
                endMark = false;
                cnt = 0;
                for( int i = 0; i < 4; i++ ) Next[i]= NULL;
        }
        ~Node( ) {
                for( int i = 0; i < 4; i++ ) {
                        if( Next[i] != NULL && Next[i] != this ) delete( Next[i] );
                }
        }
} *root;

char s[ 55 ];
int mx;

int GetID( char ch ) {
        if( ch == 'A' ) return 0;
        if( ch == 'C' ) return 1;
        if( ch == 'T' ) return 2;
        if( ch == 'G' ) return 3;
}
void Insert( char *s ) {
        int len = strlen( s );
        Node *cur = root;
        for( int i = 0; i < len; i++ ) {
                int id = GetID( s[i] );
                if( cur -> Next[id] == NULL ) cur -> Next[id] = new Node( );
                cur = cur -> Next[id];
                cur -> cnt++;
        }
        cur -> endMark = true;
}
int GetAns( Node *cur , int depth ) {
        int mx = 0;
        mx = max( mx , depth * cur -> cnt );
        for( int i = 0; i < 4; i++ ){
               if( cur -> Next[i] != NULL ) {
                        mx = max( mx , GetAns( cur -> Next[i] , depth + 1 ) );
               }
        }
        return mx;
}
int main( int argc , char const *argv[] ) {
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
                root = new Node( );
                int n;
                scanf("%d",&n);
                for( int i = 1; i <= n; i++ ) {
                        scanf("%s",s);
                        Insert( s );
                }
                printf("Case %d: %d\n",tc,GetAns( root , 0 ));
                delete ( root );
        }
        return 0;
}







