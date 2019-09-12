#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
const int inf = (int)1e9;
const LL INF = (LL)2e18;
const int N = 100005;
const int mod = 1000000007;
const double eps = 1e-8;
const double pi = acos( -1.0 );

int ara[ N ];
int BLOCK[ 350 ];
int n;
int block_size;

int Block_ID( int id ) {
    int pos = ( (id+block_size-1)/block_size );
    return pos;
}
void setblock( int id , int num ) {
    int pos = Block_ID( id );
    //cout << id << " jabe ( " << pos << " ) number block e " << endl;
    BLOCK[pos] += num;
}
int getsum( int l , int r ) {
    int block_a = Block_ID( l );
    int block_b = Block_ID( r );
    //cout << block_a << " " << block_b << endl;
    if( block_a == block_b ) {
        int sum = 0;
        for( int i = l; i <= r; i++ ) sum += ara[i];
        return sum;
    }
    int ret = 0;
    for( int i = l; ; i++ ) {
        int pos = Block_ID( i );
        if( pos != block_a ) break;
        ret += ara[i];
    }
    cout << "retA : " << ret << endl;
    for( int i = block_a+1; i < block_b; i++ ) {
        ret += BLOCK[i];
    }
    cout << "retB : " << ret << endl;
    int f = block_size*( block_b-1 );
    for( int i = f+1; i <= r; i++ ) {
        ret += ara[i];
    }
    cout << "retC : " << ret << endl;
    return ret;
}
int main( int argc, char const *argv[] ) {
    cin >> n;
    block_size = sqrt(n);

    for( int i = 1; i <= n; i++ ) {
        cin >> ara[i];
        setblock( i , ara[i] );
    }
    cout <<"Total sum : "<< getsum( 3 , 8 ) << endl;
    return 0;
}







