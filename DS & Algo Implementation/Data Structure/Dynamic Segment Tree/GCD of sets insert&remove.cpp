#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
const int inf = 1e9;

struct Node {
        Node *l , *r;
        LL gcd;
        int cnt;
        Node( ) {
                l = NULL , r = NULL , gcd = 0 , cnt = 0;
        }
        void Merge( int b , int e ) {
                gcd = 0;
                cnt = 0;
                if( l ) gcd = __gcd( gcd , l -> gcd ) , cnt += l -> cnt;
                if( r ) gcd = __gcd( gcd , r -> gcd ) , cnt += r -> cnt;
        }
} *root;

typedef Node* pnode;

void add( pnode &cur , int b , int e , int pos , int val ) {
        if( pos > e || pos < b || b > e ) return;
        if( !cur ) cur = new Node();
        if( b == e && b == pos ) {
                cur -> gcd = val;
                cur -> cnt++;
                return;
        }
        int m = ( b + e ) >> 1;
        add( cur -> l , b , m , pos , val );
        add( cur -> r , m + 1 , e , pos , val );
        cur -> Merge( b , e );
}
void rem( pnode &cur , int b , int e , int pos , int val ) {
        if( pos > e || pos < b || b > e ) return;
        if( !cur ) cur = new Node();
        if( b == e && b == pos ) {
                cur -> cnt--;
                if( cur -> cnt == 0 ) cur -> gcd = 0;
                return;
        }
        int m = ( b + e ) >> 1;
        rem( cur -> l , b , m , pos , val );
        rem( cur -> r , m + 1 , e , pos , val );
        cur -> Merge( b , e );
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( NULL );
        root = NULL;
        int q;
        cin >> q;
        while( q-- ) {
                string s;
                int val;
                cin >> s >> val;
                if( s[0] == '+' ) {
                         add( root , 1 , inf , val , val );
                         cout << ( root -> gcd == 0 ? 1 : root -> gcd ) << endl;
                }
                else {
                        rem( root , 1 , inf , val , val );
                        cout << ( root -> gcd == 0 ? 1 : root -> gcd ) << endl;
                }
        }
        return 0;
}










