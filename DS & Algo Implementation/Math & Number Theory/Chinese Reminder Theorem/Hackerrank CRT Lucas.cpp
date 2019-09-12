#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
typedef pair < int , int > ii;
const int inf = 1e9;
const LL INF = 1e18;
const int N = 1000;
const double eps = 1e-8;
const double pi = acos( -1.0 );

LL nCr( int n , int r , LL mod ) {
        vector <LL> dp( r+5 , 0 );
        dp[0] = 1;
        for( int i = 1; i <= n; i++ ) {
                for( int j = min( i , r ); j > 0; j-- ) {
                        dp[j] = ( dp[j] + dp[j-1] )%mod;
                }
        }
        return dp[r];
}
LL Lucas( int n , int r , LL mod ) {
        if( r == 0 ) return 1;
        return (Lucas( n/mod , r/mod , mod )%mod * nCr( n%mod , r%mod , mod )%mod)%mod;
}
vector <LL> prime;
vector <bool> isprime( N , true );
void sieve( ) {
        isprime[0] = isprime[1] = false;
        prime.push_back( 2 );
        for( int i = 4; i <= N; i +=2 ) isprime[i] = false;
        int sq = sqrt( N );
        for( int i = 3; i <= sq; i += 2 ) {
            if( isprime[i] ) {
                for( int j = i*i; j <= N; j += 2*i ) {
                    isprime[j] = false;
                }
            }
        }
        for( int i = 3; i <= N; i += 2 ) {
            if( isprime[i] ) prime.push_back( i );
        }
}
vector <LL> PrimeFact( LL m ) {
        vector <LL> ret;
        LL sq = sqrt( m );
        for( int i = 0; i < prime.size() && prime[i] <= sq; i++ ) {
                if( m%prime[i] == 0 ) m /= prime[i] , ret.push_back( prime[i] ) , sq = sqrt( m );
        }
        if( m > 1 ) ret.push_back( m );
        return ret;
}
LL ExtGCD( LL a , LL b , LL &p , LL &q ) {
        if( b == 0 ) { p = 1 , q = 0; return a; }
        LL x1 , y1 , gcd = ExtGCD( b , a % b , x1 , y1 );
        p = y1;
        q = x1-(a / b)*y1;
        return gcd;
}
LL CRT( vector <LL> A , vector <LL> M ) {
       if( A.size() != M.size() ) return -1;
       LL a1 = A[0] , m1 = M[0];
       int l = A.size();
       for( int i = 1; i < l; i++ ) {
                LL a2 = A[i] , m2 = M[i];
                LL p , q;
                ExtGCD( m1 , m2 , p , q );
                LL x = ( (a1*m2*q)%(m1*m2) + (a2*m1*p)%(m1*m2) ) % ( m1*m2 );
                a1 = x , m1 = m1*m2;
       }
       if( a1 < 0 ) a1 += m1;
       return a1;
}
int main( int argc , char const *argv[] ) {
        ios_base :: sync_with_stdio(false); cin.tie(NULL);
        sieve( );
        int t;
        cin >> t;
        while( t-- ) {
                LL n , r , m;
                cin >> n >> r >> m;
                if( m == 1 ) {
                        cout << 0 << endl;
                        continue;
                }
                vector <LL> M = PrimeFact( m );
                vector <LL> A;
                for( auto x : M ) A.push_back( Lucas( n , r , x ) );
                cout << CRT( A , M ) << endl;
        }
        return 0;
}






