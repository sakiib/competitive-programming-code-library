///====================== TEMPLATE STARTS HERE =====================///
#include <bits/stdc++.h>
using namespace std;

//#include <ext/pb_ds/assoc_container.hpp> // Include for built in treap
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;

//#include <sys/resource.h>     // for linux stack memory increase
//#define gc getchar_unlocked   // for linux fast io
//#define gc getchar            // for windows fast io

#define pb push_back
#define MP make_pair
#define ff first
#define ss second
#define nl puts("")
#define sp printf(" ")
#define phl debug("Hello")
#define FOR(i,x,y) for(vlong i = (x) ; i <= (y) ; ++i)
#define ROF(i,x,y) for(vlong i = (y) ; i >= (x) ; --i)
#define CLR(x,y) memset(x,y,sizeof(x))
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((vlong)(x).size())
#define UNIQUE(V) (V).erase(unique((V).begin(),(V).end()),(V).end())
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define ABS(x) ((x)<0?-(x):(x))
#define FABS(x) ((x)+eps<0?-(x):(x))
#define SQ(x) ((x)*(x))
#define LCM(x,y) (((x)/gcd((x),(y)))*(y))
#define POPCOUNT __builtin_popcountll
#define RIGHTMOST __builtin_ctzll
#define LEFTMOST(x) (63-__builtin_clzll((x)))
#define NUMDIGIT(x,y) (((vlong)(log10((x))/log10((y))))+1)
#define NORM(x) if(x>=mod) x-=mod;if(x<0) x+=mod;
#define ODD(x) (((x)&1)==0?(0):(1))
#define Set(N,p) N=((N)|((1LL)<<(p)))
#define Reset(N,p) N=((N)&(~((1LL)<<(p))))
#define Check(N,p) (!(((N)&((1LL)<<(p)))==(0)))
#define fast_cin ios_base::sync_with_stdio(false);cin.tie(NULL)
#define arrayIndexPrint(A,i) cerr<<"~ At pos: "<<i<<" = "<<A[i]
#define dump(x) cerr<<"~ "<<#x<<" = "<<x<<endl
#define arrayPrint(A,st,ed) cerr<<"~ Array:";FOR(i,st,ed) cerr<<" "<<A[i];cerr<<endl
#define LINE cerr<<"\n"; FOR(i,0,50) cerr<<"=";cerr<<"\n\n"

#define LL long long
#define LLU long long unsigned int
typedef long long vlong;
typedef unsigned long long uvlong;
typedef pair < int, int > pii;
typedef pair < vlong, vlong > pll;
typedef vector<int> vi;
typedef vector<vlong> vl;
typedef vector<pll> vll;
//typedef tree <int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pb_ds;

#ifdef forthright48
     #include <ctime>
     clock_t tStart = clock();
     #define debug(args...) {dbg,args; cerr<<endl;}
     #define timeStamp debug ("Execution Time: ", (double)(clock() - tStart)/CLOCKS_PER_SEC)
     #define bug printf("%d\n",__LINE__);

#else
    #define debug(args...)  // Just strip off all debug tokens
    #define timeStamp
#endif

struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;

inline vlong gcd ( vlong a, vlong b ) {
    a = ABS ( a ); b = ABS ( b );
    while ( b ) { a = a % b; swap ( a, b ); } return a;
}

vlong ext_gcd ( vlong A, vlong B, vlong *X, vlong *Y ){
    vlong x2, y2, x1, y1, x, y, r2, r1, q, r;
    x2 = 1; y2 = 0;
    x1 = 0; y1 = 1;
    for (r2 = A, r1 = B; r1 != 0; r2 = r1, r1 = r, x2 = x1, y2 = y1, x1 = x, y1 = y ) {
        q = r2 / r1;
        r = r2 % r1;
        x = x2 - (q * x1);
        y = y2 - (q * y1);
    }
    *X = x2; *Y = y2;
    return r2;
}

inline vlong modInv ( vlong a, vlong m ) {
    vlong x, y;
    ext_gcd( a, m, &x, &y );
    x %= m;
    if ( x < 0 ) x += m;
    return x;
}

inline vlong bigmod ( vlong a, vlong p, vlong m ) {
    vlong res = 1 % m, x = a % m;
    while ( p ) {
        if ( p & 1 ) res = ( res * x ) % m;
        x = ( x * x ) % m; p >>= 1; /// For bigmod2 multiply here using mulmod
    }
    return res;
}


//int knightDir[8][2] = { {-2,1},{-1,2},{1,2},{2,1},{2,-1},{-1,-2},{1,-2},{-2,-1} };
//int dir4[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
//int dir8[8][2] = {{-1,0},{0,1},{1,0},{0,-1},{-1,-1},{1,1},{1,-1},{-1,1}};
const vlong inf = 2147383647;
const vlong mod = 1000000007;
const double pi = 2 * acos ( 0.0 );
const double eps = 1e-11;
const int Size = 500005;

///======================  TEMPLATE ENDS HERE  =====================///

/// 1. Call setSize() to set the subtree size of each node
/// 2. Call DFS() to find result for each node
/// RES[] contains the answer

int N, Q;
vector<int> G[Size];
int subsize[Size];
int heavy[Size];
LL cnt[Size][26];
LL RES[Size];
char C[Size];
vector<pii> qry[Size];
int depth[Size];

void setSize(int u, int p, int lvl = 1){
    FOR(i,0,SZ(G[u])-1){
        int v = G[u][i];
        if(v == p) continue;
        setSize(v, u, lvl+1);
        subsize[u] += subsize[v];
    }
    depth[u] = lvl;
    subsize[u]++;
}

void rem(int u, int p){
    int h = depth[u];
    int clr = (C[u] - 'a');
    cnt[h][clr]--;
    FOR(i,0,SZ(G[u])-1){
        int v = G[u][i];
        if(v == p || heavy[v]) continue;
        rem(v, u);
    }
}

/// After we call add, if we are currently at node u
/// in our DFS, then cnt[x] = number of color
/// in the subtree of u.
void add(int u, int p){
    int h = depth[u];
    int clr = (C[u] - 'a');
    cnt[h][clr]++;
    FOR(i,0,SZ(G[u])-1){
        int v = G[u][i];
        if(v == p || heavy[v]) continue;
        add(v, u);
    }
}

void findResult(int u){
    //debug("PROCESS NODE: ",u);
    FOR(i,0,SZ(qry[u])-1){
        int h = qry[u][i].ff;
        int idx = qry[u][i].ss;
        int odd = 0;
        FOR(d,0,25){
            if(cnt[h][d]%2 == 1) odd++;
            if(cnt[h][d]>0){
                //debug("Char: ",d," at H: ",h," = ",cnt[h][d]);
            }
        }
        if(odd>1) RES[idx] = 0;
        else RES[idx] = 1;
    }
}

/// Whenever we return to a node u, only the info of
/// its heavy child should be stored in our array.
void DFS(int u, int p, int isheavy){
    int mxsize = 0, heavyChild = -1;

    /// Find the heavy child first
    FOR(i,0,SZ(G[u])-1){
        int v = G[u][i];
        if(v == p) continue;
        if(subsize[v]>mxsize){
            mxsize = subsize[v];
            heavyChild = v;
        }
    }

    FOR(i,0,SZ(G[u])-1){
        int v = G[u][i];
        if(v == p) continue;
        if(v == heavyChild) continue;
        DFS(v, u, 0); /// Only call the light edges
    }

    if(heavyChild != -1){
        DFS(heavyChild, u, 1); /// Call the heavy child now
        heavy[heavyChild] = 1;
    }

    add(u, p); /// Add current subtree excluding heavy child
    findResult(u); /// Find the result for u'th subtree

    if(heavyChild != -1){
        heavy[heavyChild] = 0;
    }

    /// When we'll return to the parent of u, u'th information
    /// will be necessary only if u is a heavy child of p
    if(isheavy == 0){
        rem(u, p);
    }
}


int main () {
    #ifdef forthright48
    freopen ( "input.txt", "r", stdin );
    //freopen ( "output.txt", "w", stdout );
    #endif // forthright48

    scanf("%d %d",&N,&Q);
    FOR(u,2,N){
        int v;
        scanf("%d",&v);
        G[u].pb(v);
        G[v].pb(u);
    }

    scanf("%s",C+1);

    FOR(i,1,Q){
        int u, h;
        scanf("%d %d",&u,&h);
        qry[u].pb(MP(h, i));
    }

    setSize(1, 1);
    DFS(1, 1, 0);

    FOR(i,1,Q){
        if(RES[i]) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
