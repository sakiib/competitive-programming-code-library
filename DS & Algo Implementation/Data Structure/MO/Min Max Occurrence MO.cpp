#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#define gc getchar
#define pc putchar
#else
#define gc getchar_unlocked
#define pc putchar_unlocked
#endif

using namespace std;

#define vi vector<int>
#define si set<int>
#define vs vector<string>
#define pii pair<int,int>
#define vpi vector<pii>
#define pri priority_queue<int>
#define rev_pri priority_queue<int,vector<int>,greater<int> >
#define mpi map<int,int>
#define i64 long long int
#define endl '\n'
#define pi acos(-1)
#define all(v) v.begin(),v.end()
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define inf INT_MAX/2
#define infll LLONG_MAX/3
#define For(i,n) for(int i=0;i<n;i++)
#define Fre(i,a,b) for(int i = a; i < b; i++)
#define sf(n) scanf("%d", &n)
#define sff(a,b) scanf("%d %d", &a, &b)
#define sfff(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define pfn(n) printf("%d\n", n)
#define pfs(n) printf("%d ", n)
#define eps 1e-8
#define ff first
#define ss second
#define mem(a,b) memset(a,b,sizeof(a))
#define READ freopen("in.txt", "r", stdin)
#define WRITE freopen("out.txt", "w", stdout)
#define sz size()
#define dbg(i) printf("yo %d\n", i)
#define foreach(i,c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define sqr(a) (a) * (a)
#define clr clear()
#define CASE(a) printf("Case %d:\n",a)

//int dx[] = {0,1,0,-1,1,1,-1,-1};
//int dy[] = {1,0,-1,0,1,-1,-1,1};


//i64 gcd(i64 a,i64 b){if(!b)return a;return gcd(b,a%b);}

inline void fastRead(int *a)
{
	register char c=0;
	while(c<33)
		c=gc();
	*a=0;
	while(c>33)
	{
		*a=*a*10+c-'0';
		c=gc();
	}
}

inline void fastWrite(int a)
{
	char snum[20];
	int i=0;
	do
	{
		snum[i++]=a%10+48;
		a=a/10;
	}
	while(a!=0);
	i=i-1;
	while(i>=0)
		pc(snum[i--]);
	pc('\n');
}

//i64 bigmod(i64 num,i64 n){if(n==0)return 1;i64 x=bigmod(num,n/2);x=x*x%mod;if(n%2==1)x=x*num%mod;return x;}

//i64 modinverse(i64 num){return bigmod(num,mod-2)%mod;}

//i64 po(i64 a,i64 b){i64 ans=1;while(b--)ans *= a;return ans;}

//i64 ncr(i64 n,i64 r){if(n==r)return 1;if(r==1)return n;if(dp[n][r]!=-1)return dp[n][r];return dp[n][r]=ncr(n-1,r)+ncr(n-1,r-1);}


// bit manipulations

//bool checkbit(int mask,int bit){return mask & (1<<bit);}

//int setbit(int mask,int bit){ return mask  (1<<bit) ; }

//int clearbit(int mask,int bit){return mask & ~(1<<bit);}

//int togglebit(int mask,int bit){return mask ^ (1<<bit);}



/// Mo's Algo with O( n * sqrt(n))


///change if needed
#define mxn 100005

struct queryInfo
{
	int l,r,idx;

	queryInfo() {}
	queryInfo(int ll,int rr,int ii)
	{
		l = ll;
		r = rr;
		idx = ii;
	}
};

int block ;


bool cmp(queryInfo a,queryInfo b)
{
	if(a.l/block==b.l/block)
		return a.r<b.r;
	return a.l<b.l;
}





vector<queryInfo> queries;

int val[mxn];   // array value
int ans[mxn];   // last ans





/// change accordigly to problem

int freq[mxn];   // freq of numbers
int ff[mxn];    /// frequency of frequency
int mx , mn;
bool need_update;

void add(int idx)
{

        int pre = freq[val[idx]]++;

        ff[pre]--;
        ff[pre+1]++;

        mx = max(mx,pre+1);
        mn = min(mn,pre+1);

        if(!ff[pre] && mn==pre)
                mn = pre+1;


}

void rem(int idx)
{

        int pre = freq[val[idx]]--;

        ff[pre]--;
        ff[pre-1]++;

        if(!ff[pre] && mx==pre)
                mx = pre - 1;

        if(pre-1)
                mn = min(mn , pre-1);
        else
                need_update = 1;


}


void update_min()
{
        Fre(i,mn , mx+1)
                if(ff[i])
                {
                        mn = i;
                        need_update = 0;
                        return;
                }

}

void doThings(int n)
{

	int pl = queries[0].l, pr = queries[0].l - 1 ;
        mx = 0;
        mn = inf;

	For(i,queries.sz)
	{
		int l = queries[i].l;
		int r = queries[i].r;


		while(pr < r)
		{
			pr++;
			add(pr);
		}

		while(pr > r)
		{
			rem(pr);
			pr--;
		}


		while(pl<l)
		{
			rem(pl);
			pl++;
		}

		while(pl>l)
		{
			pl--;
			add(pl);
		}

                if(need_update)
                        update_min();
		ans[queries[i].idx] = mx - mn;


	}
}


int main()
{
	int t,cs = 1,n,c,q,l,r;


	fastRead(&n);
	fastRead(&q);

	block = sqrt(n+1);

	Fre(i,1,n+1)
		fastRead(&val[i]);


	For(i,q)
	{
		fastRead(&l);
		fastRead(&r);
		queries.pb(queryInfo(l,r,i));
	}

	sort(all(queries),cmp);

	doThings(n);


	For(i,q)
                fastWrite(ans[i]);


	return 0;
}
