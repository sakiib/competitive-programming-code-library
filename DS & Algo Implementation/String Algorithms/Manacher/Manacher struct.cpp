#include <bits/stdc++.h>
using namespace std;

struct MANACHER {
        static const int MAXN = 1e5 + 5;
        string s;
        int mx_pal_len , pal_cen_idx;
        int P[ MAXN ];

        inline void Initilize( string str ) {
                s = str;
                mx_pal_len = 0 , pal_cen_idx = 0;
                memset( P , 0 , sizeof( P ) );
        }
        inline string Convert( string s ) {
                char ret[ 2*MAXN + 5 ];
                int id = 0 , len = s.size();
                ret[ id++ ] = '@';
                for( int i = 0; i < len; i++ ) ret[ id++ ] = '#', ret[ id++ ] = s[i];
                ret[ id++ ] = '#' , ret[ id++ ] = '$' , ret[ id ] = '\0';
                string cur = ret;
                return cur;
        }
        inline void Manacher( ) {
                memset( P , 0 , sizeof( P ) );
                string Q = Convert( s );
                int c = 0 , r = 0;
                for( int i = 1; i < Q.size() - 1; i++ ) {
                        int imir = c - ( i - c );
                        if( r > i ) P[i] = min( r - i , P[ imir ] );
                        while( Q[ i + 1 + P[i] ] == Q[ i - 1 - P[i] ] ) P[i]++;
                        if( i + P[i] > r ) c = i , r = i + P[i];
                }
                for( int i = 1; i < Q.size() - 1; i++ ) {
                        if( P[i] > mx_pal_len ) mx_pal_len = P[i] , pal_cen_idx = i;
                }
        }
} manacher;

int main( int argc , char const *argv[] ) {

        return 0;
}






