#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
const int inf = (int)1e9;
const LL INF = (LL)1e18;
const int N = 100005;
const LL MOD = 1000000007;
const double EPS = 1e-7;
const double PI = acos( -1.0 );

const int sz = N;


struct NumberTheory {

    vector < bool > isprime;
    vector < int > prime;

    int NOD[ sz+10 ];
    int SOD[ sz+10 ];
    int mark[ sz+10 ];
    int PHI[ sz+10 ];

    inline void Sieve( int sz ) {
        isprime.assign( sz+10 , true );
        isprime[0] = isprime[1] = false;
        prime.push_back( 2 );
        int sq = sqrt( sz );
        for( int i = 4; i <= sz; i += 2 ) isprime[i] = false;
        for( int i = 3; i <= sq; i += 2 ) {
            if( isprime[i] ) {
                for( int j = i*i; j <= sz; j += 2*j ) {
                    isprime[j] = false;
                }
            }
        }
        for( int i = 3; i <= sz; i += 2 ) if( isprime[i] ) prime.push_back( i );
    }
    inline void PrimeFactorize( vector < int > &primefact , int n ) {
        int sq = sqrt( n );
        for( int i = 0; i < prime.size() && prime[i] <= sq; i++ ) {
            if( n%prime[i] == 0 ) {
                n /= prime[i];
                primefact.push_back( prime[i] );
                while( n%prime[i] == 0 ) n /= prime[i];
                sq = sqrt( n );
            }
        }
        if( n > 1 ) primefact.push_back( n );
    }
    inline bool IsPrime( int n ) {
        if( n < 2 ) return false;
        for( int i = 2; i*i <= n; i++ ) if( n%i == 0 ) return false;
        return true;
    }
    inline void GenNumofDivLoop( int sz ) {
        for( int i = 1; i <= sz; i++ ) {
            for( int j = i; j <= sz; j += i ) {
                NOD[j]++;
            }
        }
    }
    inline void GenerateSumofDivLoop( int sz ) {
        for( int i = 1; i <= sz; i++ ) {
            for( int j = i; j <= sz; j += i ) {
                SOD[j] += i;
            }
        }
    }
    inline LL ExtGCD( LL a , LL b , LL &x , LL &y ) {
        if( b == 0 ) { x = 1 , y = 0; return a; }
        LL x1 , y1 , gcd = ExtGCD( b , a % b , x1 , y1 );
        x = y1;
        y = x1-(a / b)*y1;
        return gcd;
    }
    inline LL BigMod ( LL b , LL p , LL mod ) {
        LL res = 1 % mod , x = b % mod;
        while ( p ) {
           if ( p & 1 ) res = ( res * x ) % mod;
           x = ( x * x ) % mod; p >>= 1;
        }
        return res%mod;
    }
    inline void SievePhi( int sz ) {
        for( int i = 1; i <= sz; i++ ) PHI[i] = i;
        PHI[1] = 1 ,mark[1] = 1;
        for( int i = 2; i <= sz; i++ ) {
            if( !mark[i] ) {
                for( LL j = i; j <= sz; j +=i ) {
                    mark[j]=1 , PHI[j] = PHI[j]/i*(i-1);
                }
            }
        }
    }
    inline LL ModInv( LL val , LL mod ) { return BigMod( val , mod-2 , mod ); }

    inline LL NumofDivisorusingsieve( LL x ) {
        LL sq = sqrt( x );
        LL ret = 1;
        for( int i = 0; i < prime.size() && prime[i] <= sq; i++ ) {
            if( x%prime[i] == 0 ) {
               LL p = 0;
               while( x%prime[i] == 0 ) x /= prime[i] , p++;
               sq = sqrt( x );
               p++;
               ret *= p;
           }
       }
       if( x != 1 ) ret *= 2;
       return ret;
     }

} nt;

int main( int argc , char const *argv[] ) {

    nt.Sieve( 100 );
    vector < int > primefact;

    return 0;
}


