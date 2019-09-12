#include <bits/stdc++.h>
#define f(i,a,b) for (int i = a; i <= b; i++)

using namespace std;

typedef long long LL;

const int MOD = 1e9 + 7;
LL p[ 100005 ];
LL a[ 100005 ];
const int RIGHT = 131072;
const int SIZE = 255005;
int N, Q;
LL K[SIZE], D[SIZE], LK[SIZE], LD[SIZE], S[SIZE];

LL query(int l, int r, int n = 1, int a = 1, int b = RIGHT)
{
    if(a > r || b < l) return 0;
    if(a >= l && b <= r) return S[n];

    if(LK[n] != 0 || LD[n] != 0)
    {
        int sz = (b-a+1) / 2;
        K[2*n] += LK[n], K[2*n+1] += LK[n] + LD[n]*sz;
        D[2*n] += LD[n], D[2*n+1] += LD[n];
        S[2*n] += LK[n]*sz + LD[n]*sz*(sz-1) / 2;
        S[2*n+1] += (LK[n] + LD[n]*sz)*sz + LD[n]*sz*(sz-1) / 2;
        LK[2*n] += LK[n], LK[2*n+1] += LK[n] + LD[n]*sz;
        LD[2*n] += LD[n], LD[2*n+1] += LD[n];
        LK[n] = LD[n] = 0;
    }

    int mid = (a+b) / 2;
    return query(l,r,2*n,a,mid) + query(l,r,2*n+1,mid+1,b);
}

void update(int l, int r, int k, int d, int n = 1, int a = 1, int b = RIGHT)
{
    if(a >= l && b <= r)
    {
        K[n] += k, D[n] += d;
        LK[n] += k, LD[n] += d;
        int sz = (b-a+1);
        S[n] += k*sz + d*sz*(sz-1) / 2;
        return;
    }

    if(LK[n] != 0 || LD[n] != 0)
    {
        int sz = (b-a+1) / 2;
        K[2*n] += LK[n], K[2*n+1] += LK[n] + LD[n]*sz;
        D[2*n] += LD[n], D[2*n+1] += LD[n];
        S[2*n] += LK[n]*sz + LD[n]*sz*(sz-1) / 2;
        S[2*n+1] += (LK[n] + LD[n]*sz)*sz + LD[n]*sz*(sz-1) / 2;
        LK[2*n] += LK[n], LK[2*n+1] += LK[n] + LD[n]*sz;
        LD[2*n] += LD[n], LD[2*n+1] += LD[n];
        LK[n] = LD[n] = 0;
    }

    int mid = (a+b) / 2;
    if(l <= mid) update(l,min(mid,r),k,d,2*n,a,mid);
    if(r > mid) update(max(mid+1,l),r,k + d*max(mid-l+1,0),d,2*n+1,mid+1,b);

    S[n] = S[2*n] + S[2*n+1];
}
LL BigMod ( LL b , LL p , LL mod ) {
        LL res = 1 % mod , x = b % mod;
        while ( p ) {
                if ( p & 1 ) res = ( res * x ) % mod;
                x = ( x * x ) % mod; p >>= 1;
        }
        return ( res%mod );
}
int main()
{
    scanf("%d %d", &N, &Q);
    for( int i = 1; i <= N; i++ ) scanf("%lld",&a[i]);
    while(Q--)
    {
        char s[20];
        scanf("%s",s);
        if( s[0] == 'A' ) {
                int l , r;
                scanf("%d %d",&l,&r);
                update( l , r , 0 , 1 ); /// l , r , first term , diff.
        }
        else {
                int l , r;
                scanf("%d %d",&l,&r);
                printf("%lld\n",query( l , r ) );
        }
    }
    return 0;
}

