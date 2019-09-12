#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
typedef pair< int,int > ii;
typedef pair< int,ii > iii;
const int inf = 1e9;
const LL INF = 1e18;
const int N = 100005;
const int MOD = 1e9+7;
const double EPS = 1e-6;
const double PI = acos(-1.0);

const int sz = (int)(1e7+100);
const int Base = 31;

LL power[ sz ];

void GeneratePower( ) {
    power[0] = 1;
    for( int i = 1; i < sz; i++ ) power[i] = power[i-1]*Base;
}
int main( int argc, char const *argv[] ) {
    int t;
    cin >> t;
    GeneratePower( );
    for( int tc = 1; tc <= t; tc++ ) {
        string str;
        cin >> str;



        LL F = 0 , B = 0;
        for( int i = 0; i < str.size(); i++ ) F  += ( str[i] * power[i] );
        for( int i = str.size()-1 , j = 0; i >= 0; i-- , j++ ) B += ( str[j] * power[i] );



        printf("Case %d:\n",tc);
        int q;
        cin >> q;
        int len = str.size( );

        while( q-- ) {
            int k;
            string op , ch;
            cin >> op >> ch >> k;


            char c = ch[0];
            if( op[0] == 'L' ) {
                LL mul = power[k];
                F *= ( mul );
                for( int i = 0; i < k; i++ ) F += ( c*power[i] );
                for( int i = len; i < ( len+k ); i++ ) B += ( c*power[i] );
            }
            else {
                LL mul = power[k];
                for( int i = len; i < ( len+k); i++ ) F += ( c*power[i] );
                B *= ( mul );
                for( int i = 0; i < k; i++ ) B += ( c*power[i] );
            }


            if( F == B ) cout << "Yes\n";
            else cout << "No\n";

            len += k;
        }
    }
    return 0;
}

