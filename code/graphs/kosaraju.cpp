// Kosaraju {{{
struct Kosaraju {
  int N;
  vector<vector<int>> const& G;
  vector<vector<int>> Ginv;
  vector<bool> vis;
  stack<int> S;

  vector<int> comp;
  vector<vector<int>> comps;

  Kosaraju(vector<vector<int>> const& G)
    : N(size(G)), G(G), Ginv(N), vis(N), comp(N, -1) {
    for (int i = 0; i < N; i++) {
      for (auto u : G[i]) {
        Ginv[u].push_back(i);
      }
    }

    for (int i = 0; i < N; i++) if (!vis[i]) dfs(i);

    fill(begin(vis), end(vis), false);
    int cc = 0;
    while (!S.empty()) {
      int v = S.top();
      S.pop();
      if (!vis[v]) {
        comps.push_back({});
        scc(v, cc++);
      }
    }
  }

  void dfs(int v) {
    vis[v] = true;
    for (auto u : G[v]) if (!vis[u]) dfs(u);
    S.push(v);
  }

  void scc(int v, int c) {
    vis[v] = true;
    comp[v] = c;
    comps.back().push_back(v);
    for (auto u : Ginv[v]) if (!vis[u]) scc(u, c);
  }
};
// }}}
