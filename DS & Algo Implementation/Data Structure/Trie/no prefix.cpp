#include <bits/stdc++.h>
using namespace std;

#define trace(...) __f( #__VA_ARGS__ , __VA_ARGS__ )
template <typename Arg1>
void __f( const char* name , Arg1&& arg1 ) {
        cerr << name << " : " << arg1 << "\n";
}
template <typename Arg1, typename... Args>
void __f( const char* na , Arg1&& arg1 , Args&&... args ) {
        const char* c = strchr( na + 1 , ',' );
        cerr.write( na , c - na ) << " : " << arg1 << " , ";
        __f( c + 1 , args... );
}
#define endl "\n"
#define all(V) V.begin(),V.end()
#define Unique(V) sort(all(V)),V.erase(unique(all(V)),V.end())
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int LL;
typedef pair <int,int> pii;
const int MOD = 1e9 + 7;
const int inf = 1e9;
const double EPS = 1e-9;
const double PI = acos(-1.0);
const long long INF = 1e18;
const int N = 1e5 + 5;

struct node {
        node* child[15];
        bool endmark;
        node(){
                endmark = false;
                for( int i = 0; i < 15; i++ ) child[i] = nullptr;
        }
} *root;

bool add( string &s ) {
        node* cur = root;
        for( int i = 0; i < s.size(); i++ ) {
                int id = s[i]-'a';
                if( cur -> child[id] == nullptr ) {
                        cur -> child[id] = new node();
                }
                else {
                        if( cur -> child[id] -> endmark ) return true;
                }
                cur = cur -> child[id];
        }
        if( cur -> endmark ) return true;
        cur -> endmark = true;
        for( char i = 'a'; i <= 'j'; i++ ) {
                int id = i-'a';
                if( cur -> child[id] != nullptr ) return true;
        }
        return false;
}
int main( ) {
        IO;
        #ifdef LOCAL
            //freopen( "input.txt" , "r" , stdin );
        #endif // LOCAL
        root = new node();
        int n;
        cin >> n;
        while( n-- ) {
                string s;
                cin >> s;
                bool have = add( s );
                if( have ) {
                        cout << "BAD SET" << endl;
                        cout << s << endl;
                        return 0;
                }
        }
        cout << "GOOD SET" << endl;
        return 0;
}








