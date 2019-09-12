#include <bits/stdc++.h>
using namespace std;

/**
  works like multiset ( keeps duplicates )
  Size() return the size of treap.
  Erase deletes a single occurrence of a number.
 */

typedef long long LL;
const int N = 1e5+10;

struct TREAP {
        struct Node{
                LL val , prior , Size;
                Node *l , *r;
        };
        typedef Node* pnode;
        pnode root;
        TREAP( ) { root = NULL; }
        inline LL getSize( pnode t ) { return t ? t->Size : 0; }
        // return size of the treap
        inline LL Size( ) { return getSize( root ); }
        inline void upd_sz( pnode t ) {
                if( t ) t->Size = getSize( t->l ) + 1 + getSize( t->r );
        }
        inline pnode Init( LL x ) {
                pnode ret = ( pnode )malloc( sizeof( Node ) );
                ret->val = x , ret->prior = rand() , ret->Size = 1;
                ret->l = ret->r = NULL;
                return ret;
        }
        inline void Split( pnode t , pnode &l , pnode &r , LL key ) {
                if( !t ) l = r = NULL;
                else if( t->val <= key ) Split( t->r , t->r , r , key ), l = t;
                else Split( t->l , l , t->l , key ), r = t;
                upd_sz( t );
        }
        inline void Merge( pnode &t , pnode l , pnode r ) {
                if( !l || !r ) t = l ? l : r;
                else if( l->prior > r->prior ) Merge( l->r , l->r , r ), t = l;
                else Merge( r->l , l , r->l ), t = r;
                upd_sz( t );
        }
        // inserts val in treap
        inline void Insert( pnode it , pnode &t ) {
                if( !t ) t = it;
                else if( it->prior > t->prior ) Split( t , it->l , it->r , it->val ), t = it;
                else Insert( it , t->val <= it->val ? t->r : t->l );
                upd_sz( t );
        }
        inline void Insert( LL val ) { Insert(Init(val),root); }
        // Finds wheather key is present in treap or not
        inline bool Find( pnode t , LL key ) {
                if( !t ) return 0;
                if( t -> val == key ) return 1;
                else if( key <= t -> val ) return Find( t -> l , key );
                else return Find( t -> r , key );
        }
        inline bool Find( LL key ) { return Find( root , key ); }
        // erases key from treap
        inline void Erase( LL key , pnode &t ) {
                if( !t ) return;
                if( t->val == key ) {
                        pnode temp = t;
                        Merge( t , t->l , t->r );
                        free( temp );
                }
                else Erase( key , t->val < key ? t->r : t->l );
                upd_sz( t );
        }
        inline void Erase( LL key ) { Erase( key , root ); }
        inline LL KTH( pnode t , int k ) {
                LL cnt = getSize( t -> l );
                if( cnt == k - 1 ) return t -> val;
                else if( cnt >= k ) return KTH( t -> l , k );
                else return KTH( t -> r , k - cnt - 1 );
        }
        inline LL KTH( LL k ) { return Size() < k ? -1 : KTH( root , k ); }
        // returns number of elements less than s
        inline LL CountLess( LL s , pnode t ) {
                if( !t ) return 0;
                if( t->val >= s ) return CountLess( s , t->l );
                return getSize( t->l ) + 1 + CountLess( s , t->r );
        }
        inline LL CountLess( LL s ) { return CountLess( s , root ); }
        inline LL CountLessEqual( LL s , pnode t ) {
                if( !t ) return 0;
                if( t->val > s ) return CountLessEqual( s , t->l );
                return getSize( t->l ) + 1 + CountLessEqual( s , t->r );
        }
        inline LL CountLessEqual( LL s ) { return CountLessEqual( s , root ); }
        inline void Print( pnode root ) {
                if( root == NULL ) return;
                Print( root->l );
                cout << root->val << " ";
                Print( root->r );
        }
        // print the treap
        inline void Print( ) { Print( root ); cout << "\n"; }
} treap;


int main( int argc , char const *argv[] ) {
        ios_base :: sync_with_stdio(false); cin.tie(NULL);

        int q;
        cin >> q;
        while( q-- ) {
                string op;
                cin >> op;
                LL num;
                cin >> num;
                if( op[0] == 'I' ) {
                        if( !treap.Find( num ) ) treap.Insert( num );
                }
                if( op[0] == 'D' ) {
                        if( treap.Find( num ) ) treap.Erase( num );
                }
                if( op[0] == 'C' ) {
                        cout << treap.CountLess( num ) << endl;
                }
                if( op[0] == 'K' ) {
                        LL x = treap.KTH( num );
                        if( x == -1 ) cout << "invalid" << endl;
                        else cout << x << endl;
                }
        }
        return 0;
}









