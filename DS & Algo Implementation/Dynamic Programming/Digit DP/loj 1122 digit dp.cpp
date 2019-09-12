#include <bits/stdc++.h>
using namespace std;

/**
Given a set of digits S, and an integer n, you have to find how many n-digit
integers are there, which contain digits that belong to S and the difference
between any two adjacent digits is not more than two.
*/
typedef long long LL;
int m , n;
int in[ 15 ];
vector <int> V;
LL dp[ 11 ][ 2 ][ 10 ][ 2 ];
int len;

LL go( int idx , int smaller , int last , int first ) {
        if( idx >= len ) return 1LL;
        if( dp[idx][smaller][last][first] != -1 ) return dp[idx][smaller][last][first];
        LL ret = 0;
        if( smaller ) {
                for( int i = 0; i <= 9; i++ ) {
                        if( !in[i] ) continue;
                        if( first ) ret += go( idx + 1 , 1 , i , 0 );
                        else {
                                if( abs( last - i ) <= 2 ) {
                                        ret += go( idx + 1 , 1 , i , 0 );
                                }
                        }
                }
        }
        else {
                for( int i = 0; i < V[idx]; i++ ) {
                        if( !in[i] ) continue;
                        if( first ) ret += go( idx + 1 , 1 , i , 0 );
                        else {
                                if( abs( last - i ) <= 2 ) {
                                        ret += go( idx + 1 , 1 , i , 0 );
                                }
                        }
                }
                if( in[ V[idx] ] ) {
                        if( first ) ret += go( idx + 1 , 0 , V[idx] , 0 );
                        else {
                                if( abs( V[idx] - last ) <= 2 ) {
                                    ret += go( idx + 1 , 0 , V[idx] , 0 );
                                }
                        }
                }
        }
        return dp[idx][smaller][last][first] = ret;
}
LL solve( LL val ) {
        V.clear();
        while( val ) V.push_back( val%10 ) , val /= 10;
        reverse( V.begin() , V.end() );
        len = V.size();
        memset( dp , -1 , sizeof( dp ) );
        return go( 0 , 0 , 0 , 1 );
}
int main( int argc , char const *argv[] ) {
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
                memset( in , 0 , sizeof( in ) );
                scanf("%d %d",&m,&n);
                for( int i = 1; i <= m; i++ ) {
                        int val;
                        scanf("%d",&val);
                        in[val] = 1;
                }
                LL mx = 0;
                for( int i = 1; i <= n; i++ ) mx = mx * 10 + 9;
                LL ans = solve( mx );
                printf("Case %d: %lld\n",tc,ans);
        }
        return 0;
}










