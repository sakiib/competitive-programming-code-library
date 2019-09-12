#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long uLL;
typedef long long int LL;
typedef pair <int,int> pii;
typedef pair <int,pii> piii;
typedef pair <long long,long long> pll;
typedef pair <long long,pll> plll;
const int N = 700;
const int inf = 1e9;
const long long INF = 1e18;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int MOD = 1000000007;

const int Mod[ 2 ] = { 1000000007 , 1000000009 };
const int Base[ 2 ] = { 31 , 37 };
LL Pow[ N ][ 2 ];
LL HashF[ N ][ 2 ] , HashR[ N ][ 2 ];
int len;
string s , a;
int ls , la;

void BuildHash( ) {
        len = s.size();
        HashF[0][0] = 0 , HashR[len+1][0] = 0;
        HashF[0][1] = 0 , HashR[len+1][1] = 0;
        for( int i = 1; i <= len; i++ ) {
                    HashF[i][0] = ( HashF[i-1][0] * Base[0] + s[i-1] ) % Mod[0];
                    HashR[len-i+1][0] = ( HashR[len-i+2][0] * Base[0] + s[len-i] ) % Mod[0];
                    HashF[i][1] = ( HashF[i-1][1] * Base[1] + s[i-1] ) % Mod[1];
                    HashR[len-i+1][1] = ( HashR[len-i+2][1] * Base[1] + s[len-i] ) % Mod[1];
        }
}
pair <LL,LL> GetHash( string s ) {
        LL Hash1 = 0 , Hash2 = 0;
        len = s.size();
        for( int i = 1; i <= len; i++ ) {
                    Hash1 = ( Hash1 * Base[ 0 ] + s[ i-1 ] ) % Mod[ 0 ] , Hash1 %= Mod[ 0 ];
                    Hash2 = ( Hash2 * Base[ 1 ] + s[ i-1 ] ) % Mod[ 1 ] , Hash2 %= Mod[ 1 ];
        }
        return { Hash1 , Hash2 };
}
LL GetFHash( int l , int r ) {
        l ++ , r ++;
        if( l == 1 ) return ( HashF[ r ][ 0 ] << 31 ) | HashF[ r ][ 1 ];
        LL Hash1 = ( HashF[ r ][ 0 ] - HashF[ l-1 ][ 0 ] * Pow[ r-l+1 ][ 0 ] % Mod[ 0 ] );
        Hash1 = ( Hash1 + Mod[ 0 ] ) % Mod[ 0 ];
        LL Hash2 = ( HashF[ r ][ 1 ] - HashF[ l-1 ][ 1 ] * Pow[ r-l+1 ][ 1 ] % Mod[ 1 ] );
        Hash2 = ( Hash2 + Mod[ 1 ] ) % Mod[ 1 ];
        return ( Hash1 << 31 ) | Hash2;
}
LL GetBHash( int l , int r ) {
        l ++ , r ++;
        if( r == len ) return ( HashR[ l ][ 0 ] << 31 ) | HashR[ l ][ 1 ];
        LL Hash1 = ( HashR[ l ][ 0 ] - HashR[ r+1 ][ 0 ] * Pow[ r-l+1 ][ 0 ] % Mod[ 0 ] );
        Hash1 = ( Hash1 + Mod[ 0 ] ) % Mod[ 0 ];
        LL Hash2 = ( HashR[ l ][ 1 ] - HashR[ r+1 ][ 1 ] * Pow[ r-l+1 ][ 1 ] % Mod[ 1 ] );
        Hash2 = ( Hash2 + Mod[ 1 ] ) % Mod[ 1 ];
        return ( Hash1 << 31 ) | Hash2;
}
void genPower( ) {
        Pow[ 0 ][ 0 ] = Pow[ 0 ][ 1 ] = 1;
        for( int i = 1; i < N; i++ ) {
                    Pow[ i ][ 0 ] =  Pow[ i-1 ][ 0 ] * Base[ 0 ] % Mod[ 0 ];
                    Pow[ i ][ 1 ] =  Pow[ i-1 ][ 1 ] * Base[ 1 ] % Mod[ 1 ];
        }
}
bool ok( int l ) {
        unordered_map <LL,int> M;
        for( int i = 0; i + l - 1 < ls; i++ ) {
                LL Hash = GetFHash( i , i + l - 1 );
                if( M[Hash] == 0 ) M[Hash]++;
        }
        int got = 0;
        for( int i = ls; i + l - 1 < ls + la; i++ ) {
                LL Hash = GetFHash( i , i + l - 1 );
                if( M[Hash] == 1 ) return true;
        }
        return false;
}
int solve( ) {
        int lo = 0 , hi = min( ls , la ) , ret = 0;
        while( lo <= hi ) {
                int mid = ( lo + hi ) >> 1;
                if( ok( mid ) ) ret = mid , lo = mid + 1;
                else hi = mid - 1;
        }
        return ret;
}
void print( int l ) {
        unordered_map <LL,int> M;
        set <string> S;
        for( int i = 0; i + l - 1 < ls; i++ ) {
                LL Hash = GetFHash( i , i + l - 1 );
                if( M[Hash] == 0 ) M[Hash]++;
        }
        int got = 0;
        for( int i = ls; i + l - 1 < ls + la; i++ ) {
                LL Hash = GetFHash( i , i + l - 1 );
                if( M[Hash] == 1 ) {
                        S.insert( s.substr( i , l ) );
                }
        }
        for( auto x : S ) cout << x << endl;
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( NULL );
        genPower( );
        bool f = false;
        while( cin >> s >> a ) {
                ls = s.size();
                la = a.size();
                if( f ) cout << endl;
                f = true;
                s += a;
                BuildHash( );
                int mx = solve( );
                if( mx == 0 ) {
                        cout << "No common sequence." << endl;
                        continue;
                }
                print( mx );
        }
        return 0;
}











