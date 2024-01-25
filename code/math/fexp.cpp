// Fast Exponentiation {{{
int fexp(int b, int e) {
  b %= MOD;
  int ans = 1;
  while (e) {
    if (e & 1) (ans *= b) %= MOD;
    e >>= 1;
    (b *= b) %= MOD;
  }
  return ans;
}
//}}}