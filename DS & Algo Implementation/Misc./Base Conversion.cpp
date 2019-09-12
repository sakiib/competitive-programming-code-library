#include <bits/stdc++.h>
using namespace std;

#define Fast_IO ios_base::sync_with_stdio(0); cin.tie(0);

typedef unsigned long long uLL;
typedef long long int LL;
const int N = 1e5 + 5;
const int inf = 1e9;
const LL INF = 1e18;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int MOD = 1000000007;

/**
 Convert from one base to another.
 n is given in Base x , convert it to Base y
 */

map <char,int> M1;
map <int,char> M2;

int main( int argc , char const *argv[] ) {
        for( int i = 0; i < 26; i++ ) {
                M1[ i + 'A' ] = i + 10; /// A -10 , B - 11 .. Z - 35
                M2[ i + 10 ] = ( i + 'A' ); /// Vice versa.
        }
        int t;
        cin >> t;
        while( t-- ) {
                int x , y;
                string n;
                cin >> x >> y;
                cin >> n;
                LL dec = 0 , p = 1;
                for( int i = n.size()-1; i >= 0; i-- ) {
                      if( n[i] >= '0' && n[i] <= '9' ) dec += ( ( n[i] - '0' ) * p );
                      else dec += ( M1[ n[i] ] * p );
                      p *= x;
                }
                ///cout <<"Number in Decimal : "<< dec << endl;
                string ans = "";
                LL rem = 0;
                if( dec == 0 ) ans = "0";
                while( dec > 0 ) {
                        rem = dec%y;
                        dec /= y;
                        if( rem <= 9 ) ans = (char)( rem + '0' ) + ans;
                        else ans = (char)M2[ rem ] + ans;
                }
                cout << ans << endl;
        }
        return 0;
}







