#include <bits/stdc++.h>
using namespace std;

/**
this solves 1427 - Substring Frequency (II)
given a text & some patterns , it calculates number of
time each pattern occurs as a substrinhg in the text
*/

struct Node {
        int cnt;
        bool vis;
        Node *Next[ 27 ];
        vector <Node*> out;
        Node( ) {
                out.clear() , vis = false , cnt = 0;
                memset( Next , NULL , sizeof( Next ) );
        }
        ~Node( ) {
                for( int i = 1; i < 27; i++ ) {
                        if( Next[i] != NULL && Next[i] != this ) delete( Next[i] );
                }
        }
} *root;

const int N = 505;
const int MAXN = 1e6 + 5;

int n;
char text[ MAXN ];
char pattern[ N ][ N ];


int GetID( char ch ) {
        return ch - 'a' + 1;
}
void buildTrie( ) { /// pattern's , # of pattern
        root = new Node();
        for( int i = 1; i <= n; i++ ) {
                Node *cur = root;
                int len = strlen( pattern[i] );
                for( int j = 0; j < len; j++ ) {
                        int id = GetID( pattern[i][j] );
                        if( cur -> Next[id] == NULL ) cur -> Next[id] = new Node();
                        cur = cur -> Next[id];
                }
        }
}
void buildFail( ) {
        queue <Node*> Q;
        for( int i = 0; i <= 26; i++ ) {
                if( root -> Next[i] == NULL ) root -> Next[i] = root;
                else {
                        Q.push( root -> Next[i] );
                        root -> Next[i] -> Next[0] = root;
                }
        }
        while( !Q.empty() ) {
                Node *u = Q.front(); Q.pop();
                for( int i = 1; i <= 26; i++ ) {
                        if( u -> Next[i] != NULL ) {
                                Node *v = u -> Next[i];
                                Node *w = u -> Next[0];
                                while( !w -> Next[i] ) w = w -> Next[0];
                                v -> Next[0] = w = w -> Next[i];
                                w -> out.push_back( v );
                                Q.push( v );
                        }
                }
        }
}
void AhoCorasick( Node *cur , char *text ) {
        int len = strlen( text );
        for( int i = 0; i < len; i++ ) {
                int id = GetID( text[i] );
                while( !cur -> Next[id] ) cur = cur -> Next[0];
                cur = cur -> Next[id];
                cur -> cnt++;
        }
}
int dfs( Node *cur ) {
        if( cur -> vis ) return cur -> cnt;
        for( int i = 0; i < cur -> out.size(); i++ ) {
                cur -> cnt += dfs( cur -> out[i] );
        }
        cur -> vis = true;
        return cur -> cnt;
}
int main( int argc , char const *argv[] ) {
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
                scanf("%d",&n);
                scanf("%s",text);
                for( int i = 1; i <= n; i++ ) scanf("%s",pattern[i]);
                buildTrie( );
                buildFail( );
                AhoCorasick( root , text );
                printf("Case %d:\n",tc);
                for( int i = 1; i <= n; i++ ) {
                        Node *cur = root;
                        int len = strlen( pattern[i] );
                        for( int j = 0; j < len; j++ ) {
                                int id = GetID( pattern[i][j] );
                                cur = cur -> Next[id];
                        }
                        printf("%d\n",dfs( cur ) );
                }
                delete root;
        }
        return 0;
}










