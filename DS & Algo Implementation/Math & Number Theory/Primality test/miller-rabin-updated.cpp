mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct MillerRabinPrimalityCheck {
  #define ran(a, b) rng() % ((b) - (a) + 1) + (a)
  typedef long long LL;

  inline LL mulMod(LL a, LL b, LL c) {
    LL x = 0, y = a % c;
    while (b > 0) {
      if (b & 1) x = (x + y) % c;
      y = (y << 1) % c;
      b = (b >> 1);
    }
    return x;
  }

  inline LL modulo(LL a, LL b, LL c) {
    LL x = 1, y = a % c;
    while (b > 0) {
      if (b & 1) x = mulMod(x, y, c);
      y = mulMod(y, y, c);
      b = (b >> 1);
    }
    return x;
  }

  inline bool millerRabin(LL p, int iter = 5) {
    if (p == 2) {
        return true;
    }
    if (p < 2 || !(p & 1)) {
        return false;
    }

    LL s = p - 1, a, temp, mod;
    while (!(s & 1)) {
      s = (s >> 1);
    }

    for (int i = 0; i < iter; i++) {
      a = ran(2, p - 1);
      temp = s;
      mod = modulo(a, temp, p);
      while (temp != (p - 1) && mod != 1 && mod != (p - 1)) {
        mod = mulMod(mod, mod, p);
        temp = (temp << 1);
      }
      if (mod != (p - 1) && !(temp & 1)) {
        return false;
      }
    }
    return true;
  }

  inline bool isPrime(LL n) {
    return millerRabin(n);
  }
} M;
