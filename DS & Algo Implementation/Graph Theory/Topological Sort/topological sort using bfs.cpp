#include<bits/stdc++.h>
using namespace std;

vector<int> graph[200];
int indegree[200];

int main(int argc,char const *argv[]) {
    int n,k;
    while(scanf("%d%d",&n,&k)!=EOF) {
    for(int i=0;i<200;i++) {
        graph[i].clear();
        indegree[i]=0;
    }
    for(int i=1;i<=k;i++) {
        int u,x,v;
        scanf("%d%d",&u,&x);
        while(x--) {
            scanf("%d",&v);
            graph[v].push_back(u); // u depends on v // v age kore then u korte hobe
            indegree[u]++;
        }
    }
    /// for lexicographically minimum..or just use queue
    priority_queue<int,vector<int>,greater<int> > Q; //

    for(int i=1;i<=n;i++) if(indegree[i]==0) Q.push(i);

    vector<int> ans;

    while(!Q.empty()) {
        int to=Q.top(); Q.pop();
        ans.push_back(to);
        for(int i=0;i<graph[to].size();i++) {
            indegree[graph[to][i]]--;
            if(indegree[graph[to][i]]==0) Q.push(graph[to][i]);
        }
    }
    for(int i=0;i<ans.size();i++) {
        if(i==0) printf("%d",ans[i]);
        else printf(" %d",ans[i]);
    }
      printf("\n");
    }
    return 0;
}
