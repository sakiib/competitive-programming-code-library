#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(V) V.begin(),V.end()
#define see(x) cerr << #x << " = " << x << "\n";
#define Unique(V) sort(all(V)),V.erase(unique(all(V)),V.end())
#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long int LL;
typedef pair <int,int> pii;
const int MOD = 1e9 + 7;
const int inf = 1e9;
const double PI = acos(-1.0);
const long long INF = 1e18;
const int N = 1e5 + 5;

int n , q , a[ N ];
int cnt[ N ];

int main( ) {
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
                scanf("%d %d",&n,&q);
                for( int i = 0; i < n; i++ ) scanf("%d",&a[i]);
                memset( cnt , 0 , sizeof( cnt ) );
                for( int i = 0; i < n; i++ ) cnt[i] = n - i - 1 - i;
                LL ans = 0;
                for( int i = 0; i < n; i++ ) ans += 1LL*a[i]*cnt[i];
                printf("Case %d:\n",tc);
                while( q-- ) {
                        int type;
                        scanf("%d",&type);
                        if( type == 1 ) {
                                printf("%lld\n",ans);
                        }
                        else {
                                int pos , val;
                                scanf("%d %d",&pos,&val);
                                ans -= 1LL*a[pos]*cnt[pos];
                                a[pos] = val;
                                ans += 1LL*a[pos]*cnt[pos];
                        }
                }
        }
        return 0;
}







