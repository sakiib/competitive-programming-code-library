#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
string str;

struct segment {
    int open,close,sum;
    segment(){open=0; close=0; sum=0;}
    segment(int open,int close,int sum) {
        this->open=open;
        this->close=close;
        this->sum=sum;
    }
}tree[4*N];

void build(int node,int b,int e) {
    if(b==e) {
        if(str[b]=='(') tree[node]={1,0,0};
        else tree[node]={0,1,0};
        return;
    }
    int left=2*node; int right=2*node+1;
    int mid=(b+e)/2;
    build(left,b,mid);
    build(right,mid+1,e);
    int match=min(tree[left].open,tree[right].close);
    tree[node].open=tree[left].open+tree[right].open-match;
    tree[node].close=tree[left].close+tree[right].close-match;
    tree[node].sum=tree[left].sum+tree[right].sum+2*match;
}
segment query(int node,int b,int e,int i,int j) {
    if(i>e||j<b) return {0,0,0};
    if(i<=b&&j>=e) return tree[node];
    int left=2*node; int right=2*node+1;
    int mid=(b+e)/2;
    segment s1=query(left,b,mid,i,j);
    segment s2=query(right,mid+1,e,i,j);
    segment ret;
    int match=min(s1.open,s2.close);
    ret.sum=s1.sum+s2.sum+2*match;
    ret.open=s1.open+s2.open-match;
    ret.close=s1.close+s2.close-match;
    return ret;
}
int main(int argc,char const *argv[]) {
    cin>>str;
    int len=str.size();
    build(1,0,len-1);
    int q;
    scanf("%d",&q);
    for(int i=1;i<=q;i++) {
        int l,r;
        scanf("%d%d",&l,&r);
        segment S=query(1,0,len-1,--l,--r);
        printf("%d\n",S.sum);
    }
    return 0;
}

