#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long uLL;
typedef long long int LL;
typedef pair <int,int> pii;
typedef pair <int,pii> piii;
typedef pair <long long,long long> pll;
typedef pair <long long,pll> plll;
const int N = 1e3 + 5;
const int inf = 1e9;
const long long INF = 1e18;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int MOD = 1000000007;

/**
Given 3 Matix of NxN
we need to check if AxB = C better than N^3
probabilistic solution
*/

int n;

struct matrix {
        LL m[ N ][ N ];
};

matrix A , B , C;
LL x[ N ] , y[ N ];

matrix multiply( matrix x , LL *a ) {
        matrix ans;
        for( int i = 1; i <= n; i++ ) {
                ans.m[1][i] = 0;
                for( int j = 1; j <= n; j++ ) {
                        ans.m[1][i] += ( a[j]%MOD * x.m[j][i]%MOD )%MOD , ans.m[1][i] %= MOD;
                }
        }
        return ans;
}
bool Solve( ) {
        for( int i = 1; i <= n; i++ ) x[i] = rand()%MOD;
        matrix nw = multiply( A , x );
        for( int i = 1; i <= n; i++ ) y[i] = nw.m[1][i];
        nw = multiply( B , y );
        matrix temp = multiply( C , x );
        for( int i = 1; i <= n; i++ ) if( nw.m[1][i] != temp.m[1][i] ) return false;
        return true;
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( NULL );
        cin >> n;
        for( int i = 1; i <= n; i++ ) {
                for( int j = 1; j <= n; j++ ) {
                        cin >> A.m[i][j];
                }
        }
        for( int i = 1; i <= n; i++ ) {
                for( int j = 1; j <= n; j++ ) {
                        cin >> B.m[i][j];
                }
        }
        for( int i = 1; i <= n; i++ ) {
                for( int j = 1; j <= n; j++ ) {
                        cin >> C.m[i][j];
                }
        }
        if( Solve( ) ) cout << "YES" << endl;
        else cout << "NO" << endl;
        return 0;
}











