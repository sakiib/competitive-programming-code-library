#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int ara[ N ];
int BLOCK[ 350 ];
int n;
int block_size;

void Init( ) {  /// problem wise sum , max , min wise
        memset( BLOCK , 0 , sizeof(BLOCK) );
}
int Block_ID( int id ) { /// id index kon block e jabe.
        int pos = ( ( id + block_size - 1 ) / block_size );
        return pos;
}
void SetBlock( int id , int v ) { /// problem wise sum , max , min wise
        int pos = Block_ID( id ); BLOCK[pos] += v;
}
pair <int,int> StartEndofBlock( int id ) { /// start & end index of id'th BLOCK.
        int st = ( id - 1 ) * block_size + 1;
        int en = min( n , ( st + block_size - 1 ) );
        return {st,en};
}

int GetSum( int l , int r ) {
        /// start kon block & end kon block.
        int block_a = Block_ID( l ) , block_b = Block_ID( r );

        /// If whole range in same block , do a bruteforce.
        if( block_a == block_b ) {
                int sum = 0;
                for( int i = l; i <= r; i++ ) sum += ara[i];
                return sum;
        }

        /// First part bruteforce
        int ret = 0;
        for( int i = l; ; i++ ) {
                int pos = Block_ID( i );
                if( pos != block_a ) break;
                ret += ara[i];
        }
        /// middle part e SQRT decomposition.
        for( int i = block_a + 1; i < block_b; i++ ) {
                ret += BLOCK[i];
        }
        /// Last part again bruteforce.
        int f = block_size * ( block_b - 1 );
        for( int i = f + 1; i <= r; i++ ) {
                ret += ara[i];
        }
        return ret;
}
int main( int argc, char const *argv[] ) {
        cin >> n;
        block_size = sqrt(n);
        for( int i = 1; i <= n; i++ ) {
                cin >> ara[i];
                SetBlock( i , ara[i] );
        }
        cout << "Total sum : " << GetSum( 3 , 8 ) << endl;
        return 0;
}








