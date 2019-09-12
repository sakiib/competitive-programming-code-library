#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n;

char s[ N ];
char T[ N ];

int c[ N ] , RA[ N ] , tRA[ N ] , SA[ N ] , tSA[ N ];
int Pre[ N ] , PLCP[ N ] , LCP[ N ];

inline void countingSort( int k ) {
        memset( c , 0 , sizeof( c ) );
        for( int i = 0; i < n; i++ ) c[ i+k < n ? RA[ i+k ] : 0 ]++;
        for( int i = 0 , sum = 0 , t; i < max( n , 250 ); i++ ) {
                t = c[i]; c[i] = sum; sum += t;
        }
        for( int i = 0; i < n; i++ ) {
                tSA[ c[ SA[i]+k < n ? RA[ SA[i]+k ] : 0 ]++ ] = SA[i];
        }
        for( int i = 0; i < n; i++ ) SA[i] = tSA[i];
}
inline void buildSA( ) {
        for( int i = 0; i < n; i++ ) SA[i] = i , RA[i] = T[i];
        for( int k = 1 , r; k < n; k <<= 1 ) {
                countingSort( k );
                countingSort( 0 );
                tRA[ SA[0] ] = r = 0;
                for(int i = 1; i < n; i++ )
                tRA[SA[i]] = ( RA[SA[i]] == RA[SA[i-1]] && RA[SA[i]+k] == RA[SA[i-1]+k] )? r : ++r;
                for( int i = 0; i < n; i++ ) RA[i] = tRA[i];
                if( RA[ SA[n-1] ] == n - 1 ) break;
        }
}
inline void buildLCP( ) {
        Pre[ SA[0] ] = -1;
        for( int i = 1; i < n; i++ ) Pre[ SA[i] ] = SA[i-1];
        for( int i = 0 , L = 0; i < n; i++ ) {
                if( Pre[i] == -1 ) { Pre[i] = 0; continue; }
                while( T[i+L] == T[ Pre[i]+L ] ) L++;
                PLCP[i] = L;
                L = max( 0 , L - 1 );
        }
        for( int i = 0; i < n; i++ ) LCP[i] = PLCP[ SA[i] ];
}
inline void init( char *t  ) {
        n = strlen( t );
        for( int i = 0; i < n; i++ ) T[i] = t[i]; T[n++] = '#';
}
inline void Print( ) {
        for( int i = 0; i < n; i++ ) printf("%2d \t %s\n",SA[i],T+SA[i]);
        printf("\n----------------------\n\n");
        for( int i = 0; i < n; i++ ) printf("%2d \t %d\n",SA[i],LCP[i]);
}
int main( int argc , char const *argv[] ) {
        scanf("%s",s);
        init( s );
        buildSA( );
        buildLCP( );
        Print( );
        return 0;
}


/**

Suffix array with LCP
runtime : NlgN

we can avoid 0 , it contains #

Index       Suffix        LCP
  5          a            0
  3          ana          1
  1          anana        3
  0          banana       0
  4          na           0
  2          nana         2

*/










