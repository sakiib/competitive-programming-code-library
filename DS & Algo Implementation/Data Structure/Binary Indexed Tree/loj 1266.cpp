#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long uLL;
typedef long long int LL;
typedef pair <int,int> pii;
typedef pair <int,pii> piii;
typedef pair <long long,long long> pll;
typedef pair <long long,pll> plll;
const int N = 1e5 + 5;
const int inf = 1e9;
const long long INF = 1e18;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int MOD = 1000000007;

const int sz = 1005;

int q;
int BIT[ sz ][ sz ];
int val[ sz ][sz ];

void Update( int idx , int idy , int val ) {
        int y = idy;
        for( ; idx <= sz; idx += ( idx & -idx ) ) {
                idy = y;
                for( ; idy <= sz ; idy += ( idy & -idy ) ) {
                        BIT[idx][idy] += val;
                }
        }
}
int Query( int idx , int idy ) {
        int y = idy;
        int sum = 0;
        for( ; idx > 0; idx -= ( idx & -idx ) ) {
                idy = y;
                for( ; idy > 0 ; idy -= ( idy & -idy ) ) {
                        sum += BIT[idx][idy];
                }
        }
        return sum;
}
void solve( ) {
        for( int i = 1; i <= q; i++ ) {
                int type;
                scanf("%d",&type);
                if( type == 0 ) {
                        int x , y;
                        scanf("%d %d",&x,&y);
                        ++x , ++y;
                        if( val[x][y] == 1 ) continue;
                        val[x][y] = 1;
                        Update( x , y , +1 );
                }
                else {
                        int x1 , y1 , x2 , y2;
                        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
                        ++x1 , ++y1 , ++x2 , ++y2;
                        int ans = 0;
                        ans += Query( x2 , y2 );
                        ans -= Query( x1 - 1 , y2 );
                        ans -= Query( x2 , y1 - 1 );
                        ans += Query( x1 - 1 , y1 - 1 );
                        printf("%d\n",ans);
                }
        }
}
int main( int argc , char const *argv[] ) {
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
                scanf("%d",&q);
                printf("Case %d:\n",tc);
                solve( );
                memset( val , 0 , sizeof( val ) );
                memset( BIT , 0 , sizeof( BIT ) );
        }
        return 0;
}











