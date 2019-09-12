#include <bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define all(V) V.begin(),V.end()
#define Unique(V) sort(all(V)),V.erase(unique(all(V)),V.end())
typedef long long int LL;
const int N = 2e5 + 5;

const int MOD[2] = { 1000000007, 1000000009 };
const int base[2] = { 43 , 37 };
const int invbase[2] = { 395348840 , 297297300 };
int invmod1[ N ] , invmod2[ N ];
int p1[ N ] , p2[ N ];

int q;
string txt;
int st[ N ] , en[ N ];

inline int add( int x , int y , int MOD ) {
        x = x + y;
        return x >= MOD ? x - MOD : x;
}
inline int sub( int x , int y , int MOD ) {
        x = x - y;
        return x < 0 ? x + MOD : x;
}
inline int mul( int x , int y , int MOD ) {
        return ( 1LL * x * y ) % MOD;
}
inline void gen_pow( ) {
        p1[0] = 1 , p2[0] = 1;
        invmod1[0] = 1 , invmod2[0] = 1;
        for( int i = 1; i < N; i++ ) {
                p1[i] = mul( p1[i-1] , base[0] , MOD[0] );
                invmod1[i] = mul( invmod1[i-1] , invbase[0] , MOD[0] );
                p2[i] = mul( p2[i-1] , base[1] , MOD[1] );
                invmod2[i] = mul( invmod2[i-1] , invbase[1] , MOD[1] );
        }
}
inline LL get_hash( string &s ) {
        int l = s.size();
        int x = 0 , y = 0;
        for( int i = 0; i < l; i++ ) {
                x = add( x , mul( p1[i] , s[i] , MOD[0] ) , MOD[0] );
                y = add( y , mul( p2[i] , s[i] , MOD[1] ) , MOD[1] );
        }
        return (1LL*x << 31 ) | (1LL*y);
}
struct string_double_hashing {
        static const int N = 2e5 + 5;
        int tlen , fh1[ N ] , fh2[ N ];
        inline void build_hash( ) {
                tlen = txt.size();
                for( int i = 0 , j = tlen - 1; i < tlen; i++ , j-- ) {
                        fh1[i] = mul( p1[i] , txt[i] , MOD[0] );
                        if( i ) fh1[i] = add( fh1[i] , fh1[i-1] , MOD[0] );
                        fh2[i] = mul( p2[i] , txt[i] , MOD[1] );
                        if( i ) fh2[i] = add( fh2[i] , fh2[i-1] , MOD[1] );
                }
        }
        inline LL get_fhash( int l , int r ) {
                if( l == 0 ) return (1LL*fh1[r] << 31)|(1LL*fh2[r]);
                int x = sub( fh1[r], fh1[l-1], MOD[0] );
                x = mul( x, invmod1[l], MOD[0] );
                int y = sub( fh2[r], fh2[l-1], MOD[1] );
                y = mul( y, invmod2[l], MOD[1] ); return ( 1LL*x << 31LL )|(1LL*y);
        }
} H;

int main( ) {
        IO;
        #ifdef LOCAL
            //freopen( "input.txt" , "r" , stdin );
        #endif // LOCAL
        gen_pow();
        cin >> txt;
        int tlen = txt.size();
        H.build_hash();
        cin >> q;
        map < int, vector <string> > M;
        for( int i = 1; i <= q; i++ ) {
                string s;
                cin >> s;
                int l = s.size();
                M[l].push_back( s );
        }
        for( auto x : M ) {
                int l = x.first;
                map <LL,int> cnt;
                for( auto it : x.second ) cnt[ get_hash( it ) ]++;
                for( int i = 0; i + l - 1 <= tlen; i++ ) {
                        LL h = H.get_fhash( i , i + l - 1 );
                        st[i] += cnt[h];
                        en[i + l - 1] += cnt[h];
                }
        }
        LL ans = 0;
        for( int i = 0; i < tlen; i++ ) ans += 1LL * en[i] * st[i+1];
        cout << ans << endl;
        return 0;
}










