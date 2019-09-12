#include <bits/stdc++.h>
using namespace std;

/**
 cf 915 - E
 Idea from : Ashishgup
 */

typedef long long LL;
#define endl "\n"

int n , q ;
LL ans;
map <LL,LL> active;

void Init( ) {
        active[ -1 ] = -1;
        active[ 2e9 ] = 2e9;
        active[ 1 ] = n;
}
void see( ) {
        cout << "SET" << endl;
        for( auto x : active ) cout << x.first << " " << x.second << endl;
        cout << "END" << endl;
}
void Add( LL L , LL R ) { /// Always Remove [ L , R ] before Adding.
        active[ L ] = R;
        ans += ( R - L + 1 );
        see( );
}
void Remove( LL L , LL R ) {
        LL removed = 0;
        auto it = active.lower_bound( L );
        it--;
        if( it -> second >= L ) {
                active[ L ] = it -> second;
                it -> second = L - 1;
        }
        it++;
        while( it -> first <= R ) {
                if( it -> second > R ) {
                        removed += ( R + 1 - it -> first );
                        active[ R+1 ] = it -> second;
                }
                else removed += ( it -> second - it -> first + 1 );
                auto it2 = it;
                it++;
                active.erase( it2 );
        }
        ans -= removed;
        see( );
}
int main( int argc , char const *argv[] ) {
        //ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
        cin >> n >> q;
        Init( );
        ans = n;
        for( int i = 1;i <= q; i++ ) {
                LL l , r , k;
                cin >> l >> r >> k;
                Remove( l , r );

                if( k == 2 ) Add( l , r );
                cout << ans << endl;
        }
        return 0;
}






