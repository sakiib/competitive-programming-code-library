#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int a[N], ans[N];

template <typename T> class BinaryIndexedTree {
public:
  int len;
  vector <T> bit;
  BinaryIndexedTree(int sz) {
    len = sz;
    bit.resize(sz + 5, 0);
  }

  T r_query(int l, int r) {
    return p_query(r) - p_query(l - 1);
  }

  void p_update(int idx, T v) {
    if (idx <= 0) {
       return;
    }

    for (; idx <= len; idx += (idx & -idx)) {
      bit[idx] += v;
    }
  }

  T p_query(int idx) {
    T ret = 0;
    for (; idx > 0; idx -= (idx & -idx)) {
      ret += bit[idx];
    }

    return ret;
  }

  void r_update(int idx, int idy, T v) {
    for (; idx <= len; idx += (idx & -idx)) {
      bit[idx] += v;
    }

    for (++idy; idy <= len; idy += (idy & -idy)) {
      bit[idy] -= v;
    }
  }
};


int main() {
  int t;
  cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }

    BinaryIndexedTree <int> bit(N);
    cout << "Case #" << tc << ": ";
    for (int i = 1; i <= n; i++) {
      bit.p_update(a[i], 1);
      int last = ans[i - 1];
      int cnt = bit.r_query(last + 1,  1e5);
      if (cnt > last) {
        ans[i] = last + 1;
      } else {
        ans[i] = last;
      }
    }

    for (int i = 1; i <= n; i++) {
      if (i == 1) {
        cout << ans[i];
      } else {
        cout << " " << ans[i];
      }
    }
    cout << "\n";
  }
  return 0;
}
