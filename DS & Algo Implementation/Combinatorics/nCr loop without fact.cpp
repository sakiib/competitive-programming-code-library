#include <iostream>
#include <algorithm>
using namespace std;

typedef unsigned long long uLL;
typedef long long int LL;

/**
modify the input for nCr
*/
LL nCr( LL n , LL r ) {
        LL ans = 1;
        for( int i = 0; i < r; i++ ) {
                ans = ans * ( n - i )/( i + 1 );
        }
        return ans;
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( NULL );
        LL n , m;
        while( cin >> n >> m ) {
                if( n == 0 && m == 0 ) break;
                LL step = n + m;
                cout << nCr( step , min( n, m ) ) << endl;
        }
        return 0;
}











