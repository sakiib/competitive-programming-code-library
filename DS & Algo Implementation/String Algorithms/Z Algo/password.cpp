#include <bits/stdc++.h>
using namespace std;

struct BINARY_INDEXED_TREE {
        static const int MAXN = 1e6 + 5;
        int BIT[ MAXN + 5 ];
        inline void Initialize( ) {
                memset( BIT , 0 , sizeof( BIT ) );
        }
        inline int RQuery ( int l , int r ) {
                return PQuery( r ) - PQuery( l - 1 );
        }
        inline void PUpdate ( int idx , int v ) {
                if( idx <= 0 ) return;
                for( ;idx <= MAXN; idx += ( idx & -idx ) ) BIT[ idx ] += v;
        }
        inline int PQuery ( int idx ) {
                int ret = 0;
                for( ;idx > 0; idx -= ( idx & -idx ) ) ret += BIT[ idx ];
                return ret;
        }
        inline void RUpdate ( int idx , int idy , int v ) {
                for( ;idx <= MAXN; idx += ( idx & -idx ) ) BIT[ idx ] += v;
                idy++ , v *= -1;
                for( ;idy <= MAXN; idy += ( idy & -idy ) ) BIT[ idy ] += v;
        }
} bit;

// z[i] = the length of the longest common prefix between s and the suffix of s starting at i.
// z[i] = longest substring starting at i'th position which is also a prefix prefix of the string

vector <int> z_function( string &s ) {
        int n = (int)s.size( );
        vector<int> z( n );
        for( int i = 1 , l = 0 , r = 0; i < n; i++ ) {
                if( i <= r ) z[i] = min( r - i + 1 , z[i-l] );
                while( i + z[i] < n && s[z[i]] == s[i+z[i]] ) z[i]++;
                if( i + z[i] - 1 > r ) l = i , r = i + z[i] - 1;
        }
        return z;
}
int main( int argc , char const *argv[] ) {
        string s;
        cin >> s;
        vector <int> z = z_function( s );
        //for( int i = 0; i < z.size(); i++ ) cout << z[i] << " "; cout << endl;
        for( int i = 1; i < s.size(); i++ ) bit.PUpdate( z[i] , +1 );
        int len = -1;
        for( int i = s.size()-1; i > 0; i-- ) {
                if( z[i] != (s.size() - i) ) continue;
                int cnt = bit.RQuery( z[i] , s.size() );
                if( cnt >= 2 ) len = max( len , z[i] );
                bit.PUpdate( z[i] , -1 );
        }
        if( len == -1 ) cout << "Just a legend" << endl;
        else cout << s.substr( 0 , len ) << endl;
        return 0;
}













