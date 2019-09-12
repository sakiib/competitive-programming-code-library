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

int val[ N ];
string s;
LL sum[ N ];
vector <int> pos[ 30 ];

int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( nullptr );
        for( int i = 1; i <= 26; i++ ) cin >> val[i];
        cin >> s;
        s = '#' + s;
        for( int i = 1; i < s.size(); i++ ) pos[ s[i]-'a'+1 ].push_back( i );
        for( int i = 1; i < s.size(); i++ ) sum[i] += sum[i-1] + val[ s[i]-'a'+1 ];
        LL ans = 0;
        for( int i = 1; i <= 26; i++ ) {
                map <LL,LL> dp;
                for( auto x : pos[i] ) ans += dp[ sum[x-1] ] , dp[ sum[x] ]++;
        }
        cout << ans <<endl;
        return 0;
}











