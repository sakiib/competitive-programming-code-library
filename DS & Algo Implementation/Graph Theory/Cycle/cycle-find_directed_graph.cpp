#include <bits/stdc++.h>
using namespace std;

int color[ N ];
bool cycle = false;

void iscycle( int s ) {
    if( color[s] == 2 ) return;
    if( color[s] == 1 ) {
        cycle = true;
        return;
    }
    color[s] = 1;
    for( auto x : graph[s] ) iscycle( x );
    color[s] = 2;
}
int main( int argc, char const *argv[] ) {
    ios_base::sync_with_stdio(0); cin.tie(0);

    memset( color , 0 , sizeof(color) );
    return 0;
}








