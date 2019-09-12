#include<bits/stdc++.h>

using namespace std;

#define fRead(x)        freopen(x,"r",stdin)
#define fWrite(x)       freopen (x,"w",stdout)

#define LL              long long
#define ULL             unsigned long long
#define ff              first
#define ss              second
#define pb              push_back
#define INF             5e13
#define PI              acos(-1.0)
#define mk              make_pair
#define pii             pair<int,int>
#define pll             pair<LL,LL>
#define all(a)          a.begin(),a.end()
#define Unique(a)       sort(all(a)),a.erase(unique(all(a)),a.end())

#define min3(a,b,c)     min(a,min(b,c))
#define max3(a,b,c)     max(a,max(b,c))
#define min4(a,b,c,d)   min(a,min(b,min(c,d)))
#define max4(a,b,c,d)   max(a,max(b,max(c,d)))
#define SQR(a)          ((a)*(a))
#define FOR(i,a,b)      for(int i=a;i<=b;i++)
#define ROF(i,a,b)      for(int i=a;i>=b;i--)
#define REP(i,b)        for(int i=0;i<b;i++)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define ABS(x)          ((x)<0?-(x):(x))

#define SORT(v)         sort(v.begin(),v.end())
#define REV(v)          reverse(v.begin(),v.end())
#define FastRead        ios_base::sync_with_stdio(0);cin.tie(nullptr);

const LL MOD = 1e9 + 7;
template <typename T> inline T BigMod(T A,T B,T M = MOD){T ret = 1;while(B){if(B & 1) ret = (ret * A) % M;A = (A * A) % M;B = B >> 1;}return ret;}
vector<pii>v;
int n,m,q;
LL fac[200005];
void gen()
{
    fac[0]=1;
    FOR(i,1,200000)fac[i] = (fac[i-1]*i)%MOD;
}
LL COM(LL a,LL b)
{
    LL x = fac[a];
    LL y = fac[b];
    LL z = fac[a-b];
    LL yz = (y*z)%MOD;
    x = (x*BigMod(yz,MOD-2,MOD))%MOD;
    return x;
}
LL dp[1002];
LL call(int pos)
{
   if(dp[pos]!=-1)return dp[pos];
   int x = v[pos].ff;
   int y = v[pos].ss;
   LL ret = COM(n+m-x-y,n-x);
   for(int i = pos + 1;i<v.size();i++){
      if(v[i].ff>=x and v[i].ss>=y){
         ret -= call(i)*COM(v[i].ff-x+v[i].ss-y,v[i].ff-x);
         ret %= MOD;
      }
   }
//   cout << pos << " " << ret << endl;
   return dp[pos] = ret;
}
int main()
{
   FastRead
   gen();
   int t;
   cin >> t;
   while(t--)
   {
      MEM(dp,-1);
      v.clear();
      cin >> n >> m >> q;
      v.push_back(mk(1,1));
      REP(i,q){
         int x,y;
         cin >> x >> y;
         v.push_back(mk(x,y));
      }
      SORT(v);
      cout << (call(0)+MOD)%MOD << "\n";
   }


}
