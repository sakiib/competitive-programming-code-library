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

char s[ 100 ] , ans[ 100 ];
LL k;
int cnt[ 100 ];
LL fact[ 100 ];
int len;

LL calc( ) {
        LL ret = 0;
        for( int i = 1; i <= 26; i++ ) ret += cnt[i];
        LL tot = fact[ret];
        for( int i = 1; i <= 26; i++ ) tot /= fact[ cnt[i] ];
        return tot;
}
void genfact( ) {
        fact[0] = 1LL;
        for( int i = 1; i <= 30; i++ ) fact[i] = fact[i-1] * i;
}
int main( int argc , char const *argv[] ) {
        genfact( );
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
                scanf("%s %lld",s,&k);
                len = strlen( s );
                memset( cnt , 0 , sizeof( cnt ) );
                for( int i = 0; i < len; i++ ) cnt[ s[i]-'a'+1 ]++;
                LL tot = calc( );
                if( tot < k ) {
                        printf("Case %d: Impossible\n",tc);
                        continue;
                }
                for( int i = 0; i < len; i++ ) {
                        for( int ch = 1; ch <= 26; ch++ ) {
                                if( !cnt[ch] ) continue;
                                cnt[ch]--;
                                LL res = calc( );
                                if( res < k ) {
                                        cnt[ch]++;
                                        k -= res;
                                }
                                else {
                                      ans[i] = (char)(ch+'a'-1);
                                      break;
                                }
                        }
                }
                ans[len] = '\0';
                printf("Case %d: %s\n",tc,ans);
        }
        return 0;
}











