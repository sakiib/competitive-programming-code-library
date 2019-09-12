#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
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

struct Node {
        Node *l , *r;
        LL sum;
        Node ( ) : l( nullptr ) , r( nullptr ) , sum( 0 ) {}
        Node( Node *l , Node *r , LL sum ) : l( l ) , r( r ) , sum( sum ) {}
        void Merge( LL b , LL e ) {
                sum = 0;
                LL mid = ( b + e ) >> 1;
                if( l ) sum += l -> sum;
                if( r ) sum += r -> sum;
        }
} *root;

typedef Node* pNode;

void Update( pNode &cur , LL b , LL e , LL pos , LL val ) {
        if( pos > e || pos < b || b > e ) return;
        if( !cur ) cur = new Node( );
        if( b == e && b == pos ) {
                cur -> sum ++;
                return;
        }
        LL mid = ( b + e ) >> 1;
        if( pos <= mid ) Update( cur -> l , b , mid , pos , val );
        else Update( cur -> r , mid + 1 , e , pos , val );
        cur -> Merge( b , e );
}
LL Query( pNode &cur , LL b , LL e , LL i , LL j ) {
        if( i > e || j < b || b > e ) return 0;
        if( !cur ) return 0;
        if( i <= b && j >= e ) return cur -> sum;
        LL mid = ( b + e ) >> 1;
        if( j <= mid ) return Query( cur -> l , b , mid , i , j );
        else if( mid < i ) return Query( cur -> r , mid + 1 , e , i , j );
        else return Query( cur -> l , b , mid , i , j ) + Query( cur -> r , mid + 1 , e , i , j );
}

LL n , k , A , B;

LL solve( LL l , LL r ) {
        if( l > r ) return 0;
        if( Query( root , 1 , ( 1LL << n ) , l , r ) == 0 ) return A;
        if( ( r - l + 1 ) <= 1 ) {
               LL cnt = Query( root , 1 , ( 1LL << n ) , l , r );
               return cnt == 0 ? A : B * cnt * ( r - l + 1 );
        }
        LL mn = INF;
        LL mid = ( l + r ) >> 1;
        mn = min( mn , solve( l , mid ) + solve( mid + 1 , r ) );
        LL cnt = Query( root , 1 , ( 1LL << n ) , l , r );
        mn = min( mn , cnt == 0 ? A : B * cnt  *( r - l + 1 ) );
        return mn;
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( nullptr );
        cin >> n >> k >> A >> B;
        root = NULL;
        for( int i = 1; i <= k; i++ ) {
                LL pos;
                cin >> pos;
                Update( root , 1 , ( 1LL << n ) , pos , +1 );
        }
        cout << solve( 1 , ( 1LL << n ) ) << endl;
        return 0;
}












