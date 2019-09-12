#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define endl "\n"
#define all(V) V.begin(), V.end()
#define Unique(V) sort(all(V)), V.erase(unique(all(V)), V.end())
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long int LL;
const int N = 2e5 + 5;

template <typename T> using
    Treap = tree<T,null_type,
    less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;

Treap <int> treap;

/// smaller & equal hoile ( key + 1 )
/// find_by_order : 0 based pos e kon value ache
/// order_of_key : kon position e ache. ( first occ )
int main( ) {
        ios_base::sync_with_stdio( false ); cin.tie( nullptr );
        #ifdef OFFLINE
            //freopen( "input.txt" , "r" , stdin );
        #endif // OFFLINE
        int q;
        cin >> q;
        while( q-- ) {
                string s;
                cin >> s;
                if( s[0] == 'I' ) { /// na thakle insert korbo.
                        int val;
                        cin >> val;
                        int pos = treap.order_of_key( val );
                        int cval = *treap.find_by_order( pos );
                        if( cval == val ) continue; /// already ase
                        else treap.insert( val );
                }
                if( s[0] == 'D' ) { /// value thakle erase korbo
                        int val;
                        cin >> val;
                        int pos = treap.order_of_key( val );
                        int cval = *treap.find_by_order( pos );
                        if( cval == val ) treap.erase( treap.find_by_order( treap.order_of_key(val) ) );
                }
                if( s[0] == 'C' ) { /// #of values smaller than val
                        int val;
                        cin >> val;
                        cout << treap.order_of_key( val ) << endl;
                }
                if( s[0] == 'K' ) { /// kth element , if not invalid
                        int val;
                        cin >> val;
                        if( val > treap.size() ) cout << "invalid" << endl;
                        else cout << *treap.find_by_order( --val ) << endl;
                }
        }
        return 0;
}







