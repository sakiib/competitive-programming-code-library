#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int f[ N ];
int cnt[ N ][ 15 ];

void factor() {
        for( int i = 2; i <= 1e6; i++ ) {
                if( !f[i] ) {
                        for( int j = i; j <= 1e6; j += i ) {
                                f[j]++;
                        }
                }
        }
        for( int i = 1; i <= 1e6; i++ ) {
                for( int j = 0; j <= 10; j++ ) {
                        if( f[i] == j ) cnt[i][j]++;
                        cnt[i][j] += cnt[i-1][j];
                }
        }
}
int main( ) {
        factor();
        int t;
        scanf("%d",&t);
        while( t-- ) {
                int a , b , k;
                scanf("%d %d %d",&a,&b,&k);
                printf("%d\n",cnt[b][k]-cnt[a-1][k]);
        }
        return 0;
}








