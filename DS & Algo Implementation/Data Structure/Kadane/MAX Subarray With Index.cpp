#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
typedef unsigned long long uLL;
typedef long long int LL;
typedef pair <int,int> pii;
typedef pair <int,pii> piii;
typedef pair <long long,long long> pll;
typedef pair <long long,pll> plll;
const int N = 1e5 + 5;
const int inf = 1e9;
const long long INF = 1e18;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int MOD = 1000000007;

LL a[ N ];
int n;

void kadane( ) {
        LL sum = 0 , mx = -INF;
        int cur_st = 1 , st = 1 , en = 0;
        for( int i = 1; i <= n; i++ ) {
                sum += a[i];
                if( sum > mx ) mx = sum , st = cur_st , en = i;
                if( sum < 0 ) sum = 0 , cur_st = i + 1;
        }
        cout << mx << " " << st << " " << en << endl;
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( nullptr );
        int t;
        cin >> t;
        bool f = false;
        for( int tc = 1; tc <= t; tc++ ) {
                if( f ) cout << endl;
                f = true;
                cout << "Case " << tc << ":" << endl;
                cin >> n;
                for( int i = 1; i <= n; i++ ) cin >> a[i];
                kadane( );
        }
        return 0;
}












