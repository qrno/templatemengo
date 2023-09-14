mint eval_interpolation(int X, vector<mint> const& Y) {
  int N = size(Y);

  vector<mint> pref(N), suff(N);
  for (int i = 0; i < N; i++) pref[i] = suff[i] = X-i;

  auto mult = [](auto x, auto y) { return x*y; };
  partial_sum(begin(pref), end(pref), begin(pref), mult);
  partial_sum(rbegin(suff), rend(suff), rbegin(suff), mult);

  mint ans = 0;
  for (int i = 0; i < N; i++) {
    mint num = Y[i];
    if (i-1 >= 0) num *= pref[i-1];
    if (i+1 < N) num *= suff[i+1];

    mint den = 1;
    den *= C.ifact[i];
    if (N-1-i >= 0) {
      den *= C.ifact[N-1-i];
      if ((N-1-i) % 2 == 1) den *= -1;
    }

    ans += num * den;
  }

  return ans;
}
