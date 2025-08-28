// Primitive Root {{{
// Assume P is prime
int fexp_mod(int b, int e, const int P) {
  int ans = 1;
  while (e) {
    if (e & 1) ans = ans * b % P;
    e >>= 1;
    b = b * b % P;
  }
  return ans;
}

int generator(const int P) {
  vector<int> pfact;
  int phi = P-1, N = phi;
  for (int i = 2; i*i <= N; i++) {
    if (N % i == 0) {
      pfact.push_back(i);
      while (N % i == 0) N /= i;
    }
  }
  if (N > 1) pfact.push_back(N);

  for (int ans = 2; ans <= P; ans++) {
    bool ok = true;
    for (int i = 0; i < pfact.size() && ok; i++)
      ok &= fexp_mod(ans, phi/pfact[i], P) != 1;
    if (ok) return ans;
  }
  return -1;
}
// }}}
