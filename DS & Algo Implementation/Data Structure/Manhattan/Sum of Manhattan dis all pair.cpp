#include <bits/stdc++.h>
using namespace std;

/**
 x dist & y dist are calculated separately
 the manhattan formula can be decomposed into two independent sums, one for the
 difference between x coordinates and the second between y coordinates. If we know
  how to compute one of them we can use the same method to compute the other.
  So now we will stick to compute the sum of x coordinates distance.
Let’s assume that we know all distances from a point xi to all values of x’s
smaller than xi. Let’s consider other points, the first one not smaller than xi,
 and call it xj. How to compute the distances from xj to all smaller points ?
 We can use the corresponding distances from from xi. Notice that each distance
  from xj to some xk, where xk < xj equals the distance from xi to xk plus the
   distance between xj and xi. If there are A points smaller than xj and S is the
    sum of distances from xi to smaller points, then the sum of distances from
    xj to smaller points equals S + (xj – xi) * A
*/

int x[] = { -1 , 1 , 3 , 2 };
int y[] = { 5 , 6 , 5 , 3 };
int sz = 4;

int manDist( int a[] ) {
        sort( a , a + sz );
        int res = 0 , sum = 0;
        for( int i = 0; i < sz; i++ ) {
                res += ( a[i] * i - sum );
                sum += a[i];
        }
        return res;
}
int solve( ) {
        return manDist( x ) + manDist( y );
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( NULL );
        cout << solve( ) << endl;
        return 0;
}










