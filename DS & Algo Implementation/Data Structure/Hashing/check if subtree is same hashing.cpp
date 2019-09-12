#include <bits/stdc++.h>
using namespace std;

#define trace(...) __f( #__VA_ARGS__ , __VA_ARGS__ )
template <typename Arg1>
void __f( const char* name , Arg1&& arg1 ) {
        cerr << name << " : " << arg1 << "\n";
}
template <typename Arg1, typename... Args>
void __f( const char* na , Arg1&& arg1 , Args&&... args ) {
        const char* c = strchr( na + 1 , ',' );
        cerr.write( na , c - na ) << " : " << arg1 << " , ";
        __f( c + 1 , args... );
}

#define ran(a, b) rand() % ( (b) - (a) + 1 ) + (a)

typedef long long int LL;
const long long INF = 1e18;
const int N = 1e6 + 5;

int tree[ 4 * N ][ 2 ] , lazy[ 4 * N ][ 2 ];
int n , q , a[ N ];
vector <int> graph[ N ];
int st[ N ] , en[ N ] , Time , subtree[ N ];

const int mod1[5] = {1000000007, 1000000009, 1000000021, 1000000033, 1000000087};
const int mod2[5] = {1000000093, 1000000097, 1000000103, 1000000123, 1000000181};
const int base1[5] = { 23 , 29 , 31 , 37 , 41 };
const int base2[5] = { 43 , 47 , 53 , 59 , 61 };
int MOD[2] = { 1000000007, 1000000009 };
int base[2] = { 43 , 37 }, invbase[2] = { 395348840 , 297297300 };
int p[ N ][ 2 ] , invmod[ N ][ 2 ] , h[ N ][ 2 ];

inline int add( int x , int y , int MOD ) {
        return x + y >= MOD ? x + y - MOD : x + y;
}
inline int sub( int x , int y , int MOD ) {
        return x - y < 0 ? x - y + MOD : x - y;
}
inline int mul( int x , int y , int MOD ) {
        return ( 1LL * x * y ) % MOD;
}
inline void gen_pow( ) {
        p[0][0] = 1 , p[0][1] = 1 , invmod[0][0] = 1 , invmod[0][1] = 1;
        for( int i = 1; i < N; i++ ) {
                for( int id = 0; id < 2; id++ ) {
                        p[i][id] = mul( p[i-1][id] , base[id] , MOD[id] );
                        invmod[i][id] = mul( invmod[i-1][id] , invbase[id] , MOD[id] );
                }
        }
}
inline void flat_it( int s , int p ) {
        st[s] = ++Time;
        subtree[s] = 1;
        for( auto x : graph[s] ) {
                if( x != p ) flat_it( x , s ) , subtree[s] += subtree[x];
        }
        en[s] = Time;
}
inline void pushdown( int node , int b , int e ) {
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        if( lazy[node][0] != 1 ) {
                tree[l][0] = mul( tree[l][0] , lazy[node][0] , MOD[0] );
                tree[r][0] = mul( tree[r][0] , lazy[node][0] , MOD[0] );
                lazy[l][0] = mul( lazy[l][0] , lazy[node][0] , MOD[0] );
                lazy[r][0] = mul( lazy[r][0] , lazy[node][0] , MOD[0] );
                lazy[node][0] = 1;
        }
        if( lazy[node][1] != 1 ) {
                tree[l][1] = mul( tree[l][1] , lazy[node][1] , MOD[1] );
                tree[r][1] = mul( tree[r][1] , lazy[node][1] , MOD[1] );
                lazy[l][1] = mul( lazy[l][1] , lazy[node][1] , MOD[1] );
                lazy[r][1] = mul( lazy[r][1] , lazy[node][1] , MOD[1] );
                lazy[node][1] = 1;
        }
}
inline void update( int node , int b , int e , int pos , int val ) {
        if( pos > e || pos < b || b > e ) return;
        if( b == e && b == pos ) {
                tree[node][0] = p[val][0];
                tree[node][1] = p[val][1];
                return;
        }
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        update( l , b , m , pos , val );
        update( r , m + 1 , e , pos , val );
        tree[node][0] = add( tree[l][0] , tree[r][0] , MOD[0] );
        tree[node][1] = add( tree[l][1] , tree[r][1] , MOD[1] );
}
inline void update_hash( int node , int b , int e , int i , int j , int val1 , int val2 ) {
        if( i > e || j < b || b > e ) return;
        if( i <= b && j >= e ) {
                tree[node][0] = mul( tree[node][0] , val1 , MOD[0] );
                tree[node][1] = mul( tree[node][1] , val2 , MOD[1] );
                lazy[node][0] = mul( lazy[node][0] , val1 , MOD[0] );
                lazy[node][1] = mul( lazy[node][1] , val2 , MOD[1] );
                return;
        }
        pushdown( node , b , e );
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        update_hash( l , b , m , i , j , val1 , val2 );
        update_hash( r , m + 1 , e , i , j , val1 , val2 );
        tree[node][0] = add( tree[l][0] , tree[r][0] , MOD[0] );
        tree[node][1] = add( tree[l][1] , tree[r][1] , MOD[1] );
}
inline pair <int,int> query( int node , int b , int e , int i , int j ) {
        if( i > e || j < b || b > e ) return make_pair( 0 , 0 );
        if( i <= b && j >= e ) return make_pair( tree[node][0] , tree[node][1] );
        pushdown( node , b , e );
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        pair <int,int> x = query( l , b , m , i , j );
        pair <int,int> y = query( r , m + 1 , e , i , j );
        pair <int,int> z = {0,0};
        z.first = add( x.first , y.first , MOD[0] );
        z.second = add( x.second , y.second , MOD[1] );
        return z;
}
inline LL make_big( LL x , LL y ) {
        return ( x << 31 ) | y;
}
inline LL bigmod( LL b , LL p , LL mod ) {
        LL res = 1%mod , x = b%mod;
        while( p ) {
                if( p&1 ) res = (res * x)%mod;
                x = (x * x)%mod; p >>= 1;
        }
        return (res%mod);
}
inline void make_random( ) {
        srand( time(NULL) );
        MOD[0] = mod1[ ran( 0 , 4 ) ] , base[0] = base1[ ran( 0 , 4 ) ];
        invbase[0] = bigmod( base[0] , MOD[0] - 2 , MOD[0] );
        MOD[1] = mod2[ ran( 0 , 4 ) ] , base[1] = base2[ ran( 0 , 4 ) ];
        invbase[1] = bigmod( base[1] , MOD[1] - 2 , MOD[1] );
}
int main( ) {
        #ifdef LOCAL
            freopen( "input.txt" , "r" , stdin );
        #endif // LOCAL
        make_random( );
        gen_pow( );
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
                scanf("%d %d",&n,&q);
                for( int i = 1; i < N; i++ ) graph[i].clear() , subtree[i] = 0;
                for( int i = 1; i < 4 * N; i++ ) {
                        tree[i][0] = tree[i][1] = 0;
                        lazy[i][0] = lazy[i][1] = 1;
                }
                for( int i = 1; i <= n; i++ ) scanf("%d",&a[i]);
                for( int i = 1; i <= n - 1; i++ ) {
                        int u , v;
                        scanf("%d %d",&u,&v);
                        graph[u].push_back( v );
                        graph[v].push_back( u );
                }
                Time = 0 , flat_it( 1 , 0 );
                for( int i = 1; i <= Time; i++ ) {
                        update( 1 , 1 , Time , st[i] , a[i] );
                }

                printf("Case %d:\n",tc);
                while( q-- ) {
                        int type;
                        scanf("%d",&type);
                        if( type == 1 ) {
                                int node , val;
                                scanf("%d %d",&node,&val);
                                if( val < 0 )
                                    update_hash( 1, 1, Time, st[node], en[node],
                                                        invmod[-val][0], invmod[-val][1] );
                                else
                                    update_hash( 1, 1, Time, st[node], en[node],
                                                        p[val][0], p[val][1] );
                        }
                        else {
                                int x , y;
                                scanf("%d %d",&x,&y);
                                pair <int,int> p = query( 1 , 1 , Time , st[x] , en[x] );
                                LL hash1 = make_big( p.first , p.second );
                                pair <int,int> q = query( 1 , 1 , Time , st[y] , en[y] );
                                LL hash2 = make_big( q.first , q.second );
                                if( hash1 == hash2 && subtree[x] == subtree[y] ) printf("1\n");
                                else printf("0\n");
                        }
                }
        }
        return 0;
}









