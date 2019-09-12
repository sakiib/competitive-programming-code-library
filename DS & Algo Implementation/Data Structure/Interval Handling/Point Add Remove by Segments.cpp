#include <bits/stdc++.h>
using namespace std;

const int inf = 2e9;
#define ff first
#define ss second
#define mp make_pair

map <int,int> active;

void Remove( int L , int R ) {
        auto it = active.lower_bound( L );
        --it;
        if( (*it).ss >= L ) {
                active[L] = (*it).ss;
                (*it).ss = L - 1;
        }
        ++it;
        while( (*it).ff <= R ) {
                if( (*it).ss > R ) {
                        active[R+1] = (*it).ss;
                }
                auto it2 = it;
                ++it;
                active.erase( it2 );
        }
}
void Add( int L , int R ) {
        auto it = active.lower_bound( L );
        --it;
        if( (*it).ss >= L - 1 ) (*it).ss = R;
        else active[L] = R;
        it = active.lower_bound( L + 1 );
        if( (*it).ff == R + 1 ) {
                int st = (*it).ss;
                --it;
                (*it).ss = st;
                ++it;
                active.erase( it );
        }
}
void see( ) {
        printf("Active Segments\n");
        for( auto x : active ) printf("( %d , %d )\n",x.ff,x.ss);
        printf("END\n");
}
int main( int argc , char const *argv[] ) {
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
                int n , k , q;
                scanf("%d %d %d",&n,&k,&q);
                active.clear();
                active[-1] = -1;
                active[1] = k;
                active[inf] = inf;
                printf("Case %d:\n",tc);
                while( q-- ){
                        int x , y;
                        scanf("%d %d",&x,&y);
                        Remove( x , x );
                        Add( y , y );
                        // 2 extra added & 1 coz counting only in between gaps.
                        int ans = active.size() - 2 - 1;
                        if( active.find( 1 ) == active.end() ) ans++;
                        auto it = --active.end();
                        --it;
                        if( (*it).ss < n ) ans++;
                        printf("%d\n",ans);
                        //see();
                }
        }
        return 0;
}







