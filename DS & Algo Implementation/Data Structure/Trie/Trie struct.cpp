#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
const int inf = (int)1e9;
const LL INF = (LL)1e18;
const int N = 100005;
const LL MOD = 1000000007;
const double EPS = 1e-7;
const double PI = acos( -1.0 );

#define Check( N , p )         (!(((N)&((1LL)<<(p)))==(0)))

struct Trie {

    struct Node {
        int cnt , val;
        bool Endmark;
        Node* Next[ 26 ];
        Node* Child[ 2 ];
        Node ( ) {
            cnt = 0 , val = 0;
            Endmark = false;
            Child[0] = NULL , Child[1] = NULL;
            for( int i = 0; i < 26; i++ ) Next[i] = NULL;
        }
    } *Root;

    inline void Init( ) { Root = new Node( ); }

    inline void Delete( Node* cur ) {
        for( int i = 0; i < 26; i++ ) {
            if( cur -> Next[i] ) Delete( cur -> Next[i] );
        }
        delete( cur );
    }

    inline void InsertS( string str ) {
        Node* cur = Root;
        int len = str.size();
        for( int i = 0; i < len; i++ ) {
            int id = str[i]-'a';
            if( cur -> Next[id] == NULL ) cur -> Next[id] = new Node( );
            cur = cur -> Next[id];
        }
        cur -> cnt++;
        cur -> Endmark = true;
    }
    inline void InsertN( int num ) {
        Node* cur = Root;
        for( int i = 31; i >= 0; i-- ) {
            int id = Check( num , i );
            if( cur -> Child[id] == NULL ) cur -> Child[id] = new Node( );
            cur = cur -> Child[id];
            cur -> cnt++;
        }
        cur -> val = num;
    }
    inline bool SearchWord( string str ) {
        Node* cur = Root;
        int len = str.size();
        for( int i = 0; i < len; i++ ) {
            int id = str[i]-'a';
            if( cur -> Next[id] == NULL ) return false;
            cur = cur -> Next[id];
        }
        return ( cur -> Endmark );
    }
    inline void DelNum( int num ) {
        Node* cur = Root;
        for( int i = 31; i >= 0; i-- ) {
            int id = Check( num , i );
            cur = cur -> Child[id];
            cur -> cnt--;
        }
    }
    inline int OccurWord( string str ) {
        Node* cur = Root;
        int len = str.size();
        for( int i = 0; i < len; i++ ) {
            int id = str[i]-'a';
            if( cur -> Next[id] == NULL ) return 0;
            cur = cur -> Next[id];
        }
        return ( cur -> cnt );
    }
    inline int GetMinXor( int num ) {
        Node* cur = Root;
        for( int i = 31; i >= 0; i-- ) {
            int id = Check( num , i );
            if( cur -> Child[id] != NULL && cur -> Child[id] -> cnt > 0 ) {
            cur = cur -> Child[id];
            }
            else if( cur -> Child[1-id] != NULL ) {
            cur = cur -> Child[1-id];
            }
            cur -> cnt--;
        }
        return ( num^(cur -> val ) );
    }
    inline int GetMaxXor( int num ) {
        Node* cur = Root;
        for( int i = 31; i >= 0; i-- ) {
            int id = Check( num , i );
            if( cur -> Child[1-id] != NULL && cur -> Child[1-id] -> cnt > 0 ) {
            cur = cur -> Child[1-id];
            }
            else if( cur -> Child[id] != NULL ) {
            cur = cur -> Child[id];
            }
            cur -> cnt--;
        }
        return ( num^(cur -> val ) );
    }

};

Trie trie;

int main( int argc , char const *argv[] ) {

    trie.Init( );

    return 0;
}




