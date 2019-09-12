#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define mp make_pair
const int inf = 2e9;

int n , k , q;
set < pair <int,int> > EmptySeg;

void see( ) {
        for( auto it : EmptySeg ) printf("( %d , %d )\n",it.ff,it.ss);
}
int getAns( ) {
        return (int)( EmptySeg.size() );
}
void Add( int y ) {
        auto it = EmptySeg.upper_bound( mp( y , inf ) );
        --it;
        int l = (*it).ff;
        int r = (*it).ss;
        EmptySeg.erase( it );
        int ll = l;
        int rr = y - 1;
        if( ll <= rr ) EmptySeg.insert( mp( ll , rr ) );
        ll = y + 1;
        rr = r;
        if( ll <= rr ) EmptySeg.insert( mp( ll , rr ) );
}
void Remove( int x ) {
        // x pos ta empty korte hobe.
        auto it = EmptySeg.upper_bound( mp( x , inf ) );
        int al = -1 , ar = -1 , bl = inf , br = inf;
        if( it != EmptySeg.end() ) {
                // x pos er shamne kothay first empty segment ache.
                al = (*it).ff;
                ar = (*it).ss;
        }
        if( it != EmptySeg.begin() ) {
                --it;
                // x pos er age kothay first empty segment ache
                // --it important or agertai hote pare.
                bl = (*it).ff;
                br = (*it).ss;
        }
        if( br == x - 1 && al == x + 1 ) {
                // 2 ta empty set can be merged
                // 2 ta segment baad diye new merged segment inserted
                EmptySeg.erase( mp( al , ar ) );
                EmptySeg.erase( mp( bl , br ) );
                EmptySeg.insert( mp( bl , ar ) );
        }
        else if( br == x - 1 ) {
                // just ager tar sathe merge
                EmptySeg.erase( mp( bl , br ) );
                EmptySeg.insert( mp( bl , x ) );
        }
        else if( al == x + 1 ) {
                // just porer tar sathe merge
                EmptySeg.erase( mp( al, ar ) );
                EmptySeg.insert( mp( x , ar ) );
        }
        else {
                // nothing to merge , just etai inserted
                EmptySeg.insert( mp( x , x ) );
        }
}
void solve( ) {
        EmptySeg.insert( mp( k + 1 , n ) );
        while( q-- ) {
                int x , y;
                scanf("%d %d",&x,&y);
                Remove( x );
                Add( y );
                //see( );
                printf("%d\n",getAns());
        }
}
int main( int argc , char const *argv[] ) {
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
                scanf("%d %d %d",&n,&k,&q);
                printf("Case %d:\n",tc);
                EmptySeg.clear();
                solve( );
        }
        return 0;
}







