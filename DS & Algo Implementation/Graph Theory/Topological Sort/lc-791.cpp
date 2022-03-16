class Solution {
public:
  static const int N = 205;

  bool visited[26];
  vector <int> graph[N];
  stack <int> st;

  void dfs(int cur) {
    visited[cur] = true;
    for (auto nxt: graph[cur]) {
      if (!visited[nxt]) {
        dfs(nxt);
      }
    }
  }

  void topologicalSort(int cur) {
    visited[cur] = true;
    for (auto nxt: graph[cur]) {
      if (!visited[nxt]) {
        topologicalSort(nxt);
      }
    }
    st.push(cur);
  }

  int id(char ch) {
    return ch - 'a';
  }

  string customSortString(string order, string s) {
    vector <int> have (26, 0);
    for (int i = 0; i < s.size(); i++) {
      have[id(s[i])]++;
    }

    for (int i = 0; i < (int)order.size(); i++) {
      for (int j = i + 1; j < (int)order.size(); j++) {
        if (!have[id(order[i])] || !have[id(order[j])]) {
          continue;
        }
        graph[id(order[i])].push_back(id(order[j]));
      }
    }

    memset(visited, false, sizeof(visited));
    for (int i = 0; i < (int)s.size(); i++) {
      if (!visited[id(s[i])]) {
        topologicalSort(id(s[i]));
      }
    }

    memset(visited, false, sizeof(visited));
    vector <int> ord;
    while (!st.empty()) {
      int tp = st.top();
       if (have[tp])
      st.pop();
      ord.push_back(tp);
      if (!visited[tp]) {
        dfs(tp);
      }
    }

    string ans = "";
    for (auto ch: ord) {
      ans += string(have[ch], ch + 'a');
    }

    return ans;
  }
};
