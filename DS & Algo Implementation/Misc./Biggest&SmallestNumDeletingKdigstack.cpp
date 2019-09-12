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

void solve_smallest( string s , int k ) {
        stack <char> st;
        for( int i = 0; i < s.size(); i++ ) {
                while( !st.empty() && k > 0 && s[i] < st.top() ) {
                        st.pop();
                        k--;
                }
                st.push( s[i] );
        }
        while( k-- ) st.pop();
        string ans = "";
        while( !st.empty() ) {
                ans += ( st.top() );
                st.pop();
        }
        reverse( ans.begin() , ans.end() );
        cout << ans << endl;

}
void solve_biggest( string s , int k ) {
        stack <char> st;
        for( int i = 0; i < s.size(); i++ ) {
                while( !st.empty() && k > 0 && s[i] > st.top() ) {
                        st.pop();
                        k--;
                }
                st.push( s[i] );
        }
        while( k-- ) st.pop();
        string ans = "";
        while( !st.empty() ) {
                ans += ( st.top() );
                st.pop();
        }
        reverse( ans.begin() , ans.end() );
        cout << ans << endl;
}
int main( int argc , char const *argv[] ) {
        ios_base :: sync_with_stdio(false); cin.tie(NULL);
        int t;
        cin >> t;
        while( t-- ) {
                string s;
                int k;
                cin >> s >> k;
                solve_smallest( s , k );
                solve_biggest( s , k );
        }
        return 0;
}






