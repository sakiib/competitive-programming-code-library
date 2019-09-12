/**
 * Created by Sakib on 06/09/2018.
 */
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

/**
 Change the typename T for pair , long long etc as necessary.
 Has same functions like set besides 1 & 2

 1. S.order_of_key( num ) : if present returns index(0 based)
                             else returns the position of first greater element.
                             or Number of elements smaller than num.

 2. *S.find_by_order( pos ) : returns the element at position pos.
                               if no such position , returns 0

 3. *S.upper_bound( num ) : returns the value just greater than num.
                            if no such value , then returns 0

 4. *S.lower_bound( num ) : if num is present then returns num or returns
                            just the larger element than num.
                            if no such value returns 0

 5. S.find( num ) != S.end() : boolean true or false , just like Set

 6. S.erase( num ) : Erases number num , na thakle nai

 7. orderset<int> :: iterator it;
    it = S.begin() or it = S.end() , just like Set

 */

template < typename T >
using orderset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

orderset <int> S;

int main( int argc, char const *argv[] ) {
        for( int i = 1; i <= 5; i++ ) S.insert( i*10 );
        for( auto x : S ) cout << x << " "; cout <<endl;
        S.erase( 10 );
        for( auto x : S ) cout << x << " "; cout <<endl;
        S.erase( *S.find_by_order( 1 ) );
        for( auto x : S ) cout << x << " "; cout <<endl;
        return 0;
}









