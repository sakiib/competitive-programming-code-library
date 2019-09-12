#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

inline int add( int x , int y , int mod ) {
    return x + y >= mod ? x + y - mod : x + y;
}
inline int sub( int x , int y , int mod ) {
    return x - y < 0 ? x - y + mod : x - y;
}
inline int mul( int x , int y , int mod ) {
    return ( 1LL * x * y ) % mod;
}
struct hashing {
    const int N = 1000005;
    const int mod[2] = { 1000000007, 1000000009 };
    const int base[2] = { 43 , 37 };
    const int invbase[2] = { 395348840 , 297297300 };
    vector < vector <int> > p;
    vector < vector <int> > invmod;
    vector < vector <int> > fh;
    vector < vector <int> > bh; int tlen;
    inline void gen_pow( int sz ) {
        p.resize( sz + 2 );
        invmod.resize( sz + 2 );
        for( int i = 0; i <= sz; i++ ) p[i].resize( 2 ), invmod[i].resize( 2 );
        p[0][0] = 1 , p[0][1] = 1 , invmod[0][0] = 1 , invmod[0][1] = 1;
        for( int i = 1; i <= sz; i++ ) {
            for( int id = 0; id <= 1; id++ ) {
                p[i][id] = mul( p[i-1][id] , base[id] , mod[id] );
                invmod[i][id] = mul( invmod[i-1][id] , invbase[id] , mod[id] );
            }
        }
    }
    inline void build_hash( string &txt ) {
        tlen = txt.size();
        fh.resize( tlen + 2 );
        bh.resize( tlen + 2 );
        for( int i = 0; i <= tlen; i++ ) fh[i].resize( 2 ), bh[i].resize( 2 );
        for( int i = 0 , j = tlen - 1; i < tlen; i++ , j-- ) {
            for( int id = 0; id <= 1; id++ ) {
                fh[i][id] = mul( p[i][id] , txt[i] , mod[id] );
                if( i ) fh[i][id] = add( fh[i][id] , fh[i-1][id] , mod[id] );
                bh[i][id] = mul( p[j][id] , txt[i] , mod[id] );
                if( i ) bh[i][id] = add( bh[i][id] , bh[i-1][id] , mod[id] );
            }
        }
    }
    inline LL combine_hash( LL x , LL y ) { return ( x << 31 ) | y; }
    inline LL fhash( string &s ) {
        int l = s.size() , x = 0 , y = 0;
        for( int i = 0; i < l; i++ ) {
            x = add( x , mul( p[i][0] , s[i] , mod[0] ) , mod[0] );
            y = add( y , mul( p[i][1] , s[i] , mod[1] ) , mod[1] );
        } return combine_hash( x , y );
    }
    inline LL bhash( string &s ) {
        int l = s.size() , x = 0 , y = 0;
        for( int i = l - 1 , j = 0; i >= 0; i-- , j++ ) {
            x = add( x , mul( p[j][0] , s[i] , mod[0] ) , mod[0] );
            y = add( y , mul( p[j][1] , s[i] , mod[1] ) , mod[1] );
        } return combine_hash( x , y );
    }
    inline LL get_fhash( int l , int r ) {
        if( l == 0 ) return combine_hash( fh[r][0] , fh[r][1] );
        int x = sub( fh[r][0], fh[l-1][0], mod[0] );
        x = mul( x, invmod[l][0], mod[0] );
        int y = sub( fh[r][1], fh[l-1][1], mod[1] );
        y = mul( y, invmod[l][1], mod[1] ); return combine_hash( x , y );
    }
    inline LL get_bhash( int l , int r ) {
        if( l == 0 ) {
            int x = bh[r][0]; x = mul( x, invmod[tlen-r-1][0], mod[0] );
            int y = bh[r][1]; y = mul( y, invmod[tlen-r-1][1], mod[1] );
            return combine_hash( x , y );
        }
        int x = sub( bh[r][0], bh[l-1][0], mod[0] );x = mul( x, invmod[tlen-r-1][0], mod[0] );
        int y = sub( bh[r][1], bh[l-1][1], mod[1] );y = mul( y, invmod[tlen-r-1][1], mod[1] );
        return combine_hash( x , y );
    }
} h;

int main( ) {
        h.gen_pow( 1000006 );
        for( int i = 1; i <= 1000; i++ ) {
            string s = "";
            for( int j = 0; j < 1000; j++ ) s += ( i%26 + 'a' );
            h.build_hash( s );
        }
        return 0;
}









