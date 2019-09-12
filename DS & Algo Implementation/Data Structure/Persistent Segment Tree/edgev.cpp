#include <bits/stdc++.h>
using namespace std;

int a[] = { 0 , 1 , 0 , 1 , 0 , 1 , 1 , 0 , 1 , 1 , 0 };

struct node {
        node *l , *r;
        int val;
        int lazy;
        node( ) {
                l = nullptr , r = nullptr;
                val = 0 , lazy = 0;
        }
        node( node *_l , node *_r , int _val , int _lazy ) {
                l = _l , r = _r , val = _val , lazy = _lazy;
        }
        void build( int b, int e ) {
                if( b > e ) return;
                if( b == e ) {
                        val = a[b];
                        lazy = 0;
                        return;
                }
                int m = ( b + e ) >> 1;
                if( !l ) l = new node();
                if( !r ) r = new node();
                l -> build( b , m );
                r -> build( m + 1 , e );
                val = 0;
                if( l ) val += l -> val;
                if( r ) val += r -> val;
        }
        void pushdown( int b , int e ) {
                if( lazy == 0 ) return;
                int m = ( b + e ) >> 1;
                val = ( e - b + 1 ) - val;
                lazy = 0;
        }
        void update( int b , int e , int i , int j ) {
                if( i > e || j < b || b > e ) return;
                if( i <= b && j >= e ) {
                        val = ( e - b + 1 ) - val;
                        lazy ^= 1;
                        return;
                }
                int m = ( b + e ) >> 1;
                if( !l ) l = new node();
                if( !r ) r = new node();
                if( lazy ) {
                        l -> pushdown( b , m );
                        r -> pushdown( m + 1 , e );
                        lazy = 0;
                }
                l -> update( b , m , i , j );
                r -> update( m + 1 , e , i , j );
                val = 0;
                if( l ) val += l -> val;
                if( r ) val += r -> val;
        }
        int query( int b , int e , int i , int j ) {
                if( i > e || j <b || b > e ) return 0;
                if( i <= b && j >= e ) return val;
                int m = ( b + e ) >> 1;
                if( !l ) l = new node();
                if( !r ) r = new node();
                if( lazy ) {
                        l -> pushdown( b , m );
                        r -> pushdown( m + 1 , e );
                        lazy = 0;
                }
                return l -> query( b , m , i , j ) + r -> query( m + 1 , e , i , j );
        }
} *root[ 100 ];

int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( NULL );
        root[1] = new node();
        root[1] -> build( 1 , 10 );

        cout << root[1] -> query( 1 , 10 , 3 , 6 ) << endl;

        root[1] -> update( 1 , 10 , 3 , 6 );

        cout << root[1] -> query( 1 , 10 , 3 , 6 ) << endl;
        cout << root[1] -> query( 1 , 10 , 1 , 10 ) << endl;
        root[1] -> update( 1 , 10 , 3 , 6 );
        cout << root[1] -> query( 1 , 10 , 1 , 10 ) << endl;
        return 0;
}











