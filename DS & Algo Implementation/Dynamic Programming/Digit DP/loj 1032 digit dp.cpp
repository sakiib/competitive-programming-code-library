#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
vector <int> V;
int len;
LL dp[35][2][2][35];

/**
A bit is a binary digit, taking a logical value of either 1 or 0
(also referred to as "true" or "false" respectively). And every decimal number
 has a binary representation which is actually a series of bits. If a bit of a number
  is 1 and its next bit is also 1 then we can say that the number has a 1 adjacent bit.
   And you have to find out how many times this scenario occurs for all numbers up to N.
*/

LL go( int idx , int smaller , int last , int sum ) {
        if( idx >= len ) return sum;
        if( dp[idx][smaller][last][sum] != -1 ) return dp[idx][smaller][last][sum];
        LL ret = 0;
        if( smaller ) {
                for( int i = 0; i <= 1; i++ ) {
                        ret += go( idx + 1 , 1 , i , sum + ( last == 1 && i == 1 ) );
                }
        }
        else {
                for( int i = 0; i < V[idx]; i++ ) {
                        ret += go( idx + 1 , 1 , i , sum + ( last == 1 && i == 1 ) );
                }
                ret += go( idx + 1 , 0 , V[idx] , sum + ( last == 1 && V[idx] == 1 ) );
        }
        return dp[idx][smaller][last][sum]= ret;
}
LL solve( LL val ) {
        V.clear();
        while( val ) V.push_back( val%2 ) , val /= 2;
        reverse( V.begin() , V.end() );
        len = V.size();
        memset( dp , -1 , sizeof( dp ) );
        return go( 0 , 0 , 0 , 0 );
}
int main( int argc , char const *argv[] ) {
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
                LL val;
                scanf("%lld",&val);
                printf("Case %d: %lld\n",tc,solve( val ));
        }
        return 0;
}










