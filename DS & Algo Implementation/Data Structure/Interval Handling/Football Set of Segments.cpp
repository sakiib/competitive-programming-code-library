#include <bits/stdc++.h>
using namespace std;

#define Fast_IO ios_base::sync_with_stdio(0); cin.tie(0);
#define ff first
#define ss second
#define mp make_pair

typedef long long int LL;
const int inf = 2e9;

int n , k , q;
set < pair <int,int> > S;

/**
 S contains only the free segments
 initially free : ( k + 1 , n )
 operation : x y
 move person from pos x to pos y
 Pre
 */

void see( ) {
        cout << "printing set" << endl;
        for( auto it : S ) cout << it.ff << " " << it.ss << endl;
        cout << "END" << endl;
}
int getAns( ) {
        return (int)(S.size());
}
void Pre( int x ) {
        auto it = S.upper_bound( make_pair( x , inf ) );
        int al = -1 , ar = -1 , bl = inf , br = inf;
        if( it != S.end( ) ) { /// Next segment
                al = (*it).ff;
                ar = (*it).ss;
        }
        if( it != S.begin() ) { /// Ager segment
                --it;
                bl = (*it).ff;
                br = (*it).ss;
        }
        if( br == x - 1 && al == x + 1 ) {
                S.erase( mp( bl , br ) );
                S.erase( mp( al , ar ) );
                S.insert( mp( bl, ar ) );
        }
        else if( br == x - 1 ) {
                S.erase( mp( bl, br ) );
                S.insert( mp( bl , x ) );
        }
        else if( al == x + 1 ) {
                S.erase( mp( al , ar ) );
                S.insert( mp( x , ar ) );
        }
        else {
                S.insert( mp( x , x ) );
        }
}
void Post( int y ) {
        auto it = S.upper_bound( mp( y , inf ) );
        --it;
        int l = (*it).ff;
        int r = (*it).ss;
        S.erase( it );
        int ll = l;
        int rr = y - 1;
        if( ll <= rr ) S.insert( mp( ll , rr ) );
        ll = y + 1;
        rr = r;
        if( ll <= rr ) S.insert( mp( ll , rr ) );
}
void solve( ) {
        S.insert( make_pair( k + 1 , n ) );
        while( q-- ) {
                int x , y;
                scanf("%d %d",&x,&y);
                Pre( x );
                see( );
                Post( y );
                see( );
                printf("%d\n",getAns());
        }
}
int main( int argc , char const *argv[] ) {
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
                scanf("%d %d %d",&n,&k,&q);
                S.clear();
                printf("Case %d:\n",tc);
                solve( );
        }
        return 0;
}







