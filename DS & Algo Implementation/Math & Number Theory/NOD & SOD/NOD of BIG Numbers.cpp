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
 O( N^1/3 )
 */
/* Calculate ( a*b ) %c */
LL mulmod(LL a,LL b,LL c)
{
    LL x = 0 , y = a%c ;
    while(b>0)
    {
        if(b%2) x = (x+y)%c ;
        y=(y*2)%c;
        b/=2;
    }
    return x%c ;
}

/* Calculate ( a^b ) %c */
LL modulo(LL a,LL b,LL c)
{
    LL x = 1 , y = a%c ;
    while( b > 0 )
    {
        if(b%2) x = mulmod(x,y,c) ;
        y=mulmod(y,y,c);
        b/=2;
    }
    return x%c ;
}

bool Miller(LL p, LL iteration)
{
    if(p<2) return false ;
    if(p%2==0&&p!=2) return false ;

    LL s = p-1 ;
    while(s%2==0) s/=2;

    for(LL i=1;i<=iteration;i++)
    {
        LL a = rand() % (p-1)+1 , temp = s ;

        LL mod = modulo(a,temp,p);
        while(mod!=1&&mod!=p-1&&temp!=p-1)
        {
            mod = mulmod(mod,mod,p);
            temp*=2;
        }
        if(temp%2==0&&mod!=p-1) return false ;
    }
    return true ;
}

LL SQRT( LL n ) {
        LL lo = 1 , hi = 1e9, ret = 0;
        while( lo <= hi ) {
                LL mid = ( lo+hi ) >> 1;
                if( mid*mid <= n ) {
                        ret = mid;
                        lo = mid+1;
                }
                else hi = mid-1;
        }
        return ret;
}

vector <LL> prime;
vector <bool> isprime( 10*N , true );

void sieve( ) {
        isprime[0] = isprime[1] = false;
        prime.push_back( 2 );
        for( LL i = 4; i <= 10*N; i +=2 ) isprime[i] = false;
        int sq = sqrt( 10*N );
        for( LL i = 3; i <= sq; i += 2 ) {
                if( isprime[i] ) {
                    for( LL j = i*i; j <= 10*N; j += 2*i ) {
                        isprime[j] = false;
                    }
                }
        }
        for( LL i = 3; i <= 10*N; i += 2 ) {
                if( isprime[i] ) prime.push_back( i );
        }
}

LL solve( LL x ) {
        LL ans = 1;
        for( int i = 0; i < prime.size(); i++ ) {
                if( prime[i] * prime[i] * prime[i] > x ) break;
                LL cnt = 1;
                while( x%prime[i] == 0 ) {
                        x /= prime[i];
                        cnt++;
                }
                ans = ans * cnt;
        }
        if( Miller( x , 50 ) ) ans = ans * 2;
        else if( Miller( SQRT(x) , 50 ) && SQRT(x)*SQRT(x) == x ) ans = ans * 3;
        else if( x != 1 ) ans = ans * 4;
        return ans;
}

int main( int argc , char const *argv[] ) {
        ios_base :: sync_with_stdio(false); cin.tie(NULL);
        sieve( );
        LL n;
        cin >> n;
        cout << solve( n ) << endl;
        return 0;
}






