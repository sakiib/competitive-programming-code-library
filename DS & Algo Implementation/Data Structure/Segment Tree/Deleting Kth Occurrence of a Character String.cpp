#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n , q , k , len;
string str , s = " ";
int tree[ 4*N ][ 30 ];

void build( int node , int b , int e ) {
        if( b > e ) return;
        if( b == e ) {
                tree[ node ][ s[b]-'a'+1 ]++;
                return;
        }
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        build( l , b , m );
        build( r , m + 1 , e );
        for( int i = 1; i <= 26; i++ ) tree[node][i] = tree[l][i] + tree[r][i];
}
int query( int node , int b , int e , int k , int id ) {
        if( b > e ) return 0;
        if( b == e ) return b;
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        if( k <= tree[l][id] ) return query( l , b , m , k , id );
        else return query( r , m+1 , e , k - tree[l][id] , id );
}
void update( int node , int b , int e , int pos , int id ) {
        if( b > e || pos > e || pos < b ) return;
        if( b == e && b == pos ) {
                tree[ node ][ id ]--;
                s[pos] = 'X';
                return;
        }
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        update( l , b , m , pos , id );
        update( r , m + 1 , e , pos , id );
        for( int i = 1; i <= 26; i++ ) tree[node][i] = tree[l][i] + tree[r][i];
}
int main( int argc , char const *argv[] ) {
        ios_base :: sync_with_stdio(0); cin.tie(NULL);
        cin >> n >> str;
        for( int i = 1; i <= n; i++ ) s += str;
        len = s.size();
        build( 1 , 1 , len-1 );
        cin >> q;
        while( q-- ) {
                cin >> k >> str;
                int pos = query( 1 , 1 , len-1 , k , str[0]-'a'+1 );
                update( 1 , 1 , len-1 , pos , str[0]-'a'+1 );
        }
        for( int i = 1; i < len; i++ ) if( s[i] != 'X' ) cout << s[i];
        return 0;
}







