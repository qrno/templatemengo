int fexp(int b, int e) {
  if (e == 0) return 1;
  int h = fexp(b, e/2);
  h = (h * h) % MOD;
  if (e % 2) h = (h * b) % MOD;
  return h;
}
