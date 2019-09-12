#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 1e5 + 5;

int n , k;
int a[ N ];

struct Node {
        int cnt , endMark;
        Node *Next[ 27 ];
        Node( ) {
                cnt = 0 , endMark = 0;
                for( int i = 1; i <= 26; i++ ) Next[i] = NULL;
        }
} *root;

void Delete( Node* cur ) {
        for( int i = 1; i <= 26; i++ ) {
                if( cur -> Next[i] ) Delete( cur -> Next[i] );
        }
        delete( cur );
}
int GetID( char ch ) {
        return ( ch - 'A' + 1 );
}
void Insert( string s ) {
        Node *cur = root;
        int len = s.size();
        for( int i = 0; i < len; i++ ) {
                int id = GetID( s[i] );
                if( cur -> Next[id] == NULL ) cur -> Next[id] = new Node();
                cur = cur -> Next[id];
                cur -> cnt++;
        }
        cur -> endMark ++;
}
int GetAns( string s) {
        int len = s.size();
        int ans = 0;
        Node *cur = root;
        for( int i = 0; i < len; i++ ) {
                int id = GetID( s[i] );
                if( cur -> Next[id] == NULL ) break;
                if( cur -> Next[id] -> cnt > 0 ) {
                        ans++;
                        cur -> Next[id] -> cnt--;
                }
                cur = cur -> Next[id];
        }
        return ans;
}
int main( int argc , char const *argv[] ) {
        ios_base :: sync_with_stdio( false ); cin.tie( NULL );
        int n;
        while( cin >> n ) {
                if( n == -1 ) break;
                root = new Node( );
                string s;
                for( int i = 1; i <= n; i++ ) cin >> s , Insert( s );
                int ans = 0;
                for( int i = 1; i <= n; i++ ) {
                        cin >> s;
                        ans += GetAns( s );
                }
                cout << ans << endl;
                Delete( root );
        }
        return 0;
}











