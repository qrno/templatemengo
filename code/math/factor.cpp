// Factor {{{
vector<pair<int, int>> factor(int N) {
  vector<pair<int, int>> F;
  for (auto p : primes) {
    if (p*p > N) break;
    if (N % p == 0) {
      F.push_back({p, 0});
      while (N % p == 0) {
        N /= p;
        F.back().second++;
      }
    }
  }
  if (N != 1) F.push_back({N, 1});
  return F;
}
//}}}
