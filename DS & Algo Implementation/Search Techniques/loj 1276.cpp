#include <bits/stdc++.h>
using namespace std;

#define all(V) V.begin(), V.end()
#define UNIQUE(V) sort(all(V)), V.erase(unique(all(V)), V.end())
typedef long long LL;
const LL MX = 1e12;

vector <LL> V , res;

LL solve( LL a , LL b ) {
        return upper_bound( res.begin() , res.end() , b ) -
                lower_bound( res.begin() , res.end() , a );
}
void lucky( LL cur ) {
        if( cur > MX ) return;
        if( cur ) V.push_back( cur );
        lucky( cur * 10 + 4 );
        lucky( cur * 10 + 7 );
        return;
}
void verylucky( LL cur , int k ) {
        if( cur <= 0 || cur > MX ) return;
        if( cur != 1 ) res.push_back( cur );
        for( int i = k; i < V.size(); i++ ) {
                if( V[i] * cur > 0 & V[i] * cur <= MX ) {
                        verylucky( V[i] * cur , i );
                }
                else break;
        }
        return;
}
int main( ) {
        lucky( 0 );
        sort( V.begin() , V.end() );
        verylucky( 1 , 0 );
        UNIQUE( res );
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
                LL a , b;
                scanf("%lld %lld",&a,&b);
                LL ans = solve( a , b );
                printf("Case %d: %lld\n",tc,solve( a , b ));
        }
        return 0;
}








