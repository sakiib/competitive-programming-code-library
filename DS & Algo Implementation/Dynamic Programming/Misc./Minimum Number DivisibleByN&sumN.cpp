#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
const int inf = 0x3f3f3f3f; ///1061109567
int n;
int dist[ N ][ N ];

struct data {
        int sum , mod;
        string ans;
        data( int sum , int mod , string ans ): sum(sum) , mod(mod) , ans(ans){}
};

string solve( ) {
        queue <data> Q;
        memset( dist , -1 , sizeof( dist ) );
        Q.push( data( 0 , 0 , "" ) );
        dist[0][0] = 0;
        while( !Q.empty() ) {
                data f = Q.front(); Q.pop();
                int cur_sum = f.sum;
                int cur_mod = f.mod;
                string cur_ans = f.ans;
                if( cur_mod == 0 && cur_sum == n ) return cur_ans;
                for( int i = 0; i <= 9; i++ ) {
                        int sum = i + cur_sum;
                        int mod = ( cur_mod * 10 + i )%n;
                        if( sum > n ) continue;
                        if( dist[sum][mod] == -1 || dist[sum][mod] > dist[cur_sum][cur_mod] + 1 ) {
                                dist[sum][mod] = dist[cur_sum][cur_mod] + 1;
                                string temp = cur_ans;
                                temp += ( i + '0' );
                                Q.push( data( sum , mod , temp ) );
                        }
                }
        }
        return "";
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( NULL );
        int t;
        cin >> t;
        while( t-- ) {
                cin >> n;
                if( n < 10 ) cout << n << endl;
                else cout << solve() << endl;
        }
        return 0;
}










