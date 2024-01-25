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
    G[v].push_back(neg(u));
    G[neg(v)].push_back(u);
    G[u].push_back(neg(v));
    G[neg(u)].push_back(v);
  }
  void add_impl(int v, int u) {
    G[v].push_back(u);
    G[neg(u)].push_back(neg(v));
  }
  void add_same(int v, int u) {
    G[v].push_back(u);
    G[neg(v)].push_back(neg(u));
    G[u].push_back(v);
    G[neg(u)].push_back(neg(v));
  }

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
