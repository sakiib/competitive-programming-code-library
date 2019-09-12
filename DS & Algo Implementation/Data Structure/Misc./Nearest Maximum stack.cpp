#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
#include<stack>
#include<vector>
#include<deque>
#include<functional>
#include<string>
#include<iostream>
#include<cctype>
#include<set>
#include<climits>
#include<iomanip>
#include<cassert>
#include<sstream>

using namespace std;

typedef long long LL;
const int N = 8e4 + 5;

int n;
int a[ N ];

int main( ) {
        scanf("%d",&n);
        for( int i = 1; i <= n; i++ ) scanf("%d",&a[i]);
        stack <int> S;
        S.push( n+1 );
        LL ans = 0;
        for( int i = n; i >= 1; i-- ) {
                while( !S.empty() && a[i] > a[ S.top() ] && S.top() != (n+1) ) {
                        S.pop();
                }
                ans += ( S.top() - i - 1 );
                cout << i << " " << S.top() << endl;
                S.push( i );
        }
        printf("%lld\n",ans);
        return 0;
}













