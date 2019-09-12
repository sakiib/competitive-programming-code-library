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

const int Base = 31;

LL Pow[ N ];

void GeneratePower( ) {
    Pow[0] = 1;
    for( int i = 1; i < N; i++ ) Pow[i] = Pow[i-1]*Base;
}
int main( int argc , char const *argv[] ) {

    GeneratePower( );

    string str;
    while( cin >> str ) {
       LL HashF = 0 , HashB = 0;
       int len = str.size( );
       int pos = len;

       for( int i = len-1; i >= 0; i-- ) {
          HashF = HashF*Base+str[i];
          HashB += Pow[len-i-1]*str[i];

          if( HashF == HashB ) pos = i;
          cout << i << " " << len-i-1 << " " << i << endl;
          cout << HashF << " " << HashB << endl;
       }
       cout << str;
       for( int i = pos-1; i >= 0; i-- ) cout << str[i];
       cout << endl;
    }
    return 0;
}




