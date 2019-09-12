#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 1e5 + 5;
const int INF = 1e5;

struct segment {
        LL sum , max_suff , max_pref , ans;
        segment(){}
        segment( LL sum , LL max_suff , LL max_pref , LL ans ) {
                this -> sum = sum;
                this -> max_suff = max_suff;
                this -> max_pref = max_pref;
                this -> ans = ans;
        }
};

int n , q;
LL a[ N ];
segment Tree[ 4*N ];

void Build( int node , int b , int e ) {
        if( b > e ) return;
        if( b == e ) {
                Tree[node].sum = a[b];
                Tree[node].max_suff = a[b];
                Tree[node].max_pref = a[b];
                Tree[node].ans = a[b];
                return;
        }
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        Build( l , b , m );
        Build( r , m + 1 , e );
        Tree[node].sum = Tree[l].sum + Tree[r].sum;
        Tree[node].max_pref = max( Tree[l].max_pref , Tree[l].sum + Tree[r].max_pref );
        Tree[node].max_suff = max( Tree[r].max_suff , Tree[r].sum + Tree[l].max_suff );
        Tree[node].ans = max( Tree[l].ans , Tree[r].ans );
        Tree[node].ans = max( Tree[node].ans , Tree[l].max_suff + Tree[r].max_pref );
}
void Update( int node , int b , int e , int pos , LL val ) {
        if( pos > e || pos < b || b > e ) return;
        if( b == e && b == pos ) {
                Tree[node].sum = val;
                Tree[node].max_pref = val;
                Tree[node].max_suff = val;
                Tree[node].ans = val;
                return;
        }
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        Update( l , b , m , pos , val );
        Update( r , m + 1 , e , pos , val );
        Tree[node].sum = Tree[l].sum + Tree[r].sum;
        Tree[node].max_pref = max( Tree[l].max_pref , Tree[l].sum + Tree[r].max_pref );
        Tree[node].max_suff = max( Tree[r].max_suff , Tree[r].sum + Tree[l].max_suff );
        Tree[node].ans = max( Tree[l].ans , Tree[r].ans );
        Tree[node].ans = max( Tree[node].ans , Tree[l].max_suff + Tree[r].max_pref );
}
segment Query( int node , int b , int e , int i , int j ) {
        if( i > e || j < b || b > e ) return { -INF, -INF, -INF, -INF };
        if( i <= b && j >= e ) return Tree[node];
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        segment s1 = Query( l , b , m , i , j );
        segment s2 = Query( r , m + 1 , e , i , j );
        segment ret = { -INF, -INF, -INF, -INF };
        ret.sum = s1.sum + s2.sum;
        ret.max_pref = max( s1.max_pref , s1.sum + s2.max_pref );
        ret.max_suff = max( s2.max_suff , s2.sum + s1.max_suff );
        ret.ans = max( s1.ans , s2.ans );
        ret.ans = max( ret.ans , s1.max_suff + s2.max_pref );
        return ret;
}
int main( int argc , char const *argv[] ) {
        scanf("%d",&n);
        for( int i = 1; i <= n; i++ ) scanf("%lld",&a[i]);
        Build( 1 , 1 , n );
        scanf("%d",&q);
        while( q-- ) {
                int l , r;
                scanf("%d %d",&l,&r);
                printf("%lld\n",Query( 1 , 1 , n , l , r ).ans );
        }
        return 0;
}













