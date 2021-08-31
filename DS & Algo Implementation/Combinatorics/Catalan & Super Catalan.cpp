// Catalan numbers: C(n) = binomial(2n,n)/(n+1) = (2n)!/(n!(n+1)!).
// Also called Segner numbers

LL catalan[N], scatalan[N];

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

void genCatalan() {
  catalan[1] = 1 % MOD, catalan[2] = 1 % MOD;
  for (int i = 3; i <= 26; i++) {
    catalan[i] = ((4 * i - 6) % MOD * catalan[i - 1] % MOD * ModInv(i, MOD)) % MOD;
  }
  scatalan[1] = 1 % MOD, scatalan[2] = 1 % MOD;
  for (int i = 3; i <= 26; i++) {
    scatalan[i] = (3 * (2 * i - 3) % MOD * scatalan[i - 1] % MOD) % MOD;
    scatalan[i] -= ((i - 3) % MOD * scatalan[i - 2] % MOD * ModInv(i, MOD)) % MOD;
    if (scatalan[i] < 0) scatalan[i] += MOD;
  }
  for (int i = 1; i <= 26; i++) cout << catalan[i] << "\n";
}