#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
typedef unsigned long long uLL;
typedef long long int LL;
typedef pair <int,int> pii;
typedef pair <int,pii> piii;
typedef pair <long long,long long> pll;
typedef pair <long long,pll> plll;
const int N = 2e5 + 1;
const int inf = 1e9 + 1;
const long long INF = 1e18;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int MOD = 1000000007;

int n;
int l[ 2 ][ N ];

struct Node {
        Node *l , *r;
        int mn;
        int lazy;
        Node ( ) : l( NULL ) , r( NULL ) , mn( 0 ) , lazy( 0 ) {};
        void Merge( int b , int e ) {
                mn = 2*inf;
                int mid = ( b + e ) >> 1;
                if( l ) mn = min( mn , l -> mn );
                if( r ) mn = min( mn , r -> mn );
        }
} *root;

typedef Node* pNode;

void Propagate( pNode &cur , int b , int e ) {
        if( cur -> lazy == 0 ) return;
        int mid = ( b + e ) >> 1;
        if( !( cur -> l ) ) cur -> l = new Node();
        if( !( cur -> r ) ) cur -> r = new Node();
        cur -> l -> mn += ( cur -> lazy );
        cur -> r -> mn += ( cur -> lazy );
        cur -> l -> lazy += cur -> lazy;
        cur -> r -> lazy += cur -> lazy;
        cur -> lazy = 0;
}
void Update( pNode &cur , int b , int e , int i , int j , int val ) {
        if( i > e || j < b || b > e ) return;
        if( i <= b && j >= e ) {
                cur -> mn += val;
                cur -> lazy += val;
                return;
        }
        Propagate( cur , b , e );
        int mid = ( b + e ) >> 1;
        if( j <= mid ) {
                if( !(cur -> l) ) cur -> l = new Node();
                Update( cur -> l , b , mid , i , j , val );
        }
        else if( mid < i ) {
                if( !(cur -> r) ) cur -> r = new Node();
                Update( cur -> r , mid + 1 , e , i , j , val );
        }
        else {
                if( !(cur -> l) ) cur -> l = new Node();
                if( !(cur -> r) ) cur -> r = new Node();
                Update( cur -> l , b , mid , i , j , val );
                Update( cur -> r , mid + 1 , e , i , j , val );
        }
        cur -> Merge( b , e );
}
int QueryMIN( pNode &cur , int b , int e , int i , int j ) {
        if( !cur ) return 2*inf;
        if( i > e || j < b || b > e ) return 2*inf;
        if( i <= b && j >= e ) return cur -> mn;
        Propagate( cur , b , e );
        int mid = ( b + e ) >> 1;
        if( j <= mid ) return QueryMIN( cur -> l , b , mid , i , j );
        else if( mid < i ) QueryMIN( cur -> r , mid + 1 , e , i , j );
        else return min( QueryMIN( cur -> l , b , mid , i , j ) ,
                         QueryMIN( cur -> r , mid + 1 , e , i , j ) );
}

int main( int argc , char const *argv[] ) {
        scanf("%d",&n);
        root = new Node();
        for( int i = 1; i <= n; i++ ) {
                scanf("%d %d",&l[0][i],&l[1][i]);
        }
        for( int i = 1; i <= n; i++ ) {
                Update( root , 1 , inf , l[0][i]+1 , l[1][i]+1 , +1 );
        }
        for( int i = 1; i <= n; i++ ) {
                Update( root , 1 , inf , l[0][i]+1 , l[1][i]+1 , -1 );
                int mn = QueryMIN( root , 1 , inf , l[0][i]+1 , l[1][i]+1 );
                if( mn >= 1 ) return printf("%d\n",i),0;
                Update( root , 1 , inf , l[0][i]+1 , l[1][i]+1 , +1 );
        }
        printf("-1\n");
        return 0;
}












