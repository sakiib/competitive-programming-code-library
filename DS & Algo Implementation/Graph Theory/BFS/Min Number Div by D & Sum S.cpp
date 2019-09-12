#include <bits/stdc++.h>
using namespace std;

int d , s;
int dist[ 5005 ][ 505 ];

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
                if( cur_mod == 0 && cur_sum == s ) return cur_ans;
                for( int i = 0; i <= 9; i++ ) {
                        int sum = i + cur_sum;
                        int mod = ( cur_mod * 10 + i )%d;
                        if( sum > s ) continue;
                        if( dist[sum][mod] == -1 || dist[sum][mod] > dist[cur_sum][cur_mod] + 1 ) {
                                dist[sum][mod] = dist[cur_sum][cur_mod] + 1;
                                string temp = cur_ans;
                                temp += ( i + '0' );
                                Q.push( data( sum , mod , temp ) );
                        }
                }
        }
        return "-1";
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( NULL );
        cin >> d >> s;
        cout << solve( ) << endl;
        return 0;
}












