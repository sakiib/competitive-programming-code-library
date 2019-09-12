#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(V) V.begin(), V.end()
#define Unique(V) sort(all(V)), V.erase(unique(all(V)), V.end())
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long int LL;
const int N = 1e5 + 5;

#define ff first
#define ss second
const int MOD = 100000000;

int n;
pair <int,int> a[ N ];
int dp[ N ];

bool cmp( pair <int,int> a , pair <int,int> b ) {
        return a.first == b.first ? a.second < b.second : a.first < b.first;
}
int add( int x , int y , int MOD ) {
        x += y;
        return x >= MOD ? x - MOD : x;
}
int solve( int idx ) {
        if( idx > n ) return 0;
        if( dp[idx] != -1 ) return dp[idx];
        int ret = 0;
        ret = add( ret , solve( idx + 1 ), MOD  );
        int lo = idx + 1 , hi = n , pos = n + 1;
        while( lo <= hi ) {
                int mid = ( lo + hi ) >> 1;
                if( a[mid].first >= a[idx].second ) pos = mid , hi = mid - 1;
                else lo = mid + 1;
        }
        ret = add( ret , add( 1 , solve( pos ) , MOD ) , MOD );
        return dp[idx] = ret;
}
int main( ) {
        #ifdef OFFLINE
            freopen( "input.txt" , "r" , stdin );
        #endif // OFFLINE
        while( scanf("%d",&n) ) {
                if( n == -1 ) break;
                for( int i = 1; i <= n; i++ ) {
                        scanf("%d %d",&a[i].ff,&a[i].ss);
                }
                sort( a + 1 , a + n + 1 , cmp );
                memset( dp , -1 , sizeof( dp ) );
                printf("%08d\n",solve(1));
        }
        return 0;
}






