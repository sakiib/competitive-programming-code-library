LL nCr[1005][1005];

void BinomCoeff() {
  for (int i = 0; i < 1005; i++) nCr[i][0] = 1;
  for (int i = 1; i < 1005; i++) {
    for (int j = 1; j <= i; j++) {
      nCr[i][j] = (nCr[i - 1][j] + nCr[i - 1][j - 1]);
    }
  }
}