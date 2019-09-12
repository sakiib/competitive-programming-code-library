#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(V) V.begin(), V.end()
#define Unique(V) sort(all(V)), V.erase(unique(all(V)), V.end())
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long int LL;
const int N = 1e5 + 5;

const int chr = 62;
char txt[ 100005 ];
char pat[ 2005 ];

/**
code taken from : shahed shohel
count occurences of each pattern in string
*/
int sz , ln;
int nxt[ 2001*1001 ][ 65 ];
int fl[ 2001*1001 ] , fr[ 2001*1001 ] , ed[ 2001*1001 ] , ls[ 2001*1001 ];
int Q[ 2001*1001 ];

void init( ) {
        fl[sz] = 0;
        fr[sz] = 0;
        for( int i = 0; i < chr; i++ ) nxt[sz][i] = -1;
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
                if( nxt[cr][id] == -1 ) init() , nxt[cr][id] = sz++;
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
        scanf("%s",txt);
        int q;
        scanf("%d",&q);
        sz = 0;
        init();
        sz++;
        for( int i = 1; i <= q; i++ ) {
                scanf("%s",pat);
                add( i );
        }
        reverse_link( );
        calc( );
        for( int i = 1; i <= q; i++ ) {
                if( fr[ed[i]] > 0 ) puts("Y");
                else puts("N");
        }
        return 0;
}






