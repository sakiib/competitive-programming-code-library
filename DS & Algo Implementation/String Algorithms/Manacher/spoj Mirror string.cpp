#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
typedef pair < int , int > ii;
const int inf = 1e9;
const LL INF = 1e18;
const int N = 1e5 + 5;
const int mod = 1000000007;
const double eps = 1e-8;
const double pi = acos( -1.0 );

const int sz = 3005; /// max string len
int P[ 2*sz + 5 ]; /// must be atleast 2 times of string s.

string Convert( string s ) {
        string ret = "@";
        for( int i = 0; i < s.size(); i++ ) ret += "#" + s.substr( i , 1 );
        ret += "#$";
        return ret;
}
string convert( string s ) { /// works faster than the above one.
        char ret[ 2*sz + 5 ];
        int id = 0 , len = s.size();
        ret[ id++ ] = '@';
        for( int i = 0; i < len; i++ ) ret[ id++ ] = '#', ret[ id++ ] = s[i];
        ret[ id++ ] = '#' , ret[ id++ ] = '$' , ret[ id ] = '\0';
        string cur = ret;
        return cur;
}
void Manacher( string s ) {
        memset( P , 0 , sizeof( P ) );
        string Q = convert( s );
        int c = 0 , r = 0;
        for( int i = 1; i < Q.size() - 1; i++ ) {
                int imir = c - ( i - c );
                if( r > i ) P[i] = min( r - i , P[ imir ] );
                while( Q[ i + 1 + P[i] ] == Q[ i - 1 - P[i] ] ) P[i]++;
                if( i + P[i] > r ) c = i , r = i + P[i];
        }
        int mx_pal = 0 , cen_idx = 0;
        map <int,int> cnt;
        int mx = 0;
        for( int i = 1; i < Q.size() - 1; i++ ) {
                if( P[i] == 0 ) continue;
                cnt[ P[i] ]++;
                mx = max( mx , P[i] );
        }
        cout << mx << " " << cnt[ mx ] << endl;
}
int main( int argc , char const *argv[] ) {
        ios_base :: sync_with_stdio(false); cin.tie(NULL);
        int t;
        cin >> t;
        while( t-- ) {
                string s;
                cin >>s;
                Manacher( s );
        }
        return 0;
}




