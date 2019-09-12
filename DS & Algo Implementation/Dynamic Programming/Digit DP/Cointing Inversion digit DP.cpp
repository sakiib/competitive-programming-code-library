#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;

LL dig[ 20 ];
LL dp[ 20 ][ 10 ][ 2 ][ 2 ][ 20 ][ 500 ];

LL go( int idx , int x , int lead , int tight , int cur , int inv ) {
        if( idx == -1 ) return inv;
        if( !tight && dp[idx][x][lead][tight][cur][inv] != -1 )
                                            return dp[idx][x][lead][tight][cur][inv];
        LL ret = 0;
        int up = tight ? dig[idx] : 9;
        for( int i = 0; i <= up; i++ ) {
                ret += go( idx - 1 , x , lead&&( i == 0 ) , tight&&( dig[idx] == i ) ,
                             ( lead && i == 0 ) ? cur : ( i < x ) ? (cur+1) : cur ,
                             ( lead && i == 0 ) ? inv : ( i == x ) ? inv + cur : inv );

        }
        if( !tight ) dp[idx][x][lead][tight][cur][inv] = ret;
        return ret;
}
LL solve( LL num ) {
        int l = 0;
        while( num ) dig[l++] = num%10 , num /= 10;
        LL tot = 0;
        for( int i = 1; i <= 9; i++ ) tot += go( l - 1 , i , 1 , 1 , 0 , 0 );
        return tot;
}
int main( int argc , char const *argv[] ) {
        int t;
        scanf("%d",&t);
        memset( dp , -1 , sizeof( dp ) );
        for( int tc = 1; tc <= t; tc++ ) {
                LL a , b;
                scanf("%lld %lld",&a,&b);
                printf("Case %d: %lld\n",tc,( solve( b ) - solve( a - 1 ) ));
        }
        return 0;
}












