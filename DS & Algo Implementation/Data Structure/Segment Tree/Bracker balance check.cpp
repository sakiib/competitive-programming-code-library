#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long uLL;
typedef long long int LL;
typedef pair <int,int> pii;
typedef pair <int,pii> piii;
typedef pair <long long,long long> pll;
typedef pair <long long,pll> plll;
const int N = 1e6 + 5;
const int inf = 1e9;
const long long INF = 1e18;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int MOD = 1000000007;

int n;
string s;

struct data {
        int o , c , m;
} tree[ 4*N ];

void build( int node , int b , int e ) {
        if( b > e ) return;
        if( b == e ) {
                if( s[b] == '(' ) tree[node].o++;
                else tree[node].c++;
                return;
        }
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        build( l , b , m );
        build( r , m + 1 , e );
        tree[node].m = min( tree[l].o , tree[r].c );
        tree[node].o = tree[l].o + tree[r].o - tree[node].m;
        tree[node].c = tree[l].c + tree[r].c - tree[node].m;
}
void toggle( int node , int b , int e , int pos ) {
        if( pos > e || pos < b || b > e ) return;
        if( pos == b && b == e ) {
                if( s[b] == '(' ) {
                      s[b] = ')';
                      tree[node].o-- , tree[node].c++;
                }
                else {
                        s[b] = '(';
                        tree[node].o++ , tree[node].c--;
                }
                return;
        }
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        toggle( l , b , m , pos );
        toggle( r , m + 1 , e , pos );
        tree[node].m = min( tree[l].o , tree[r].c );
        tree[node].o = tree[l].o + tree[r].o - tree[node].m;
        tree[node].c = tree[l].c + tree[r].c - tree[node].m;
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( NULL );

        cin >> n >> s;
        build( 1 , 0 , n - 1 );
        int ans = 0;
        for( int i = 0; i < n; i++ ) {
                toggle( 1 , 0 , n - 1 , i );
                ans += ( tree[1].o == 0 && tree[1].c == 0 );
                toggle( 1 , 0 , n - 1 , i );
        }
        cout << ans << endl;
        return 0;
}











