#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
typedef pair< int,int > ii;
typedef pair< int,ii > iii;
const int inf = 1e9;
const LL INF = 1e18;
const int N = 100005;
const int MOD = 1e9+7;
const double EPS = 1e-6;
const double PI = acos(-1.0);

const int sz = 2050;

int mat[ sz ][ sz ];
int BIT[ sz ][ sz ];
char str[ 100 ];

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
int main( int argc, char const *argv[] ) {
    int t;
    scanf("%d",&t);
    for( int tc = 1; tc <= t; tc++ ) {
        int n;
        scanf("%d",&n);
        while( true ) {
            scanf("%s",str);
            if( strcmp(str,"END") == 0 ) break;
            if( strcmp(str,"SET") == 0 ) {
                int x , y , val;
                scanf("%d%d%d",&x,&y,&val);
                x++ , y++;
                Update( x , y , -mat[x][y]+val );
                mat[x][y] = val;
            }
            else {
                int x1 , y1 , x2 , y2;
                scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
                x1++ , y1++ , x2++ , y2++;
                int ans = 0;
                ans += Query( x2 , y2 );
                ans -= Query( x1-1 , y2 );
                ans -= Query( x2 , y1-1 );
                ans += Query( x1-1 , y1-1 );
                printf("%d\n",ans);
            }
        }
        memset( BIT , 0 , sizeof( BIT ) );
        memset( mat , 0 , sizeof( mat ) );
    }
    return 0;
}

