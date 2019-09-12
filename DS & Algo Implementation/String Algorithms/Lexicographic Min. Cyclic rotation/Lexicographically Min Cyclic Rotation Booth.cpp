#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
typedef pair < int , int > ii;
const int inf = 1e9;
const LL INF = 1e18;
const int N = 1e5 + 5;
const int mod = 1000000007;
const double eps = 1e-8;
const double pi = acos( -1.0 );

/// O( N )

string s;
int len;

int Booth( ) {
        int n = len << 1 , i = 0 , j = 1 , k = 0 , a , b;
        while( i + k < n && j + k < n ) {
                a = ( i + k >= len ) ? s[ i + k - len ] : s[ i + k ];
                b = ( j + k >= len ) ? s[ j + k - len ] : s[ j + k ];
                if( a == b ) k++;
                else if( a > b ) { i = i + k + 1; if( i <= j ) i = j + 1; k = 0; }
                else { j = j + k + 1; if( j <= i ) j = i + 1; k = 0; }
        }
        return ( i < j ? i : j );
}
int main( int argc , char const *argv[] ) {
        ios_base :: sync_with_stdio(false); cin.tie(NULL);
        cin >> len >> s;
        int pos = Booth( );
        cout << "Pos : " << pos << endl;
        cout << "Lexicographically Min Cyclic Rotation : " << endl;

        string x = s.substr( pos , len - pos );
        x += s.substr( 0 , pos );
        cout << x << endl;
        return 0;
}






