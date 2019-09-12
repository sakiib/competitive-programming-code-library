#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
typedef unsigned long long uLL;
typedef long long int LL;
typedef pair <int,int> pii;
typedef pair <int,pii> piii;
typedef pair <long long,long long> pll;
typedef pair <long long,pll> plll;
const int N = 1e5 + 5;
const int inf = 1e9;
const long long INF = 1e18;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int MOD = 1000000007;

LL calc( LL x ) {
        /// calculate something..
}
LL TernarySearchMIN( LL l , LL r ) {
        LL lo = l , hi = r , ret = INF;
        int iteration = 300;
        while( iteration -- ) {
                LL midL = ( 2 * lo + hi )/3 , midR = ( lo + 2 * hi )/3;
                LL valL = calc( midL ) , valR = calc( midR );
                if( valL < valR ) hi = midR;
                else lo = midL;
        }
        for( LL i = lo; i <= hi; i++ ) ret = min( ret , calc( i ) );
        return ret;
}
LL TernarySearchMAX( LL l , LL r ) {
        LL lo = l , hi = r , ret = -INF;
        int iteration = 300;
        while( iteration -- ) {
                LL midL = ( 2 * lo + hi )/3 , midR = ( lo + 2 * hi )/3;
                double valL = calc( midL ) , valR = calc( midR );
                if( valL > valR ) hi = midR;
                else lo = midL;
        }
        for( LL i = lo; i <= hi; i++ ) ret = max( ret , calc( i ) );
        return ret;
}
double TernarySearchMIN( double l , double r ) {
        double lo = l , hi = r , ret = INF;
        int iteration = 300;
        while( iteration -- && hi - lo > EPS ) {
                double midL = ( 2.0 * lo + hi )/3.0 , midR = ( lo + 2.0 * hi )/3.0;
                double valL = calc( midL ) , valR = calc( midR );
                if( valL < valR ) hi = midR;
                else lo = midL;
        }
        ret = min( calc( lo ) , calc( hi ) );
        return ret;
}
double TernarySearchMAX( double l , double r ) {
        double lo = l , hi = r , ret = -INF;
        int iteration = 300;
        while( iteration -- && hi - lo > EPS ) {
                double midL = ( 2.0 * lo + hi )/3.0 , midR = ( lo + 2.0 * hi )/3.0;
                double valL = calc( midL ) , valR = calc( midR );
                if( valL > valR ) hi = midR;
                else lo = midL;
        }
        ret = max( calc( lo ) , calc( hi ) );
        return ret;
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( nullptr );

        return 0;
}










