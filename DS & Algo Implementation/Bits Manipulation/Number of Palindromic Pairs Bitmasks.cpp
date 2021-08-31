// https://codeforces.com/contest/1045/problem/I
#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
const int N = 1e5 + 5;

int Set(int N, int pos) {
  return N |= (1 << pos);
}

int Reset(int N, int pos) {
  return N = N & ~(1 << pos);
}

bool Check(int N, int pos) {
  return (bool)(N & (1 << pos));
}

int Toggle(int N, int pos) {
  return (N ^= (1 << pos));
}

int mask[N];
map <int, int> M;
map <int, int> cnt;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < s.size(); j++) {
      mask[i] = Toggle(mask[i], (s[j] - 'a'));
    }
  }
  
  LL ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += cnt[mask[i]];
    for (int j = 0; j < 26; j++) {
      int cur = mask[i];
      cur = Toggle(cur, j);
      ans += cnt[cur];
    }
    cnt[mask[i]]++;
  }
  cout << ans << "\n";
  return 0;
}