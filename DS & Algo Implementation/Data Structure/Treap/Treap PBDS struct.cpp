#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template <typename T> using Treap = tree <T, null_type, less<T>,
                rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> class PBDS {
    public :
        Treap <T> treap;
        /// this treap contains only unique elements...
        /// for multiset , use pair instead or less_equal...
        inline void add( T val ) { treap.insert( val ); }

        inline int sz( ) { return treap.size(); }

        inline bool has( T val ) {
                return treap.find( val ) != treap.end();
        }
        inline void print( ) {
                cout << "<------ treap contains : -----> " << "\n";
                for( auto x : treap ) cout << x << " "; cout << "\n";
                cout << "<------------ END ------------>" << "\n";
        }
        inline void rem( T val ) {
                if( treap.find( val ) == treap.end() ) return;
                treap.erase( treap.find_by_order( treap.order_of_key( val ) ) );
        }
        inline int smaller( T val ) {
                return treap.order_of_key( val );
                /// returns #of elements smaller than val
        }
        inline T KTH( int k ) {
                if( treap.size( ) < k ) return -1;
                else return *treap.find_by_order( --k );
                /// if k param is one based , make sure --k , else just k
        }
};

PBDS <int> treap;

int main( int argc , char const *argv[] ) {
        //freopen( "input.txt" , "r" , stdin );
        srand( time(NULL) );
        for( int i = 1; i <= 10; i++ ) treap.add( i );

        return 0;
}










