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

int ara[ N ];
vector <int> Tree[ 4*N ];

void Build( int node , int b , int e ) {
    if( b > e ) return;
    if( b == e ) {
        Tree[node].push_back( ara[b] );
        return;
    }
    int left = 2*node , right = 2*node+1 , mid = (b+e)/2;
    Build( left , b , mid );
    Build( right , mid+1 , e );
    merge(Tree[left].begin(),Tree[left].end() ,
          Tree[right].begin(),Tree[right].end(),back_inserter(Tree[node]));
}
int Query( int node , int b , int e , int i , int j , int k ) {
    if( i > e || j < b ) return 0;
    if( i <= b && j >= e ) {
        return upper_bound (Tree[node].begin(),Tree[node].end(),k)-Tree[node].begin();
    }
    int left = 2*node , right = 2*node+1 , mid = (b+e)/2;
    int q1 = Query( left , b , mid , i , j , k );
    int q2 = Query( right , mid+1 , e , i , j , k );
    return q1+q2;
}
int main( int argc, char const *argv[] ) {
    int n , q;
    scanf("%d%d",&n,&q);
    for( int i = 1; i <= n; i++ ) {
        scanf("%d",&ara[i]);
    }
    Build( 1 , 1 , n );
    while( q-- ) {
        int l , r , k;
        scanf("%d%d%d",&l,&r,&k);
        int lo = -inf , hi = inf;
        int ans = -1;
        while( lo <= hi ) {
            int mid = (lo+hi)/2;
            if( Query( 1 , 1 , n , l , r , mid) >= k ) ans = mid , hi = mid-1;
            else lo = mid+1;
        }
        printf("%d\n",ans);
    }
    return 0;
}
