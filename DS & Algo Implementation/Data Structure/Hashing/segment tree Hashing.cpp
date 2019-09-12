#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
const int MOD = 1e9 + 7;
const int N = 1e5 + 5;
const int base = 43;

int len , q;
string s;
int a[ 4*N ];
int p[ N ];

inline int mul( int x , int y , int MOD ) {
        return ( 1LL * x * y )%MOD;
}
inline int add( int x , int y , int MOD ) {
        x += y;
        return x >= MOD ? x - MOD : x;
}
inline int sub( int x , int y , int MOD ) {
        x -= y;
        return x < 0 ? x + MOD : x;
}

struct data {
        int l , fhash , rhash;
        data() : l( 0 ) , fhash( 0 ) , rhash( 0 ) {}
        data( int l , int fhash , int rhash ) :
                l( l ) , fhash( fhash ) , rhash( rhash ) {}
};

data tree[ 4*N ];

inline data combine( data a , data b ) {
        data ret = data( 0 , 0 , 0 );
        ret.l = a.l + b.l;
        ret.fhash = add( a.fhash , mul( b.fhash , p[a.l] , MOD ) , MOD );
        ret.rhash = add( b.rhash , mul( a.rhash , p[b.l] , MOD ) , MOD );
        return ret;
}
inline void gen_power( ) {
        p[0] = 1;
        for( int i = 1; i < N; i++ ) p[i] = mul( p[i-1] , base , MOD );
}
inline void build( int node , int b , int e ) {
        if( b > e ) return;
        if( b == e ) {
                tree[node] = data( 1 , a[b] , a[b] );
                return;
        }
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        build( l , b , m );
        build( r , m + 1 , e );
        tree[node] = combine( tree[l] , tree[r] );
}
inline void update( int node , int b , int e , int pos , int val ) {
        if( b > e || pos > e || pos < b ) return;
        if( b == e && b == pos ) {
                tree[node] = data( 1 , val , val );
                return;
        }
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        update( l , b , m , pos , val );
        update( r , m + 1 , e , pos , val );
        tree[node] = combine( tree[l] , tree[r] );
}
inline data query( int node , int b , int e , int i , int j ) {
        if( i > e || j < b || b > e ) return data( 0 , 0 , 0 );
        if( i <= b && j >= e ) return tree[node];
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        return combine( query( l , b , m , i , j ) , query( r , m + 1 , e , i , j ) );
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( nullptr );
        #ifdef forthright48
            freopen( "input.txt" , "r" , stdin );
        #endif // forthright48
        gen_power();
        int t;
        cin >> t;
        while( t-- ) {
                cin >> len >> q >> s;
                for( int i = 0; i < len; i++ ) a[i+1] = (s[i] - 'a' + 1);
                build( 1 , 1 , len );
                while( q-- ) {
                        int type;
                        cin >> type;
                        if( type == 1 ) {
                                int pos;
                                string c;
                                cin >> pos >> c;
                                update( 1 , 1 , len , pos , c[0] - 'a' + 1 );
                        }
                        else {
                                int l , r;
                                cin >> l >> r;
                                data res = query( 1 , 1 , len , l , r );
                                if( res.fhash == res.rhash ) {
                                        cout << "Adnan Wins" << endl;
                                }
                                else {
                                        cout << "ARCNCD!" << endl;
                                }
                        }
                }
        }
        return 0;
}









