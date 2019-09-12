#include <bits/stdc++.h>
using namespace std;

/**
    Suffix array implementation using bucket sorting + lcp.
    Complexity O(n log n), text is the target string.
    1. Fill text with the input string.
    2. Assign len = length of text.
    3. Call suffixSort()
    4. Result is at 2 different arrays: suffix[i] contains index of i'th sorted string
       and sufRank[stp][i] contains rank of i'th suffix.
**/

const int N = 1e5 + 5;
const int LOGN = 25;

int suffix[ N ] , temp[ N ];
int sum[ N ] , cnt[ N ] , suffRank[ LOGN ][ N ];
string text;
int len , stp , mv;

bool suffixCMP( const int &a , const int &b ) {
        return text[ a ] != text[ b ] ? text[ a ] < text[ b ] : false;
}
bool Equal( const int &u , const int &v ) {
        if( !stp ) return text[ u ] == text[ v ];
        if( suffRank[ stp-1 ][ u ] != suffRank[ stp-1 ][ v ] ) return false;
        int a = u + mv < len ? suffRank[ stp-1 ][ u+mv ] : -1;
        int b = v + mv < len ? suffRank[ stp-1 ][ v+mv ] : -1;
        return a == b;
}
void Update( ) {
        int rnk = 0;
        for( int i = 0; i <= len - 1; i++ ) sum[ i ] = 0;
        for( int i = 0; i <= len - 1; i++ ) {
                suffix[ i ] = temp[ i ];
                if( i && !Equal( suffix[ i ] , suffix[ i-1 ] ) ) {
                        suffRank[ stp ][ suffix[i] ] = ++rnk;
                        sum[ rnk+1 ] = sum[ rnk ];
                }
                else suffRank[ stp ][ suffix[i] ] = rnk;
                sum[ rnk+1 ]++;
        }
}
void BucketSort( ) {
        for( int i = 0; i <= len - 1; i++ ) cnt[i] = 0;
        memset( temp , -1 , sizeof( temp ) );
        for( int i = 0; i <= mv - 1; i++ ) {
                int idx = suffRank[ stp - 1 ][ len - i - 1 ] , x = sum[ idx ];
                temp[ x+cnt[idx] ] = len - i - 1 , cnt[ idx ]++;
        }
        for( int i = 0; i <= len - 1; i++ ) {
            int idx = suffix[ i ] - mv; if( idx < 0 )continue;
            idx = suffRank[ stp-1 ][ idx ];
            int x = sum[ idx ];
            temp[ x + cnt[idx] ] = suffix[i] - mv , cnt[ idx ]++;
        }
        Update( );
}
void SuffixSort( ) {
        for( int i = 0; i <= len - 1; i++ ) temp[i] = i;
        sort( temp , temp + len , suffixCMP );
        stp = 0 , Update( ) , ++stp;
        for( mv = 1; mv < len; mv <<= 1) BucketSort( ) , stp++;
        stp--;
        for( int i = 0; i <= stp; i++ ) suffRank[ i ][ len ] = -1;
}
int LCP( int u , int v ) {
        if( u == v ) return len - u;
        int ret = 0;
        for( int i = stp; i >= 0; i-- ) {
                if( suffRank[ i ][ u ] == suffRank[ i ][ v ] ) {
                        ret += ( 1 << i ) , u += ( 1 << i ) , v += ( 1 << i );
                }
        }
        return ret;
}
int main( int argc , char const *argv[] ) {
        text = "banana"; /// 5 , 3 , 1 , 0 , 4 , 2
        len = text.size( );
        SuffixSort( );
        for( int i = 0; i < len; i++ ) cout << suffix[i] << " "; cout << "\n";
        cout << LCP( 0 , 5 ) << endl;
        return 0;
}

/**

Index       Suffix          Rank        Next Rank
  5          a               0             -1
  3          ana             1              0
  1          anana           1              1
  0          banana          2              3
  4          na              3             -1
  2          nana            3              3

*/













