#include <bits/stdc++.h>
using namespace std;

/**
this one solves lightoj 1427
given some patterns & a txt , calculates # of times each pat occurs in txt
*/

struct aho_corasick {
        struct node {
                int next[ 27 ];
                node( ) { memset( next , -1 , sizeof( next ) ); }
        };

        static const int N = 500 * 500 + 50; /// total length of patterns
        int sz , len , root;
        node tree[ N ];
        int suffix[ N ] , path[ N ] , ff[ N ] , ed[ N ];

        void initialize( ) {
                root = sz = len = 0;
                tree[root] = node( );
                for( int i = 0; i < N; i++ ) suffix[i] = ff[i] = 0;
        }
        void add( char *s , int idx ) {
                int cur = root , l = strlen( s );
                for( int i = 0; i < l; i++ ) {
                        int id = s[i] - 'a';
                        if( tree[cur].next[id] == -1 ) {
                                tree[cur].next[id] = ++sz; tree[sz] = node( );
                        }
                        cur = tree[cur].next[id];
                }
                ed[idx] = cur;
        }
        void reverse_link( ) {
                queue <int> Q;
                for( int i = 0; i < 26; i++ ) {
                        if( ~tree[root].next[i] ) Q.push( tree[root].next[i] );
                        else tree[root].next[i] = root;
                }
                while( !Q.empty() ) {
                        int u = Q.front(); Q.pop();
                        for( int i = 0; i < 26; i++ ) {
                                int v = tree[u].next[i];
                                if( v == -1 ) {
                                        tree[u].next[i] = tree[suffix[u]].next[i];
                                        continue;
                                }
                                suffix[v] = tree[ suffix[u] ].next[i];
                                Q.push( v );
                                path[len++] = v;
                        }
                }
        }
        void calc( char *s ) {
                int cur = root , l = strlen( s );
                for( int i = 0; i < l; i++ ) {
                        int id = s[i] - 'a';
                        cur = tree[cur].next[id];
                        ff[cur]++;
                }
                for( int i = len - 1; i >= 0; i-- ) {
                        ff[ suffix[ path[i] ] ] += ff[ path[i] ];
                }
        }
} aho;

char txt[ 1000005 ] , pat[ 505 ];

int main( ) {
        //freopen( "input.txt" , "r" , stdin );
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
                aho.initialize();
                int q;
                scanf("%d",&q);
                scanf("%s",txt);
                for( int i = 1; i <= q; i++ ) {
                        scanf("%s",pat);
                        aho.add( pat , i );
                }
                aho.reverse_link();
                aho.calc( txt );
                printf("Case %d:\n",tc);
                for( int i = 1; i <= q; i++ ) printf("%d\n",aho.ff[ aho.ed[i] ]);
        }
        return 0;
}






