#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(V) V.begin(), V.end()
#define Unique(V) sort(all(V)), V.erase(unique(all(V)), V.end())
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long int LL;
const int N = 205;

const int MOD[] = { 1000000007 , 1000000009 };
const int base[] = { 43 , 37 };
const int invbase[] = { 395348840 , 297297300  };

int n;
char s[ N ][ N ];
int p[ N ][ 2 ] , invmod[ N ][ 2 ];
int hr[ N ][ N ][ 2 ] , rh[ N ][ N ][ 2 ];
int hc[ N ][ N ][ 2 ] , ch[ N ][ N ][ 2 ];

inline int add( int x , int y , int MOD ) {
        x += y;
        return x >= MOD ? x - MOD : x;
}
inline int sub( int x , int y , int MOD ) {
        x -= y;
        return x < 0 ? x + MOD : x;
}
inline int mul( int x , int y , int MOD ) {
        return ( 1LL * x * y ) % MOD;
}
inline void gen_pow( ) {
        p[0][0] = p[0][1] = invmod[0][0] = invmod[0][1] = 1;
        for( int i = 1; i < N; i++ ) {
                for( int id = 0; id < 2; id++ ) {
                        p[i][id] = mul( p[i-1][id] , base[id] , MOD[id] );
                        invmod[i][id] = mul( invmod[i-1][id] , invbase[id] , MOD[id] );
                }
        }
}
inline LL get_rfhash( int ro , int l , int r ) {
        if( l == 0 ) return (1LL*hr[ro][r][0] << 31)|(1LL*hr[ro][r][1]);
        int x = sub( hr[ro][r][0], hr[ro][l-1][0], MOD[0] ); x = mul( x, invmod[l][0], MOD[0] );
        int y = sub( hr[ro][r][1], hr[ro][l-1][1], MOD[1] ); y = mul( y, invmod[l][1], MOD[1] );
        return (1LL*x << 31LL)|(1LL*y);
}
inline LL get_rbhash( int ro , int l , int r ) {
        if( l == 0 ) {
                int x = rh[ro][r][0]; x = mul( x, invmod[n-r-1][0], MOD[0] );
                int y = rh[ro][r][1]; y = mul( y, invmod[n-r-1][1], MOD[1] );
                return (1LL*x << 31LL)|(1LL*y);
        }
        int x = sub( rh[ro][r][0], rh[ro][l-1][0], MOD[0] ); x = mul( x, invmod[n-r-1][0], MOD[0] );
        int y = sub( rh[ro][r][1], rh[ro][l-1][1], MOD[1] ); y = mul( y, invmod[n-r-1][1], MOD[1] );
        return (1LL*x << 31LL)|(1LL*y);
}
inline LL get_cfhash( int co , int l , int r ) {
        if( l == 0 ) return (1LL*ch[co][r][0] << 31)|(1LL*ch[co][r][1]);
        int x = sub( ch[co][r][0], ch[co][l-1][0], MOD[0] ); x = mul( x, invmod[l][0], MOD[0] );
        int y = sub( ch[co][r][1], ch[co][l-1][1], MOD[1] ); y = mul( y, invmod[l][1], MOD[1] );
        return (1LL*x << 31LL)|(1LL*y);
}
inline LL get_crhash( int co , int l , int r ) {
        if( l == 0 ) {
                int x = hc[co][r][0]; x = mul( x, invmod[n-r-1][0], MOD[0] );
                int y = hc[co][r][1]; y = mul( y, invmod[n-r-1][1], MOD[1] );
                return (1LL*x << 31LL)|(1LL*y);
        }
        int x = sub( hc[co][r][0], hc[co][l-1][0], MOD[0] ); x = mul( x, invmod[n-r-1][0], MOD[0] );
        int y = sub( hc[co][r][1], hc[co][l-1][1], MOD[1] ); y = mul( y, invmod[n-r-1][1], MOD[1] );
        return (1LL*x << 31LL)|(1LL*y);
}
inline bool ok( int len ) {
        if( len > n ) return false;
        for( int i = 0; i <= n - len; i++ ) {
                for( int j = 0; j <= n - len; j++ ) {
                        bool f1 = true;
                        for( int l = 0; l < len; l++ ) {
                                int x = i + l , y = j;
                                f1 &= ( get_rfhash( x , y , y + len - 1 ) == get_rbhash( x , y , y + len - 1 ) );
                        }
                        bool f2 = true;
                        for( int l = 0; l < len; l++ ) {
                                int x = i , y = j + l;
                                f2 &= ( get_cfhash( y , x , x + len - 1 ) == get_crhash( y , x , x + len - 1 ) );
                        }
                        if( f1 && f2 ) return true;
                }
        }
        return false;
}
int main( ) {
        //FIO;
        #ifdef OFFLINE
            freopen( "input.txt" , "r" , stdin );
        #endif // OFFLINE
        scanf("%d",&n);
        for( int i = 0; i < n; i++ ) scanf("%s",s[i]);
        gen_pow();
        for( int i = 0; i < n; i++ ) {
                for( int j = 0 , k = n - 1; j < n; j++ , k-- ) {
                        for( int id = 0; id < 2; id++ ) {
                                hr[i][j][id] = mul( p[j][id] , s[i][j] , MOD[id] );
                                if( j ) hr[i][j][id] = add( hr[i][j][id] , hr[i][j-1][id] , MOD[id] );
                                rh[i][j][id] = mul( p[k][id] , s[i][j] , MOD[id] );
                                if( j ) rh[i][j][id] = add( rh[i][j][id] , rh[i][j-1][id] , MOD[id] );
                        }
                }
        }
        for( int i = 0; i < n; i++ ) {
                for( int j = 0 , k = n - 1; j < n; j++ , k-- ) {
                        for( int id = 0; id < 2; id++ ) {
                                ch[i][j][id] = mul( p[j][id] , s[j][i] , MOD[id] );
                                if( j ) ch[i][j][id] = add( ch[i][j][id] , ch[i][j-1][id] , MOD[id] );
                                hc[i][j][id] = mul( p[k][id] , s[j][i] , MOD[id] );
                                if( j ) hc[i][j][id] = add( hc[i][j][id] , hc[i][j-1][id] , MOD[id] );
                        }
                }
        }
        vector <int> odd , even;
        for( int i = 1; i <= N; i += 2 ) odd.push_back( i );
        for( int i = 2; i <= N; i += 2 ) even.push_back( i );
        int lo = 0 , hi = odd.size() - 1;
        int mx1 = 0;
        while( lo <= hi ) {
                int mid = ( lo + hi ) >> 1;
                if( ok( odd[mid] ) ) mx1 = odd[mid] , lo = mid + 1;
                else hi = mid - 1;
        }
        lo = 0 , hi = even.size() - 1;
        int mx2 = 0;
        while( lo <= hi ) {
                int mid = ( lo + hi ) >> 1;
                if( ok( even[mid] ) ) mx2 = even[mid] , lo = mid + 1;
                else hi = mid - 1;
        }
        printf("%d\n",max( mx1,mx2));
        return 0;
}





