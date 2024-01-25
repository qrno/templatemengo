// Eulerian Cycle {{{
pair<bool, vector<int>> eulerian_cycle(int N, vector<pair<int, int>> const& E) {
  int M = size(E);

  vector<vector<pair<int, int>>> G(N);
  for (int i = 0; i < M; i++) {
    auto [v, u] = E[i];
    G[v].push_back({u, i});
    G[u].push_back({v, i});
  }

  for (int i = 0; i < N; i++)
    if (size(G[i]) % 2)
      return {false, {}};

  vector<int> path;
  vector<bool> seen(M);

  auto dfs = [&](auto &&F, int v) -> void {
    while (!G[v].empty()) {
      auto [u, idx] = G[v].back();
      G[v].pop_back();
      if (seen[idx]) continue;
      seen[idx] = true;
      F(F, u);
    }
    path.push_back(v);
  };
  dfs(dfs, 0);

  if (size(path) != M+1) return {false, {}};

  reverse(begin(path), end(path));
  return {true, path};
}
//}}}
