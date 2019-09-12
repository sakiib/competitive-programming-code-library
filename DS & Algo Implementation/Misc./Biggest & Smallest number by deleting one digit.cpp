#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
typedef pair < int , int > ii;
const int inf = 1e9;
const LL INF = 1e18;
const int N = 1e5 + 5;
const int mod = 1000000007;
const double eps = 1e-8;
const double pi = acos( -1.0 );

/**
If we were asked to find the smallest number by deleting
only one number , we will find the first digit which is
greater than the digit to the right of it and delete it,
or delete the right most digit if there is no such digit
*/



int main( int argc , char const *argv[] ) {
        ios_base :: sync_with_stdio(false); cin.tie(NULL);
        string num;
        cin >> num;

        string n = num;
        /// smallest
        bool f = false;
        for( int i = 0; i < num.size()-1; i++ ) {
                if( num[i] > num[i+1] ) {
                        num.erase( num.begin()+i );
                        f = true;
                        break;
                }
        }
        if( !f ) num.erase( num.begin() + num.size() - 1 );
        cout <<"Smallest : "<< num << endl;


        for( int i = 0; i < n.size()-1; i++ ) {
                if( n[i] < n[i+1] ) {
                        n.erase( n.begin()+i );
                        f = true;
                        break;
                }
        }
        if( !f ) n.erase( n.begin() + 0 );
        cout <<"biggest : "<< n << endl;
        return 0;
}






