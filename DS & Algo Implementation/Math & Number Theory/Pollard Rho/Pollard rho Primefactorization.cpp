#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
const int N = 1e5 + 5;
long double range = 1e18;

LL mulmod( LL a , LL b , LL c ) {
        LL x = 0 , y = a%c;
        while( b > 0 ) {
                if( b&1 ) x = ( x + y ) % c;
                y = ( y << 1 ) % c;
                b = b >> 1;
        }
        return x;
}
LL modulo( LL a , LL b , LL c ) {
        LL x = 1 , y = a % c;
        while( b > 0 ) {
                if( b&1 ) x = mulmod( x , y , c );
                y = mulmod( y , y , c );
                b = b >> 1;
        }
        return x;
}
bool miller( LL p , int iter ) {
        if( p < 2 ) return false;
        if( p == 2 ) return true;
        if( !( p&1 ) ) return false;
        LL s = p - 1 , a , temp , mod;
        while( !( s&1 ) ) s = s >> 1;
        for( int i = 0; i < iter; i++ ) {
                a = rand( ) % ( p - 1 ) + 1;
                temp = s;
                mod = modulo( a , temp , p );
                while( temp != ( p - 1) && mod != 1 && mod != ( p - 1 ) ) {
                        mod = mulmod( mod , mod , p );
                        temp = temp << 1;
                }
                if( mod != ( p - 1 ) && !( temp&1 ) ) return false;
        }
        return true;
}
LL randerson( ) {
        long double pseudo = ( long double )rand()/( long double )RAND_MAX;
        return ( long long ) ( round (( long double )range * pseudo ) ) + 1;
}
LL Calc( LL x , LL n , LL c ) {
        return ( mulmod( x , x , n ) + c )%n;
}
LL GCD( LL a , LL b ) {
        return !b ? a : GCD( b , a%b );
}
LL Pollard_rho( LL n ) {
        LL d = 1 , i = 1 , k = 1 , x = 2 , y = x , c;
        do {
                c = randerson()%n;
        } while( ( c == 0 ) || ( c + 2 )%n == 0 );
        while( d != n ) {
                if( i == k ) k *= 2LL , y = x , i = 0;
                x = Calc( x , n , c );
                i++;
                d = GCD( abs( y - x ) , n );
                if( d != 1 ) return d;
        }
}
vector <LL> GetPrimeFacts( LL n ) {
        vector <LL> ret;
        if( n == 1 ) return ret;
        if( miller( n , 5 ) ) {
                ret.push_back( n ); return ret;
        }
        LL d = Pollard_rho( n );
        ret = GetPrimeFacts( d );
        vector <LL> temp = GetPrimeFacts( n/d );
        for( int i = 0; i < temp.size(); i++ ) ret.push_back( temp[i] );
        return ret;
}
int main( int argc , char const *argv[] ) {
        LL n;
        scanf("%lld",&n);
        vector <LL> d = GetPrimeFacts( n );

        map <LL,LL> cnt;

        for( auto x : d ) cnt[x]++;
        for( auto x : cnt ) cout << x.first << " " << x.second << endl;
        return 0;
}






