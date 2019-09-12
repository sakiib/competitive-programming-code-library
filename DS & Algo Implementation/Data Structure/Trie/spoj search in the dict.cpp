#include <bits/stdc++.h>
using namespace std;

int n , q;
char s[ 25 ];

struct Node {
        bool endMark;
        int cnt;
        Node *Next[ 27 ];
        Node( ) {
                endMark = false , cnt = 0;
                for( int i = 1; i <= 26; i++ ) Next[i] = NULL;
        }
} *root;

void Insert( char *s ) {
        Node *cur = root;
        int len = strlen( s );
        for( int i = 0; i < len; i++ ) {
                int id = s[i] - 'a' + 1;
                if( cur -> Next[id] == NULL ) {
                        cur -> Next[id] = new Node( );
                }
                cur = cur -> Next[id];
                cur -> cnt++;
        }
        cur -> endMark = true;
}
Node* Find( char *s ) {
        Node *cur = root;
        int len = strlen( s );
        for( int i = 0; i < len; i++ ) {
                int id = s[i] - 'a' + 1;
                if( cur -> Next[id] == NULL ) return NULL;
                cur = cur -> Next[id];
        }
        return cur;
}
void Print( Node *cur , vector <char> V , char *s ) {
        if( cur -> endMark && (int)V.size() > 0 ) {
                printf("%s",s);
                for( auto x : V ) printf("%c",x);
                printf("\n");
        }
        for( int i = 1; i <= 26; i++ ) {
                if( cur -> Next[i] != NULL ) {
                        V.push_back( (char)( i + 'a' - 1 ) );
                        Print( cur -> Next[i] , V , s );
                        V.pop_back( );
                }
        }
}
int main( int argc , char const *argv[] ) {
        root = new Node( );
        scanf("%d",&n);
        for( int i = 1; i <= n; i++ ) {
                scanf("%s",s);
                Insert( s );
        }
        scanf("%d",&q);
        for( int tc = 1; tc <= q; tc++ ) {
                printf("Case #%d:\n",tc);
                scanf("%s",s);
                Node *cur = Find( s );
                vector <char> V;
                if( cur == NULL ) printf("No match.\n");
                else Print( cur , V , s );
        }
        return 0;
}















