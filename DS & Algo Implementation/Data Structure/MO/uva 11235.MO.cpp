#include<bits/stdc++.h>
using namespace std;

const int N=100005;
const int k=320; //~sqrt(100000)
int n,q,mx=0,l=1,r=0;
int ara[2*N];
int cnt[2*N],ans[2*N],freq[2*N];

struct query {
    int l,r,id;

    query () {}
    query(int _l,int _r,int _id) {
        l=_l, r=_r, id=_id;
    }
    bool operator < (const query &q) const {
        int block_a=l/k, block_b=q.l/k;
        if(block_a==block_b) return (r<q.r);
        return (block_a<block_b);
    }
} Q[2*N];

void add(int x) {
    if(cnt[ara[x]]>0) ans[cnt[ara[x]]]--;
    cnt[ara[x]]++;
    ans[cnt[ara[x]]]++;
    mx=max(mx,cnt[ara[x]]);
}
void rem(int x) {
    ans[cnt[ara[x]]]--;
    if(ans[mx]==0) mx--;
    cnt[ara[x]]--;
    if(cnt[ara[x]]>0) ans[cnt[ara[x]]]++;
}
void MO() {
    sort(Q+1,Q+q+1);

    l=1,r=0;
    for(int i=1;i<=q;i++) {
        while(l<Q[i].l) rem(l++);
        while(l>Q[i].l) add(--l);
        while(r<Q[i].r) add(++r);
        while(r>Q[i].r) rem(r--);
        freq[Q[i].id]=mx;
    }
}
int main(int argc,char const *argv[]) {

    while(scanf("%d",&n)) {
        if(n==0) break;
        mx=0;
        scanf("%d",&q);
        for(int i=1;i<=n;i++) {
            scanf("%d",&ara[i]);
            ara[i]+=100000;
        }
        for(int i=1;i<=q;i++) {
            int le,ri;
            scanf("%d%d",&le,&ri);
            Q[i].l=le; Q[i].r=ri; Q[i].id=i;
        }
        MO();
        for(int i=1;i<=q;i++) {
            printf("%d\n",freq[i]);
        }
        for(int i=1;i<=2*N;i++) {
            ans[i]=0,cnt[i]=0;
        }
    }
    return 0;
}
