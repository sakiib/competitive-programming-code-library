#include <bits/stdc++.h>
using namespace std;

const int chr = 26;
char txt[ 1000005 ];
char pat[ 505 ];

int sz , ln;
int nxt[ 505*505 ][ chr ];
int fl[ 505*505 ] , fr[ 505*505 ];
int ed[ 505*505 ] , ls[ 505*505 ];
int Q[ 505*505 ];

void node( ) {
        fl[sz] = 0;
        fr[sz] = 0;
        for( int i = 0; i < chr; i++ ) nxt[sz][i] = -1;
}
void init( ) {
        sz = 0;
        node();
        sz++;
}
int getid( char ch ) {
        if( ch >= 'a' && ch <= 'z' ) return ch-'a';
        else if( ch >= 'A' && ch <= 'Z' ) return 26+(ch-'A');
        else return 52+(ch-'0');
}
void add( int id ) {
        int cr = 0;
        for( int i = 0; pat[i]; i++ ) {
                int id = getid( pat[i] );
                if( nxt[cr][id] == -1 ) {
                        node() , nxt[cr][id] = sz++;
                }
                cr = nxt[cr][id];
        }
        ed[id] = cr;
}
void reverse_link( ) {
        int l = 0 , r = 0 , u = 0 , v;
        for( int i = 0; i < chr; i++ ) {
                if( nxt[u][i] == -1 ) nxt[u][i] = 0;
                else Q[r++] = nxt[u][i];
        }
        ln = 0;
        while( l < r ) {
                u = Q[l++];
                for( int i = 0; i < chr; i++ ) {
                        v = nxt[u][i];
                        if( v == -1 ) {
                                nxt[u][i] = nxt[fl[u]][i];
                                continue;
                        }
                        Q[r++] = v;
                        fl[v] = nxt[fl[u]][i];
                        ls[ln++] = v;
                }
        }
}
void calc( ) {
        int cr = 0;
        for( int i = 0; txt[i]; i++ ) {
                int id = getid( txt[i] );
                cr = nxt[cr][id];
                fr[cr]++;
        }
        for( int i = ln - 1; i >= 0; i-- ) {
                fr[ fl[ls[i]] ] += fr[ ls[i] ];
        }
}
int main( ) {
        #ifdef OFFLINE
            freopen( "input.txt" , "r" , stdin );
        #endif // OFFLINE
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
                init();
                int q;
                scanf("%d",&q);
                scanf("%s",txt);
                for( int i = 1; i <= q; i++ ) {
                        scanf("%s",pat);
                        add( i );
                }
                reverse_link();
                calc();
                printf("Case %d:\n",tc);
                for( int i = 1; i <= q; i++ ) {
                        printf("%d\n",fr[ed[i]]);
                }
        }
        return 0;
}


