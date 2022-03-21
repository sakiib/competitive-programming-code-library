#include <bits/stdc++.h>
using namespace std;

// keep idx, tight, lead & change the rest accordingly
// careful with lead for leading zero handling
// memset only once
typedef long long LL;
#define endl "\n"
#define Case "Case #" << tc << ": "

LL dp[13][2][2][109][109][109];
int dig[20];

LL go(int idx, bool tight, bool lead, int tSum, int prod, int sum) {
  if (idx == -1) {
    return tSum == sum && prod % tSum == 0;
  }

  if (!tight && !lead && dp[idx][tight][lead][tSum][prod][sum] != -1) {
    return dp[idx][tight][lead][tSum][prod][sum];
  }

  LL ret = 0;
  int up = tight ? dig[idx] : 9;
  for (int i = 0; i <= up; i++) {
    ret += go(idx - 1, tight && (dig[idx] == i), lead&&(i==0), tSum, lead&&(i==0)? prod:(prod % tSum * i % tSum) % tSum, sum + i);
  }

  if (!tight) {
    dp[idx][tight][lead][tSum][prod][sum] = ret;
  }
  return ret;
}

LL solve(LL x, int sum) {
  int len = 0;
  while (x) {
    dig[len++] = x % 10, x /= 10;
  }

  return go(len - 1, 1, 1, sum, 1, 0);
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif // LOCAL
  ios_base::sync_with_stdio(false); cin.tie(0);
  int t;
  cin >> t;
  memset(dp, -1, sizeof(dp));
  for (int tc = 1; tc <= t; tc++) {
    LL l, r;
    cin >> l >> r;
    LL ans = 0;

    for (int i = 1; i <= 108; i++) {
      ans += solve(r, i);
      ans -= solve(l - 1, i);
    }

    cout << Case << ans << endl;
  }
  return 0;
}
