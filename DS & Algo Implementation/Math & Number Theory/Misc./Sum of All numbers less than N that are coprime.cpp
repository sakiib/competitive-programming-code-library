#include <bits/stdc++.h>
using namespace std;

/**
 problem : Sum of all numbers less than N , that are coprime with N
 N = 10 , [ 1 , 3 , 7 , 9] , sum = 20
 formula : phi(n) * n / 2;
 for proof & more : see forthright48 blog

 phi( n )  = n * all( ( pi - 1 )/pi ) , pi are the primefactors.
 phi( n ) = phi( a ) * phi( b )  , if a , b are the primefactors of n

 */

const int N = 1e5 + 5;
int n;

int PHI[ N ];
bool mark[ N ];

void SievePhi( int sz ) {
        for( int i = 1; i <= sz; i++ ) PHI[i] = i;
        PHI[1] = 1 , mark[1] = true;
        for( int i = 2; i <= sz; i++ ) {
                if( !mark[i] ) {
                        for( int j = i; j <= sz; j +=i ) {
                                mark[j] = true , PHI[j] = PHI[j]/i*(i-1);
                        }
                }
        }
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( NULL );
        SievePhi( 100 );
        cin >> n;
        cout << "ans : "<< ( PHI[n] * n ) / 2 << endl;
        return 0;
}










