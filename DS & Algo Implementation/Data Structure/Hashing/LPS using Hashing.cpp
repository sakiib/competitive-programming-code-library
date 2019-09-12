#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef pair <int,int> pii;
typedef pair <long long,long long> pll;
const int MOD = 1e9 + 7;
const double EPS = 1e-8;
const int N = 1e5 + 5;
const int inf = 1e9;
const long long INF = 1e18;

const int base[] = { 43 , 47 };
const int mod[] = { 1000000007 , 1000000009 };

int cnt[ 5*N ];
int p[ 5*N ][ 2 ];

void add( int &x , int y , int mod ) {
        x += y;
        if( x >= mod ) x -= mod;
}
void sub( int &x , int y , int mod ) {
        x -= y;
        if( x < 0 ) x += mod;
}
int mul( int x , int y , int mod ) {
        return ( 1LL * x * y ) % mod;
}
int fall_back( string &s ) {
        p[0][0] = 1 , p[0][1] = 1;
        for( int i = 1; i < 5 * N; i++ ) {
                p[i][0] = mul( p[i-1][0] , base[0] , mod[0] );
                p[i][1] = mul( p[i-1][1] , base[1] , mod[1] );
        }
        int hash1 = 0 , hash2 = 0 , hash3 = 0 , hash4 = 0;
        int f = -1;
        for( int i = 0 , j = s.size() - 1; i < s.size() - 1; i++ , j-- ) {
                add( hash1 , mul( p[i][0] , s[i] , mod[0] ) , mod[0] );
                add( hash2 , mul( p[i][1] , s[i] , mod[1] ) , mod[1] );
                hash3 = mul( hash3 , p[1][0] , mod[0] );
                add( hash3 , s[j] , mod[0] );
                hash4 = mul( hash4 , p[1][1] , mod[1] );
                add( hash4 , s[j] , mod[1] );
                LL ff = ( 1LL * hash1 << 31 ) | hash2 , bb = ( 1LL * hash3 << 31 ) | hash4;
                if( ff == bb ) f = i;
        }
        return f + 1;
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( nullptr );
        string a , b;
        cin >> a >> b;
        if( a.size( ) < b.size( ) ) return cout << a << endl,0;
        for( int i = 0; i < a.size(); i++ ) cnt[ a[i]-'0' ]++;
        int l = b.size( );
        vector <int> ans;
        int j = 0;
        int f = fall_back( b );
        while( cnt[1] || cnt[0] ) {
                if( cnt[ b[j]-'0' ] > 0 ) {
                        ans.push_back( b[j]-'0' ) , cnt[ b[j] - '0' ]-- , j++;
                        if( j == b.size() ) j = f;
                }
                else break;
        }
        while( cnt[1]-- ) ans.push_back( 1 );
        while( cnt[0]-- ) ans.push_back( 0 );
        for( auto x : ans ) cout << x;
        return 0;
}













