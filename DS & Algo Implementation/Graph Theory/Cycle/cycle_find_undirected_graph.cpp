#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef pair <int, ii> iii;
typedef long long int LL;
typedef unsigned long long uLL;
const int inf = (int) 1e9;
const LL INF = (LL) 2e18;
const int N = 100005;
const int mod = 1000000007;
const double eps = 1e-8;
const double pi = acos(-1.0);

vector <int> graph[N];
bool cycle = false;
bool visited[N];

void iscycle(int s, int p) {
  visited[s] = true;
  for (auto x: graph[s]) {
    if (!visited[x]) iscycle(x, s);
    else if (visited[x] && x != p) {
      cycle = true;
      return;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 1; i <= 5; i++) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  
  memset(visited, false, sizeof(visited));
  for (int i = 1; i <= 5; i++)
    if (!visited[i]) iscycle(i, 0);
    
  if (cycle) cout << "cycle found" << endl;
  else cout << "no cycle found" << endl;
  return 0;
}

/**
yes :
1 2
2 3
2 4
3 4
4 5
no : tree
1 2
1 3
2 4
2 5
*/
