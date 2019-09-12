#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
typedef long long LL;

const int mod[ 2 ] = { 1000000007 , 1000000009 };
const int base[ 2 ] = { 31 , 37 };
char s[ N ];
LL p[ N ][ 2 ];

void genPower( ) {
        p[0][0] = p[0][1] = 1;
        for(int i = 1; i < N; i++ ) {
                p[i][0] = ( p[i-1][0] * base[0] ) % mod[0];
                p[i][1] = ( p[i-1][1] * base[1] ) % mod[1];
        }
}
int solve( ) {
        int len = strlen( s );
        LL fhash1 = 0 , fhash2 = 0 , bhash1 = 0 , bhash2 = 0;
        int pos = 0;
        for( int i = len - 1; i >= 0; i-- ) {
                fhash1 = ( fhash1 * base[0] + s[i] ) % mod[0];
                fhash2 = ( fhash2 * base[1] + s[i] ) % mod[1];
                bhash1 = ( bhash1 + p[len-1-i][0] * s[i] ) % mod[0];
                bhash2 = ( bhash2 + p[len-1-i][1] * s[i] ) % mod[1];
                pair <LL,LL> a = { fhash1 , fhash2 } , b = { bhash1 , bhash2 };
                if( a == b ) pos = i;
        }
        return pos - 1;
}
int main( int argc , char const *argv[] ) {
        genPower( );
        while( scanf("%s",s) != EOF ){
                int idx = solve( );
                printf("%s",s);
                for( int i = idx; i >= 0; i-- ) printf("%c",s[i]);
                printf("\n");
        }
        return 0;
}
















