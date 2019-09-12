#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef pair <int,int> pii;
typedef pair <long long,long long> pll;
const int MOD = 1e9 + 7;
const double EPS = 1e-8;
const int N = 1e5 + 5;
const int inf = 1e9;
const long long INF = 1e18;

int gaussian( vector < vector<double> > &a, vector<double> &ans ) {
        int n = (int) a.size();
        int m = (int) a[0].size() - 1;
        vector<int> where ( m , -1 );
        for ( int col = 0, row = 0; col < m && row < n; ++col ) {
            int sel = row;
            for ( int i = row; i < n; ++i )
                if (abs (a[i][col]) > abs (a[sel][col])) sel = i;
            if (abs (a[sel][col]) < EPS) continue;
            for ( int i = col; i <= m; ++i ) swap (a[sel][i], a[row][i]);
            where[col] = row;
            for ( int i = 0; i < n; ++i )
                if (i != row) {
                    double c = a[i][col] / a[row][col];
                    for ( int j = col; j <= m; ++j ) a[i][j] -= a[row][j] * c;
                }
                ++row;
        }
        ans.assign ( m , 0 );
        for ( int i = 0; i < m; ++i )
            if (where[i] != -1) ans[i] = a[where[i]][m] / a[where[i]][i];
        for ( int i = 0; i < n; ++i ) {
            double sum = 0;
            for ( int j = 0; j < m; ++j ) sum += ans[j] * a[i][j];
            if (abs (sum - a[i][m]) > EPS) return 0;
        }
        for ( int i = 0; i < m; ++i ) if ( where[i] == -1 ) return inf;
        return 1;
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( nullptr );
        #ifdef forthright48
            freopen( "input.txt" , "r" , stdin );
        #endif // forthright48
        int t;
        cin >> t;
        while( t-- ) {
                int n , m;
                cin >> m >> n;
                vector < vector <double> > temp;
                for( int i = 1; i <= m; i++ ) {
                        vector <double> V;
                        for( int j = 0; j <= n; j++ ) {
                                double x;
                                cin >> x;
                                V.push_back( x );
                        }
                        temp.push_back( V );
                }
                vector <double> res;
                int ans = gaussian( temp , res );
                if( ans == 1 ) cout << 1 << endl;
                else cout << 0 <<endl;
        }
        return 0;
}


