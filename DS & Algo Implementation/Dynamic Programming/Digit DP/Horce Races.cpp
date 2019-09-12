#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
typedef long long int LL;
const int MOD = 1000000007;

string a , b;
int k;
int dig[ 1010 ];
LL dp[ 1010 ][ 2 ][ 1010 ][ 2 ];

LL go( int idx , bool tight , int last , int f ) {
        if( idx == -1 ) return f;
        if( !tight && dp[idx][tight][last][f] != -1 ) return dp[idx][tight][last][f];
        LL ret = 0;
        int up = tight ? dig[idx] : 9;
        for( int i = 0; i <= up; i++ ) {
                int cf = f;
                if( i == 4 || i == 7 ) {
                        if( last != 1008 && abs( last - idx ) <= k ) cf = 1;
                }
                ret += go( idx-1, tight&&(dig[idx]==i), (i==4||i==7)? idx : last, cf);
                ret %= MOD;
        }
        if( !tight ) dp[idx][tight][last][f] = ret;
        return ret;
}
LL solve( string &s ) {
        int len = 0;
        for( int i = s.size() - 1; i >= 0; i-- ) dig[len++] = (s[i]-'0');
        return go( len - 1 , 1 , 1008 , 0 );
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( nullptr );
        int t;
        cin >> t >> k;
        memset( dp , -1 , sizeof( dp ) );
        while( t-- ) {
                cin >> a >> b;
                LL ans = solve( b ) - solve( a );
                bool f = false;
                stack <int> S;
                for( int i = 0; i < a.size(); i++ ) {
                        if( a[i] == '4' || a[i] == '7' ) {
                                if( !S.empty() ) {
                                        if( abs( S.top() - i ) <= k ) f = true;
                                } S.push( i );
                        }
                }
                if( f ) ans++;
                cout << ( ans < 0 ? ans + MOD : ans ) << endl;
        }
        return 0;
}







