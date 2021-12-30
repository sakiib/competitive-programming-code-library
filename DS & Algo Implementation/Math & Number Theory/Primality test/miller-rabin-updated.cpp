#define random(a, b) rng() % ((b) - (a) + 1) + (a)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct MillerRabinPrimalityCheck {
  inline long long mulMod(long long a, long long b, long long c) {
    long long x = 0, y = a % c;
    while (b > 0) {
      if (b & 1) x = (x + y) % c;
      y = (y << 1) % c;
      b = (b >> 1);
    }
    return x;
  }

  inline long long modulo(long long a, long long b, long long c) {
    long long x = 1, y = a % c;
    while (b > 0) {
      if (b & 1) x = mulMod(x, y, c);
      y = mulMod(y, y, c);
      b = (b >> 1);
    }
    return x;
  }

  inline bool millerRabin(long long p, int iter = 5) {
    if (p == 2) {
        return true;
    }
    if (p < 2 || !(p & 1)) {
        return false;
    }

    long long s = p - 1, a, temp, mod;
    while (!(s & 1)) {
      s = (s >> 1);
    }

    for (int i = 0; i < iter; i++) {
      a = random(2, p - 1);
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

  inline bool isPrime(long long n) {
    return millerRabin(n, 5);
  }
} M;
