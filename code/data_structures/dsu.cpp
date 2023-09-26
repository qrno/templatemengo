//{{{ DSU
struct DSU {
  vector<int> P, S;
  explicit DSU (int N) : P(N, -1), S(N, 1) {};
  int leader(int a) {
    if (P[a] == -1) return a;
    return P[a] = leader(P[a]);
  }
  int merge(int a, int b) {
    a = leader(a);
    b = leader(b);
    if (a == b) return a;
    if (S[a] < S[b]) swap(a, b);
    P[b] = a;
    S[a] += S[b];
    return a;
  }
  int same(int a, int b) {
    return leader(a) == leader(b);
  }
};
//}}}
