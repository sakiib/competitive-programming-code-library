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
int  Set( int N , int pos )    { return N |= ( 1 << pos ); }
int  Reset( int N , int pos )  { return N = N & ~( 1 << pos ); }
bool Check( int N , int pos )  { return (bool)( N & ( 1 << pos ) );}
int  Toggle( int N , int pos ) { return ( N ^= ( 1 << pos ) ); }

map <int,int> M;
int mask[ N ];
LL ans;
map <int,int> cnt;

int main( int argc , char const *argv[] ) {
        Fast_IO;
        int n;
        cin >> n;
        for( int i = 1; i <= n; i++ ) {
                string s;
                cin >> s;
                for( int j = 0; j < s.size(); j++ ) {
                        mask[i] = Toggle( mask[i] , ( s[j] - 'a' ) );
                }
        }
        for( int i = 1; i <= n; i++ ) {
                ans += cnt[ mask[i] ];
                for( int j = 0; j < 26; j++ ) {
                        int cur = mask[i];
                        cur = Toggle( cur , j );
                        ans += cnt[ cur ];
                }
                cnt[ mask[i] ]++;
        }
        cout << ans << endl;
        return 0;
}







