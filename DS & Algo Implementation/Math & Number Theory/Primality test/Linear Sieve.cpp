#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(V) V.begin(), V.end()
#define Unique(V) sort(all(V)), V.erase(unique(all(V)), V.end())
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long int LL;
const int N = 1e5 + 5;

vector <int> prime;
bool is_composite[ N ];

void sieve( int n ) {
        fill( is_composite, is_composite + n, false );
        for( int i = 2; i <= n; ++i ) {
            if( !is_composite[i] ) prime.push_back( i );
            for( int j = 0; j < prime.size () && i * prime[j] <= n; ++j ) {
                is_composite[i * prime[j]] = true;
                if( i%prime[j] == 0 ) break;
            }
        }
        is_composite[0] = is_composite[1] = true;
}
int main( ) {
        //FIO;
        #ifdef OFFLINE
            //freopen( "input.txt" , "r" , stdin );
        #endif // OFFLINE
        sieve( 100000 );
        for( auto x : prime ) printf("%d ",x);
        return 0;
}






