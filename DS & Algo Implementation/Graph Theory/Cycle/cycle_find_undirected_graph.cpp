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

// UVA - 10004
#include <bits/stdc++.h>
using namespace std;

/**
Undirected & 1 based index
*/
const int N = 1e5 + 5;
int color[N];
vector < int > graph[N];

bool biColorable(int s, int c) {
  color[s] = c;
  bool ret = true;
  for (auto x: graph[s]) {
    if (color[x] == c) return false;
    if (color[x] == -1) ret &= biColorable(x, c ^ 1);
  }
  return ret;
}
int main(int argc, char
  const * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  while (cin >> n) {
    if (n == 0) break;
    int k;
    cin >> k;
    for (int i = 1; i < N; i++) color[i] = -1, graph[i].clear();
    for (int i = 1; i <= k; i++) {
      int u, v;
      cin >> u >> v;
      ++u, ++v;
      graph[u].push_back(v);
      graph[v].push_back(u);
    }
    if (biColorable(1, 1)) cout << "BICOLORABLE." << endl;
    else cout << "NOT BICOLORABLE." << endl;
  }
  return 0;
}

---
call: hasCycle(i, -1, visited, graph)
  
bool hasCycle(int node, int parent, vector <bool> &visited,vector <vector <int> > &graph) {
    visited[node] = true;
    for (auto nxt: graph[node]) {
        if (!visited[nxt]) {
            if (hasCycle(nxt, node, visited, graph)) return true;
        } else if (nxt != parent) {
            return true;
        }
    }

    return false;
}
