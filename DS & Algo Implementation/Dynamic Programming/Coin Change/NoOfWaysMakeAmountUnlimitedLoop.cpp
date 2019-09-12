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

int coin[] = { 1 , 5 , 10 , 25 , 50 };
LL ways[ 30001 ];

/**
 1 coin can be used infinite times.
 total number of ways to make an amount.
 */

int main( int argc , char const *argv[] ) {
        int n;
        ways[0] = 1;
        for( int i = 0; i < 5; i++ ) {
                for( int j = coin[i]; j <= 30000; j++ ) {
                        ways[j] += ways[ j - coin[i] ];
                }
        }
        while( scanf("%d",&n) != EOF ) {
                if( ways[n] > 1 )
                printf("There are %lld ways to produce %d cents change.\n",ways[n],n);
                else
                printf("There is only 1 way to produce %d cents change.\n",n);
        }
        return 0;
}



