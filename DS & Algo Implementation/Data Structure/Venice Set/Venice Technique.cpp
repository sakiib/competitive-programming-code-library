#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
const int N = 1e5 + 5;

struct VeniceSet {
        multiset <LL> S;
        LL water_lvl = 0;
        inline void Add( LL val ) {
                S.insert( val + water_lvl );
        }
        inline void UpdateAll( LL val ) {
                water_lvl += val;
        }
        inline LL GetSize( ) {
                return S.size( );
        }
        inline LL GetMin( ) {
                return ( *S.begin( ) - water_lvl );
        }
        inline void Remove( LL val ) {
                S.erase( S.find( val + water_lvl ) );
        }
}S;

int n;
LL v[ N ] , t[ N ];

int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( nullptr );
        cin >> n;
        for( int i = 1; i <= n; i++ ) cin >> v[i];
        for( int i = 1; i <= n; i++ ) cin >> t[i];
        for( int i = 1; i <= n; i++ ) {
                S.Add( v[i] );
                S.UpdateAll( t[i] );
                LL ans = ( t[i] * S.GetSize() );
                while( S.GetSize() > 0 && S.GetMin() < 0 ) {
                        LL mn = S.GetMin( );
                        ans -= abs( mn );
                        S.Remove( mn );
                }
                cout << ans << " ";
        }
        return 0;
}











