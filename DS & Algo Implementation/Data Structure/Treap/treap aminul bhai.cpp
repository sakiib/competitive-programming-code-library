#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(V) V.begin(), V.end()
#define Unique(V) sort(all(V)), V.erase(unique(all(V)), V.end())
typedef long long int LL;
const int N = 1e5 + 5;

struct node {
        node *l , *r;
        int val , prior , size;
        node( ) {}
        node( int v ) {
                val = v, prior = rand(), size = 1, l = r = NULL;
        }
};

typedef node* pnode;

struct Treap {
        pnode t;
        Treap( ) {}
        int size( ) {
                return sz( t );
        }
        int sz( pnode t ) {
                return t ? t -> size : 0;
        }
        void upd_sz( pnode t ) {
                if( t ) t -> size = sz( t -> l ) + 1 + sz( t -> r );
        }
        void split( pnode t , pnode &l , pnode &r , int key ) {
                if( !t ) l = r = NULL;
                else if( t -> val <= key ) {
                        split( t -> r , t -> r , r , key ); l = t;
                }
                else {
                        split( t -> l , l , t -> l , key ); r = t;
                }
                upd_sz( t );
        }
        void merge( pnode &t , pnode l , pnode r ) {
                if( !l || !r ) t = l ? l : r;
                else if( l -> prior > r -> prior ) {
                        merge( l -> r , l -> r , r ); t - l;
                }
                else {
                        merge( r -> l , l , r -> l ); t = r;
                }
                upd_sz( t );
        }
        void insert( pnode &t , pnode it ) {
                if( !t ) t = it;
                else if( it -> prior > t -> prior ) {
                        split( t , it -> l , it -> r , it -> val ); t = it;
                }
                else {
                        insert( t -> val <= it -> val ? t -> r : t -> l , it );
                }
                upd_sz( t );
        }
        void erase( pnode &t , int key ) {
                if( !t ) return;
                else if( t -> val == key ) {
                        pnode temp = t; merge( t , t -> l , t -> r );
                        free( temp );
                }
                else {
                        erase( t -> val < key ? t -> r : t -> l , key );
                }
                upd_sz( t );
        }
        void init( pnode &t , int c ) {
                t -> prior = rand( ); t -> size = 1;
                t -> l = t -> r = NULL; t -> val = c;
        }
        int getKth( pnode temp , int par , int k ) {
                if( temp == NULL ) return 0;
                int cur_sz = par + sz( temp -> l ) + 1;
                if( cur_sz == k ) return temp -> val;
                else if( cur_sz <= k ) return getKth( temp -> r , cur_sz , k );
                else return getKth( temp -> l , par , k );
        }
        /// #of elements <= k , for smaller change cond. to < from <=
        int orderOf( pnode temp , int k ) {
                if( temp == NULL ) return 0;
                if( temp -> val <= k ) {
                        return sz( temp -> l ) + 1 + orderOf( temp -> r , k );
                }
                else {
                        return orderOf( temp -> l , k );
                }
        }
        void print( pnode t ) {
                if( !t ) return;
                print( t -> l ); cout << t -> val << "\n"; print( t -> r );
        }
        inline void insert( int k ) { pnode it = new node( k ); insert( t , it ); }

        inline void erase( int k ) { erase( t , k ); }
        /// kth is one bases , 1st , 2nd etc..
        inline int getKth( int k ) { return getKth( t , 0 , k ); }

        inline int orderOf( int k ) { return orderOf( t , k ); }

        inline void print( ) { print( t ); }

        inline void nullify( pnode t ) {
                if( t == NULL ) return;
                nullify( t -> l ); nullify( t -> r );
                t -> l = NULL; t -> r = NULL; t = NULL;
        }
        inline void clear( ) { nullify( t ); t = NULL; }
} treap;

/// etay jhamela ase , need to fix it...

int main( ) {

        return 0;
}








