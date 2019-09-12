#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL inf=1e15;
LL ara[100005];
char str[10];

struct segment {
    LL first,second;
    segment (){first=0; second=0;}
    segment (LL first,LL second) {
        this->first=first;
        this->second=second;
    }
}tree[4*100005];

void build(LL node,LL b,LL e) {
    if(b==e) {
        tree[node].first=ara[b];
        tree[node].second=-inf;
        return;
    }
    LL left=2*node; LL right=2*node+1; LL mid=(b+e)/2;
    build(left,b,mid);
    build(right,mid+1,e);
    tree[node].first=max(tree[left].first,tree[right].first);
    tree[node].second=min(max(tree[left].second,tree[right].first)
    ,max(tree[left].first,tree[right].second));
}
void update(LL node,LL b,LL e,LL pos,LL val) {
    if(pos>e||pos<b) return;
    if(b==e&&b==pos) {
        tree[node].first=val;
        tree[node].second=-inf;
        return;
    }
    LL left=2*node; LL right=2*node+1; LL mid=(b+e)/2;
    update(left,b,mid,pos,val);
    update(right,mid+1,e,pos,val);
    tree[node].first=max(tree[left].first,tree[right].first);
    tree[node].second=min(max(tree[left].second,tree[right].first)
    ,max(tree[left].first,tree[right].second));
}
segment query(LL node,LL b,LL e,LL i,LL j) {
    if(i>e||j<b) return {-inf,-inf};
    if(i<=b&&j>=e) {
        return tree[node];
    }
    LL left=2*node; LL right=2*node+1; LL mid=(b+e)/2;
    segment ret;
    segment s1=query(left,b,mid,i,j);
    segment s2=query(right,mid+1,e,i,j);
    ret.first=max(s1.first,s2.first);
    ret.second=min(max(s1.first,s2.second),max(s1.second,s2.first));
    return ret;
}
int main(int argc,char const *argv[]) {
    LL n;
    scanf("%lld",&n);
    for(int i=1;i<=n;i++) {
        scanf("%lld",&ara[i]);
    }
    build(1,1,n);
    int q;
    scanf("%d",&q);
    for(int i=1;i<=q;i++) {
        scanf("%s",str);
        char c=str[0];
        LL pos,val,l,r;
        segment S;
        switch(c) {
        case 'U' : scanf("%lld%lld",&pos,&val);
                   update(1,1,n,pos,val);
                   break;
        case 'Q' : scanf("%lld%lld",&l,&r);
                   S=query(1,1,n,l,r);
                   printf("%lld\n",S.first+S.second);
                   break;
        }
    }
    return 0;
}







