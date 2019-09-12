#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
typedef pair < int , int > ii;
const int inf = 1e9;
const LL INF = 1e18;
const int N = 1e5 + 5;
const int mod = 1000000007;
const double eps = 1e-8;
const double pi = acos( -1.0 );
bool Check( int N , int pos )  { return (bool)( N & ( 1 << pos ) );}

const int mx = 30;

struct node {
        int cnt;
        node* child[2];
        int endmark;
        node(){
                cnt = 0;
                endmark = 0;
                child[0] = child[1] = nullptr;
        }
} *root;

void add( int val ) {
        node* cur = root;
        for( int i = mx; i >= 0; i-- ) {
                int id = Check( val , i );
                if( cur -> child[id] == nullptr ) {
                        cur -> child[id] = new node();
                }
                cur = cur -> child[id];
                cur -> cnt++;
        }
        cur -> endmark++;
}
void del( int val ) {
        node* cur = root;
        for( int i = mx; i >= 0; i-- ) {
                int id = Check( val , i );
                cur = cur -> child[id];
                cur -> cnt--;
        }
        cur -> endmark--;
}
int get_count( node* cur , int p , int l , int pos , int smaller ) {
        if( smaller ) return cur -> cnt;
        if( cur -> endmark ) return 0;
        int idp = Check( p , pos );
        int idl = Check( l , pos );
        int ret = 0;
        for( int i = 0; i <= 1; i++ ) {
              if( cur -> child[i] != nullptr && (idp^i) <= idl ) {
                    int chk = 0;
                    if( (idp^i) < idl ) chk = 1;
                    ret += get_count( cur -> child[i] , p , l , pos-1 , chk );
              }
        }
        return ret;
}
int main( int argc , char const *argv[] ) {
        root = new node();
        int q;
        scanf("%d",&q);
        for( int i = 1; i <= q; i++ ) {
                int op;
                scanf("%d",&op);
                if( op == 1 ) {
                        int val;
                        scanf("%d",&val);
                        add( val );
                }
                else if( op == 2 ) {
                        int val;
                        scanf("%d",&val);
                        del( val );
                }
                else {
                        int p , l;
                        scanf("%d %d",&p,&l);
                        printf("%d\n",get_count( root , p , l , mx , 0 ) );
                }
        }
        return 0;
}

