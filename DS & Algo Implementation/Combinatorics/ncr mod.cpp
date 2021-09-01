LL fact[N];

LL BigMod(LL b, LL p, LL mod) {
  LL res = 1 % mod, x = b % mod;
  while (p) {
    if (p & 1) res = (res * x) % mod;
    x = (x * x) % mod;
    p >>= 1;
  }
  return (res % mod);
}

LL ModInv(LL val, LL mod) {
  return BigMod(val, mod - 2, mod);
}

void genfact() {
  fact[0] = 1 LL;
  for (int i = 1; i < N; i++) {
    fact[i] = (fact[i - 1] % mod * i % mod) % mod;
  }
}