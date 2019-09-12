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

/**
Counting occurrences of all digits in L to R

*/
LL a , b;
int len;
LL dp[18][2][100][2][10];
vector <int> num;
LL ans[ 11 ];

void calc( LL x ) {
        num.clear();
        while( x ) {
                num.push_back( x%10 ) , x /= 10;
        }
        reverse( num.begin() , num.end() );
        len = num.size();
}
LL go0( int pos , int chk , int cnt , int st , int dig ) {
        if( pos >= len ) return cnt;
        if( dp[pos][chk][cnt][st][dig] != -1 ) return dp[pos][chk][cnt][st][dig];
        LL ret = 0;
        if( chk ) {
                for( int i = 0; i <= 9; i++ ) {
                        ret += go0( pos+1 , 1 , cnt+(!st&&i == dig) , (st&&i == 0) , dig   );
                }
        }
        else {
                for( int i = 0; i < num[pos]; i++ ) {
                        ret += go0( pos+1 , 1 , cnt+(!st&&i == dig) , (st&&i == 0) , dig  );
                }
                ret += go0( pos+1 , 0 , cnt+(!st&&num[pos] == dig) , (st&&num[pos] == 0) ,dig );
        }
        return dp[pos][chk][cnt][st][dig] = ret;
}
LL go( int pos , int chk , int cnt , int st , int dig ) {
        if( pos >= len ) return cnt;
        if( dp[pos][chk][cnt][st][dig] != -1 ) return dp[pos][chk][cnt][st][dig];
        LL ret = 0;
        if( chk ) {
                for( int i = 0; i <= 9; i++ ) {
                        ret += go( pos+1 , 1 , cnt+(i == dig) , st , dig   );
                }
        }
        else {
                for( int i = 0; i < num[pos]; i++ ) {
                        ret += go( pos+1 , 1 , cnt+(i == dig) , st , dig  );
                }
                ret += go( pos+1 , 0 , cnt+( num[pos] == dig) , st ,dig );
        }
        return dp[pos][chk][cnt][st][dig] = ret;
}
LL solve0( LL x ) {
        if( x == -1 ) return -1;
        calc( x );
        memset( dp , -1 , sizeof(dp) );
        return go0( 0 , 0 , 0 , 1 , 0 );
}
LL solve( LL x , int dig ) {
        if( x == -1 ) return -1;
        calc( x );
        memset( dp , -1 , sizeof(dp) );
        return go( 0 , 0 , 0 , 1 , dig );
}
int main( int argc , char const *argv[] ) {
        LL a , b;
        //freopen( "input.txt" , "r" ,stdin );
        //freopen( "output.txt" , "w" , stdout );
        while( cin >> a >> b ) {
                if( a == 0 && b == 0 ) break;
                memset( ans , 0 , sizeof( ans ) );
                for( int i = 0; i <= 9; i++ ) {
                        if( i == 0 ) {
                                ans[i] = solve0( b ) - solve0( a - 1 );
                        }
                        else {
                                ans[i] = solve( b , i ) - solve( a - 1 , i );
                        }
                }
                for( int i = 0; i <= 9; i++ ) {
                        if( i == 0 ) cout << ans[i];
                        else cout << " " << ans[i];
                }
                cout << endl;
        }
        return 0;
}







