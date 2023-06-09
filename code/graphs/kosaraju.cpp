struct Kosaraju {
  const int n;
  V<V<int>> G, Ginv;
  V<bool> vis;
  V<int> comp;
  stack<int> S;

  explicit Kosaraju(int n) : n(n), G(n), Ginv(n), comp(n, -1) {}

  auto add_edge(int v, int u) {
    G[v].pb(u);
    Ginv[u].pb(v);
  }

  auto dfs(int v) -> void {
    vis[v] = true;
    for (auto u : G[v]) if (!vis[u]) dfs(u);
    S.push(v);
  }

  auto scc(int v, int c) -> void {
    vis[v] = true; comp[v] = c;
    for (auto u : Ginv[v]) if (!vis[u]) scc(u, c);
  }

  auto run() {
    vis.assign(n, false);
    loop (i, n) if (!vis[i]) dfs(i);
    vis.assign(n, false);
    int cc = 0;
    while (!S.empty()) {
      int v = S.top(); S.pop();
      if (!vis[v]) scc(v, cc++);
    }
  }
};
