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
const int N = 5e5 + 5;

pair <int,int> p[ N ];
multiset <int> A , B , C , D;

int main( ) {
        IO;
        #ifdef LOCAL
            freopen( "input.txt" , "r" , stdin );
        #endif // LOCAL
        int q;
        cin >> q;
        int t = 0 , answer = 0;
        while( q-- ) {
                string op;
                cin >> op;
                if( op[0] == '+' ) {
                        int x , y;
                        cin >> x >> y;
                        x ^= answer;
                        y ^= answer;
                        p[t++] = make_pair( x , y );
                        A.insert( + x + y );
                        B.insert( - x + y );
                        C.insert( - x - y );
                        D.insert( + x - y );
                }
                if( op[0] == '-' ) {
                        int n;
                        cin >> n;
                        n ^= answer;
                        --n;
                        pair <int,int> last = p[n];
                        int x = last.first;
                        int y = last.second;
                        A.erase( A.find( + x + y ) );
                        B.erase( B.find( - x + y ) );
                        C.erase( C.find( - x - y ) );
                        D.erase( D.find( + x - y ) );
                }
                if( op[0] == '?' ) {
                        int x , y;
                        cin >> x >> y;
                        x ^= answer;
                        y ^= answer;
                        int a1 = + x + y , b1 = - x + y , c1 = - x - y , d1 = + x - y;
                        auto it1 = A.end(); --it1;
                        auto it2 = B.end(); --it2;
                        auto it3 = C.end(); --it3;
                        auto it4 = D.end(); --it4;
                        int a2 = (*it1) , b2 = (*it2) , c2 = (*it3) , d2 = (*it4);
                        int X = a2 - a1 , Y = b2 - b1 , XX = c2 - c1 , YY = d2 - d1;
                        answer = max( X , max( Y , max( XX , YY ) ) );
                        cout << answer << endl;
                }
        }
        return 0;
}








