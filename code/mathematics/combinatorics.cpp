// Combinatorics {{{
template <unsigned P>
struct Combinatorics {
  vector<Z<P>> fact, ifact;

  explicit Combinatorics(int N) : fact(N), ifact(N) {
    fact[0] = 1;
    for (int i = 1; i < N; i++) fact[i] = fact[i-1] * i;
    ifact[N-1] = 1 / fact[N-1];
    for (int i = N-1; i-1 >= 0; i--) ifact[i-1] = ifact[i] * i;
  }

  Z<P> C(int n, int k) const {
    return k < 0 || n < k ?  0 : fact[n] * ifact[k] * ifact[n-k];
  }

  Z<P> S(int n, int k) const {
    return k == 0 ? n == 0 : C(n + k - 1, k - 1);
  }
};
//}}}
