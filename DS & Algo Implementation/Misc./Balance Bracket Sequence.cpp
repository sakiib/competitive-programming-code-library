#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long uLL;
typedef long long int LL;
const int N = 1e5 + 5;
const int inf = 1e9;
const LL INF = 1e18;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int MOD = 1000000007;
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(args...) { dbg,args; cerr<<"\n"; }
struct debugger{
template<typename T>debugger& operator,(const T& v){cerr<<v<<" ";return *this;}}dbg;
#define endl "\n"
#define Fix( x ) setprecision( x ) << fixed
#define mem( a , x ) memset( a , x , sizeof( a ) )
#define sz( V ) (int)V.size( )
#define all( V ) V.begin( ),V.end( )
#define Unique( V ) sort( all( V ) ), V.erase( unique( all( V ) ), V.end() )

bool balanced( string s ) {
        stack <char> S;
        for( int i = 0; i < s.size(); i++ ) {
                if( s[i] == '(' ) S.push( '(' );
                else {
                        if( S.empty() ) return false;
                        if( S.top() == '(' ) S.pop();
                        else S.push( ')' );
                }
        }
        return ( S.empty() ? true : false );
}
int main( int argc , char const *argv[] ) {
        string s;
        cin >> s;
        if( balanced( s ) ) cout << "Balanced" << endl;
        else cout << "NOT Balanced" << endl;
        return 0;
}





