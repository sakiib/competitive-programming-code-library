#include <bits/stdc++.h>
using namespace std;
 
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << "\n";
}
template <typename Arg1, typename... Args>
void __f(const char* na, Arg1&& arg1, Args&&... args) {
  const char* c = strchr(na + 1, ',');
  cerr.write(na, c - na) << " : " << arg1 << " , ";
  __f(c + 1, args...);
}
#define endl "\n"
#define all(v) v.begin(), v.end()
#define UNIQUE(v) sort(all(v)),v.erase(unique(all(v)),v.end())
typedef long long LL;
typedef pair <int,int> pii;
const double pi = acos(-1.0);
const double eps = 1e-8;
const int mod = 1e9 + 7;
const int inf = 1e9;
const LL INF = 1e18;
const int N = 1e6 + 5;
const int base = 37;
 
inline int add(int x, int y, int mod) {
  return x + y >= mod ? x + y - mod : x + y;
}
inline int sub(int x, int y, int mod) {
  return x - y < 0 ? x - y + mod : x - y;
}
inline int mul(int x, int y, int mod) {
  return (1LL * x * y) % mod;
}
 
struct hashing {
  const int N = 1000005; int tlen;
  #define ran(a, b) rand() % ( (b) - (a) + 1 ) + (a)
  const int mod1[5] = {1000000007, 1000000009, 1000000021, 1000000033, 1000000087};
  const int mod2[5] = {1000000093, 1000000097, 1000000103, 1000000123, 1000000181};
  const int base1[5] = {23, 29, 31, 37, 41};
  const int base2[5] = {43, 47, 53, 59, 61};
  int mod[2] = {1000000007, 1000000009};
  int base[2] = {43, 37}, invb[2] = {395348840, 297297300};
  vector <vector <int> > p; vector <vector <int> > invm;
  vector <vector <int> > fh; vector <vector <int> > bh;
 
  LL bigmod(LL b, LL p, LL mod) {
    LL res = 1%mod, x = b%mod;
    while (p) {
        if(p&1) res = (res * x)%mod;
        x = (x * x)%mod; p >>= 1;
    }
    return (res%mod);
  }
  void gen_pow(int sz) {
    p.resize(sz + 2); invm.resize(sz + 2);
    for (int i = 0; i <= sz; i++) p[i].resize(2), invm[i].resize(2);
 
    srand(time(NULL));
    mod[0] = mod1[ran(0 , 4)] , base[0] = base1[ran(0, 4)];
    invb[0] = bigmod(base[0], mod[0] - 2 , mod[0]);
    mod[1] = mod2[ran(0, 4) ], base[1] = base2[ran(0, 4)];
    invb[1] = bigmod(base[1], mod[1] - 2, mod[1]);
    p[0][0] = p[0][1] = invm[0][0] = invm[0][1] = 1;
 
    for (int i = 1; i <= sz; i++) {
      for (int id = 0; id <= 1; id++) {
        p[i][id] = mul(p[i-1][id], base[id], mod[id]);
        invm[i][id] = mul(invm[i-1][id], invb[id], mod[id]);
      }
    }
  }
  void build_hash(string &txt) {
    tlen = txt.size(); fh.resize(tlen + 2); bh.resize(tlen + 2);
    for (int i = 0; i <= tlen; i++) fh[i].resize(2), bh[i].resize(2);
    for (int i = 0 , j = tlen - 1; i < tlen; i++ , j--) {
      for (int id = 0; id <= 1; id++) {
        fh[i][id] = mul(p[i][id], txt[i], mod[id]);
        if (i) fh[i][id] = add(fh[i][id], fh[i-1][id], mod[id]);
        bh[i][id] = mul(p[j][id], txt[i], mod[id]);
        if (i) bh[i][id] = add(bh[i][id], bh[i-1][id], mod[id]);
      }
    }
  }
  LL combine_hash(LL x, LL y) { return ( x << 31 ) | y; }
  LL get_fhash(int l, int r) {
    if (l == 0) return combine_hash(fh[r][0], fh[r][1]);
    int x = sub(fh[r][0], fh[l-1][0], mod[0]); x = mul(x, invm[l][0], mod[0]);
    int y = sub(fh[r][1], fh[l-1][1], mod[1]); y = mul(y, invm[l][1], mod[1]);
    return combine_hash( x , y );
  }
  LL get_bhash(int l, int r) {
    if (l == 0) {
      int x = bh[r][0]; x = mul(x, invm[tlen-r-1][0], mod[0]);
      int y = bh[r][1]; y = mul(y, invm[tlen-r-1][1], mod[1]);
      return combine_hash(x , y );
    }
    int x = sub(bh[r][0], bh[l-1][0], mod[0]);
    x = mul(x, invm[tlen-r-1][0], mod[0]);
    int y = sub(bh[r][1], bh[l-1][1], mod[1]);
    y = mul(y, invm[tlen-r-1][1], mod[1]); return combine_hash(x, y);
  }
} h;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  #ifdef LOCAL
    freopen("input.txt", "r", stdin);
  #endif // LOCAL
  h.gen_pow(1e6);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    string x = "", y = "";
    int l = 0, r = s.size() - 1;
    while (l < r && s[l] == s[r]) {
      x += s[l], y += s[r], l++, r--;
    }
    if (l == r) {
      cout << x;
      cout << s[l];
      reverse(y.begin(), y.end());
      cout << y << endl;
      continue;
    }
    string rem = s.substr(l, r - l + 1);
    h.build_hash(rem);
    int len = 0;
    for (int i = 0; i < rem.size(); i++) {
      if (h.get_fhash(0, i) == h.get_bhash(0, i)) len = i + 1;
    }
    string L = rem.substr(0, len);
    len = 0;
    int sz = rem.size();
    for (int i = sz - 1; i >= 0; i--) {
      if (h.get_fhash(i, sz - 1) == h.get_bhash(i, sz - 1)) len = sz - i;
    }
    string R = rem.substr(sz - len, len);
 
    if ((int)L.size() >= (int)R.size()) {
      cout << x;
      cout << L;
      reverse(y.begin(), y.end());
      cout << y << endl;
    }
    else {
      cout << x;
      cout << R;
      reverse(y.begin(), y.end());
      cout << y << endl;
    }
  }
  return 0;
}
