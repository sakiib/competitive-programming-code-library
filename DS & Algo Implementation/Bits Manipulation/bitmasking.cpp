// common bitwise operations

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

#define RIGHTMOST __builtin_ctzll // rightmost setbit position
#define POPCOUNT __builtin_popcountll // total setbit, use ll for long long
#define LEFTMOST(x) (63 - __builtin_clzll(x)) // leftmost setbit position
