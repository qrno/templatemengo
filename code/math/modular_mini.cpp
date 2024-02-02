int mul(int a, int b) { return (a * b) % MOD; }
int add(int a, int b) { return (a + b) % MOD; }
int fexp(int b, int e=MOD-2) {
  b %= MOD;
  int ans = 1;
  while (e) {
    if (e & 1) ans = mul(ans, b);
    e >>= 1;
    b = mul(b, b);
  }
  return ans;
}

