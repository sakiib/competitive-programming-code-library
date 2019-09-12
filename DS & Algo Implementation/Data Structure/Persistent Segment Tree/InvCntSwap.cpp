#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(V) V.begin(), V.end()
#define Unique(V) sort(all(V)), V.erase(unique(all(V)), V.end())
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long int LL;
const int N = 2e5 + 5;

vector <int> V;
int n , q , id , a[ N ];
map <int,int> ID;

struct node {
        node *l , *r;
        int val;

        node( ) {
                l = nullptr , r = nullptr , val = 0;
        }
        node( node *l , node *r , int val ) : l(l), r(r), val(val) {}

        node* update( int b , int e , int pos , int v ) {
                if( b > e || pos > e || pos < b ) return this;
                if( b == e && b == pos ) {
                        node *ret = new node( l , r , val );
                        ret -> val += v;
                        return ret;
                }
                int mid = ( b + e ) >> 1;
                node *ret = new node();
                if( pos <= mid ) {
                        ret -> r = r;
                        ret -> l = l -> update( b , mid , pos , v );
                }
                else {
                        ret -> l = l;
                        ret -> r = r -> update( mid+1 , e , pos , v );
                }
                ret -> val = ( ret -> l -> val + ret -> r -> val );
                return ret;
        }

        int query( node *prev , int b , int e , int i , int j ) {
                if( i > e || j < b || b > e ) return 0;
                if( i <= b && j >= e ) return val - prev -> val;
                int mid = ( b + e ) >> 1;
                int q1 = l -> query( prev -> l , b , mid , i , j );
                int q2 = r -> query( prev -> r , mid+1 , e , i , j );
                return q1 + q2;
        }

} *root[ 8*N ];

int main( ) {
        #ifdef OFFLINE
            freopen( "input.txt" , "r" , stdin );
        #endif // OFFLINE
        scanf("%d %d",&n,&q);
        for( int i = 1; i <= n; i++ ) {
                scanf("%d",&a[i]);
                V.push_back( a[i] );
        }
        id = 0;
        Unique(V);
        for( auto x : V ) ID[x] = ++id;
        for( int i = 1; i <= n; i++ ) a[i] = ID[a[i]];
        node *null = new node();
        null -> l = null -> r = null;
        root[0] = null;
        for( int i = 1; i <= n; i++ ) {
                root[i] = root[i-1] -> update( 1 , id , a[i] , +1 );
        }
        LL tot = 0;
        for( int i = 1; i < n; i++ ) {
                int l = i + 1 , r = n;
                tot += root[r] -> query( root[l-1] , 1 , id , 1 , a[i]-1 );
        }
        while( q-- ) {
                int l , r;
                scanf("%d %d",&l,&r);
                if( l == r || a[l] == a[r] ) printf("%lld\n",tot);
                else {
                        LL cur = tot;
                        if( l > r ) swap( l , r );
                        int ll = l , rr = r;
                        l += 1 , r -= 1;
                        cur -= root[r] -> query( root[l-1] , 1 , id , 1 , a[ll]-1 );
                        cur -= root[r] -> query( root[l-1] , 1 , id , a[rr] + 1 , id );
                        cur += root[r] -> query( root[l-1] , 1 , id , 1 , a[rr]-1 );
                        cur += root[r] -> query( root[l-1] , 1 , id , a[ll]+1 , id );
                        if( a[ll] < a[rr] ) cur++;
                        else cur--;
                        printf("%lld\n",cur);
                }
        }
        return 0;
}






