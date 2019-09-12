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

LL fact[25];
map <LL,int> M;

void gen_fact( ) {
        fact[1] = 1LL;
        for( int i = 2;i <= 19; i++ ) fact[i] = i * fact[i-1];
}
void calc( int pos , LL val ) {
        M[val] = 1;
        for( int i = pos; i <= 19;i++ ) {
                if( val > INF/fact[i] ) continue;
                calc( i , val*fact[i] );
        }
}
int main( int argc , char const *argv[] ) {
        Fast_IO;
        gen_fact();
        M[1] = 1;
        calc( 2 , 1 );
        int t;
        cin >> t;
        while( t-- ) {
                LL n;
                cin >> n;
                if( M[n] ) cout << "YES" << endl;
                else cout << "NO" << endl;
        }
        return 0;
}








