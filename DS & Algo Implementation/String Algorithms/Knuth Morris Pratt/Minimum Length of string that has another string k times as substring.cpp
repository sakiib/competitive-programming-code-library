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

int Failure[ 50*N ];
char pattern[ 50*N ];

void Failure_Function( int lp ) {
        Failure[0] = Failure[1] = 0;
        for( int i = 2; i <= lp; i++ ) {
                int j = Failure[i-1];
                while( true ) {
                        if( pattern[j] == pattern[i-1] ) {
                                Failure[i] = j+1;
                                break;
                        }
                        if( j == 0 ) {
                                Failure[i] = 0;
                                break;
                        }
                        j = Failure[j];
                }
        }
}
int main( int argc , char const *argv[] ) {
        int t;
        scanf("%d",&t);
        while( t-- ) {
                LL k;
                scanf("%s %lld",pattern,&k);
                int len = strlen( pattern );
                Failure_Function( len );
                LL mx = Failure[len];
                if( mx ==  0 ) {
                        printf("%lld\n",1LL*k*len);
                        continue;
                }
                LL tot = 1LL*k*len;
                LL ans = tot - 1LL*mx*(k-1);
                printf("%lld\n",ans);
        }
        return 0;
}






