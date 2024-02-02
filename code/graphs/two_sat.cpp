// TwoSat {{{
struct TwoSat {
  int N;
  vector<vector<int>> G;
  TwoSat(int N) : N(N), G(2*N) {}

  int neg(int u) { return u + ((u < N) ? N : -N); }
  void add_or(int v, int u) {
    G[neg(v)].push_back(u);
    G[neg(u)].push_back(v);
  }
  void add_diff(int v, int u) {
    add_or(v, u);
    add_or(neg(v), neg(u));
  }
  void add_impl(int v, int u) {
    add_or(neg(v), u);
  }
  void add_same(int v, int u) {
    add_impl(v, u);
    add_impl(neg(v), neg(u));
  }
  void add_true(int v) {
    add_or(v, v);
  }
  void add_false(int v) {
    add_or(neg(v), neg(v));
  };

  // Assumes Kosaraju returns components in topological ordering v -> u implies scc[v] <= scc[u]
  pair<bool, vector<bool>> solve() {
    vector<bool> res(N);
    auto scc = Kosaraju(G).comp;
    for (int i = 0; i < N; i++) {
      if (scc[i] == scc[neg(i)]) return {false, {}};
      res[i] = scc[i] < scc[neg(i)];
    }
    return {true, res};
  }
};
//}}}

