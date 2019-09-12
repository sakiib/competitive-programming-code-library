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
Counting Number of 0 in L to R
*/
LL a , b;
int len;
LL dp[18][2][100][2];
vector <int> num;

void calc( LL x ) {
        num.clear();
        while( x ) {
                num.push_back( x%10 ) , x /= 10;
        }
        reverse( num.begin() , num.end() );
        len = num.size();
}
LL go( int pos , int chk , int cnt , int st ) {
        if( pos >= len ) return cnt;
        if( dp[pos][chk][cnt][st] != -1 ) return dp[pos][chk][cnt][st];
        LL ret = 0;
        if( chk ) {
                for( int i = 0; i <= 9; i++ ) {
                        ret += go( pos+1 , 1 , cnt+(!st&&i == 0) , (st&&i == 0)   );
                }
        }
        else {
                for( int i = 0; i < num[pos]; i++ ) {
                        ret += go( pos+1 , 1 , cnt+(!st&&i == 0) , (st&&i == 0)  );
                }
                ret += go( pos+1 , 0 , cnt+(!st&&num[pos] == 0) , (st&&num[pos] == 0) );
        }
        return dp[pos][chk][cnt][st] = ret;
}
LL solve( LL x ) {
        if( x == -1 ) return -1;
        calc( x );
        memset( dp , -1 , sizeof(dp) );
        return go( 0 , 0 , 0 , 1 );
}
int main( int argc , char const *argv[] ) {
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
                scanf("%lld %lld",&a,&b);
                //cout << solve( b ) << " " << solve( a-1 ) << endl;
                printf("Case %d: %lld\n",tc,(solve(b)-solve(a-1)));
        }
        return 0;
}






