#include <bits/stdc++.h>
using namespace std;

struct Hashing {
        typedef long long LL;
        static const int N = 1e5 + 5;
        LL hash1[ N ] , hash2[ N ] , inv1[ N ] , inv2[ N ];
        LL mod1 = 1000000097 , mod2 = 1000000009;
        LL multiplier1 = 43, multiplier2 = 31;
        LL invMultiplier1 = 441860508 , invMultiplier2 = 838709685;
        int n;
        void buildHash( string s ) {
                n = s.size();
                inv1[0] = inv2[0] = 1;
                LL p1 = 1 , p2 = 1;
                for( int i = 0; i < n; i++ ) {
                        hash1[i + 1] = ( hash1[i] + s[i] * p1 ) % mod1;
                        p1 = ( p1 * multiplier1 ) % mod1;
                        inv1[i + 1] = inv1[i] * invMultiplier1 % mod1;
                        hash2[i + 1] = ( hash2[i] + s[i] * p2 ) % mod2;
                        p2 = ( p2 * multiplier2 ) % mod2;
                        inv2[i + 1] = inv2[i] * invMultiplier2 % mod2;
                }
        }
        LL getHash( int i, int j ) { //0-based forward hash
                return getHash_2( i, j - i + 1);
        }

        LL getHash_2( int i, int len ) { //i is 0  based indexed
                return (((hash1[i + len] - hash1[i] + mod1) * inv1[i] % mod1) << 32)
                        + (hash2[i + len] - hash2[i] + mod2) * inv2[i] % mod2;
        }
        LL revHash( int i, int j ){ ////0-based reverse hash
                return getHash( n - j - 1, n - i - 1 );
        }
} H;

int main( int argc , char const *argv[] ) {
        string s = "xyabaxy";
        H.buildHash( s );
        cout << H.getHash( 2 , 4 ) << endl;
        cout << H.revHash( 2 , 4 ) << endl;
        cout << H.revHash( 5 , 6 ) << endl;
        return 0;
}















