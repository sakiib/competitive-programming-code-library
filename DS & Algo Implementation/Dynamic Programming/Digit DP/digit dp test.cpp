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

int a , len;
vector <int> num;

void calc( int x ) {
        num.clear();
        while( x ) {
              num.push_back( x%10 ) , x /= 10;
        }
        reverse( num.begin() , num.end() );
        len = num.size();
}
/// st handles leading zero..
void solve( int pos , int chk , string ret , int cnt , int st ) {
        if( pos >= len ) {
                cout << ret <<" ->  " << cnt << endl;
                return;
        }
        if( chk ) {
                for( int i = 0; i <= 9; i++ ) {
                        string k = ret;
                        k += ( i+'0' );
                        solve( pos+1 , 1 , k , cnt+(!st&&i == 0) , (st&&i == 0)   );
                }
        }
        else {
                for( int i = 0; i < num[pos]; i++ ) {
                        string k = ret;
                        k += ( i+'0' );
                        solve( pos+1 , 1 , k , cnt+(!st&&i == 0) , (st&&i == 0)  );
                }
                string k = ret;
                k += ( num[pos]+'0' );
                solve( pos+1 , 0 , k , cnt+(!st&&num[pos] == 0) , (st&&num[pos] == 0) );
        }
}
int main( int argc , char const *argv[] ) {
        ios_base :: sync_with_stdio(false); cin.tie(NULL);
        while( cin >> a ) {
                calc( a );
                solve( 0 , 0 , "" , 0 , 1 );
        }
        return 0;
}






