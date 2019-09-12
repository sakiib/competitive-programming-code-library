#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template <typename T> using
Treap = tree <T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef unsigned long long uLL;
typedef long long int LL;
typedef pair <int,int> pii;
typedef pair <long long,long long> pll;
const int N = 1e5 + 5;
const int inf = 1e9;
const long long INF = 1e18;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int MOD = 1000000007;

int n , m;
int a[ 5*N ] , cnt[ 10*N ];
int ans;

int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( NULL );
        cin >>n >> m;
        for( int i = 1; i <= n; i++ ) cin >> a[i];
        int mx = 1 , len = 1 , i = 1 , j = 1 , taken = 1;
        int st = 1 , en = 1;
        cnt[ a[1] ]++;
        while( i <= n && j <= n ) {
                while( taken <= m && j <= n ) {
                        j++;
                        len++;
                        if( cnt[ a[j] ] == 0 ) taken++;
                        cnt[ a[j] ]++;
                }
                if( len - 1 > mx ) {
                        mx = len - 1;
                        st = i , en = j - 1;
                }
                while( taken > m ) {
                        cnt[ a[i] ]--;
                        if( cnt[ a[i] ] == 0 ) taken--;
                        i++ , len--;
                }
        }
        cout << st << " " << en << endl;
        return 0;
}
















