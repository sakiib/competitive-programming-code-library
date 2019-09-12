#include <bits/stdc++.h>
using namespace std;

int n , m;

vector <int> prefix_function( vector <int> v ) {
        int n = (int)v.size();
        vector <int> pi( n );
        for ( int i = 1; i < n; i++ ) {
                int j = pi[i-1];
                while ( j > 0 && v[i] != v[j] ) j = pi[j-1];
                if ( v[i] == v[j] ) j++;
                pi[i] = j;
        }
        return pi;
}
vector <int> find_occurences( vector<int> &text , vector<int> &pattern ) {
        vector <int> v = pattern;
        v.push_back( -1 );
        for( auto &it : text ) v.push_back( it );
        int sz1 = text.size() , sz2 = pattern.size();
        vector <int> lps = prefix_function( v );
        vector <int> store;
        for( int i = sz2 + 1; i <= sz1 + sz2; i++ ) {
                if( lps[i] == sz2 ) store.push_back( i - 2 * sz2 );
        }
        return store;
}
int main( int argc , char const *argv[] ) {
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
                scanf("%d %d",&n,&m);
                vector <int> A , B;
                int num;
                for( int i = 1; i <= n; i++ ) scanf("%d",&num) , A.push_back( num );
                for( int i = 1; i <= m; i++ ) scanf("%d",&num) , B.push_back( num );
                vector <int> V = find_occurences( A , B );
                if( V.size() == 0 ) printf("-1\n");
                else printf("%d\n",V[0]+1);
                //for( auto x : V ) cout << x << " "; cout << endl;
        }
        return 0;
}















